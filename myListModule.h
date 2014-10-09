#ifndef MYLISTMODULE_H
#define MYLISTMODULE_H

typedef struct list *List;
typedef struct gNode *GraphNode;

List createList();
List addListNode(List list, void* data);
List deleteNode();
void deleteList();
void* getval(); 
void* getkey();
void setVal();
void setKey(); 

#endif
