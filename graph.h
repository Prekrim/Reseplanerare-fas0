#ifndef GRAPH_H
#define GRAPH_H

typedef struct gNode *GraphNode;
typedef struct path *Path;


GraphNode findGraphNode(GraphNode map, char *key);
void deleteGraphNode();
void deletePath();
Path createPath(int travel_time, char* line, GraphNode node);
void linkGraphNodes(GraphNode one, GraphNode two, int travel_time, char* line);
GraphNode createGraphNode(char* newName, List paths);
GraphNode adjacentGraphNode(Path path);
List getPaths(GraphNode node);
List findAllRoutes(GraphNode start, GraphNode end, List searched, List allSearchPaths);
int getTravelTime(GraphNode node);
GraphNode fastestRoute(List list);
GraphNode getFastestRoute(GraphNode start, GraphNode end);

#endif
