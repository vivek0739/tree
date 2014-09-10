//level orde traversal
#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 500
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
//create a queue

struct node **create_queue(int *front,int* rear)
{
	struct node **queue=(struct node **)calloc(sizeof(struct node*),MAX_Q_SIZE);
	*front=*rear=0;
	return queue;
}
void enqueue(struct node **queue,int *rear,struct node *new_node)
{
	//overflow
	queue[*rear]=new_node;
	(*rear)++;
}
struct node *dequeue(struct node **queue,int *front,int *rear)
{
	if( !(*rear) || front>rear) return NULL;
	(*front)++;
	return queue[*front-1];
	
}
void printLevelOrder(struct node *root)
{
	int front,rear;
	struct node **queue=create_queue(&front,&rear);
	struct node *temp_node = root;
	printf("%d%d",front,rear);
	while(temp_node)
	{ 
		printf("%d ",temp_node->data);
		if(temp_node -> left)
			enqueue(queue,&rear,temp_node->left);
		if(temp_node ->right)
			enqueue(queue,&rear,temp_node->right);
		
		temp_node = dequeue(queue,&front,&rear);
		//if(temp_node)
		//temp_node=temp_node->left;
		
	}
}
int main()
{
  struct node *root = newnode(1);
  root->left        = newnode(2);
  root->right       = newnode(3);
  root->left->left  = newnode(4);
  root->left->right = newnode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}
