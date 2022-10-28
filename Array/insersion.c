#include <stdio.h>

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int insertion(int arr[], int capacity, int size, int digit, int index)
{
    if (index > size)
        return -1;
    else
    {
        for (int i = size - 1; i >= index; i--)
            arr[i + 1] = arr[i];
        arr[index] = digit;
        return 1;
    }
}

int main()
{
    int arr[100] = {2, 34, 56, 12, 67};
    int size = 5;
    printf("Old array : \n");
    displayArray(arr, size);
    printf("\n");
    int num;
    printf("Enter how many numbers you want to enter : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        int digit, index;
        printf("Enter number : ");
        scanf("%d", &digit);
        printf("Enter index : ");
        scanf("%d", &index);
        insertion(arr, 100, size, digit, index);
        size++;
    }
    printf("Updated array : \n");
    displayArray(arr, size);

    return 0;
}