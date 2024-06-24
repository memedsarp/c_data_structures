#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head;

void Insert(int x);
void Insertn(int x, int n);
void Deleten(int n);
void Reverse();
void Print();
void PrintRecursiveReverse(struct Node* temp);
void PrintRecursive(struct Node* temp);

int main(int argc, char const *argv[])
{
  head = NULL;

  // Manuel entry
  /*
  int n, x;
  printf("How many numbers do you want to insert? ");
  scanf("%d", &n);

  for(int i=0; i<n; i++)
  {
    printf("Insert a num: ");
    scanf("%d", &x);
    Insert(x);
  }
  */
  //Automated entry

  srand(time(NULL));

  for(int i=0; i<1; i++)
  {
    Insert(rand() % 100);
  }

  Insert(100);
  Insertn(200, 0);
  Insertn(300, 0);
  Insertn(800, 85);

  Deleten(85);
  Deleten(0);

  Print();
  
  Reverse();
  Print();
  PrintRecursive(head);
  printf("\n");
  PrintRecursiveReverse(head);
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
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;

  struct Node* tail = head;
  for(int i=0; i<n-1; i++)
  {
    if (tail->next == NULL)
    {
      break;
    } else
    {
      tail = tail->next;
    }
  }
  if (head == NULL)
  {
    Insert(x);
  } else if (n == 0)
  {
    temp->next = head;
    head = temp;
  } else if (tail->next == NULL)
  {
    tail->next = temp;
  } else
  {
    temp->next = tail->next;
    tail->next = temp;
  }
}

void Deleten(int n)
{
  if (n == 0)
  {
    struct Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
    return;
  } 
  struct Node* tail = head;

  for(int i=1; i<n; i++)
  {
    if (tail->next == NULL)
    {
      return;
    }
    tail = tail->next;
  }

  if (tail->next == NULL)
  {
    return;
  }
  {
    struct Node* temp = tail->next;
    tail->next = tail->next->next;
    temp->next = NULL;
    free(temp);
  }
}

void Reverse()
{
  if (head->next != NULL)
  {
  struct Node* temp1 = head;
  struct Node* temp2 = head->next;
  struct Node* temp3 = head->next->next;

  temp1->next = NULL;
  while(temp3 != NULL)
  {    
    temp2->next = temp1;
    temp1 = temp2;
    temp2 = temp3;
    temp3 = temp3->next;
  }

  temp2->next = temp1;
  head = temp2;
  } else if (head->next == NULL)
  {
    return;
  } else if (head->next->next == NULL)
  {
    struct Node* temp1 = head;
    struct Node* temp2 = head->next;

    temp2->next = temp1;
    temp1->next = NULL;
    head = temp2;
  }
}

void Print()
{
  struct Node* temp = head;
  printf("\nThe list is: ");
  while(temp != NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void PrintRecursive(struct Node* temp)
{
  if (temp == NULL)
  {
    return;
  }
  printf("%d ", temp->data);
  PrintRecursive(temp->next);
}

void PrintRecursiveReverse(struct Node* temp)
{
  if (temp == NULL)
  {
    return;
  }
  PrintRecursiveReverse(temp->next);
  printf("%d ", temp->data);
}