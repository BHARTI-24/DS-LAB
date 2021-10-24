/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 100

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

int main()
{
    int value, choice;
    while(1)
    {
        printf("\n****** MENU ******");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : printf("\nEnter the value to be insert:  ");
                     scanf("%d", &value);
                     push(value);
                     break;
                     
            case 2 : pop();
                     break;
                     
            case 3 : display();
                     break;
                     
            case 4 : exit(0);
            default: ("\nInvalid choice! Please enter again!!");
        }
    }
}

void push(int value)
{
    if(top == SIZE-1)
      printf("\nStack is Full!");
    else {
        top++;
        stack[top] = value;
        printf("\n Insertion successfull!");
    }
}

void pop()
{
    if(top == -1)
      printf("\n Stack is Empty!");
    else {
        printf("\n The deleted element of the Stack is : %d", stack[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
      printf("\n Stack is Empty!");
    else
    {
        int i;
        printf("\n The elements of the Stack is :\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}