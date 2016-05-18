#pragma once
#include "Application.hpp"
#include <vector>
#include <iostream>

using namespace std;

class PixelMap
{
public:
	// The colors available for the map
	enum Color
	{
		None,
		Blue = 0x00bbbb
	};
	// Render the map
	void Render();
	// Set the color of a cell on the map
	bool CellSetColor(int x, int y, Color color);

	PixelMap(const int width, const int height);
	~PixelMap();
private:
	// The width of the map
	int myWidth;
	// The height of the map
	int myHeight;
	// The vector of the map
	vector<vector<Color>> myPixelMap;
};

