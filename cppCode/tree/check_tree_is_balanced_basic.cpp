/* Cpp program to check if a tree is height-balanced or not BASIC
Time Complexity: O(n^2) Worst case occurs in case of skewed tree.*/
//#include <bits/stdc++.h> // Includes all standard libraries
#include <iostream>
#include <algorithm> //max function

using namespace std; 

/* A binary tree node has data, 
pointer to pLeft child and 
a pointer to pRight child */
class node { 
public: 
    /* Constructor  */
    node(int initData= 0, node* initLeft = NULL, node* initRight = NULL): 
    data(initData), pLeft(initLeft), pRight(initRight) {};

    /* Returns true if binary tree 
    with root as root is height-balanced */
    bool isBalanced();
    /* Returns the height of a binary tree */
    int height();
    
    void setLeft(node* setLeft){pLeft = setLeft;};
    void setRight(node* setRigth){pRight = setRigth;};
    void setData(int setData){data = setData;};
private:
  
    int data; 
    node* pLeft; 
    node* pRight; 
}; 


bool node::isBalanced() 
{ 
    int leftHeight  = 0; // Height of left subtree 
    int rightHeight = 0; // Height of right subtree
    bool isLeftBalanced = true; // NULL is balanced
    bool isRightBalanced = true; //NULL is balanced 

    /* Get the height of left and right sub trees */
    if(pLeft != NULL)
    {
        leftHeight = pLeft->height(); 
        isLeftBalanced = pLeft->isBalanced();
    }
    if(pRight != NULL)
    {
        rightHeight = pRight->height();
        isRightBalanced = pRight->isBalanced();
    }   

    return (abs(leftHeight - rightHeight) <= 1   && 
            isLeftBalanced && 
            isRightBalanced);
}

int node::height() 
{ 
    int leftHeight  = 0; // Height of left subtree 
    int rightHeight = 0; // Height of right subtree

    /* Get the height of left and right sub trees */
    if(pLeft != NULL)
    {
        leftHeight = pLeft->height(); 
    }
    if(pRight != NULL)
    {
        rightHeight = pRight->height();
    }
    
    /*height = 1 + max of left 
        height and right heights */
    return (1 + max(leftHeight, rightHeight)); 
}


 

// Driver code 
int main() 
{ 
    /* Constructed binary tree is 
            1 
          /   \ 
         2     3 
        / \   / \
       4  5  (6  7)
      / 
     8 
    */
    node root(1); 
    root.setLeft(new node(2,new node(4,new node(8)),new node(5)));
    root.setRight(new node(3)); // not balanced
    //root.setRight(new node(3,new node(4),new node(7))); // balanced
    if (root.isBalanced()) 
        cout << "Tree is balanced"; 
    else
        cout << "Tree is not balanced"; 
    return 0; 
} 
