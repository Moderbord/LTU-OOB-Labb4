#include "pch.h"
#include "SortedArray.h"
#include <iostream>



int main()
{
	SortedArray sArray;

	sArray.insert(5);
	sArray.insert(3);
	sArray.insert(6);
	sArray.insert(9);
	sArray.insert(2);

	sArray.remove(3);

	sArray.insert(8);

	sArray.print();
}
