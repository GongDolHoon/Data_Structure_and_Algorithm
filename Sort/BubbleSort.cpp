#include <iostream>

#define SIZE 5

void bubbleSort(int data[])
{
	for(int i = 0; i < SIZE-1; ++i)
	{
		for(int j = 0; j < SIZE-i-1; ++j)
		{
			if(data[j] > data[j+1])
			{
				int temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
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
	
	bubbleSort(nums);
	
	printf("\n\nSorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	}
	
	return 0;
}

