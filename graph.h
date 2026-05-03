#ifndef GRAPH_H
#define GRAPH_H

typedef struct AdjNode {
    int dest_city_id;
    struct AdjNode* next;
} AdjNode;

typedef struct {
    AdjNode* head;
} AdjList;

typedef struct {
    int num_vertices;
    AdjList* array;
} Graph;

Graph* create_graph(int vertices);
void add_edge(Graph* graph, int src, int dest);
void DFS(Graph* graph, int vertex); // Sondan 2. rakam tek (5) olduðu için DFS
void DFS_util(Graph* graph, int vertex, int* visited);

#endif
