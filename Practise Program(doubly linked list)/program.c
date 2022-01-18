/* Write a menu driven program to inplement this the following operations using doubly Linked list.
     a> Insertion at beginning  b> Insertion at end  c> Insertion after specified node
     d> Deletion at beginning  e>  Deletion at the end   f> Deletion of the node having given data
     g> Display   h>  Search for an element. */
     
     
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
};

struct node* start = NULL;

void display(){
    if(start == NULL){
        printf("\nThe List is empty\n");
        return;
    }
    else{
        struct node* temp;
        temp = start;
        while(temp != NULL){
            printf("\nThe contents of the Linked List :> %d\n\t", temp->data);
            temp = temp->next;
        }
    }
}

void insertAtBeg(){
    int info;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted:  ");
    scanf("%d", &info);
    temp->data = info;
    temp->prev = NULL;
    
    temp->next = start;
    start = temp;
}

void insertAtEnd(){
    int info;
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &info);
    temp->data = info;
    temp->next = NULL;
    trav = start;
    
    if (start == NULL) {
 
        start = temp;
    }
    
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

void insertAtPosition()
{
    int info, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
 
    printf("\nEnter position : ");
    scanf("%d", &pos);
     

    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;

    }
    
    else if (pos == 1) {
      
      insertAtBeg();
    }
 
    else {
      printf("\nEnter number to be inserted: ");
    scanf("%d", &info);
    newnode->data = info;
    temp = start;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}
 
void deleteBeg()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
        printf("\nDeletion successfull");
    }
}

void deleteEnd()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
        printf("\nDeletion successfull");
    }
}

void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;
 
    if (start == NULL)
        printf("\nList is empty\n");
 
    else {
        // Position to be deleted
        printf("\nEnter position : ");
        scanf("%d", &pos);
 
        // If the position is the first node
        if (pos == 1) {
            deleteBeg(); 
            if (start != NULL) {
                start->prev = NULL;
         }
            free(position);
            printf("\nDeletion successfull");
            return;
        }
 
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
 
        free(position);
        printf("\nDeletion successfull");
    }
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = start;   
    if(ptr == NULL)  
    {  
        printf("\nThe List is empty.\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  

int main()
{
    int choice;
    while (1) {
 
        printf("\n\n\tMENU OF DOUBLY LINKED LIST\n\n\t1  Display\n");
        printf("\t2  For insertion at the beginning\n");
        printf("\t3  For insertion at the end\n");
        printf("\t4  For insertion at any position\n");
        printf("\t5  For deletion of the first element\n");
        printf("\t6  For deletion of the last element\n");
        printf("\t7  For deletion of element at any position\n");
        printf("\t8  To search an element\n");
        printf("\t9  Exit\n");
        printf("\nEnter Choice :>\t");
     scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insertAtBeg();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteBeg();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            search();
            break;
 
        case 9:
            exit(1);
            break;
        default:
            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}














