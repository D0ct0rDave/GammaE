#include "stb_image.h"

// ----------------------------------------------------------------------------
PixelFormat GetPixelFormatFromChannels(int channels)
{
	switch (channels)
	{
		case 1:	return PixelFormat::GRAY8;
		case 3:	return PixelFormat::RGB24;
		case 4:	return PixelFormat::ARGB32;
	}

	return PixelFormat::ARGB32;
}
// ----------------------------------------------------------------------------
Texture* poCreateTexture(int width, int height, int numChannels)
{
	Texture* tex = new Texture();

	tex->channels = 3;
	tex->width = width;
	tex->height = height;
	tex->palette = NULL;
	tex->data = (unsigned char*)malloc(tex->height * tex->width * tex->channels);
	tex->pixelFormat = GetPixelFormatFromChannels(tex->channels);
	
	return tex;
}
// ----------------------------------------------------------------------------
Texture* poLoadTexture(char* _szFilename)
{
	Texture* tex = new Texture();
	tex->data = stbi_load(_szFilename, (int*)&tex->width, (int*) & tex->height, (int*)&tex->channels, 0);
	if (tex->data == NULL)
	{
		delete tex;
	}
	tex->palette = NULL;
	tex->pixelFormat = GetPixelFormatFromChannels(tex->channels);

	return tex;
}
// ----------------------------------------------------------------------------
Texture* poCreateTextureCopy(Texture* _poTex)
{
	Texture* tex = new Texture();

	size_t dataSize = _poTex->width * _poTex->height * _poTex->channels;
	tex->data = (unsigned char*)malloc(dataSize);
	memcpy(tex->data, _poTex->data, dataSize);

	tex->width = _poTex->width;
	tex->height = _poTex->height;
	tex->channels = _poTex->channels;
	tex->pixelFormat = _poTex->pixelFormat;

	if (_poTex->palette != NULL)
	{
		tex->palette = new Palette();

		size_t paletteDataSize = _poTex->palette->numColors * 4;
		tex->palette->data = (unsigned char*)malloc(paletteDataSize);
		memcpy(tex->palette->data, _poTex->palette->data, paletteDataSize);

		tex->palette->numColors = _poTex->palette->numColors;
	}

	return tex;
}
// ----------------------------------------------------------------------------
MipMap* poCreateMipMapFromTexture(Texture* _poTex)
{
	MipMap* mipMap = new MipMap();

	// Generate a mipmap from the given texture
	mipMap->lods.push_back(poCreateTextureCopy(_poTex));

	return mipMap;
}
// ----------------------------------------------------------------------------
MipMap* poCreateMipMap(int width, int height, int numChannels)
{
	Texture* texture = poCreateTexture(width, height, numChannels);
	MipMap* mipMap = poCreateMipMapFromTexture(texture);
	DestroyTexture(texture);

	return mipMap;
}
// ----------------------------------------------------------------------------
MipMap* poCreateMipMapCopy(MipMap* _poMipMap)
{
	MipMap* mipMap = new MipMap();
	for (int cLod = 0;cLod < _poMipMap->lods.size(); cLod++)
	{
		mipMap->lods.push_back(poCreateTextureCopy(_poMipMap->lods[cLod]));
	}

	return mipMap;
}
// ----------------------------------------------------------------------------
MipMap* poLoadTextureAsMipmap(char* _szFilename)
{
	Texture* texture = poLoadTexture(_szFilename);
	if (texture == NULL)
	{
		return NULL;
	}
	
	MipMap* mipmap = poCreateMipMapFromTexture(texture);
	DestroyTexture(texture);
	
	return mipmap;
}
// ----------------------------------------------------------------------------
void DestroyTexture(Texture* _poTex)
{
	free(_poTex->data);
	if (_poTex->palette != NULL)
	{
		free(_poTex->palette->data);
		delete _poTex->palette;
	}

	delete _poTex;
}
// ----------------------------------------------------------------------------
void DestroyMipMap(MipMap* _poMipMap)
{
	for (int cLod = 0;cLod < _poMipMap->lods.size(); cLod++)
	{
		DestroyTexture(_poMipMap->lods[cLod]);
	}

	delete _poMipMap;
}
// ----------------------------------------------------------------------------
