#include <iostream>

#define SIZE 5

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int data[], int left, int right)
{
	int i = left;
	
	int* leftPointer = &(data[left]);
	int* rightPointer = &(data[right]);
	
	for(int i = left; i < right; ++i)
	{
		if(data[i] < data[right])
		{
			swap(&(data[i]), &(data[left]));
			left++;
		}
	}
	
	swap(rightPointer, &(data[left]));
	
	return left;
}

void quickSortRecursive(int data[], int left, int right)
{
	if(left >= right)
	{
		return;
	}
	
	int pivotPos = partition(data, left, right);
	
	quickSortRecursive(data, 0, pivotPos-1);
	quickSortRecursive(data, pivotPos + 1, right);
}

void quickSort(int data[])
{
	quickSortRecursive(data, 0, SIZE-1);
}

int main()
{
	int nums[SIZE] = {3, 1, 2, 5, 4};
	
	printf("Unsorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	
	}
	
	quickSort(nums);
	
	printf("\n\nSorted Array: ");
	
	for(const int data: nums)
	{
		printf("%d ", data);
	}
	
	return 0;
}

