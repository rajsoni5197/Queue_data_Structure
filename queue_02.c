//implementation of linked list based queue.
#include <stdio.h>
#include <stdlib.h>

//making of a linked list
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front  =NULL;
struct Node *rear ;

struct Node *getNewNode(int x)
{
    struct Node *newNodePointer = (struct Node *)malloc(sizeof(struct Node));
    newNodePointer->data = x;
    newNodePointer->next = NULL;
    return newNodePointer;
}
void printQueue()
{
    //  printf("\nfornt=>%d , Rear =>%d\n",front,rear);
    if(!front)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    
    while(temp)
    {
        printf("%d |%d |%d  =>\t",temp, temp->data, temp->next);
        temp = temp->next;
    }
   
    printf("\n");
    return;
}
void enQueue(int x) //insert at tail.
{
    struct Node *newNode = getNewNode(x);
   
    if (!front) //if list is empty.
    {
        front = newNode;
        rear = newNode;
        return;
    }
    
    rear->next =newNode;
    rear = newNode;
    return;
}
void deQueue() //delete from head or start
{
    if(!front)
    {
        printf("Error: can't, DeQueue Queue is empty.\n");
        return;
    }
    if(front==rear)
    {
        rear =NULL;
    }
    struct Node* temp = front;
    front = front->next;
    free(temp);
}
int isEmpty()
{
    return front?0:1;
}
struct Node* atFront()
{
    
    return front?front:NULL;
}

int main()
{
    int option;
    while (1)
    {
        printf("\n\nGive us What do You want to do to the queue \n1->Enqueue\n2->Dequeue\n3->IsEmpty\n4->AtFront\n");
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
            if(!atFront())break;
            printf("%d |%d |%d  \n",atFront(),atFront()->data, atFront()->next);

            break;
        default:

            printf("Error: Wrong Input\n");
            break;
        }
    }
}
