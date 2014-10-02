#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path{
  int value;
  struct stop *node1;
  struct stop *node2;
} *Path;

typedef struct node{
  char* name;
  int c;
  Path numberOfPaths[c];
  
} *Node;

int main (int argc, char* argv[]){
  printf("This program does nothing, yet!\n");
  
  
  
}
