#ifndef MYLISTMODULE_H
#define MYLISTMODULE_H

typedef struct list *List;
typedef struct node *Node;

List createList();
List addNode(List list, Node node);
List deleteNode();
void deleteList();
void* getval(); 
void* getkey();
void setVal();
void setKey(); 

#endif
