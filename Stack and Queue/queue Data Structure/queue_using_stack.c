#include <stdio.h>
#define N 10
int stack1[N];
int top1 = -1;
int stack2[N];
int top2 = -1;
int count = 0;

void push1(int x)
{
    if (top1 == N - 1)
        printf("Queue Overflow\n");
    else
    {
        top1++;
        stack1[top1] = x;
        count++;
    }
}

void push2(int x)
{
    if (top2 == N - 1)
        printf("Queue Overflow\n");
    else
    {
        top2++;
        stack2[top2] = x;
    }
}

int pop1()
{
    if (top1 == -1)
        printf("Queue(stack_1) is empty\n");
    else
    {
        // printf("Dequed element is %d\n", stack1[top1]);
        int x = stack1[top1];
        top1--;
        return x;
    }
}

int pop2()
{
    if (top2 == -1)
        printf("Queue(stack_2) is empty\n");
    else
    {
        // printf("Dequed element is %d\n", stack2[top2]);
        int x = stack2[top2];
        top2--;
        return x;
    }
}

void display()
{
    if (top1 == -1)
        printf("Queue is empty\n");
    else
    {
        for (int i = 0; i <= top1; i++)
            printf("%d\n", stack1[i]);
    }
}

void enque(int x)
{
    push1(x);
}

void deque()
{
    while (top1 != -1)
    {
        int x = pop1();
        push2(x);
    }

    if (stack2[top2] != 0)
        printf("Dequed element = %d\n", stack2[top2]);
    
    pop2();

    while (top2 != -1)
    { 
        int y = pop2();
        push1(y);
    }
}

int main()
{
    deque();
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    display();
    deque();
    display();
    deque();
    display();

    return 0;
}