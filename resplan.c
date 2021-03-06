#include "myListModule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// Function prototypes
void readLine(char* dest, int n, FILE *source);
void allRoutes(List map);
int chooseIndex();

// Adds the string in source to dest
void readLine(char* dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n'){
    dest[len-1] = '\0';}
}

// Parses input string into a list of elements separated by commas in the string
List parseBusInfo(char *string, List result){
  if(*string != '\0' && *string != '\n'){
    char buffer[128];
    char c = string[0];
    for (int i = 0; c != ',' && c != '\n'; i++) {
      buffer[i] = string[i];
      c = string[i+1];
      buffer[i+1] = '\0';
    }
    
    char *stringAfterFirstComma = strchr(string, ',');
    if (stringAfterFirstComma){
      stringAfterFirstComma = &(stringAfterFirstComma[2]);
      addListNode(result, &buffer);
      parseBusInfo(stringAfterFirstComma, result);
    } else {
      addListNode(result, string);
    }
  }
  return result;
}

// Returns a GraphNode map with the bus network from file "filename"
GraphNode createBusMap(char* filename){
  char *busLine = malloc(128);
  char *stationName = malloc(128);
  char *destination = malloc(128);
  int *travelTime = malloc(sizeof(int)); 
  
  /*
  
  while(!(feof(busNetwork))){
      readLine(lineRead, 128, busNetwork);
      for (int i = 0; c != *lineReadFromComma; i++) {
	buffer[i] = lineRead[i];
	c = lineRead[i+1];
	[i+1] = '\0';
      }
      strcmp(busLine, buffer);
      
      
    }
  */
}

typedef struct gNode{
  char* name;
  List paths;
} *GraphNode;


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



// Prints all routes between two given nodes
void allRoutes(List map){
  char buffer[128];
  GraphNode start = NULL;
  GraphNode end = NULL;
  
  puts("");
  puts("Where do you want to travel from?");
  printf("? ");
  readLine(buffer, 128, stdin);
  start = Graph_map(map, buffer);
          
  if (start != NULL){
    puts("Where do you want travel to?");
    readLine(buffer, 128, stdin);
    end = Graph_map(map, buffer);
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
  int choice = -1;
  puts("");
  puts("Please choose an operation");
  puts("1. Possible routes between two stops");
  puts("2. Travel from stop A to stop B at Z o clock");
  puts("3. Travel from Stop A to stop B and arrive at Z o clock");
  puts("0. Exit Travel Planner");
  printf("? ");
  scanf("%d", &choice);
  while(getchar() != '\n'); // Clear stdin
  
  return choice;
}

int main (int argc, char* argv[]){
  
    if (argc < 2){
    puts("Usage: resplan [FILE]");
    return -1;
  }
  
  puts("");
  puts("  _______   ______");
  puts(" |__   __| |  __  |");
  puts("    | |    | |_/ /");
  puts("    | |    |  __/");
  puts("    | |    | |");
  puts("    |_|    |_|");
  puts("Welcome to Uppsala travel planner");
  
  // Initialize the node map
  //FILE *busNetwork = fopen(argv[1], "r");
  char *testString = "110, Polacksbacken, Grundstugan, 4";
  //readLine(testString, 128, busNetwork);
  List map = NULL;

  List result = createList();
  parseBusInfo(testString, result);
  printf("%s\n", (char *)getElementAtIndex(result, 0));
  printf("%s\n", (char *)getElementAtIndex(result, 1));
  printf("%s\n", (char *)getElementAtIndex(result, 2));
  printf("%s\n", (char *)getElementAtIndex(result, 3));

  for (int j = 0; j < listLength(result); j++) {
    printf("List element %d is %s\n", j, (char *)getElementAtIndex(result, j));
  }

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
  //if (choice == 0)
      puts("Good bye!");
  return 0;
}
