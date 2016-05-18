#include "..\Headers\PixelMap.hpp"



void PixelMap::Render()
{
	// Calculate the width and height of the each cell
	int cellWidth = Application::Get()->GetScreenWidth() / myWidth;
	int cellHeight = Application::Get()->GetScreenHeight() / myHeight;

	// Render all the cell of the map with appropriate color
	for (int i = 0; i < myHeight; i++)
	{
		for (int j = 0; j < myWidth; j++)
		{
			const Color color = myPixelMap[i][j];
			if (color != NULL)
			{
				Application::Get()->SetDrawColor(color, 0xFF);
				Application::Get()->DrawFilledRect(cellWidth * j, cellHeight * i, cellWidth, cellHeight);
			}
			
		}
	}
}

bool PixelMap::CellSetColor(int x, int y, Color color)
{
	// Is the cell out of range?
	if (x >= myWidth || y >= myHeight)
	{
		// Yes, report and quit
		cout << "the cell which you are trying to color does not exist" << endl;
		return false;
	}

	// Set the color of the cell
	myPixelMap[y][x] = color;

	return true;
}

PixelMap::PixelMap(const int width, const int height)
{
	// Initialize the size of the map
	myWidth = width;
	myHeight = height;
	// Initialize the vector holding the map
	for (int i = 0; i < height; i++)
	{
		vector<Color> row;
		for (int j = 0; j < width; j++)
		{
			row.push_back(None);
		}
		myPixelMap.push_back(row);
	}
}

PixelMap::~PixelMap()
{
}
