#include "rogueutil.h"
#include <stdlib.h> // for rand()
#include <time.h>
#include <iostream>

using namespace std;
using namespace rogueutil;

void draw(int*, int, int);
void randomizeArray(int*);
void bubbleSort(int*, int*);
void quickSort(int*, int, int, int*);
int partition(int*, int, int, int*);
void insertionSort(int*, int, int*);

#define NUM_VALUES 100
#define MAX_VALUE 25
#define DELAY 0 //delay after each new draw, in milliseconds

int main(void)
{
	int numBubSwaps = 0, numQuickSwaps = 0, numInsSwaps = 0;
	hidecursor();
	int * theArray = new int[NUM_VALUES];

	srand (time(NULL));

	randomizeArray(theArray);

	bubbleSort(theArray, &numBubSwaps);
	randomizeArray(theArray);

	quickSort(theArray, 0, NUM_VALUES-1, &numQuickSwaps);
	randomizeArray(theArray);

	insertionSort(theArray, NUM_VALUES, &numInsSwaps);

	cls();
	setColor(WHITE);

	cout<<"Number of sorts in each algorithm:"<<endl<<"Bubble sort: "<<numBubSwaps<<endl;
	cout<<"Quick sort: "<<numQuickSwaps<<endl<<"Insertion sort: "<<numInsSwaps;

	return 0;
}

void draw(int* theArray, int a, int b)
{
	setColor(WHITE);
	for (int j = 0; j < MAX_VALUE; j++)
	{
		if (j==theArray[a])
		{
			setColor(BLACK);
		}
		printXY(a+1, MAX_VALUE-j, to_string(theArray[a]%10));
	}
	setColor(WHITE);
	for (int j = 0; j < MAX_VALUE; j++)
	{
		if (j==theArray[b])
		{
			setColor(BLACK);
		}
		printXY(b+1, MAX_VALUE-j, to_string(theArray[b]%10));
	}

/*	for (int i = a; i <= b; i++)
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

	}*/
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

void bubbleSort(int* theArray, int* numBubSwaps)
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
				*numBubSwaps += 1;
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

void quickSort(int theArray[], int low, int high, int* numQuickSwaps)
{
	if (low < high)
	{
		int p = partition(theArray, low, high, numQuickSwaps);
		quickSort(theArray, low, p-1, numQuickSwaps);
		quickSort(theArray, p+1, high, numQuickSwaps);
	}

	return;
}

int partition(int theArray[], int low, int high, int* numQuickSwaps)
{
	int pivot = theArray[high];
	int i = (low-1);
	for (int j = low; j < high; j++)
	{
		if (theArray[j] <= pivot)
		{
			i += 1;
			swap(&theArray[i], &theArray[j]);
			*numQuickSwaps += 1;
			draw(theArray, i, j);
		}
	}
	swap(&theArray[i+1], &theArray[high]);
	*numQuickSwaps += 1;
	draw(theArray, i+1, high);
	return (i+1);
}

void insertionSort(int* theArray, int len, int* numInsSwaps)
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
			*numInsSwaps += 1;
			draw(theArray, j, j+1);
			j--;
		}
		theArray[j+1] = key;
	}

	return;
}
