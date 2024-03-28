#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
// Función para crear una lista vacía
List * createList() {
  List *Lista = (List *)malloc(sizeof(List));
  Lista -> current = NULL;
  Lista -> head = NULL;
  Lista -> tail = NULL;
  return Lista;
}
//retornar el primer nodo (head) y actualiza el current para que apunte a ese nodo.
void * firstList(List * list) {
    Node *current1 = list->head;
    if (current1 != NULL){
      list->current = current1;
      return current1->data;
    }
    return NULL;
}

void * nextList(List * list) {
  Node *current1 = list->head;
  if (current1 != NULL){
    if (list->current->next != NULL){
      list->current = list->current->next;
      return list->current->data;
    }
    
  }
    return NULL;
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}