#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *newnode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
bool is_sum_tree(struct node *root)
{
	int right=0,left=0;
	if(root == NULL || (root->left==NULL && root->right == NULL))
		return true;
	if(root->left) left=root->left->data;
	if(root->right) right=root->right->data;
	return (root->data==left+right && is_sum_tree(root->left) && is_sum_tree(root->right));
}
int main()
{
  struct node *root  = newnode(10);
  root->left         = newnode(8);
  root->right        = newnode(2);
  root->left->left   = newnode(3);
  root->left->right  = newnode(5);
  root->right->right = newnode(2);
  if(is_sum_tree(root))

    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
int k=4;
 	printf("%lu",sizeof(k));
  getchar();
  return 0;
}
