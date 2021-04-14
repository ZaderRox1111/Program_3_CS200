#include <stdio.h>

//finds maximum value in array
int max(int* arrayPtr, int size)
{
	//create variables, initialize max as small number
	int index;
	int max = 0;

	//loop through arrayptr
	//if the element is greater than max set new max as element
	for (index = 0; index < size; index++)
	{
		if (*(arrayPtr + index) > max)
		{
			max = *(arrayPtr + index);
		}
	}

	//return max value
	return max;
}

//finds minimum value in array
int min(int* arrayPtr, int size)
{
	//create variables, make min a large number
	int index;
	int min = 10000000;

	//loop through arrayptr
	//if the element is greater than max set new max as element
	for (index = 0; index < size; index++)
	{
		if (*(arrayPtr + index) < min)
		{
			min = *(arrayPtr + index);
		}
	}
	//return the minimum
	return min;
}

//finds the average value of an array
float average(int* arrayPtr, int size)
{
	//create variables
	int index;
	float average;
	int sum = 0;

	//loop through ptr array and add each value to the sum
	for (index = 0; index < size; index++)
	{
		sum += *(arrayPtr + index);
	}

	//divide sum by number of values (size) for average
	average = (float) sum / size;

	//return average value
	return average;
}

//sorts the array, smallest value first to largest value
void bubbleSort(int* arrayPtr, int size)
{
	//create variables
	int outIndex, inIndex, hold;

	//loop through ptr array with nested loops
	//swap values if first is greater
	for (outIndex = 0; outIndex < size - 1; outIndex++)
	{
		for (inIndex = 0; inIndex < size - outIndex - 1; inIndex++)
		{
			if (*(arrayPtr + inIndex) > *(arrayPtr + inIndex + 1))
			{
				hold = *(arrayPtr + inIndex);
				*(arrayPtr + inIndex) = *(arrayPtr + inIndex + 1);
				*(arrayPtr + inIndex + 1) = hold;
			}
		}
	}
}

//finds the median number of an array
//if the array is even, finds the average btwn the middle two
float median(int* arrayPtr, int size)
{
	//create variables
	float medianValue;
	int medianIndex;
	bubbleSort(arrayPtr, size);

	//if the size is even, average middle values
	//if odd, take the middle value
	//(size + 1) / 2 - 1 (-1 for index)
	if (size % 2 == 0)
	{
		//find first value to be averaged
		medianIndex = size / 2;
		medianValue = *(arrayPtr + medianIndex);

		//add second value to be averaged
		medianIndex--;
		medianValue += *(arrayPtr + medianIndex);

		//take the average
		medianValue /= 2;
	}
	else
	{
		//find median index, then value
		medianIndex = ((size + 1) / 2) - 1;
		medianValue = *(arrayPtr + medianIndex);
	}

	//return the median
	return medianValue;
}

//main function
//obtains max, min, average, and median and prints them
//prints original array as well, using pointers
int main()
{
	int array[] = {1, 4, 7, 3, 2, 9, 12, 5};
	int* arrayPtr = array;
	int size = sizeof(array) / sizeof(int);
	int index, maxVal, minVal;
	float averageVal, medianVal;

	for (index = 0; index < size; index++)
	{
		printf("%3d", *(arrayPtr + index));
	}
	printf("\n");

	maxVal = max(arrayPtr, size);
	minVal = min(arrayPtr, size);
	averageVal = average(arrayPtr, size);
	medianVal = median(arrayPtr, size);

	printf("Max value is: %d\n", maxVal);
	printf("Min value is: %d\n", minVal);
	printf("Average value is: %.3f\n", averageVal);
	printf("Median value is: %.1f\n", medianVal);

	return 0;
}
