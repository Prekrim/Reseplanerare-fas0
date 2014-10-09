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


//typedef struct gNode *GraphNode;

/*
List addListNode(List list, void* data);
void* getval(); 
void* getkey();
void setVal();
void setKey(); 
*/
typedef struct listNode *ListNode;
typedef struct list *List;

List createList();
void addNode(List list, void *data);
ListNode findNode(List list, void* searchData, int *found);
void deleteNode(List list, ListNode target);
void deleteList(List list);
void* getData(ListNode node); 
void setData(ListNode node, void* newData);
void clearNode(ListNode node);
ListNode prevNode(List list, ListNode searchNode);




#endif
