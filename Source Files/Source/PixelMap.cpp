#include "..\Headers\PixelMap.hpp"



void PixelMap::Render()
{
	// Get the application for rendering
	Application * app = Application::Get();

	// Calculate the width and height of the each cell
	int cellWidth = app->GetScreenWidth() / myWidth;
	int cellHeight = app->GetScreenHeight() / myHeight;

	// Render all the cell of the map with appropriate color
	for (int i = 0; i < myHeight; i++)
	{
		for (int j = 0; j < myWidth; j++)
		{
			// Retrieve the color of the cell
			const string color = myPixelMap[i][j];
			// If the color of the cell is not black
			if (color != "")
			{
				// Color the cell with appropriate color
				app->SetDrawColor(*colorMap[color], 0xFF);
				app->DrawFilledRect(cellWidth * j, cellHeight * i, cellWidth, cellHeight);
			}
		}
	}
}

bool PixelMap::CellSetColor(int x, int y, string color)
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

string PixelMap::CellGetColor(int x, int y)
{
	// Is the cell out of range?
	if (x >= myWidth || y >= myHeight)
	{
		// Yes, report and quit
		cout << "the cell which you are trying to color does not exist" << endl;
		return "None";
	}

	// Return the color of the cell
	return myPixelMap[y][x];
}

bool PixelMap::AddColor(string colorName, int color)
{
	// Does a color with this name already exist?
	if (colorMap[colorName] != NULL)
	{
		// Yes, report and quit
		cout << "A color with the name " << colorName << " already exists." << endl;
		return false;
	}

	// Add the color to the color map
	int* storedColor = new int(color);
	colorMap[colorName] = storedColor;

	return true;
}

bool PixelMap::RemoveColor(string colorName)
{
	// Does a color with this name exist?
	if (colorMap[colorName] == NULL)
	{
		// No, report and quit
		cout << "The color with the name " << colorName << " doesn't exist." << endl;
		return false;
	}

	// Remove the color from the color map
	colorMap[colorName] = NULL;

	return false;
}

PixelMap::PixelMap(const int width, const int height)
{
	// Initialize the size of the map
	myWidth = width;
	myHeight = height;
	// Initialize the vector holding the map
	for (int i = 0; i < height; i++)
	{
		vector<string> row;
		for (int j = 0; j < width; j++)
		{
			row.push_back("");
		}
		myPixelMap.push_back(row);
	}
}

PixelMap::~PixelMap()
{
}
