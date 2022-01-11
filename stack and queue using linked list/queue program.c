
//WAP to implement Queues using Linked Representation.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front, *rear, *temp, *front1;

void enq(int data);
void deq();
void empty();
void display();
void create();

int count = 0;

void main(){
    printf("\t Queue using linked list");
    int no, ch, e;

    printf("\n1.Enqueue");
    printf("\n2.Dequeue");
    printf("\n3.Empty");
    printf("\n4.Exit");
    printf("\n5.Display");

    create();
    while(1){
        printf("\n\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: printf("\n\tEnter data: ");
            scanf("%d",&no);
            enq(no);
            break;

            case 2: deq();
                    break;

            case 3: empty();
                    break;

            case 4: exit(0);
            case 5: display();
                    break;

            default: printf("Wrong choice!!");
                     break;
        }

    }

}

void create(){
    front = rear = NULL;
}


void enq(int data){
    if(rear == NULL){
        rear = (struct node*)malloc(1*sizeof(struct node));
        rear->next = NULL;
        rear->data = data;
        front = rear;
    }
    else{

        temp = (struct node*)malloc(1*sizeof(struct node));
        rear->next = temp;
        temp->data = data;
        temp->next = NULL;

        rear = temp;
    }
    count++;
}

void display(){
    front1 = front;

    if((front1 == NULL)&&(rear == NULL)){
        printf("\t Queue is empty !!");
        return;
    }
    printf("\t FRONT -> ");
    while(front1 != rear){
        printf("%d-> ", front1->data);
        front1 = front1->next;
    }
    if(front1 == rear)
        printf("%d-> ", front1->data);
    printf("REAR\n");
}

void deq(){
   front1 = front;

   if(front1 == NULL){
    printf("\n\t Queue underflow!!");
    return;
   }
   else
    if(front1->next != NULL){
        front1 = front1->next;
        printf("\n Dequeued value : %d", front->data);
        free(front);
        front = front1;
    }
    else{
        printf("\n Dequeued value : %d", front->data);
        free(front);
        front = NULL;
        rear = NULL;
    }
    count--;
   
}

void empty(){
if((front == NULL)&&(rear == NULL))
   printf("\n  Queue is empty\n");
   else
    printf("\n Queue is not empty\n");
}

