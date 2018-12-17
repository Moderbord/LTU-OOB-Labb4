#pragma once
#include <iostream>

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
		int i = size;
		while (i >= 0)
		{
			if (arr[i - 1] > x) {
				arr[i] = arr[i - 1];		// Right-shifts last compared value
				i--;
			} 
			else
			{
				arr[i] = x;
				size++;
				return;
			}
		}
	}

	void remove(int x)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == x)
			{
				size--;

				for (int j = i; j < size; j++)
				{
					arr[j] = arr[j + 1];
				}
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