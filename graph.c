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


// Returns a node that is reachable from map
GraphNode findGraphNode(GraphNode map, char* key){


  return map;
}


// Deletes a node
void deleteGraphNode(GraphNode map, GraphNode target){

}

// Deletes a path
void deletePath(Path path){
  free(path);
}

// Create a path
Path createPath(int travel_time, char* line, GraphNode node){
  Path newPath = malloc(sizeof(struct path));
  newPath->travel_time = travel_time;
  newPath->line = line;
  newPath->node = node;

  return newPath;
}

// Adds node one to the list of adjecent nodes of node two and vice versa 
void linkGraphNodes(GraphNode one, GraphNode two, int travel_time, char* line){
  
  //Create the desired paths to and from each node
  Path fromOne = createPath(travel_time, line, two);
  Path fromTwo = createPath(travel_time, line, one);

  // Assign the paths to each node
  addListNode(one->paths, fromOne);
  addListNode(two->paths, fromTwo);
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
  /*
  if (findListNode(searched, start->name, 0) != NULL){
    return NULL;
    }
  */
  // Extract all paths from the start node
  List allPaths = getPaths(start);

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
    GraphNode newGraphNode = createGraphNode(start->name, newPathList);
    
    addListNode(allSearchPaths, newGraphNode); 
  }
  
  ListNode nextListNode = getListNodeAtIndex(allSearchPaths, 0);
  GraphNode nextNode = getData(nextListNode);
  findAllRoutes(nextNode, end, searched, allSearchPaths);
  
  return allSearchPaths;
}

int getTravelTime(GraphNode node){
  int travelTime = 0;
  while (node != NULL){
    ListNode currentListPath = getListNodeAtIndex(node->paths, 0);
    Path currentPath = getData(currentListPath);
    travelTime += currentPath->travel_time;
    node = adjacentGraphNode(currentPath);
  }
  return travelTime;
}

GraphNode fastestRoute(List list){
  GraphNode fastestNode = NULL;
  int fastest = -1;
  if (list == NULL) {return NULL;}
  
  int length = listLength(list);
  for (int i = 0; i < length; i++) {
    ListNode currentListNode = getListNodeAtIndex(list, i);
    GraphNode currentNode = getData(currentListNode);
    int travelTime = getTravelTime(currentNode);

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


GraphNode getFastestRoute(GraphNode start, GraphNode end){
  List alreadyVisitedNodes = createList();
  List theFinalListofNodes = createList();
  List result = findAllRoutes(start, end, alreadyVisitedNodes, theFinalListofNodes);  
  
  // Find the shortest path
  GraphNode fastest = fastestRoute(result);

  // Return a list with the nodes in the shortest path
  return fastest;
}

