#include <iostream>
#include <ctime>

#define MAX_ARR 20

void merge(int data[], int left, int mid, int right)
{
	int* sortedArray = new int[right - left + 1];
	int* firstArrayPointer = &(data[left]);
	int* secondArrayPointer = &(data[mid + 1]);
	int* sortedArrayPointer = &(sortedArray[0]);
	int* pivotPointer = &(data[mid]);
	
	while (firstArrayPointer <= pivotPointer && secondArrayPointer <= &(data[right]))
	{
		if(*firstArrayPointer < *secondArrayPointer)
		{
			*(sortedArrayPointer++) = *(firstArrayPointer++);
		}
		else 
		{
			*(sortedArrayPointer++) = *(secondArrayPointer++);
		}
	}
	
	if(firstArrayPointer > pivotPointer)
	{
		while(secondArrayPointer <= &(data[right]))
		{
			*(sortedArrayPointer++) = *(secondArrayPointer++);
		}
	}
	else
	{
		while(firstArrayPointer <= pivotPointer)
		{
			*(sortedArrayPointer++) = *(firstArrayPointer++);
		}
	}
	
	int i = left;
	int k = 0;
	
	for(i = left, k = 0; i <= right; ++i, ++k)
	{
		data[i] = sortedArray[k];
	}
	
	delete sortedArray;
}

void mergeSortRecursive(int data[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSortRecursive(data, left, mid);
		mergeSortRecursive(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}

void mergeSort(int data[])
{
	mergeSortRecursive(data, 0, MAX_ARR - 1);
}

int main(void)
{
	srand(time(NULL));
	
	int arr[MAX_ARR];
	
	for(int i = 0; i < MAX_ARR; ++i)
	{
		arr[i] = (rand() % 1000) + 1;
	}
	
	std::cout << "Unsorted Array: ";
	
	for(const int data : arr)
	{
		std::cout << data << " ";
	}
	
	std::cout << std::endl;
	
	mergeSort(arr);
	
	std::cout << "Sorted Array: ";
	
	for(const int data : arr)
	{
		std::cout << data << " ";
	}
	
	std::cout << std::endl;
	
	return 0;
}
