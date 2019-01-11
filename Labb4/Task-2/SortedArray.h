#pragma once
#include <iostream>
#include <stdio.h>

class SortedArray
{
private:
	int *arr;
	int size;

public:
	SortedArray() 
	{
		arr = new int[0];
		size = 0;
	};

	void insert(int x)
	{
		int *newArr = new int[size + 1];
		std::memcpy(newArr, arr, sizeof(int)*size);
		delete[] arr;
		arr = newArr;

		int i = size;
		while (i >= 0)
		{
			if (arr[i - 1] > x) {			// Compared value is higher than inserted value
				arr[i] = arr[i - 1];		// Right-shifts last compared value
				i--;						// Next value
			} 
			else							// Compared value is equal or lower than inserted value
			{		
				arr[i] = x;					// Inserts value
				size++;
				return;
			}
		}
	}

	void remove(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == x)						// Matched value
			{
				size--;								// Decrease size

				for (int j = i; j < size; j++)		// Left-shift from matched value to new size
				{
					arr[j] = arr[j + 1];
				}

				int *newArr = new int[size];
				std::memcpy(newArr, arr, sizeof(int)*size);
				delete[] arr;
				arr = newArr;

				return;
			}
		}
	}

	void print()
	{
		if (size < 1)
		{
			std::cout << "Array contains no values" << std::endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << std::endl;
		}
	}
};