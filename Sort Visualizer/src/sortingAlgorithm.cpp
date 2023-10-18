#include "rogueutil.h"
#include <stdlib.h> // for rand()
#include <time.h>
#include <iostream>

using namespace std;
using namespace rogueutil;

void draw(int*, int, int);
void randomizeArray(int*);
void bubbleSort(int*);
void quickSort(int*, int, int);
int partition(int*, int, int);
void insertionSort(int*, int);

#define NUM_VALUES 50
#define MAX_VALUE 25
#define DELAY 0 //delay after each new draw, in milliseconds

int main(void)
{
	hidecursor();
	int * theArray = new int[NUM_VALUES];

	srand (time(NULL));

	randomizeArray(theArray);

	bubbleSort(theArray);
	randomizeArray(theArray);

	quickSort(theArray, 0, NUM_VALUES-1);
	randomizeArray(theArray);

	insertionSort(theArray, NUM_VALUES);

	return 0;
}

void draw(int* theArray, int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		setColor(WHITE);
		for (int j = 0; j < MAX_VALUE; j++)
		{
			if (j==theArray[i])
			{
				setColor(BLACK);
			}
				printXY(i+1,MAX_VALUE-j,to_string((theArray[i]%10)));
		}

	}
	msleep(DELAY);
	return;
}

void randomizeArray(int * theArray)
{
	for (int i = 0; i < NUM_VALUES; i++)
	{
		theArray[i] = 1 +(rand() % MAX_VALUE);
		draw(theArray, i,i);
	}

}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* theArray)
{
	bool swapped;
	int temp = 0;
	for (int i = 0; i < NUM_VALUES; i++)
	{
		swapped = false;
		for (int j = 0; j < NUM_VALUES - i - 1; j++)
		{
			if (theArray[j] > theArray[j+1])
			{
				swap(&theArray[j], &theArray[j+1]);
				swapped = true;
				draw(theArray, j, j+1);
			}
			//draw(theArray);
		}
		if (swapped == false)
			break;
	}

	return;
}

void quickSort(int theArray[], int low, int high)
{
	if (low < high)
	{
		int p = partition(theArray, low, high);
		quickSort(theArray, low, p-1);
		quickSort(theArray, p+1, high);
	}

	return;
}

int partition(int theArray[], int low, int high)
{
	int pivot = theArray[high];
	int i = (low-1);
	for (int j = low; j < high; j++)
	{
		if (theArray[j] <= pivot)
		{
			i += 1;
			swap(&theArray[i], &theArray[j]);
			draw(theArray, i, j);
		}
	}
	swap(&theArray[i+1], &theArray[high]);
	draw(theArray, i+1, high);
	return (i+1);
}

void insertionSort(int* theArray, int len)
{
	int key;
	int j;
	for (int i = 0; i < len; i++)
	{
		key = theArray[i];
		j = i - 1;

		while (j >= 0 && theArray[j] > key)
		{
			swap(&theArray[j], &theArray[j+1]);
			draw(theArray, j, j+1);
			j--;
		}
		theArray[j+1] = key;
	}

	return;
}
