#include "rogueutil.h"
#include <stdlib.h> // for rand()
#include <time.h>
#include <iostream>

using namespace std;
using namespace rogueutil;

void draw(int*);
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

	//bubbleSort(theArray);
	//randomizeArray(theArray);

	//quickSort(theArray, 0, NUM_VALUES-1);
	//randomizeArray(theArray);

	insertionSort(theArray, NUM_VALUES);

	return 0;
}

void draw(int* theArray)
{
	for (int i = 0; i < NUM_VALUES; i++)
	{
		setColor(WHITE);
		for (int j = 0; j < MAX_VALUE; j++)
		{
			{
				printXY(i+1,j+1,"X");
			}
			if (j+1 == theArray[i])
				setColor(BLACK);
		}

	}
	msleep(DELAY);
	return;
}

void randomizeArray(int * theArray)
{
	for (int i = 0; i < NUM_VALUES; i++)
	{
		theArray[i] = rand() % MAX_VALUE + 1;
		draw(theArray);
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
				draw(theArray);
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
			draw(theArray);
		}
	}
	swap(&theArray[i+1], &theArray[high]);
	draw(theArray);
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
			draw(theArray);
			j--;
		}
		theArray[j+1] = key;
	}

	return;
}
