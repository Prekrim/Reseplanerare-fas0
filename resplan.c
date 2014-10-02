#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct path{
  int value;
  struct stop *north;
  struct stop *south;
} *Path;

typedef struct stop{
  char* name;
  path numberOfPaths[sizeof(struct path) + 9]
  
} *Stop;

int main (int argc, char* argv[]){
  printf("This program does nothing, yet!\n");

}
