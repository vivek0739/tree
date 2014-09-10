#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right,*next;
};
struct node *newnode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	temp->next=NULL;
}
void populate_right(struct node *root)
{
	struct node *curr=root;

}
