#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node *prev;
};

bool isEmpty(Node *p)
{
  return p == NULL;
}

void insertNode(Node **pStart, int value)
{
  Node *p1, *p2;
  
  p1 = (Node *)malloc(sizeof(Node));
  p1->value = value;
  p1->next = NULL;
  p1->prev = NULL; 
  
  if (*pStart == NULL)
  {
    *pStart = p1;
    p1->prev = *pStart;
  }
  else
  {
    p2 = *pStart;
    
    while(p2->next != NULL)
    {
      p2 = p2->next;
    }
    
    p2->next = p1;
    p1->prev = p2;
  }
}

void deleteNode(Node **pStart, int value)
{
  Node *before, *discard;
  
  if (isEmpty(*pStart))
  {
    cout << "List is empty!" << endl;
  }
  else
  {
    before = NULL;
    discard = *pStart;
    
    if (discard->value == value)
    {
      *pStart = discard->next;
      if ((*pStart)->next != NULL)
      {
        (*pStart)->prev = NULL;
      }
      free(discard);
      return;
    }
    while (discard != NULL && discard->value != value)
    {
      before = discard;
      discard = discard->next;
    }
    if (discard == NULL)
    {
      cout << "Item does not exist!" << endl;
      return;
    }
    else
    {
      before->next = discard->next;
      if (discard->next != NULL)
      {
        discard->next-prev = before;
      }
      free(discard);
      return;
    }
  }
}

void addWithin(Node **p, int value, int pos)
{
  Node *p1, *here, *before;
  
  p1 = (Node *)malloc(sizeof(Node));
  p1->value = value;
  p1->next = NULL;
  p1->prev = NULL;
  
  if (isEmpty(*p) && pos > 1)
  {
    cout << "List is empty!" << endl;
    return;
  }
  else
  {
    if ()
    {
      
    }
  
  }
}

void printAllItems(Node *pStart)
{
  
}

int main()
{
  Node *pStart;
  pStart = NULL;
  
  insertNode(&pStart, 1);
  
}
