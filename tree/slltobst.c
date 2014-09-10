//linked list to tree
struct Tnode *sortedListToBST(struct Lnode *head)
(
	int n=countLNode(head);
	return sortedListToBSTRecur(&head,n);
}
struct Tnode *sortedListToBSTRecur(struct Lnode **head,int n)
{
	if(n<=0) return NULL;
	struct Tnode *left =sortedListToBSTRecur((*head) ,n/2);
	struct Tnode *root = newNode((*head)->data);
	root->left=left;
	*head=(*head)->next;
	root->right=sortedListToBSTRecur(*head,n-n/2-1);
	return root;
	
		
}
struct Tnode *sortedDLLToBSTRecur(struct Lnode **head,int n)
{
	if (n<=0) return NULL;
	struct Tnode *left =sortedDLLToBSTRecur(head,n/2);
	struct Tnode *root = (*head);
	root->prev=left;
	*head=(*head)->next;
	root->next=sortedDLLToBSTRecur(head,n-n/2-1);
	return root;
}

