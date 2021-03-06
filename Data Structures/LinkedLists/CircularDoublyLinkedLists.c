#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
 struct node*prev;
}*head=NULL,*tail=NULL;

struct node* temp, *store_next;
int i;
struct node* create(int val)
{
	struct node* n= (struct node*)malloc(sizeof(struct node));
	n->data = val;
	n->prev = NULL;
	n->next = head;
	return n;
}
void insert_end(int val)
{
		struct node* n= create(val);
		if(head==NULL)
			head=tail=n;
		else
		{
			store_next=tail;
			tail->next = n;
			n->prev = store_next;
			tail = n;
		}
}
void insert_begin(int val)
{
		struct node* n= create(val);
		if(head==NULL)
			head=tail=n;
		else
		{
			n->next=head;
			head->prev=n;
			tail->next=n;
			head=n;
		}
}
void insert_middle(int val,int pos)
{
		struct node* n= create(val);
		if(head==NULL)
			head=tail=n;
		else if(pos==1)
			insert_begin(val);
		else
		{
			temp=head;
			for(i=2;i<pos;i++)
				temp=temp->next;

			store_next = temp->next;
			temp->next = n;
			n->prev = temp->next;
			n->next = store_next;
			store_next->prev = n;
		}
}
void delete_begin()
{
	if(head==NULL)
		return;
	else if (head->next == head)
		head=NULL;
	else
	{
		head = head->next;
		tail->next = head;
		head ->prev = NULL;
	}
}
void delete_end()
{
	if(head==NULL)
		return;
	else
	{
	 tail = tail->prev;
	 tail->next = head;
	}
}
void delete_middle(int pos,int size)
{
	if(head==NULL)
		return;
	else if(pos==1)
		delete_begin();
	else if(pos<=size)
	{
		temp=head;
		for(i=2;i<pos;i++)
			temp=temp->next;

		store_next = temp->next->next;
		temp->next = store_next;
		store_next->prev = temp;
	}
	else
		printf("No element in that position can not delete any element \n");
}
void print(struct node* head)
{
	temp=head;
	while(temp->next!=head)
	{
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
		printf("%d ",temp->data);
}
int main()
{
int size,val,pos;
	 printf("Enter the number of nodes : ");
	 scanf("%d",&size);
	 printf("Enter the nodes : ");
	 for(i=0;i<size;i++)
	 {
	  scanf("%d",&val);
	  insert_end(val);
	 }
	 print(head);
printf("\nEnter the value you want to insert at beginning : ");
 	scanf("%d",&val);
 	insert_begin(val);
 	print(head);
 printf("\nEnter the value and pos for inserting at middle : ");
 	scanf("%d%d",&val,&pos);
	 insert_middle(val,pos);
	 print(head);
 printf("\nEnter the pos for deleting : ");
 	 scanf("%d",&pos);
  	delete_middle(pos,size);
  	print(head);
delete_begin();
printf("\nDeleted at beginning !\n");
print(head);
delete_end();
printf("\nDeleted at end !\n");
print(head);
}
