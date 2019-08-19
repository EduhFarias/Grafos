## Test

#include <stdio.h>
#include <stdlib.h>
#include <Graph.h>

#define MAX_SIZE 20

typedef struct adj_list {
  int item;
  adj_list *next;
}AdjList;

typedef struct graph {
  AdjList *vertices[MAX_SIZE];
  short visited[MAX_SIZE];
}Graph;

Graph* createGraph(){
  Graph new_graph = (Graph*) malloc(sizeof(Graph));
  int i;
  for(i = 0; i < MAX_SIZE-1; i++){
    new_graph->vertices[i] = NULL;
    new_graph->visited[i] = 0;
  }
  return new_graph;
}

AdjList* createAdjList(int item){
  AdjList *new_AdjL = (AdjList*) malloc(sizeof(AdjList));
  new_AdjL->item = item;
  new_AdjL->next = NULL;
  return new_AdjL;
}

void add_edge(Graph *graph, int vertex1, int vertex2){
  AdjList *vertex = createAdjList(vertex2);
  vertex->next = graph->vertices[vertex1];
  graph->vertices[vertex1] = vertex;
  
  //Grafo não direcionado.
  vertex = createAdjList(vertex1);
  vertex->next = graph->vertices[vertex2];
  graph->vertices[vertex2] = vertex;
}

void dfs(Graph *graph, int source){
  graph->visited[source] = 1;
  printf("%d\n", source);
  
  AdjList *AdjL = graph->vertices[source];
  while(AdjL != NULL){
    if(!graph->visited[AdjL->item]){
      dfs(graph, AdjL->item);
    }
    AdjL = AdjL->next;
  }
}

void bfs(Graph *graph, int source){
  
}

void printGraph(Graph *graph);
