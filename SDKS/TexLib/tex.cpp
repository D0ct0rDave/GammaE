#include "tex.h"

Texture* poLoadTexture(char* _szFilename)
{
	Texture* tex = new Texture();
	tex->data = stbi_load(_szFilename, &tex->width, &tex->height, &tex->channels, 0);
	if (tex->data == NULL)
	{
		delete Tex;
	}
	tex->palette = NULL;
	
	return tex;
}

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

MipMap* poCreateMipMapFromTexture(Texture* _poTex)
{
	MipMap* mipMap = new MipMap();

	// Generate a mipmap from the given texture
	mipMap->lods.push_back(poCreateTextureCopy(_poTex));

	return mipMap;
}

MipMap* poCreateMipMapCopy(MipMap* _poMipMap)
{
	MipMap* mipMap = new MipMap();
	for (int cLod = 0;cLod < _poMipMap->lods.size(); cLod++)
	{
		mipMap->lods.push_back(poCreateTextureCopy(_poMipMap->lods[cLod]));
	}

	return mipMap;
}

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

void DestroyMipMap(MipMap* _poMipMap)
{
	for (int cLod = 0;cLod < _poMipMap->lods.size(); cLod++)
	{
		DestroyTexture(_poMipMap->lods[cLod]);
	}

	delete _poMipMap;
}
