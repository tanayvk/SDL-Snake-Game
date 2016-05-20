#pragma once
#include "Application.hpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

class PixelMap
{
public:
	// Render the map
	void Render();

	// Set the color of a cell on the map
	bool CellSetColor(int x, int y, string color);
	// Get the color of a cell on the map
	string CellGetColor(int x, int y);

	// Add color to the color map
	bool AddColor(string colorName, int color);
	// Remove a color from the color map
	bool RemoveColor(string colorName);

	PixelMap(const int width, const int height);
	~PixelMap();
private:
	// The width of the map
	int myWidth;
	// The height of the map
	int myHeight;

	// The vector holding the map
	vector<vector<string>> myPixelMap;

	// The color map
	map<string, int*> colorMap;
};

