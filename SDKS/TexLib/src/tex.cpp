#include "tex.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// ----------------------------------------------------------------------------
int GetChannelsFromMipMapPixelFormat(int pixelformat)
{
	switch (pixelformat)
	{
		case 1:	return 1;
		case 2:
		case 5:
		case 6:
		case 7: return 2;
		case 8: return 3;
		case 9: return 4;
	}

	assert(pixelformat != 3, "Format not supported");
	return 0;
}
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
		return NULL;
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
MipMap* poLoadMipMap(FILE* fd)
{
	unsigned short version;
	unsigned char lods;
	unsigned int mipmapWidth;
	unsigned int mipmapHeight;
	unsigned char format;

	fread(&version, sizeof(version), 1, fd);
	fread(&format, sizeof(format), 1, fd);
	fread(&lods, sizeof(lods), 1, fd);
	fread(&mipmapWidth, sizeof(mipmapWidth), 1, fd);
	fread(&mipmapHeight, sizeof(mipmapHeight), 1, fd);

	unsigned char channels = GetChannelsFromMipMapPixelFormat(format);

	MipMap* mipMap = poCreateMipMap(mipmapWidth, mipmapHeight, channels);
	fread(mipMap->lods[0]->data, mipmapWidth * mipmapHeight * channels, 1, fd);

	for (int l = 1;l < lods;l++)
	{
		mipmapWidth >>= 1;
		mipmapHeight >>= 1;
		fseek(fd, mipmapWidth * mipmapHeight * channels, SEEK_CUR);
	}

	return mipMap;
}
// ----------------------------------------------------------------------------
void FlipTextureVertical(Texture* texture)
{
	stbi__vertical_flip(texture->data, texture->width, texture->height, texture->channels);
}
// ----------------------------------------------------------------------------
bool SaveTexture(char* _szFilename, Texture* texture)
{
	return stbi_write_png(_szFilename, texture->width, texture->height, texture->channels, texture->data, 0);
}
// ----------------------------------------------------------------------------
