#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node *stack[MAX];
int top=-1;
void push(struct node *item);
struct node *pop();
int empty();

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
}*root=NULL;

void insert(int key)
{
	struct node *tmp,*ptr,*par;
	ptr=root;
	par=NULL;
	while(ptr!=NULL)
	{
		par=ptr;
		if(key<ptr->info)
		{
			ptr=ptr->lchild;
		}
		else if(key>ptr->info)
		{
			ptr=ptr->rchild;
		}
		else
		{
			printf("Duplicate value\n");
			return;
		}
	}
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=key;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	if(par==NULL)
	root=tmp;
	else if(key<par->info)
	par->lchild=tmp;
	else
	par->rchild=tmp;
	return;
}

void pre()
{
        struct node *ptr=root;
        if(ptr==NULL)
        {
                printf("no elements\n");
                return;
        }
        push(ptr);
        while(!empty())
        {
                ptr=pop();
                printf("%d ",ptr->info);
                if(ptr->rchild!=NULL)
		{
                        push(ptr->rchild);
		}
                if(ptr->lchild!=NULL)
		{
                        push(ptr->lchild);
		}
        }
}


void push(struct node *item)
{
        if(top==(MAX-1))
        {
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}


struct node *pop()
{
        struct node *item;
        if(top==-1)
        {
                printf("Stack Underflow");
                exit(1);
        }
        item=stack[top];
        top=top-1;
        return item;
}

int empty()
{
        if(top==-1)
        return 1;
        else
        return 0;
}

int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.create\n2.preorderrec\n3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("ENTER A ELEMENT\n");
			       scanf("%d",&x);
			       insert(x);
			       break;
			case 2:pre();
			       break;
			case 3:exit(1);
			default:exit(1);
		}
	}
}	

