#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LIMIT 10

//Used for passing multiple arguments to a thread
struct Passing_for_threads  {
    int array[LIMIT];
    int array_size;
    int sum;
}; typedef struct Passing_for_threads arg_t;

int addition(int array[], int size) 
{
    int buffer = 0;
    for(int i = 0; i < size; i++){
        buffer += array[i];
    }
    return buffer;
}

int multiplacation(int array[], int size) 
{
    int buffer = 0;
    for(int i = 0; i < size; i++){
        if (i == 0) 
            buffer = array[i];
        else 
            buffer *= array[i];
    }
    return buffer;
}

int subtraction(int array[], int size) 
{
    int buffer = 0;
    for(int i = 0; i < size; i++){
        if (i == 0) 
            buffer = array[i];
        else 
            buffer -= array[i];
    }
    return buffer;
}

int average(float sum, int size) 
{
    float avg = sum / (float)size;
    return avg;
}
void *routine(arg_t *argt)
{
    int add = addition(argt->array, argt->array_size);
    int mul = multiplacation(argt->array, argt->array_size);
    int sub = subtraction(argt->array, argt->array_size);

    printf("Addition of elements = %d\n", add);
    printf("product of elements = %d\n", mul);
    printf("Subbtraction of elements = %d\n", sub);

    argt->sum = add;
}

int main() 
{
printf("Enter ten numbers: ");
    arg_t args;
    int sum;

    //Getting array from the user
    for (int i = 0; i < LIMIT; i++) {
        scanf("%d", &args.array[i]);
    }

    //Finding the size of the array
    int arr_size = sizeof(args.array)/sizeof(args.array[0]);
    args.array_size = arr_size;

    //Passing the array and size of array to the thread to find out sum and product
    pthread_t thread;
    pthread_create(&thread, NULL, routine, &args);
    pthread_join(thread, NULL);

    float avg = average(args.sum, args.array_size);
    printf("average of elements = %f\n", avg);

    return EXIT_SUCCESS;
}