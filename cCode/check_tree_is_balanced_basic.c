/* C program to check if a tree is height-balanced or not BASIC
Time Complexity: O(n^2) Worst case occurs in case of skewed tree.*/
#include <stdio.h> 
#include <stdlib.h> 
#define bool int 
  
/* A binary tree node has data, pointer to pLeft child 
   and a pointer to pRight child */
struct node { 
    int data; 
    struct node* pLeft; 
    struct node* pRight; 
}; 
  
/* Returns the height of a binary tree */
int height(struct node* node); 
  
/* Returns true if binary tree with root as root is height-balanced */
bool isBalanced(struct node* root) 
{ 
	int leftHeight  = 0; // Height of left subtree 
	int rightHeight = 0; // Height of right subtree
  
    /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 
  
    /* Get the height of left and right sub trees */
    leftHeight = height(root->pLeft); 
    rightHeight = height(root->pRight); 
  
    return (abs(leftHeight - rightHeight) <= 1 && 
	    isBalanced(root->pLeft) && 
		isBalanced(root->pRight));

} 
  
/* returns maximum of two integers */
int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
} 
  
/*  The function Compute the "height" of a tree. Height is the 
    number of nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int height(struct node* node) 
{ 
    /* base case tree is empty */
    if (node == NULL) 
        return 0; 
  
    /* If tree is not empty then height = 1 + max of pLeft 
      height and pRight heights */
    return 1 + max(height(node->pLeft), height(node->pRight)); 
} 
  
/* Helper function that allocates a new node with the 
   given data and NULL pLeft and pRight pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
        malloc(sizeof(struct node)); 
    node->data = data; 
    node->pLeft = NULL; 
    node->pRight = NULL; 
  
    return (node); 
} 
  
int main() 
{ 
	/* Constructed binary tree is 
			1 
		   / \ 
		   2 3 
		  / \ 
		  4 5
		 / 
		7 
	*/
    struct node* root = newNode(1); 
    root->pLeft = newNode(2); 
    root->pRight = newNode(3); 
    root->pLeft->pLeft = newNode(4); 
    root->pLeft->pRight = newNode(5); 
    root->pLeft->pLeft->pLeft = newNode(8); 
  
    if (isBalanced(root)) 
        printf("Tree is balanced"); 
    else
        printf("Tree is not balanced"); 
  
    getchar(); 
    return 0; 
}