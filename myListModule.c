#include "myListModule.h"
#include <stdlib.h>

typedef struct listNode {
  void *data;
  struct listNode *next;
} *ListNode;

typedef struct list {
  ListNode first;
  ListNode last;
} *List;

List createList(){
  List list = malloc(sizeof(struct list));
  list->first = NULL;
  list->last = NULL;
  return list;
}

void addListNode(List list, void *data){
  if(list != NULL){
    ListNode newNode = malloc(sizeof(struct listNode));
    newNode->data = data;

    if(list->first == NULL){
      list->first = newNode;
      list->last = newNode;
    }else{
      (list->last)->next = newNode;
      list->last = newNode;
    }
  }
}

ListNode findListNode(List list, void* searchData, int *found){
  ListNode targetNode = list->first;
  while(searchData != targetNode->data && targetNode->next != NULL){
    targetNode = targetNode->next;
  }
  if(targetNode->next == NULL){
    *found = -1;
    return NULL;
  }
  *found = 1;
  return targetNode;
}

void* findElement(List list, void* searchData, int *found){
  return (findListNode(list, searchData, found))->data;
}

void deleteListNode(List list, ListNode target){
  if(target != NULL && list != NULL){
    ListNode prev = prevListNode(list, target);
    if(list->first == list->last){ // List is only one element long
      list->first = NULL;
      list->last = NULL;
      clearListNode(target);
    }
    else if(target == list->first){ // Target is first element in list
      list->first = target->next;
      clearListNode(target);
    }
    else if(target == list->last){ //target is last element in list
      list->last = prev;
      clearListNode(target);
    } else{ // Recursive search for element somewhere in list
      List recList = list;
      recList->first = (list->first)->next;
      deleteListNode(recList, target);
    }// Rekursionsproblem kanske?? definierar recList varje gång??
  }
}

void deleteList(List list){
  if(list != NULL){
    if(list->first != list->last){ // List has more than one element
      ListNode prev = prevListNode(list, list->last);
      list->last = prev;
      clearListNode(prev->next);
      deleteList(list);
    }else if(list->first != NULL && list->last != NULL){ // List has one element only
      deleteListNode(list, list->first);
    }else{ // List is the empty list
      free(list);
    }      
  }
}

void* getData(ListNode node){
  return node->data;
}

void setData(ListNode node, void* newData){
  node->data = newData;
}

void clearListNode(ListNode node){
  free(node);
}

ListNode prevListNode(List list, ListNode searchNode){
  if(searchNode != NULL){
    ListNode prev = list->first;
    while (prev->next != searchNode && prev->next != NULL) {
      prev = prev->next;
    }
    return prev;
  }
  return NULL;

}

ListNode getListNodeAtIndex(List list, int index){ // Is 0-indexed
  ListNode node = list->first;
  if(node->next != NULL){
    for(int counter = 0; counter < index; counter++){
      node = node->next;
    }
    return node;
  }
  return node;
}

void* getElementAtIndex(List list, int index){
  return (getListNodeAtIndex(list, index))->data;
}

ListNode getLastListNode(List list){
  return list->last;
}

void* getLastElement(List list){
  return (list->last)->data;
}

ListNode getFirstListNode(List list){
  return list->first;
}

void* getFirstElement(List list){
  return (list->first)->data;
}

int listLength(List list){
  ListNode node = list->first;
  int counter = 0;
  if(list->first == NULL && list->last == NULL){ // List is empty, defined as length 0
    return counter;
  }else if(list->first == list->last){ // List is one element long
    return ++counter;
  }else
    while (node->next != NULL) {
      node = node->next;
      counter++;
    }
  counter++;
  return counter;
}
/*
void listIterator(List list, (void (foo*)(int))){
  ListNode node = list->first;
  while(node != NULL){
    function(node);
    node = node->next;
  }
}
*/
