#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

// Function Prototypes
struct Node* GetNewNode(int x);
void InsertAtHead(int x);
void Print(struct Node* temp);

int main(int argc, char const *argv[])
{
  InsertAtHead(10);
  InsertAtHead(20);

  printf("%d\n", head->data);
  printf("%d\n", head->next->data);
  printf("%d\n", head->next->prev->data);

  Print(head);

  free(head);
  return 0;
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

void Print(struct Node* temp)
{
  printf("The list is: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

