#include <iostream>

#define SIZE 5

void insertionSort(int data[])
{
	for(int i = 1; i < SIZE; ++i)
	{
		for(int j = i-1; j >= 0; --j)
		{
			if(data[i] < data[j])
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
			else
			{
				break;
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
	
	insertionSort(nums);
	
	printf("\n\nSorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	}
	
	return 0;
}
