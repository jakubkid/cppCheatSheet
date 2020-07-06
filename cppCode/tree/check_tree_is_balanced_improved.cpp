/* Cpp program to check if a tree is height-balanced or not improved
Time Complexity: O(n) Worst case occurs in case of skewed tree.*/
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
    bool isBalanced(int* height);

    
    void setLeft(node* setLeft){pLeft = setLeft;};
    void setRight(node* setRigth){pRight = setRigth;};
    void setData(int setData){data = setData;};
private:
  
    int data; 
    node* pLeft; 
    node* pRight; 
}; 

/* Returns true if binary tree 
with root as root is height-balanced */
bool node::isBalanced(int* height) 
{ 
    int leftHeight  = 0; // Height of left subtree 
    int rightHeight = 0; // Height of right subtree
    bool isLeftBalanced = true; // default is balanced
    bool isRightBalanced = true; //default is balanced 
    /* Get the heights of left and right subtrees 
    And store the returned heights*/
    if(pLeft != NULL)
    {
        isLeftBalanced = pLeft->isBalanced(&leftHeight); 
    }
    if(pRight != NULL)
    {
        isRightBalanced = pRight->isBalanced(&rightHeight); 
    }

    /* Height of current node is max of heights of left and 
    right subtrees plus 1*/
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1; 

    /* If difference between heights of left and right  
    subtrees is less than 2and and left and right subtrees  
    are balanced then return true */
    return ((abs(leftHeight -rightHeight) <= 1) && 
            isLeftBalanced && 
            isRightBalanced);
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
    int height = 0;
    root.setLeft(new node(2,new node(4,new node(8)),new node(5)));
    root.setRight(new node(3)); // not balanced
    //root.setRight(new node(3,new node(4),new node(7))); // balanced
    if (root.isBalanced(&height)) 
        cout << "Tree is balanced"; 
    else
        cout << "Tree is not balanced"; 
    return 0; 
} 
