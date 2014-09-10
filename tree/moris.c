#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left,*right;

};
struct node *newnode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void morris_preorder(struct node *root)
{
	struct node *curr=root;
	if(root == NULL)
		return;
	while(root)
	{
		if(root->left == NULL)
		{
			printf("%d ",root->data);
			root=root->right;
		}
		else
		{
			struct node *curr=root->left;
			while(curr->right!= NULL && curr->right != root)
				curr=curr->right;
			if(curr->right == NULL)
			{
				curr->right=root;
				printf("%d ",root->data);
				root=root->left;
			}
			else
			{
				curr->right=NULL;
				root=root->right;
				
			}
		}
	}
	
}
void morris_inorder(struct node *root)
{
	struct node *curr=root;
	if(root == NULL)
		return ;
	struct node *pre=NULL;
	while(curr != NULL)
	{
		//reached leftmost node
		if(curr->left == NULL)
		{
			printf("%d ",curr->data);
			curr=curr->right;
		}
		else
		{
			//find predecessor
			pre=curr->left;
			while(pre->right != NULL && pre->right != curr)
				pre=pre->right;
			//thread pre to curr
			if(pre->right == NULL)
				{
					pre->right=curr;
					curr=curr->left;

				}
			//revert to original as now the predecessor has been traversed;
			else
				{
					pre->right=NULL;
					printf("%d ",curr->data);
					curr=curr->right;
				}
		}
		
	}
}
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5); 
 
  morris_preorder(root);
 
  getchar();
  return 0;
}
