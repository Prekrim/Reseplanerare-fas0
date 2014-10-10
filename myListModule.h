#ifndef MYLISTMODULE_H
#define MYLISTMODULE_H

/*
  A simple datastructure of a generic list with
  a first and last element, can be further
  developed with append and prepend functionality.
  Uses void pointers for data to handle generic
  list data
  (C) Oliver Stein 2014
  Use at own risk! ;)
*/

typedef struct list *List;
typedef struct listNode *ListNode;

List createList();
void addListNode(List list, void *data);
ListNode findListNode(List list, void* searchData, int *found);
void* findElement(List list, void* searchData, int *found);
void deleteListNode(List list, ListNode target);
void deleteList(List list);
void* getData(ListNode node); 
void setData(ListNode node, void* newData);
void clearListNode(ListNode node);
ListNode prevListNode(List list, ListNode searchNode);
ListNode getListNodeAtIndex(List list, int index); //Is 0-indexed
void* getElementAtIndex(List list, int index); // Is 0-indexed
ListNode getLastListNode(List list);
void* getLastElement(List list);
ListNode getFirstListNode(List list);
void* getFirstElement(List list);
int listLength(List list);

#endif
