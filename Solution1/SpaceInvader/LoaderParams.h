#pragma once

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class LoaderParams {
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID, std::string tag) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID), m_tag(tag) {}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	std::string getTag() const { return m_tag; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_textureID;
	std::string m_tag;
};