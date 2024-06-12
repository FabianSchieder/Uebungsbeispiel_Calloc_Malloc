#include <iostream>
#include <stdlib.h>

void* createArrayWithMalloc(size_t size);
void* createArrayWithCalloc(size_t size);

void randomNumbersOnArray(int* ptr, size_t size);

void printArray(int* ptr, size_t size);

int main()
{
    size_t size = 5;

    printf("\nMalloc: ");
    int* ptr = (int*)createArrayWithMalloc(size);
    randomNumbersOnArray(ptr, size);
    printArray(ptr, size);

    printf("\n\nCalloc: ");
    int* ptr2 = (int*) createArrayWithCalloc(size);
    randomNumbersOnArray(ptr2, size);
    printArray(ptr2, size);


    free(ptr), free(ptr2);

    return 0;
}

void* createArrayWithMalloc(size_t size)
{
    return malloc(size * sizeof(int));
}

void randomNumbersOnArray(int* ptr, size_t size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 100;
    }
}

void printArray(int* ptr, size_t size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\n%d", ptr[i]);
    }
}

void* createArrayWithCalloc(size_t size)
{
    return calloc(size, sizeof(int));
}
