//binary search tree in c

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue>

using namespace std;

struct bstnode																								//structure of node
{
	int data;
	struct bstnode*left;
	struct bstnode*right;
};

int max(int a,int b)																						//max function to find max of 2 integers
{
	if(a>=b)
		return a;
		
	return b;
}

struct bstnode*Getnewnode(int data)																			//Getnewnode
{	
	struct bstnode*newnode=(struct bstnode*)malloc(sizeof(struct bstnode));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

void Insert(struct bstnode**nodeptr,int data)																//Insert into tree
{
	if((*nodeptr)==NULL)
	{
		 *nodeptr=Getnewnode(data);
		 printf("Insertion successful\n");		
	}
	
	else if(data<=(*nodeptr)->data)
	{
		Insert(&((*nodeptr)->left),data);
	}
	else if(data>(*nodeptr)->data)
	{
		Insert(&((*nodeptr)->right),data);
	}
	else
		printf("Insertion unsuccessful\n");
}

bool Search(struct bstnode*node,int data)															     	//Search in the tree
{
	if(node==NULL) return true;
	
	else if(node->data==data) return false;
	
	else if(node->data>=data)return Search(node->left,data);
	
	//if(node->data<data)
	else return Search(node->right,data);
}
void Display(struct bstnode*node,int k)																		//Display the tree
{	
	int i;
	for(i=0;i<k;i++)
	{
		printf(" ");
	}
	printf("%d \n",node->data);
	for(i=0;i<k-1;i++)
	{
		printf(" ");
	}
	printf("/ \\  \n");
	
	if(node->left!=NULL)
	{
		Display(node->left,k-2);
	}
	if(node->right!=NULL)
	{
		Display(node->right,k+2);
	}
}

int Height(struct bstnode*node)																		//Find height of tree
{
	if(node==NULL)
	{
		return -1;
	}
	
	return 1+max(Height(node->left),Height(node->right));
}

int min(struct bstnode*node)																		//Find minimum element of bst
{	
	if(node==NULL)
	{
		return -99999;
	}
	while(node->left!=NULL)
	{
		node=node->left;
	}
	return node->data;
}

int max(struct bstnode*node)																		//Find max element of bst
{	
	if(node==NULL)
	{
		return -99999;
	}
	while(node->left!=NULL)
	{
		node=node->left;
	}
	return node->data;
}

void Levelorder(struct bstnode*root)
{
	if(root==NULL)
	{
		return;
	}
	
	queue <struct bstnode*> q;
	q.push(root);
	
	while(!q.empty())	//while theres atleast 1 discovered node
	{
		struct bstnode*current=q.front();
		printf("%d ",current->data);
		q.pop();
		
		if(current->left!=NULL)		q.push(current->left);
		if(current->right!=NULL)	q.push(current->right);
	}
}

void Preorder(struct bstnode*root)
{
	 if(root==NULL)
	 	return;
	 	
	 printf("%d ",root->data);
	 Preorder(root->left);
	 Preorder(root->right);
}

void Inorder(struct bstnode*root)
{
	if(root==NULL)
	 	return;
	 
	 Inorder(root->left);	
	 printf("%d ",root->data);
	 Inorder(root->right);
}

void Postorder(struct bstnode*root)
{
	if(root==NULL)
	 	return;
	 
	 Postorder(root->left);	
	 Postorder(root->right);
	 printf("%d ",root->data);
}

int main()																							//main fuction
{	
	printf("Welcome to binary search tree");
	
	int n=-1;
	
	int data;
	struct bstnode*root=NULL;
	
	while(n!=100)
	{
		printf("\nEnter 1.insert an element  2.seaach an element   3.delete an element  4.display binary tree  5.level order traversal(breadth first search)  6.depth first search  7.height of binary tree   8.find min and max element   100.exit\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:printf("Enter the element to be inserted\n");
				   scanf("%d",&data);
				   Insert(&root,data);
				   break;
				   
			case 2:printf("Enter the element to be searched\n");
				   scanf("%d",&data);
				   if(Search(root,data)==true)
				   		printf("Element found");
				   else
				   		printf("Element not found");
				   break;
				   
			case 4:printf("Displaying the binary tree \n");
			       Display(root,50);
			       break;
			
			case 5:printf("The level order traversal of the tree is\n");
				   Levelorder(root);
				   break;
					    
			case 6:printf("Enter your choice  1.pre order traversal  2.inorder traversal  3.post order traversal\n");
				   {
				   		int x;
				   		scanf("%d",&x);
				   		
				   		switch(x)
				   		{
				   			case 1:Preorder(root);
								   break;
						    
							case 2:Inorder(root);
									break;
									
						    case 3:Postorder(root);
									break;
									
							default:printf("Wrong input\n");
										
						}
				   }
				   break;
			
			       
			case 7:printf("The height of the binary tree is ");
				   {
						int x=Height(root);
				   		printf("%d\n",x);
				   }
				   break;
				   
			case 8:{
						if(min(root)==-99999)
						{
							printf("The tree is empty\n");
							break;
						}
						printf("The minimum element is %d",min(root));
						printf("Thw maximum element is %d",max(root));
				
				   }
				   break;
		    
		    case 100:printf("terminating program");
					 break;
			   
			default:printf("wrong input\n");
		}
		
	}
	
	return 0;
}
