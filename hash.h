#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 10 // Hash tablosu boyutu

typedef struct {
    int tracking_number;
    char content[50];
    int destination_city_id;
} Package;

typedef struct {
    Package** table; // Açýk adresleme için pointer dizisi
} HashTable;

HashTable* create_hash_table();
int hash_function_type_A(int key); // Tip A Hash Fonksiyonu
void insert_package(HashTable* ht, int tracking_number, const char* content, int dest_city);
void print_memory_report(HashTable* ht); // Bellek izleme raporu için

#endif
