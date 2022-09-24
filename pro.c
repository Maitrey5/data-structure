/*
 * pro.c
 * assingment to expression with array type
 *
 *  Created on: 17-Sep-2022
 *      Author: root
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char name[10];
	char div;
	int rollno;
	int marks;
	struct node* next;
};

struct node* first;
struct node* last;
struct node* nn;

void insert()
{
	char a[10];
	char d;
	printf("\n");
	printf("\n");

	int m,r;
	printf("enter the name :");
	scanf("%s",a);
	printf("enter the roll :");
	scanf("%d",&r);
	printf("enter the division :");
	scanf(" %c",&d);
	printf("enter the marks :");
	scanf("%d",&m);



	nn=(struct node*)malloc(sizeof(struct node));
	strcpy(nn->name,a);
//	nn->name=a;
	nn->rollno=r;
	nn->marks=m;
	nn->div=d;
	nn->next=NULL;

	if(first==NULL)
	{
		first=nn;
		last=nn;
	}
	else
	{
		last->next=nn;
		last=nn;
	}
	printf("\n");
		printf("\n");

}

void delete()
{
	if(first==NULL)
	{
		printf("ll is empty \n");
		return;
	}
	printf("\n");
	int b;
				printf("enter the  roll no :");
				scanf("%d",&b);


				struct node* prev=NULL;
				struct node* curr=first;


				while(curr->rollno!=b)
				{
					prev=curr;
					curr=curr->next;
				}
				prev->next=curr->next;

				if(prev->next==NULL)
				{
					last=prev;
				}

				free(curr);
}

void display()
{
	if(first==NULL)
	{
		printf("ll is empty \n");
		return;
	}
	struct node* p=first;
//
//	do
//	{
//		printf("%s",p->name);
//		printf("\n");
//		printf("%d",p->rollno);
//		printf("\n");
//		printf("%c",p->div);
//		printf("\n");
//		printf("%d",p->marks);
//		printf("\n");
//	    first=first->next;
//	}while(p->next!=NULL);

	printf("\n");
	printf("\n");


	while(first->next!=NULL)
	{
		printf("name :%s",first->name);
		printf("\n");
		printf("roll no :%d",first->rollno);
		printf("\n");
		printf("division :%c",first->div);
		printf("\n");
		printf("marks :%d",first->marks);
		printf("\n\n");
	    first=first->next;
	}
	printf("name :%s",first->name);
	printf("\n");
	printf("roll no :%d",first->rollno);
	printf("\n");
	printf("division :%c",first->div);
	printf("\n");
	printf("marks :%d",first->marks);
	printf("\n");
	printf("\n");
	first=p;


	printf("\n");
}

void search()
{
	if(first==NULL)
	{
		printf("ll is empty");
		return;
	}
	printf("\n");
	printf("\n");


	struct node* pa=first;
	int r,max;
	char a[10];

	max=pa->marks;
	strcpy(a,pa->name);

//	a = pa->name;

	do
	{
		if(pa->marks > max)
		{
		max=pa->marks;
		strcpy(a,pa->name);
//		a=pa->name;
		}

		pa=pa->next;
	}while(pa->next!=NULL);

	printf("maximum marks = %d \n",max);
	printf("name = %s \n",a);

}
int main()
{
	int o,u=1;
	while(u)
	{
		printf("press 1 for creation\n");
		printf("press 2 for delete \n");
		printf("press 3 for display \n");
		printf("press 4 searching a student with maximum marks \n");

		scanf("%d",&o);
		switch(o)
		{
		case 1:
		insert();
		break;

		case 2:
		delete();
		break;

		case 3:
		display();
		break;

		case 4:
		search();
		break;

		case 5:
		u=0;
		break;

		default:
		break;
		}

	}
}


