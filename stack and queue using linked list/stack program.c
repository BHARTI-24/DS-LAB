#include<stdio.h>
#include<stdlib.h>
struct nodestack
{
int data;
struct nodestack *next;
};
struct nodestack *top=NULL;
struct nodestack *temp=NULL, *head=NULL;

void push()
 {
     struct nodestack *new=malloc(sizeof(struct nodestack));
  int ele;
  printf("Enter the element to be inserted \n");
  scanf("%d",&ele);

   if(top==NULL)
   {
    new->data=ele;

    head = new;
   }
   else
   {
   temp = head;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   new->data=ele;
   temp->next=new;
   }
   new->next=NULL;
   top=new;
}

void display()
{
temp=head;
printf("\n Stack: \t");
while(temp!=NULL){
    printf("%d->",temp->data);
    temp = temp->next;
}
printf("top");
}


void pop()
{
temp=head;
struct nodestack *ptr;
int popele=top->data;
printf("\n\t %d is poped from the stack",popele);
  if(head->next==NULL){
    top=NULL;
  }else{
  while(temp->next!=NULL){
    ptr=temp;
    temp=temp->next;
  }
  ptr->next=NULL;
  top=ptr;
}
free(temp);
}


int main()
{
    printf("\n\t Stack implementation using linked list\n");
    int choice;

while(1)
{
printf("\n---Stack----");
printf("\n 1.Push\n 2.Pop \n 3.display \n 4.exit ");
printf("\n enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:{ push();
break;
}
case 2:{
    if(top==NULL){
            printf("\n Stack underflow!!");
    }
    else{
        pop();
    }

break;
}
case 3:{
if(top==NULL){
printf("\n\tStack underflow!!\n");
}
else{
    display();
}
break;
}
case 4: {exit(0);
break;}
default: printf("\n Invalid choice");
}
}
return 0;
}

