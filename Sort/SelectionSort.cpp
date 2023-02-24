#include <iostream>

#define SIZE 5

void selectionSort(int data[])
{
	for(int i = 0; i < SIZE-1; ++i)
	{
		int min = data[i];
		int min_index = i;
		for(int j = 0 + i; j < SIZE-1; ++j)
		{
			if(min > data[j+1])
			{
				min = data[j+1];
				min_index = j+1;
			}
		}
		int temp = data[i];
		data[i] = min;
		data[min_index] = temp;
	}
}

int main()
{
	int nums[SIZE] = {3, 1, 2, 5, 4};
	
	printf("Unsorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	
	}
	
	selectionSort(nums);
	
	printf("\n\nSorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	}
	
	return 0;
}
