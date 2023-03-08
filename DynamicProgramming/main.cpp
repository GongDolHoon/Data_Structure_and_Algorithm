#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#include "Item.h"

#define BACKPACK_SPACE 15
#define NUMBER_OF_ITEMS 5

int32_t GetMaxValue(std::vector<Item*> items);

int main()
{
	std::vector<Item*> items(NUMBER_OF_ITEMS);
	items[0] = new Item(3, 5);
	items[1] = new Item(9, 12);
	items[2] = new Item(1, 2);
	items[3] = new Item(5, 4);
	items[4] = new Item(7, 9);

	int max = GetMaxValue(items);

	std::cout << "Max Value: " << max << std::endl;
}

int32_t GetMaxValue(std::vector<Item*> items)
{
	int32_t cache[NUMBER_OF_ITEMS][BACKPACK_SPACE + 1] = {0};

	for (int i = 1; i <= BACKPACK_SPACE; ++i)
	{
		if(items[0]->GetSpace() > i)
		{
			continue;
		}

		cache[0][i] = items[0]->GetValue();
	}

	for (int i = 1; i < NUMBER_OF_ITEMS; ++i)
	{
		for (int j = 1; j <= BACKPACK_SPACE; ++j)
		{
			if (items[i]->GetSpace() > j)
			{
				cache[i][j] = cache[i - 1][j];
				continue;
			}

			int32_t remainingSpace = j - items[i]->GetSpace();
			int32_t remainingMaxValue = cache[i - 1][remainingSpace];

			int32_t firstChoice = cache[i - 1][j];
			int32_t secondChoice = items[i]->GetValue() + remainingMaxValue;

			cache[i][j] = fmax((double)firstChoice, (double)secondChoice);
		}
	}

	return cache[NUMBER_OF_ITEMS -1][BACKPACK_SPACE];
}