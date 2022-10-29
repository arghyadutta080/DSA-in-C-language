#include <stdio.h>
#define N 10
int queue[N];
int front = -1, rear = -1;

void enque(int x)
{
    if (rear == N - 1)                      // when queue is full
        printf("Queue overflow\n");

    else if (front == -1 && rear == -1)     // when queue is empty
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else                                    // when queue is not full, not empty
    {
        rear++;
        queue[rear] = x;
    }
}

void deque()
{
    if (front == -1 && rear == -1)
        printf("Queue underflow\n");

    else if (front == rear)                 // when one element remains inside queue, we have to show the queue is empty after deque
        front = rear = -1;

    else                                    // when queue is not full, not empty
    {
        printf("Dequed element = %d\n", queue[front]);
        front++;
    }
}

void display()
{
    for (int i = front; i <= rear; i++)
        printf("%d\n", queue[i]);    
}

void peek()
{
    printf("Top most element is %d\n", queue[front]);
}

int main()
{
    deque();
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    display();
    peek();
    deque();
    display();
    deque();
    display();
    
    return 0;
}