#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
};

Node* createNode(int val)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertNode(Node *root, int val)
{
  if (root == NULL)
    return createNode(val);
  if (val < root->value)
  {
    root->left = insertNode(root->left, val);
  }
  else if (val > root->value)
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}

Node* searchNode(Node* root, int val)
{
  if (root == NULL || root->value == val)
  {
    return root;
  }
  if (val < root->value)
  {
    return searchNode(root->left, val);
  }
  return searchNode(root->right, val);
}

Node* findMin(Node* node)
{
  while (node && node-> left != NULL)
  {
    node = node->left;
  }
  return node;
}

Node* deleteNode(Node* root, int val)
{
  if (root == NULL)
    return NULL;
    
  if (val < root->value)
  {
    root->left = deleteNode(root->left, val);
  }
  else if (val > root->value)
  {
    root->right = deleteNode(root->right, val);
  }
  else
  {
    if(root->left == NULL)
    {
      Node* temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node* temp = root->left;
      free(root);
      return temp;
    }
    
    Node * temp = findMin(root->right);
    root->value = temp->value;
    root->right = deleteNode(root->right, temp->value);
  }
  return root;
}

void printPreOrder(Node *ptr)
{
  if (ptr != NULL)
  {
    cout << ptr->value << endl;
    printPreOrder(ptr->left);
    printPreOrder(ptr->right);
  }
}

void printPostOrder(Node *ptr)
{
  if (ptr != NULL)
  {
    printPostOrder(ptr->left);
    printPostOrder(ptr->right);
    cout << ptr->value << endl;
  }
}

void printInOrder(Node *ptr)
{
  if (ptr != NULL)
  {
    printInOrder(ptr->left);
    cout << ptr->value << endl;
    printInOrder(ptr->right);
  }
}

void deleteTree(Node *root)
{
  if (root != NULL)
  {
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
  }
}

int main()
{
  Node* root = NULL;
  int values[] = {50, 30, 20, 40, 70, 60, 80};
  for (int val : values)
      root = insertNode(root, val);

  cout << "Inorder traversal: ";
  printInOrder(root);
  cout << endl;

  cout << "Preorder traversal: ";
  printPreOrder(root);
  cout << endl;

  cout << "Postorder traversal: ";
  printPostOrder(root);
  cout << endl;

  int key = 20;
  root = deleteNode(root, key);
  cout << "After deleting " << key << ": ";
  printInOrder(root);
  cout << endl;

    // Free all memory
  deleteTree(root);
  return 0;
}
