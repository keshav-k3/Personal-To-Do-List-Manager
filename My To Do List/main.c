#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct todo {
char data[100];
struct todo * link;
int count;
};
struct todo *root=NULL;
int z;
//Main Program with To Do List Option//
int main ()
{
    int choice;
    welcome();
    while(1)
        { printf("\n\n1.See your ToDo List\n\n2.Create a new task in your ToDo\n\n3.Delete an existing task in your ToDo\n\n4.Update a task in your ToDo\n\n5.Exit\n\nPlease enter your choice \t");
        scanf("\t%d",&choice);
        switch (choice)
        {
            case 1:Display();
            printf("\n");
            break;
            case 2:Create();
            printf("\n");
            break;
            case 3:Delete();
            printf("\n");
                break;
            case 4:Update();
            printf("\n");
            break;

            case 5: exit(0);
            default:printf("Invalid Choice");
        }
        }

}
//Welcome Message//
void welcome()
{
    system("color 1F");
   printf("\n\n\n\n\n");
   printf("\t------------------------------------------------------------------------------------------------------\n\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  WELCOME TO YOUR TODO LIST \n\n");
   printf("\t------------------------------------------------------------------------------------------------------");
   printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tLET'S BEGIN\n\n\n\n\n\n\n\n\n\t");
   system("pause");
}
//Display Function for Listing tasks from ToDo List//
void Display()
{
    struct todo *temp;
    temp=root;
    if(temp==NULL)
    {
        printf("\nNo Tasks Added\n");
    }
    else
    {
    while (temp!=NULL)
    {
        printf("%d\t",temp->count);
        puts(temp->data);
        fflush(stdin);
        temp=temp->link;
    }
    printf("\n\n");
    }
}
//Insert Function for Creating new tasks in ToDo List//
void Create()
{
    struct todo *temp;
    temp=(struct todo*)malloc(sizeof(struct todo));
    printf("\nEnter a Task\n");
    fflush(stdin);
    printf("\n");
    gets(temp->data);
    temp->link=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {   struct todo *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
     count();
}
//Count Function to fix count//
void count(){
  struct todo *temp;
  int i=1;
  temp=root;
  while(temp!=NULL){
    temp->count=i;
    i++;

    temp=temp->link;
  }
  z=i;
}

//Delete Function to delete tasks//
void Delete()
{
    struct todo *temp;
    int l;

    printf("\nEnter Task no. to be deleted\n");
    scanf("%d",&l);
    if(l>=z)
       {

        printf("\nInvalid Option\n");}
    else if(l==1)
    {
        temp=root;
        root=temp->link;
        temp->link=NULL;
        free(temp);
    }
    else
    {
        struct todo *p=root,*q;
        int i=1;
        while(i<l-1)
           {p=p->link;
        i++;
           }
           q=p->link;
           p->link=q->link;
           q->link=NULL;
           free(q);

}
count();
}

//Update Function to update existing tasks//
void Update()
{
    struct todo *temp;
    int l;

    printf("\nEnter Task no. to be updated\n");
    scanf("%d",&l);

    if(l>=z)
        printf("\nInvalid Option\n");
    else if(l==1)
    {
        temp=root;

         printf("\nEnter the new task\n");
           fflush(stdin);
         gets(temp->data);

    }
    else
    {
        struct todo *p=root,*q;
        int i=1;
        while(i<l-1)
           {p=p->link;
        i++;
           }
           q=p->link;

            printf("\nEnter the new task\n");
              fflush(stdin);
            gets(q->data);

}
count();
}
