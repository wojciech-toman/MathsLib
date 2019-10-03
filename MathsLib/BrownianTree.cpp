#include "BrownianTree.h"


namespace MathsLib
{
	bool* BrownianTree::operator()(const std::vector <TREE_SEED>& _seeds, unsigned int _width, unsigned int _height,
		unsigned int _iterations)
	{
		// If no seeds are defined, return NULL
		if(!_seeds.size())
			return NULL;

		int i, j, x, y, xNew, yNew;
		bool found;

		bool* pData = new bool[_width * _height];
		memset(pData, false, sizeof(bool) * _width * _height);

		// Put starting seeds
		for(unsigned int k = 0; k < _seeds.size(); ++k)
			pData[_seeds[k].second * _width + _seeds[k].first] = true;

		for(unsigned int n = 0; n < _iterations; ++n)
		{
			// Put new walker
			x = rand() % (_width - 2) + 1;
			y = rand() % (_height - 2) + 1;

			// Repeat until we find another seed
			while(true)
			{
				// Move in a random direction
				xNew = x + (rand() % 3) - 1;
				if(xNew > 0 && xNew < static_cast<int>(_width) - 1)
					x = xNew;
				yNew = y + (rand() % 3) - 1;
				if(yNew > 0 && yNew < static_cast<int>(_height) - 1)
					y = yNew;

				// Have we struck an existing point?
				found = false;
				for(i = -1; i <= 1; ++i)
				{
					for(j = -1; j <= 1; ++j)
					{
						if(pData[(y + j) * _width + (x + i)] == true)
						{
							found = true;
							break;
						}
					}
					
					if(found)
						break;
				}

				if(found)
					break;
			}
			
			pData[y * _width + x] = true;
		}

		return pData;
	}

}