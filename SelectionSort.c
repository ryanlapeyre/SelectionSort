#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <stdbool.h> 
#define SORTSIZE 8
#define RANDOMRANGE 10
void SelectionSort2DimensionalArray(int[][SORTSIZE]);
void SelectionSortPointers(int*);
void SelectionSortArray(int[]);
void RandomizeArray(int[]);
void RandomizePointer(int*);
void Randomize2DimensionalArray(int[][SORTSIZE]);
void PrintArray(int[]);
void PrintPointer(int*);
void Print2DimensionalArray(int[][SORTSIZE]);
int main (void)
{
    srand(time(NULL)); 
    int* pointerElements = malloc(sizeof(int)*SORTSIZE);
    int arrayElements [SORTSIZE] = {0};
    int arrayElements2Dimensional[SORTSIZE][SORTSIZE] = {{0}};
    //Array Sort
    puts("");
    RandomizeArray(arrayElements);
    puts("One Dimensional Array Elements (greastest to least)");
    PrintArray(arrayElements);
    SelectionSortArray(arrayElements);
    PrintArray(arrayElements);
    puts("");
    //Pointer Sort
    RandomizePointer(pointerElements);
    puts("One Dimensional Pointer Elements (least to greatest)");
    PrintPointer(pointerElements);
    SelectionSortPointers(pointerElements);
    PrintPointer(pointerElements);
    free(pointerElements);
    puts("");
    //2Dimensional Array Sort
    Randomize2DimensionalArray(arrayElements2Dimensional);
    puts("Two Dimensional Array Elements (greastest to least)");
    Print2DimensionalArray(arrayElements2Dimensional);
    SelectionSort2DimensionalArray(arrayElements2Dimensional);
    Print2DimensionalArray(arrayElements2Dimensional);
    puts("");
    return 1;
}


void SelectionSort2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE] )
{
    int firstCounter = 0;
    int secondCounter = 0;
    int thirdCounter = 0;
    int spareItem = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++ )
    {    
        for(thirdCounter = 0; thirdCounter < SORTSIZE - 1; thirdCounter++)
        {
            //We have another nested for loop here to visit all of the elements in this 2Dimensional array
            //It's so we can visit all of the rows in this array. The next loop is for the columns, which are sorted.
            //The next loop is the actual sorting loop, which compares elements next to each other and swaps them if 
            // it's needed.
            for(secondCounter = thirdCounter + 1; secondCounter < SORTSIZE; secondCounter++)
            {
                if(arrayElements2Dimensional[firstCounter][thirdCounter] < arrayElements2Dimensional[firstCounter][secondCounter]) 
                {
                    //Pay attention to how we're sorting if the next element is greater. 
                    //Thus, if we have a condition to sort if this element is greater, our sort will be greatest to least.
                    spareItem = arrayElements2Dimensional[firstCounter][secondCounter];
                    arrayElements2Dimensional[firstCounter][secondCounter] = arrayElements2Dimensional[firstCounter][thirdCounter];
                    arrayElements2Dimensional[firstCounter][thirdCounter] = spareItem;
                }
            }
        }
    }
    return;
}
void SelectionSortPointers(int* pointerElements)
{
    int firstCounter = 0;
    int secondCounter = 0;
    int spareItem = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE - 1; firstCounter++)
    {    
        for(secondCounter = firstCounter + 1; secondCounter < SORTSIZE; secondCounter++)
        {
            if ( *(pointerElements + secondCounter) < *(pointerElements + firstCounter) )
            {
                //Pay attention to how we're sorting if the next element is smaller.. 
                //Thus, if we have a condition to sort if this element is smaller, our sort will be least to greatest.
                spareItem = *(pointerElements + secondCounter);
                *(pointerElements + secondCounter) = *(pointerElements + firstCounter);
                *(pointerElements + firstCounter ) = spareItem;
            }
        }
    }
    return;
}
void SelectionSortArray(int arrayElements[])
{
    int firstCounter = 0;
    int secondCounter = 0;
    int spareItem = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE - 1; firstCounter++)
    {    
        for(secondCounter = firstCounter + 1; secondCounter < SORTSIZE; secondCounter++)
        {
            if(arrayElements[secondCounter ] > arrayElements[firstCounter]) 
            {
                //Pay attention to how we're sorting if the next element is greater. 
                //Thus, if we have a condition to sort if this element is greater, our sort will be greatest to least.
                spareItem = arrayElements[secondCounter];
                arrayElements[secondCounter] = arrayElements[firstCounter];
                arrayElements[firstCounter] = spareItem;
            }
        }
    }
    return;
}
void RandomizeArray(int arrayElements[])
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        arrayElements[counter] = rand() % RANDOMRANGE;
    }
    return;
}
void RandomizePointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        *(pointerElements + counter) = rand() % RANDOMRANGE;
    }
    return;
} 
void Randomize2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            arrayElements2Dimensional[firstCounter][secondCounter] = rand() % RANDOMRANGE;
        }
    }
    return;
}

void PrintArray(int arrayElements[]) 
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " , arrayElements[counter]);
    }
    puts("");
    return;
}
void PrintPointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " ,  *(pointerElements + counter) );
    }
    puts("");   
    return;
}
void Print2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            printf("%d | " , arrayElements2Dimensional[firstCounter][secondCounter] );
        }
        puts("");
    }
    puts("");
    return;
}
