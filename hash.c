#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HashTable* create_hash_table() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (Package**)malloc(sizeof(Package*) * TABLE_SIZE);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Tip A Hash Fonksiyonu (Çift son rakam için)
int hash_function_type_A(int key) {
    return key % TABLE_SIZE;
}

// Açýk Adresleme (Open Addressing - Linear Probing)
void insert_package(HashTable* ht, int tracking_number, const char* content, int dest_city) {
    int index = hash_function_type_A(tracking_number);
    int original_index = index;
    int i = 0;

    // Çakýþma kontrolü (Linear Probing)
    while (ht->table[index] != NULL) {
        printf("  [!] Çakisma yasandi! Paket: %d, Indeks: %d dolu.\n", tracking_number, index);
        i++;
        index = (original_index + i) % TABLE_SIZE;
        if (i >= TABLE_SIZE) {
            printf("  [Hata] Hash tablosu dolu!\n");
            return;
        }
    }

    Package* new_pkg = (Package*)malloc(sizeof(Package));
    new_pkg->tracking_number = tracking_number;
    strcpy(new_pkg->content, content);
    new_pkg->destination_city_id = dest_city;

    ht->table[index] = new_pkg;
    printf("  [+] Paket %d eklendi -> Indeks: %d (Bellek Adresi: %p)\n", tracking_number, index, (void*)new_pkg);
}

// Bellek Ýzleme Raporunu Yazdýran Fonksiyon
void print_memory_report(HashTable* ht) {
    printf("\n======================================================\n");
    printf("              BELLEK IZLEME RAPORU (RAM DURUMU)         \n");
    printf("======================================================\n");
    printf("HashTable Ana Bellek Adresi: %p\n", (void*)ht);
    printf("Dizi (Table) Adresi: %p\n\n", (void*)ht->table);
    printf("%-10s %-15s %-20s %-15s\n", "Indeks", "Paket ID", "Veri Adresi (0x..)", "Icerik");
    printf("------------------------------------------------------\n");
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        if (ht->table[i] != NULL) {
            printf("[%d]        %-15d %-20p %-15s\n", 
                i, ht->table[i]->tracking_number, (void*)ht->table[i], ht->table[i]->content);
        } else {
            printf("[%d]        %-15s %-20s %-15s\n", i, "BOS", "NULL", "-");
        }
    }
    printf("======================================================\n");
}
