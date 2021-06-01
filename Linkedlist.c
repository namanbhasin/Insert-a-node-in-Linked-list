#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
	int info;
	struct node *next;
}node;
node *getnode(int);
int sum(node *,int);
void traverse(node *);
int count(node *,int);
node *addfirst(node *,int);
node *addlast(node *,int);
int main()
{
	node *start = NULL;
	int item,num,ch;
	int s=0;
	do
	{
		printf("\n 1. SUM\n 2. TRAVERSE\n 3. COUNT\n 4. MAX\n 5. FIND\n 6. ADDFIRST\n \
7. ADDLAST\n 8. ADDAFTER\n 9. ADDBEFORE\n 10. EXIT\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Sum is %d\n",sum(start,s));
				break;
			case 2:
				traverse(start);
				break;
			case 3:
				printf("Total number of nodes is %d\n",count(start,s));
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				printf("Enter the item you want to add in firstplace \n");
				scanf("%d",&item);
				start=addfirst(start,item);
				break;
			case 7:
				printf("Enter the item that you want to add in lastplace\n");
				scanf("%d",&item);
				start=addlast(start,item);
		}
	}while(ch!=10);
	return 0;
}
node *getnode(int item)
{
	node *t=(node *)malloc(sizeof(node));
	t->info=item;
	return t;
}
int sum(node *start, int s)
{
	node * ptr=start;
	while(ptr!=NULL)
	{
		s=s+ptr->info;
		ptr=ptr->next;
	}
	return s;
}
void traverse(node *start)
{
	printf("List is:- \n");
	node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}
int count(node *start,int s)
{
	node * ptr=start;
	while(ptr!=NULL)
	{
		s=s+1;
		ptr=ptr->next;
	}
	return s;
}
node *addfirst(node *start,int item)
{
	node *newnode;
	newnode=getnode(item);
	newnode->next=start;
	start=newnode;
	return start;
}
node *addlast(node *start,int item)
{
	node *newnode;
	newnode=getnode(item);
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
	node *ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	}
	return start;
}
