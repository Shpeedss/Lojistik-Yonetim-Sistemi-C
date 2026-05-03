#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    int i;
    for (i = 0; i < vertices; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    // Çift yönlü baðlantý (Undirected Graph varsayýmýyla)
    AdjNode* newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->dest_city_id = dest;
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = (AdjNode*)malloc(sizeof(AdjNode));
    newNode->dest_city_id = src;
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFS_util(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("Sehir %d -> ", vertex);

    AdjNode* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int connected_vertex = temp->dest_city_id;
        if (!visited[connected_vertex]) {
            DFS_util(graph, connected_vertex, visited);
        }
        temp = temp->next;
    }
}

// DFS (Depth First Search) Algoritmasý
void DFS(Graph* graph, int start_vertex) {
    int* visited = (int*)malloc(graph->num_vertices * sizeof(int));
    int i;
    for (i = 0; i < graph->num_vertices; i++)
        visited[i] = 0;

    printf("\nDFS Gezinimi (Baslangic: Sehir %d):\n", start_vertex);
    DFS_util(graph, start_vertex, visited);
    printf("SON\n");
    free(visited);
}
