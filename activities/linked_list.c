#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

struct Node *createNode(int data) {
  struct Node *newNode = malloc(sizeof(*newNode));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
// or create the new node first for safety then assign later with temps next
void append(struct Node **head, int data) {
  struct Node *temp = *head;
  if(*head == NULL) {
    *head = createNode(data);
  } else {
      while (temp -> next != NULL) {
        temp = temp -> next;
      }
      temp -> next = createNode(data);
  }
}

void traverse(struct Node* head) {
  struct Node *temp = head;
  while(temp != NULL) {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }
}


