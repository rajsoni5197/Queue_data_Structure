//Array based Queue implementation .
#include <stdio.h>
#define Max_Queue_size 6

//making a queue.
int Queue[Max_Queue_size], Front = -1, Rear = -1;
void printQueue()
{
    int i;
    if (Front == -1)
    {
        printf("Error:list is Empty\n");
        return;
    }
    for (i = Front; i < Max_Queue_size; i = (i + 1) % Max_Queue_size)
    {
        printf("%d =>%d \t", i, Queue[i]);
        if (i == Rear)
        {
            break;
        }
    }
    printf("\n");
}
void deQueue()
{
    if (Front == -1)
    {
        printf("Error: Queue is Empty,Can't Dnqueue.\n");
        return;
    }
    if (Front == Rear)
    {
        //a dequeue will make the queue left with no element .
        Front = Rear = -1;
        return;
    }
    Front = (Front + 1) % Max_Queue_size;
    return;
}
void enQueue(int x)
{
    if (Front == -1)
    { // front=rear=0;
        Front = (Front + 1) % Max_Queue_size;
        Rear = (Rear + 1) % Max_Queue_size;
        Queue[Rear] = x;
        return;
    }
    if ((Rear + 1) % Max_Queue_size == Front)
    {
        printf("Error: Queue Overflow,Can't Enqueue.\n");
        return;
    }
    Rear = (Rear + 1) % Max_Queue_size;
    Queue[Rear] = x;
    return;
}
int isEmpty()
{
    return Front == -1?1:0;
}
int atFront()
{
    if(isEmpty())return 0;
    printf("%d \n",Queue[Front]);
    return Queue[Front];   
}

//taking input from user and testing queue.

int main()
{
    int option;
    while (1)
    {
        printf("\n\nGive us What do You want to do to the queue \n1->Enqueue\n2->Dequeue\n3->IsEmpty\n2->AtFront\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Give us the value to Enqueue\t");
            scanf("%d", &option);

            enQueue(option);
            printQueue();
            break;
        case 2:
            deQueue();
            printQueue();
            break;
        case 3:
            isEmpty() ? printf("yes The Queue is Empty\n") : printf("No The Queue is not Empty\n");
            break;
        case 4:
            atFront();
            break;
        default:

            printf("Error: Wrong Input\n");
            break;
        }
    }
}
