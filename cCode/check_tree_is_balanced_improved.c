/* C program to check if a tree is height-balanced or not improved
Time Complexity: O(n) Worst case occurs in case of skewed tree.*/
#include <stdio.h> 
#include <stdlib.h> 
#define bool int 
  
/* A binary tree node has data, pointer to left child 
   and a pointer to right child */
struct node { 
    int data; 
    struct node* pLeft; 
    struct node* pRight; 
}; 
  
/* The function returns true if root is balanced else false 
   The second parameter is to store the height of tree.   
   Initially, we need to pass a pointer to a location with value  
   as 0. We can also write a wrapper over this function */
bool isBalanced(struct node* root, int* height) 
{ 
	int leftHeight  = 0; // Height of left subtree 
	int rightHeight = 0; // Height of right subtree
  
    if (root == NULL) { 
        *height = 0; 
        return 1; 
    } 
  
    /* Get the heights of left and right subtrees in lh and rh  
    And store the returned values in l and r */
    bool isLeftBalanced = isBalanced(root->pLeft, &leftHeight); 
    bool isRightBalanced = isBalanced(root->pRight, &rightHeight); 
  
    /* Height of current node is max of heights of left and  
     right subtrees plus 1*/
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; 
  
    /* If difference between heights of left and right  
     subtrees is less than 2and and left and right subtrees  
     are balanced then return true */
    return (abs(leftHeight - rightHeight) <= 1) &&
	        isLeftBalanced &&
		    isRightBalanced;

} 
  
/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
  
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
        malloc(sizeof(struct node)); 
    node->data = data; 
    node->pLeft = NULL; 
    node->pRight = NULL; 
  
    return (node); 
} 
  
// Driver code 
int main() 
{ 
    int height = 0; 
  
    /* Constructed binary tree is 
             1 
           /   \ 
         2      3 
       /  \    / 
     4     5  6 
    / 
   7 
  */
    struct node* root = newNode(1); 
    root->pLeft = newNode(2); 
    root->pRight = newNode(3); 
    root->pLeft->pLeft = newNode(4); 
    root->pLeft->pRight = newNode(5); 
    root->pRight->pLeft = newNode(6); 
    root->pLeft->pLeft->pLeft = newNode(7); 
  
    if (isBalanced(root, &height)) 
        printf("Tree is balanced"); 
    else
        printf("Tree is not balanced"); 
  
    getchar(); 
    return 0; 
}