#include "myListModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funktion prototypes
typedef struct gNode *GraphNode;
typedef struct path *Path;
void readLine(char* dest, int n, FILE *source);
void allRoutes();
void linkGraphNodes(GraphNode one, GraphNode two);
GraphNode findGraphGraphNode(GraphNode map, char *key);
Path createPath(int travel_time, char* line, GraphNode node);

typedef struct path{
  int travel_time;
  char* line;
  struct gNode *node;
  //struct node *node2;
} *Path;

typedef struct gNode{
  char* name;
  List paths;
} *GraphNode;

// Returns a node that is reachable from map
GraphNode findGraphNode(GraphNode map, char* key){

  return map;
}

/*
// Deletes a node
void deleteGraphNode(){

}

// Deletes a path
void deletePath(){

}
*/
// Adds node one to the list of adjecent nodes of node two and vice versa 
void linkGraphNodes(GraphNode one, GraphNode two, int travel_time, char* line){
  Path fromOne = createPath(travel_time, line, two);
  Path fromTwo = createPath(travel_time, line, one);
  one->paths = addListNode(paths, fromOne);
  two->paths = addListNode(paths, fromTwo);
}

// Returns a node with the name newName
GraphNode createGraphNode(char* newName, List paths){
  GraphNode newGraphNode = malloc(sizeof(struct gNode));
  newGraphNode->paths = paths;
  newGraphNode->name = newName;
  return newGraphNode;
}

// Returns the node connected by 'path' to the node contianing the name 'key'
GraphNode adjacentGraphNode(Path path){
  return (path->node);
}



// Returns a list with all nodes adjacent to the input node
List getPaths(GraphNode node){
  List paths = node->paths;
  return paths;
}

List findAllRoutes(GraphNode start, GraphNode end, List searched, List allSearchPaths){
  
  if (findListNode(searched, start->name, 0) != NULL){
    return NULL;
    }
 
  // Extract all paths from the start node
  List allPaths = getPaths(start);

  if (currentPaths == NULL){return NULL;}

  // Add the name of this node the the list of searched nodes
  searched = addListNode(searched, start->name);
  
  int length = listLength(allPaths)
  for (i = 0; i < length; i++) {
    Path currentPath = getListNodeAtIndex(i, allPaths);
    int time = currentPath->travelTime;
    GraphNode newGraphNode = createGraphNode(start->name, currentPath);
    
    allSearchPaths = addListNode(allSearchPaths, 
  }

  findAllRoutes();
  
  return currentPaths;
}

List getFastestRoute(GraphNode start, GraphNode end){
  // Get all nodes adjacent to the starting node

  // Recursively walk down the "tree" and assign travel time to the paths to find the shortest one
  /*
    Spara in varje {restid och nod} = path i en lista för varje rek.
    t.ex ((pollacks, 10), (slottet, 5))

    När någon når slutstationen sparar vi in det i en lista.
    Ligger det redan någonting där kollar vi restiden.
    Spara listan med minst restid.

    Kolla nuvarande restid mot slutlistan:
    Slutlistan == NULL (ingen gren har nått slutet än) -> gör inget
    Slutlistans restid < nuvarande restid -> avbryt rekursionen
    Slutlistans restid = nuvarande && vi har nått målet -> avbryt
    (annars)Slutlistans restid > nuvarande -> fortsätt (gör inget)
    
    int size = sizeOfList(searchTree);

    for (i = 0; i < size; i++) {
    getFastestRoute("första noden i listan", end);
    första noden i listan = andra noden i listan
    }

  
  
  */
  // Return a list with the nodes in the shortest path
  List routes = NULL;
  return routes;
}


// Adds the string in source to dest
void readLine(char* dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n'){
    dest[len-1] = '\0';}
}

// Prints all routes between two given nodes
void allRoutes(GraphNode map){
  char buffer[128];
  GraphNode start = NULL;
  GraphNode end = NULL;
  
  puts("");
  puts("Where do you want to travel from?");
  printf("? ");
  readLine(buffer, 128, stdin);
  start = findGraphNode(map, buffer);
  
  if (start != NULL){
    puts("Where do you want travle to?");
    readLine(buffer, 128, stdin);
    end = findGraphNode(map, buffer);
  }
  
  if (end != NULL){
    // Here we want a funtion that can find all possible routes between two nodes
    
  }
  
  if (start == NULL || end == NULL){
    puts("");
    puts("Could not find a location by that name");
  }
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
  GraphNode map = NULL;
  
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

    default:
      puts("Could not parse choice, please try again");
      break;
    }
    choice = chooseIndex();
  }
  if (choice == 0)
      puts("Good bye!");
  return 0;
}
