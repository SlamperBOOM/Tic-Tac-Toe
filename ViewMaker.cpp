#include "ViewMaker.h"

void ViewMaker::DrawField(const std::vector<std::vector<char>>& field, std::string message)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			pattern[i * 2][j * 2] = field[i][j];
		}
	}
	CleanScreen();
	for (int i = 0; i < 5; ++i)
	{
		std::cout << pattern[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << message << std::endl;
}
