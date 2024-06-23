#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head;

void Insert(int x);
void Insertn(int x, int n);
void Print();

int main(int argc, char const *argv[])
{
  head = NULL;

  int n, x;
  printf("How many numbers do you want to insert? ");
  scanf("%d", &n);

  for(int i=0; i<n; i++)
  {
    printf("Insert a num: ");
    scanf("%d", &x);
    Insert(x);
  }

  Insertn(100, 0);
  Insertn(200, 1);
  Insertn(300, 60);

  Print();
  printf("%d", head->data);
  return 0;
}

void Insert(int x)
{
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
  } else
  {
    struct Node* tail = head;
    while(tail->next != NULL){
      tail = tail->next;
    }
    tail->next = temp;
  }
}

void Insertn(int x, int n)
{
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->next = NULL;

  struct Node* temp = head;
  for(int i=0; i<n-1; i++)
  {
    if (temp->next == NULL)
    {
      break;
    } else
    {
      temp = temp->next;
    }
  }
  if (head == NULL)
  {
    Insert(x);
  } else if (n == 0)
  {
    newNode->next = head;
    head = newNode;
  } else if (temp->next == NULL)
  {
    temp->next = newNode;
  } else
  {
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

void Print()
{
  struct Node* temp = head;
  printf("The list is: ");
  while(temp != NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}