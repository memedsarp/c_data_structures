#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

struct Node* GetNewNode(int x);
void InsertAtHead(int x);

int main(int argc, char const *argv[])
{
  InsertAtHead(10);
  InsertAtHead(20);

  printf("\n%d", head->data);
  printf("\n%d", head->next->data);
  printf("\n%d", head->next->prev->data);
}

struct Node* GetNewNode(int x)
{
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}


void InsertAtHead(int x)
{
  struct Node* newNode = GetNewNode(x);
  if (head == NULL)
  {
    head = newNode;
    return;
  } else
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }
}
