/*
AVL Tree Implementation file

riffed and modified heavily by Aaron Crandall - 2016
All implementation in hearder because of templating

Implemented/modified by Kimi Phan - 2016
-implementation of rotation functions
-implementation of node heights
-implementation of contains function
-implementation of remove function
*/

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <queue>
#include <iostream>

using namespace std;

template<class T>
class AVLNode
{
public:
    // Default blank AVLNode constructor
    AVLNode()
    {
      left = right = nullptr;
      height = 0;
    }

    // Constructor with provided element (data) and children
    AVLNode(const T& el, AVLNode *l = nullptr, AVLNode *r = nullptr)
    {
      key = el;
      left = l;
      right = r;
      height = 0;
    }

    T key;                 // Key to compare/insert on of type <T>
    AVLNode *left, *right; // Children of this node
    int height;            // Height of this node in the tree
};

template<class T>
class AVLTree
{
public:
  AVLTree() {root = nullptr;}

  void insert(const T& key) {insert(root, key);}
  void printTree() {printTree(root);}

  bool contains(const T& key) {return(contains(root, key));}
  void remove(const T& key) {remove(root, key);}

private:
  AVLNode<T>* root;

  // single right rotate
  void rightRotation(AVLNode<T>* &node)
  {
    AVLNode<T>* left = node->left;

    node->left = left->right;
    left->right = node;
    node->height = height_of_node(node);
    node = left;
  }

  // Date added: October 19, 2016
  // single left rotate
  void leftRotation(AVLNode<T>* &node)
  {
    AVLNode<T>* right = node->right;

    node->right = right->left;
    right->left = node;
    node->height = height_of_node(node);
    node = right;
  }

  // Date added: October 19, 2016
  // Date modified: October 26, 2016
  // Modified:
  //  - node to node->left
  // Description:
  //  - double rotation right - left
  void doubleRotationRightLeft(AVLNode<T>* &node)
  {
    rightRotation(node->right);
    leftRotation(node);
  }

  // Date added: October 20, 2016
  // Date modified: October 26, 2016
  // Modified:
  //  - node to node->right
  // Description:
  //  - double rotation left - right
  void doubleRotationLeftRight(AVLNode<T>* &node)
  {
    leftRotation(node->left);
    rightRotation(node);
  }

  // Date added: October 26, 2016
  // checks the height of the tree
  int height_of_node(AVLNode<T>* node)
  {
    int height = -1;
    if (node != NULL)
    {
      int left_height = height_of_node(node->left); // gets the height of the left tree
      int right_height = height_of_node(node->right); // gets the height of the right tree
      int max_height = max(left_height, right_height); // find the max between the two heights
      height = max_height + 1; // calculates the height
    }
    return height;
  }

  // Date updated: October 26, 2016
  // inserts the node into the tree.
  void insert(AVLNode<T>* &node, const T& key)
  {
    if (node == nullptr)
    {
      node = new AVLNode<T>(key);
    }
    else if (key > node->key) // inserts right side of the tree
    {
      insert(node->right, key);
    }
    else // inserts left side of the tree
    {
      insert(node->left, key);
    }
    balance(node); // balances the tree after the node is inserted
  }

  // Date added: October 26, 2016
  // balances the tree
  void balance(AVLNode<T>* & node)
  {
    if (node == nullptr) // tree is empty or the tree is balanced
    {
      return;
    }
    // cases if tree is not balanced
    if (height_of_node(node->left) - height_of_node(node->right) > 1)
    {
      // left heavy tree
      if (height_of_node(node->left->left) >= height_of_node(node->left->right))
      {
        rightRotation(node);
      }
      else
      {
        doubleRotationLeftRight(node);
      }
    }
    else if (height_of_node(node->right) - height_of_node(node->left) > 1)
    {
      // right heavy tree
      if (height_of_node(node->right->right) >= height_of_node(node->right->left))
      {
        leftRotation(node);
      }
      else
      {
        doubleRotationRightLeft(node);
      }
    }
    node->height = height_of_node(node);
  }

  // Date added: October 25, 2016
  // Sees if a node is in the tree.
  bool contains(AVLNode<T>* root, const T& key)
  {
    if (root == NULL) // the node is not in the tree
    {
      return false;
    }
    else
    {
      if (key == root->key) // the node is in the tree
      {
        return true;
      }
      else if (key < root->key) // searches the right side of the tree
      {
        return contains(root->left, key);
      }
      else // searchs the left side of the tree
      {
        return contains(root->right, key);
      }
    }
  }

  // Date added: October 26, 2016
  // finds the min of the tree
  AVLNode<T> * findMin(AVLNode<T>* node)
  {
    return (node->left != nullptr) ? findMin(node->left): node;
  }

  // Date Created: October 26, 2016
  // removes a node from the tree
  void remove(AVLNode<T>* &root, const T& key)
  {
    if (root == nullptr)
    {
      return; // key was not found
    }

    if (key < root->key)
    {
      remove(root->left, key); // goes down the left side of the tree
    }
    else if(key > root->key)
    {
      remove(root->right, key); // goes down the right side of the tree
    }
    else
    {
        AVLNode<T>* temp = root;
        if (temp->left == nullptr && temp->right == nullptr) // no children
        {
          root = nullptr;
          delete temp;
        }
        else if (temp->left != nullptr && temp->right == nullptr) // has left child
        {
          root = temp->left;
          delete temp;
        }
        else if (temp->right != nullptr && temp->left == nullptr) // has right child
        {
          root = temp->right;
          delete temp;
        }
        else if (temp->left != nullptr && temp->right != nullptr) // with children
        {
          root->key = findMin(root->right)->key; // finds the min of the right sub-tree
          remove(root->right, root->key);
        }
    }
    balance(root);
    if (root != nullptr)
    {
      root->height = height_of_node(root);
    }
  }

// Date modified: October 26, 2016
// Modified:
//  - took out the endl in the if (curr->height < curr_height)
//  - reformated to print correctly
  void printTree(AVLNode<T>* node)
  {
    queue<AVLNode<T>*> bufQueue;

    int currentLevel = 0;
    int nextLevel = 0;
    int curr_height = node->height;
    bufQueue.push(node);
    while(!bufQueue.empty())
    {
      AVLNode<T>* curr = bufQueue.front();
      if(curr->left != nullptr)
      {
        bufQueue.push(curr->left);
        nextLevel +=1;
      }
      if(curr->right != nullptr)
      {
        bufQueue.push(curr->right);
        nextLevel += 1;
      }
      if(curr->height < curr_height)
      {
        //cout << endl;
        curr_height = curr->height;
      }
      cout << curr->key<< " ";
      bufQueue.pop();

      if(currentLevel <= 1)
      {
        cout << endl;
        currentLevel = nextLevel;
        nextLevel = 0;
      }
      else
        currentLevel -=1;
    }
    cout << endl;
  }
};

#endif
