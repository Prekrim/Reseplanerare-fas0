#ifndef MYLISTMODULE_H
#define MYLISTMODULE_H

typedef struct list *List;

List createList();
List addNode();
List deleteNode();
void deleteList();
void* getval(); 
void* getkey();
void setVal();
void setKey(); 

#endif
