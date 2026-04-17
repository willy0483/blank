#include "texture.h"

Texture::Texture(const char* filePath)
	: id(0)
	, filePath(filePath)
	, width(0)
	, height(0)
	, format(GL_RGB)
	, wrapS(GL_REPEAT)
	, wrapT(GL_REPEAT)
	, filterMin(GL_LINEAR)
	, filterMax(GL_LINEAR)
{}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Texture::Load()
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMax);

	//stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
	if(data)
	{
		if(nrChannels == 1)
		{
			format = GL_RED;
		}
		else if(nrChannels == 3)
		{
			format = GL_RGB;
		}
		else if(nrChannels == 4)
		{
			format = GL_RGBA;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
