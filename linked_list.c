#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// struct node

struct Node
{
  int data;
  struct Node* next;
};

struct Node* head;

//function prototypes

void Insert(int x);
void Insertn(int x, int n);
void Deleten(int n);
void Reverse(struct Node* temp);
void Print(struct Node* temp);
void PrintRecursiveReverse(struct Node* temp);
void PrintRecursive(struct Node* temp);

// main function

int main(int argc, char const *argv[])
{
  free(head);
  printf("%p\n", &head);
  head = (100, NULL);

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
  Insert(200);
  Insert(300);

  Deleten(0); 
 
  Reverse(head);
  PrintRecursiveReverse(head);
  printf("\n");
  PrintRecursive(head);
  Print(head);

  
  printf("%p\n", &head);
  return 0;
}

// inserts at the end

void Insert(int x)
{
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
    free(temp);
  } else
  {
    struct Node* tail = head;
    while(tail->next != NULL){
      tail = tail->next;
    }
    tail->next = temp;
  }
}

// inserts into given position - if position greater than the length, inserts at the end

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

// deletes the given position - if position is greater, deletes nothing

void Deleten(int n)
{
  if (n == 0)
  {
    struct Node* temp = head;
    head = head->next;
    free(head);
  } else {
    struct Node* tail = head;
    for(int i=1; i<n; i++)
    {
      tail = tail->next;
    }
    if (tail->next != NULL)
    {
      struct Node* temp = tail->next;
      tail->next = tail->next->next;
      free(tail->next);
    }
  }
}

// reverses the linked list

void Reverse(struct Node* temp)
{
  if (temp == NULL)
  {
    return;
  } else if (temp->next != NULL)
  {
    struct Node *temp1 = NULL;
    struct Node *temp2 = temp;
    struct Node *temp3;

    while(temp2 != NULL)
    {    
      temp3 = temp2->next;
      temp2->next = temp1;
      temp1 = temp2;
      temp2 = temp3;
    }

    head = temp1;
  }
}

// prints the elements

void Print(struct Node* temp)
{
  if (head == NULL)
  {
    printf("The list is empty");
  } else
  {
    printf("\nThe list is: ");
    while(temp != NULL)
    {
      printf(" %d", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}


// prints the elements using recursion

void PrintRecursive(struct Node* temp)
{
  if (temp == NULL)
  {
    printf("\n");
    return;
  }
  printf("%d ", temp->data);
  PrintRecursive(temp->next);
}

// prints the elements in reverse using recursion

void PrintRecursiveReverse(struct Node* temp)
{
  if (temp == NULL)
  {
    printf("\n");
    return;
  }
  PrintRecursiveReverse(temp->next);
  printf("%d ", temp->data);
}