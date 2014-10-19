#ifndef GRAPH_H
#define GRAPH_H

typedef struct gNode *GraphNode;
typedef struct path *Path;

// GRAPHS
GraphNode Graph_createNode(char* newName, List paths);
void Graph_deleteNode(List map, GraphNode target);

GraphNode Graph_nodeInList(List map, GraphNode node);
GraphNode Graph_map(List map, char* key);
void Graph_linkNodes(GraphNode one, GraphNode two, int travel_time, char* line);
List Graph_findAllRoutes(GraphNode start, GraphNode end, List searched, List allSearchPaths);
GraphNode Graph_fastestRoute(List list);

// PATHS
void Graph_deletePath(Path path);

#endif
