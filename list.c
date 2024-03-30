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
List * createList() {
  List *Lista = (List *)malloc(sizeof(List));
  Lista -> head = NULL;
  Lista -> tail = NULL;
  Lista -> current = NULL;
  return Lista;
}
void * firstList(List * list) {
    Node *current1 = list->head;
    if (current1 != NULL){
      list->current = current1;
      return current1->data;
    }
    return NULL;
}
void * nextList(List * list) {
  Node *current1 = list->current;
  if (current1 != NULL && current1->next != NULL){
      list->current =  current1->next;
    return list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  Node *current1 = list->tail;
  if (current1 != NULL){
    list->current = current1;
    return current1->data;
  }
  return NULL;
}

void * prevList(List * list) {
Node *current1 = list->current;
  if (current1 != NULL && current1->prev != NULL){
      list->current =  current1->prev;
    return list->current->data;
  }
  return NULL;
}

void pushFront(List * list, void * data) {
  Node *nuevito = createNode(data);
  if (list->head == NULL){
    list->head = nuevito;
    list->tail = nuevito;
  }
  else{
    nuevito->next = list->head;
    list->head->prev = nuevito;
    list->head = nuevito;
  }
}


void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}
void pushCurrent(List * list, void * data) {
  Node *nuevito = createNode(data);
  if (list->current != NULL){
    if(list->current->next != NULL){
      list->current->next->prev = nuevito;
      nuevito->next = list->current->next;
      list->current->next = nuevito;
      nuevito->prev = list->current;
    }
    else{
      list->current->next = nuevito;
      nuevito->prev = list->current;
      list->tail = nuevito;
      
    }
  }
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
  Node *current1 = list->current;
  if (current1 != NULL){
    if(current1->prev != NULL){
      current1->prev->next = current1->next;
      
    }
    else{
      list->head = current1->next;
      
    }
    if(current1->next != NULL){
      current1->next->prev = current1->prev;
      
    }
  }
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}