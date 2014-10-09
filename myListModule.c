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

void addNode(List list, void *data){
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

ListNode findNode(List list, void* searchData, int *found){
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

void deleteNode(List list, ListNode target){
  if(target != NULL && list != NULL){
    ListNode prev = prevNode(list, target);
    if(list->first == list->last){ // List is only one element long
      deleteList(list);
    }
    else if(target == list->first){ // Target is first element in list
      list->first = target->next;
      clearNode(target);
    }
    else if(target == list->last){ //target is last element in list
      list->last = prev;
      clearNode(target);
    } else{ // Recursive search for element somewhere in list
      List recList = list;
      recList->first = (list->first)->next;
      deleteNode(recList, target);
    }// Rekursionsproblem kanske?? definierar recList varje gång??
  }
}

void deleteList(List list){
  if(list != NULL){
    if(list->first != list->last){ // List has more than one element
      ListNode prev = prevNode(list, list->last);
      list->last = prev;
      clearNode(prev->next);
      deleteList(list);
    }else{
      clearNode(list->first);
      free(list);
    }
  }
}

void* getData(ListNode node){
  return node->data;
}

void setData(ListNode node, void* newData){
  //free(node->data);
  //node->data = malloc(sizeof(void*));
  // Lägg newData i data (heape), LÖS SAMMA PROBLEM!
  node->data = newData;
}

void clearNode(ListNode node){
  //free(node->data); LÖS PROBLEMET I newNode först!
  free(node);
}

ListNode prevNode(List list, ListNode searchNode){
  if(searchNode != NULL){
    ListNode prev = list->first;
    while (prev->next != searchNode && prev->next != NULL) {
      prev = prev->next;
    }
    return prev;
  }
  return NULL;

}

ListNode getNodeAtIndex(List list, int index){ // Is 0-indexed
  ListNode node = list->first;
  if(node->next != NULL){
    for(int counter = 0; counter < index; counter++){
      node = node->next;
    }
    return node;
  }
  return node;
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
