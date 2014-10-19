#include <stdlib.h>
#include <string.h>
#include "myListModule.h"
#include "graph.h"

typedef struct path{
  int travel_time;
  char* line;
  struct gNode *node;
} *Path;

typedef struct gNode{
  char* name;
  List paths;
} *GraphNode;

// Function prototypes
GraphNode Graph_createNode(char* newName, List paths);
void Graph_deleteNode(List map, GraphNode target);
void Graph_deletePath(Path path);
void Graph_linkNodes(GraphNode one, GraphNode two, int travel_time, char* line);
GraphNode Graph_map(List map, char* key);
GraphNode Graph_nodeInList(List map, GraphNode node);
Path Graph_createPath(int travel_time, char* line, GraphNode node);
GraphNode Graph_adjacentNode(Path path);
List Graph_getPaths(GraphNode node);
List Graph_findAllRoutes(GraphNode start, GraphNode end, List searched, List allSearchPaths);
GraphNode Graph_fastestRoute(List list);
GraphNode Graph_getFastestRoute(GraphNode start, GraphNode end);


GraphNode Graph_createNode(char* newName, List paths){
  GraphNode newGraphNode = malloc(sizeof(struct gNode));
  newGraphNode->paths = paths;
  newGraphNode->name = newName;
  return newGraphNode;
}

Path Graph_containsMatch(List paths, Path path){
  char* key = path->line;
  int len = listLength(paths);
  
  for (int i = 0; i <= len; i++) {
    Path currentPath = getElementAtIndex(paths, i);    
    
    if (strcmp(currentPath->line == key)){
      return currentPath;
    }
    
  }
  
  return NULL;
}



void Graph_deleteNode(List map, GraphNode target){
  //GraphNode node = Graph_nodeInList(map, target);
  List paths = Graph_getPaths(node);
  char* key = node->name;
  List checkedPaths = createList();


  // Rebind the paths going through
  While (paths != NULL){
    
    int len = listLength(paths);  
    for (int i = 0; i <= len; i++) {
      Path currentPath = getElementAtIndex(paths, i);
      Path matchingPath = Graph_containsMatch(paths, currentPath);
      if (matchingPath != NULL){
	GraphNode link1 = Graph_adjacentNode(currentpath);
	GraphNode link2 = Graph_adjacentNode(matchingPath);
	
	
      }
      
    }
  }
  
}





  free(target);
}



void Graph_deletePath(Path path){
  free(path);
}



void Graph_linkNodes(GraphNode one, GraphNode two, int travel_time, char* line){
  
  //Create the desired paths to and from each node
  Path fromOne = Graph_createPath(travel_time, line, two);
  Path fromTwo = Graph_createPath(travel_time, line, one);

  // Assign the paths to each node
  addListNode(one->paths, fromOne);
  addListNode(two->paths, fromTwo);
}



GraphNode Graph_map(List map, char* key){

  if (map == NULL){return NULL;}

  int len = listLength(map);
  for (int i = 0; i < len; i++) {
    
    GraphNode newNode = getElementAtIndex(map, i);
    char* name = newNode->name;
    
    if(strcmp(key, name)){return newNode;}
  }
  
  
  return NULL;
}



GraphNode Graph_nodeInList(List map, GraphNode node){
  int found = 0;
  GraphNode target = findElement(map, node, &found);
  if(found == 0){return NULL;}

  return target;
}


// Create a path
Path Graph_createPath(int travel_time, char* line, GraphNode node){
  Path newPath = malloc(sizeof(struct path));
  newPath->travel_time = travel_time;
  newPath->line = line;
  newPath->node = node;

  return newPath;
}


// Returns the node connected by 'path' to the node contianing the name 'key'
GraphNode Graph_adjacentNode(Path path){
  return (path->node);
}

// Returns a list with all nodes adjacent to the input node
List Graph_getPaths(GraphNode node){
  List paths = node->paths;
  return paths;
}

List Graph_findAllRoutes(GraphNode start, GraphNode end, List searched, List allSearchPaths){
  /*
  if (findListNode(searched, start->name, 0) != NULL){
    return NULL;
    }
  */
  // Extract all paths from the start node
  List allPaths = Graph_getPaths(start);

  // Add the name of this node the the list of searched nodes
  char* name = start->name;
  addListNode(searched, name);
  
  int length = listLength(allPaths);
  for (int i = 0; i < length; i++) {
    // Extract the desired list node containing path
    ListNode currentPathInList = getListNodeAtIndex(allPaths, i);
    // Extract the desired path
    Path currentPath = getData(currentPathInList);
    
    // Create a new graph node which only contains one path
    List newPathList = createList(); // Creates a new list
    addListNode(newPathList, currentPath); // Add the path to the list
    GraphNode newGraphNode = Graph_createNode(start->name, newPathList);
    
    addListNode(allSearchPaths, newGraphNode); 
  }
  
  ListNode nextListNode = getListNodeAtIndex(allSearchPaths, 0);
  GraphNode nextNode = getData(nextListNode);
  Graph_findAllRoutes(nextNode, end, searched, allSearchPaths);
  
  return allSearchPaths;
}

int Graph_getTravelTime(GraphNode node){
  int travelTime = 0;
  while (node != NULL){
    ListNode currentListPath = getListNodeAtIndex(node->paths, 0);
    Path currentPath = getData(currentListPath);
    travelTime += currentPath->travel_time;
    node = Graph_adjacentNode(currentPath);
  }
  return travelTime;
}

GraphNode Graph_fastestRoute(List list){
  GraphNode fastestNode = NULL;
  int fastest = -1;
  if (list == NULL) {return NULL;}
  
  int length = listLength(list);
  for (int i = 0; i < length; i++) {
    ListNode currentListNode = getListNodeAtIndex(list, i);
    GraphNode currentNode = getData(currentListNode);
    int travelTime = Graph_getTravelTime(currentNode);

    if (fastest == -1){
      fastest = travelTime;
      fastestNode = currentNode;
    }
    
    if (fastest > travelTime) {
      fastest = travelTime;
      fastestNode = currentNode;
    }
    
  }
 return fastestNode;
}


GraphNode Graph_getFastestRoute(GraphNode start, GraphNode end){
  List alreadyVisitedNodes = createList();
  List theFinalListofNodes = createList();
  List result = Graph_findAllRoutes(start, end, alreadyVisitedNodes, theFinalListofNodes);  
  
  // Find the shortest path
  GraphNode fastest = Graph_fastestRoute(result);

  // Return a list with the nodes in the shortest path
  return fastest;
}

