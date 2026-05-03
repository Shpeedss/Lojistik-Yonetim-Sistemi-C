#include <stdio.h>
#include <stdlib.h> // system("PAUSE") için eklendi
#include "hash.h"
#include "graph.h"

int main() {
    printf("--- Lojistik Yonetim Sistemi (Ogr No: 1250505052) ---\n");
    printf("Sistem Ayarlari: Tip A Hash | Acik Adresleme | DFS Gezinme\n\n");

    // 1. GRAF YAPISININ TEST EDÝLMESÝ (DFS)
    int num_cities = 5; 
    Graph* graph = create_graph(num_cities);
    
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    DFS(graph, 0); 

    // 2. HASH TABLOSU YAPISININ TEST EDÝLMESÝ VE BELLEK RAPORU
    printf("\n--- Paket Kayit Sistemi ---\n");
    HashTable* ht = create_hash_table();

    insert_package(ht, 102, "Elektronik Esya", 1); 
    insert_package(ht, 202, "Kisisel Evrak", 3);   
    insert_package(ht, 555, "Giyim", 2);
    insert_package(ht, 340, "Yedek Parca", 0);
    insert_package(ht, 112, "Kitap", 4);

    print_memory_report(ht);

    printf("\n");
    // Dev-C++'ta program bitince siyah ekranýn hemen kapanmamasý için:
    system("PAUSE"); 
    
    return 0;
}
