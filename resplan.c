#include "myListModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funktion prototypes
typedef struct node *Node;
typedef struct path *path;
void readLine(char* dest, int n, FILE *source);
void allRoutes();
void linkNodes(Node one, Node two);
Node findNode(Node map, char *key);

typedef struct path{
  int weight;
  char* line;
  struct node *node1;
  struct node *node2;
} *Path;

typedef struct node{
  char* name;
  List paths;
} *Node;

// Returns a node that is reachable from map
Node findNode(Node map, char* key){

  return map;
}

// Returns the node connected by 'path' to the node contianing the key 'key'
Node adjacentNode(Path path, char* key){
  Node node1 = path->node1;
  Node node2 = path->node2;
  if (node1 == NULL && node2 == NULL){return NULL;}
  if (node1 != NULL || node1->name == key){return node2;}
  if (node2 != NULL || node2->name == key){return node1;}
  else{return NULL;}
}
/*
// Find all adjecent nodes to the input node
List getPaths(Node node){
  List paths = node->paths;
  List nodes = NULL;
  char* key = node->name;
  while(paths != NULL){
    
    Node foundNode = adjacentNode(paths, key);
    nodes = addNode(nodes, foundNode);
  }
  return nodes;
}
*/

// Adds the string in source to dest
void readLine(char* dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n'){
    dest[len-1] = '\0';}
}

// Prints all routes between two given nodes
void allRoutes(Node map){
  char buffer[128];
  Node start = NULL;
  Node end = NULL;
  
  puts("");
  puts("Where do you want to travel from?");
  printf("? ");
  readLine(buffer, 128, stdin);
  start = findNode(map, buffer);
  
  if (start != NULL){
    puts("Where do you want travle to?");
    readLine(buffer, 128, stdin);
    end = findNode(map, buffer);
  }
  
  if (end != NULL){
    // Here we want a funtion that can find all possible routes between two nodes
    
  }
  
  if (start == NULL || end == NULL){
    puts("");
    puts("Could not find a location by that name");
  }
}

// Returns a node with the name newName
Node createNode(char* newName){
  Node newNode = malloc(sizeof(struct node));
  newNode->paths = NULL;
  newNode->name = newName;
  return newNode;
}

// Adds node one to the list of adjecent nodes of node two and vice versa 
void linkNodes(Node one, Node two){

}

// Prints the GUI on the screen and returns the desired numeric option.
int chooseIndex(){
  int choice = 0;
  puts("");
  puts("Please choose an operation");
  puts("1. Possible routes between two stops");
  puts("2. Travel from stop A to stop B at Z o clock");
  puts("3. Travel from Stop A to stop B and arrive at Z o clock");
  printf("? ");
  scanf("%d", &choice);
  while(getchar() != '\n'); // Clear stdin
  
  return choice;
}

int main (int argc, char* argv[]){
  /*
    if (argc < 2){
    puts("Usage: resplan [FILE]");
    return -1;
  }
  */
  puts("");
  puts("  _______   ______");
  puts(" |__   __| |  __  |");
  puts("    | |    | |_/ /");
  puts("    | |    |  __/");
  puts("    | |    | |");
  puts("    |_|    |_|");
  puts("Welcome to Uppsala travel planner");
  
  // Initialize the node map
  Node map = NULL;
  
  int choice = chooseIndex();
  
  while (choice != 0){
 
    switch (choice){
    case 1:   
      // Find all routes between two stops
      allRoutes(map);
      break;
      
    case 2:
      // Find all possible ways to travel from X to Y at a given time
      puts("This is case 2");
      break;

    case 3:
      // Find all possible ways to travel from X to Y and arrive at a given time
      puts("This is case 3");
      break;

    case 0:
      puts("Good bye!");

    default:
      puts("Could not parse choice, please try again");
      break;
    }
    choice = chooseIndex();
  }
  return 0;
}
