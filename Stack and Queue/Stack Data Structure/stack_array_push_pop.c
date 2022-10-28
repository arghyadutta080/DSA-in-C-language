#include <stdio.h>
#include <stdlib.h>
#define N 10
int stack[N];
int top = -1;

void push(int value)
{
    if (top == N - 1)
        printf("\nStack overflow\n");
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack Underflow\n");
    else
    {
        printf("Popped value = %d\n", stack[top]);
        top--;
    }
}

void display()
{
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main()
{
    printf("Press 1 to push\nPress 2 to pop\nPress 3 to diaplay\nPress 4 to exit the code\n");
    int x;
    while (x != 4)
    {
        printf("Enter your choice : ");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            int value;
            printf("Enter the value to push : \n");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            break;
        }
    }

    return 0;
}