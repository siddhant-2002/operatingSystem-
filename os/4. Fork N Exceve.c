#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    int pid = fork();

    if (pid < 0)
    {
        printf("Error creating child process\n");
        exit(1);
    }

    if (pid != 0)
    {
        sort(array, size);
        int status;
        wait(&status);
        char *args[size + 2];

        int sorted_array[size];

        printf("Sorted array by parent is: ");
        for (int i = 1; i <= size; i++)
        {
            args[i] = malloc(sizeof(char) * 10);
            sprintf(args[i], "%d", sorted_array[i - 1]);
            printf("%d ", array[i - 1]);
        }
        args[size + 1] = NULL;
        for (int i = 1; i <= size; i++)
        {
            free(args[i]);
        }
    }

    else
    {
        sort(array, size);
        char *args[size + 2];
        args[0] = "./display_reverse";
        for (int i = 1; i <= size; i++)
        {
            args[i] = malloc(sizeof(char) * 10);
            sprintf(args[i], "%d", array[i - 1]);
        }
        args[size + 1] = NULL;
        execve("./display_reverse", args, NULL);
    }
}







