#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <glad/glad.h>

#include "../stb_image.cpp"

class Texture
{
private:
	unsigned int id;

	std::string filePath;

	int width;
	int height;
	int nrChannels;

	unsigned int format;
	unsigned int wrapS;
	unsigned int wrapT;
	unsigned int filterMin;
	unsigned int filterMax;

public:
	Texture(const char* filePath);
	~Texture();

	void Load();
	void Bind();
    void UnBind();
};

#endif
