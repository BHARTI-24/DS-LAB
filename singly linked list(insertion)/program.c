#include<stdio.h>
#include<stdlib.h>
#include<conio.h>// for getch() function to read a char


struct student // for storing details of student of different types using structure
{
  int sem;
  char name[40];
  char  USN[20];
};


struct node
{
  struct student s;
  struct node *next;
};

// declaring head as global
 struct node *head;
 struct node *new,*temp;




 // inserting node at the end case 3
 void insertEnd(){

new = (struct node*)malloc (sizeof(struct node));
        if(head==NULL){

            head=new;
    printf("\n \t DETAILS OF STUDENT \n");
   printf("\nEnter the current semester >>\t");
   scanf("%d",&new->s.sem);
    printf("\nEnter the Name >>\t");
    scanf("%s",new->s.name);
    printf("\nEnter USN >>\t");
   scanf("%s",new->s.USN);
            new->next=NULL;
        }
        else
        {
            temp=head;

            while(temp->next!=NULL){
                temp=temp->next;
            }

               printf("\n \t DETAILS OF STUDENT \n");
               printf("\nEnter the current semester >>\t");
               scanf("%d",&new->s.sem);
               printf("\nEnter the Name >>\t");
               scanf("%s",new->s.name);
               printf("\nEnter USN >>\t");
               scanf("%s",new->s.USN);
               temp->next=new;
               new->next=NULL;

        }
}



// inserting node at pos
void insertPos(int x){
    int i=0;
    struct node *ptr;
    ptr=head;
    new = (struct node*)malloc (sizeof(struct node));
     if(x==1){
        head=new;
        new->next=ptr;
     }
     else{
            for(i=1;i<x-1;i++)
            {
                ptr=ptr->next;
            }

                temp=ptr->next;

                ptr->next=new;
               new->next=temp;

     }


  printf("\n \t DETAILS OF STUDENT \n");
   printf("\nEnter the current semester >>\t");
   scanf("%d",&new->s.sem);
    printf("\nEnter the Name >>\t");
    scanf("%s",new->s.name);
    printf("\nEnter USN >>\t");
   scanf("%s",new->s.USN);

}

// insert node at the first pos  case 1
void insertBeg(){

        new = (struct node*)malloc (sizeof(struct node));

   printf("\n \t DETAILS OF STUDENT \n");
   printf("\nEnter the current semester >>\t");
   scanf("%d",&new->s.sem);
    printf("\nEnter the Name >>\t");
    scanf("%s",new->s.name);
    printf("\nEnter USN >>\t");
   scanf("%s",new->s.USN);
    if(head==NULL)// if first node
       {
           head=new;
           temp=new;
       }
       else // p used as a pointer to node to link two nodes
       {
           temp->next=new;
           temp=new;
       }

     }

// to display the list
void display()
{
    printf("\n \n \t <--------------------------->\n\n");
    struct node *temp;
    temp=head;
    int j=1;
    while(temp)// loop until temp not NULL
    {

        printf("\n\n \t Details of Student %d \n\n",j);
        printf("\tSemester : %d\n" ,temp->s.sem);
        printf("\tName: %s\n" ,temp->s.name);
        printf("\tUSN : %s\n" ,temp->s.USN);
        temp=temp->next;
        j++;
    }
}

  int main(){

    printf("\t <<<<<SINGLY LINKED LIST>>>>>\n");
    int choice;
    int nodecount=0;
    int x;
    do{
         printf("\n\t Enter your choice :> \n  \n 1. Insertion of a node at first position\n 2. Insertion At any position \n 3. Insertion of node at the end of list \n 4. Display the contents of the linked list. \n 5. Exit\n\t>>");
         scanf("%d",&choice);

    switch(choice)
    {



        case 1:{

                insertBeg();
                 nodecount++;
            break;
        }
        case 2:
            {

                    int pos=0;
                     printf("\n Position >>  ");
                    scanf("%d",&pos);
                    if(pos<=0){
                        printf("\n \t Invalid postion \n");
                        break;
                    }


                    insertPos(pos);

            break;
            }
        case 3:
                    {
                    insertEnd();
                    nodecount++;
                    break;
                    }
        case 4:
            {

               display();
                break;
            }
        case 5:
            {
                printf("\n\n\t <---- EXITED----->\n\n");
              exit(0);
              break;

            }
        default:
            printf("invalid choice");

    }
    printf("\n \t<<<TO repeat, enter '0'+>>\t");
    scanf("%d",&x);

    }while(x==0);


    return 0;

}


