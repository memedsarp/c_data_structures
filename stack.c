#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data;
  Node* next;
} Node;

Node* top = NULL;

// functions

int isEmpty(Node* top);
void Push(int x, Node* top);
void Print(Node* top);

int main(int argc, char const *argv[])
{ 
  Node* top = malloc(sizeof(Node));
  top->data = 15;
  top->next = NULL;

  Push(10, top);

  free(top);

  return 0;
}

int isEmpty(Node* top)
{
  if (top == NULL)
  {
    return 1;
  }
  return 0;
}

void Push(int x, Node* top)
{
  if (isEmpty(top))
  {
    Node* top = malloc(sizeof(Node));
    top->data = x;
    top->next = NULL;
    return;
  }
  Node* temp = top;
  temp = top;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  Node* temp2 = malloc(sizeof(Node));
  temp2->data = x;
  temp2->next = NULL;

  temp->next = temp2;
}
