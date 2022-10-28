#include <stdio.h>

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int deletion(int arr[], int size, int index)
{
    if (index > size)
        return -1;
    else
    {
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
    }
    return 1;
}

int main()
{
    int arr[100] = {2, 34, 56, 12, 67};
    int size = 5;
    printf("Old array : \n");
    displayArray(arr, size);
    printf("\n");
    int num;
    printf("Enter how many numbers you want to delete : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        int index;
        printf("Enter index : ");
        scanf("%d", &index);
        if (i != 0)
            index--;
        // size of array decreases after every iteration so, input index need to be decrerased one manually to point actual index we desire
        deletion(arr, size, index);
        size--;
    }
    printf("Updated array : \n");
    displayArray(arr, size);

    return 0;
}