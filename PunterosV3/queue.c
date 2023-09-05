#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *val;
  struct node *next;
} QueueNode;

typedef struct {
  QueueNode *primero, *ultimo;
} Queue;
 
Queue *makeQueue() {
  Queue *q = malloc(sizeof(Queue));
  q->primero = NULL;
  q->ultimo = NULL;
  return q;
}

void put(Queue *q, void *ptr) {
  QueueNode *nuevo = malloc(sizeof(QueueNode));
  nuevo->val = ptr;
  nuevo->next = NULL;
  if (q->ultimo == NULL) {
    q->primero = nuevo;
    q->ultimo = nuevo;
  } else {
    QueueNode *penultimo = q->ultimo;
    penultimo->next = nuevo;
    q->ultimo = nuevo;
  }
}

void *get(Queue *q) {
  if (q->primero == NULL) {
    return NULL;
  }
  QueueNode porDestruir = *q->primero;
  free(q->primero);
  if (q->primero == q->ultimo) { // comparamos las direcciones
    q->ultimo = NULL;
  }
  q->primero = porDestruir.next;
  return porDestruir.val;
}

void freeQueue(Queue *q) {
  QueueNode *qn = q->primero;
  while (qn) {
    QueueNode tmp = *qn; // para no usar qn después de liberarlo
    free(qn);
    qn = tmp.next;
  }
  free(q);
}

int main() {
  int a= 5, b= 7, c= -3;
  Queue *q= makeQueue();
  put(q, &a); put(q, &b); put(q, &c);
  int *pa= get(q);
  printf("%d\n", *pa);
  freeQueue(q);
  return 0;
}
