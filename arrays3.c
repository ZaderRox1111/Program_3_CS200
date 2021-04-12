#include <stdio.h>

int max(int array[], int size)
{
	//create variables, initialize max as small number
	int index;
	int max = 0;

	//loop through the array
	//if the element at the array is greater than the max
	//set max as the element
	for(index = 0; index < size; index++)
	{
		if (array[index] > max) 
		{
			max = array[index];
		}
	}

	//return the max value
	return max;
}

int min(int array[], int size)
{
	//create variables, initialize min as large number
	int index;
	int min = 100000000;

	//loop through the array
	//if the element at the array is less than the min
	//set min as the element
	for(index = 0; index < size; index++)
	{
		if (array[index] < min) 
		{
			min = array[index];
		}
	}

	//return the min value
	return min;
}

float average(int array[], int size)
{
	//create variables
	int index;
	float average;
	int sum = 0;

	//loop through the array and add each element to find the sum
	for (index = 0; index < size; index++)
	{
		sum = sum + array[index];
	}

	printf("sum: %d\n", sum);

	//to find average divide total sum by amount of values (sum)
	average = (float) sum / size;

	//return the average
	return average;
}

void bubbleSort(int array[], int size)
{
	//create variables
	int outIndex, inIndex, hold;

	//loop through the array with nested loops
	//swap values if first is greater
	for (outIndex = 0; outIndex < size - 1; outIndex++)
	{
		for (inIndex = 0; inIndex < size - outIndex - 1; inIndex++)
		{
			if (array[inIndex] > array[inIndex + 1])
			{
				hold = array[inIndex];
				array[inIndex] = array[inIndex + 1];
				array[inIndex + 1] = hold;
			}
		}
	}
}

float median(int array[], int size)
{
	//create variables
	float medianValue;
	int medianIndex;
	bubbleSort(array, size);

	//if the size is even, you have to average the two middle vals
	//if it is odd, you take the middle value
	//(size + 1) / 2 - 1 (-1 for index)
	if (size % 2 == 0)
	{
		//find first value to be averaged
		medianIndex = size / 2;
		medianValue = array[medianIndex];

		//add second value to be averaged
		medianIndex = medianIndex - 1;
		medianValue = medianValue + array[medianIndex];

		//take the average
		medianValue = medianValue / 2;
	}
	else
	{
		//find median index, then find value with the index
		medianIndex = ((size + 1) / 2) - 1;
		medianValue = array[medianIndex];
	}

	//return the median
	return medianValue;
}

int main()
{
	int array[] = {1, 4, 7, 3, 2, 9, 12, 5};
	int size = sizeof(array) / sizeof(int);
	int index, maxVal, minVal;
	float averageVal, medianVal;

	for (index = 0; index < size; index++)
	{
		printf("%3d", array[index]);
	}
	printf("\n");

	maxVal = max(array, size);
	minVal = min(array, size);
	averageVal = average(array, size);
	medianVal = median(array, size);

	printf("Max value is: %d\n", maxVal);
	printf("Min value is: %d\n", minVal);
	printf("Average value is: %.3f\n", averageVal);
	printf("Median value is: %.1f\n", medianVal);

	return 0;
}
