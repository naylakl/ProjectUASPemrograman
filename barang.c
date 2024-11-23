#include <stdio.h>
#include "header.h"

Barang barangList[MAX_BARANG];
int totalBarang = 0;

void loadBarangFromFile() {
    FILE *fp = fopen("barang.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    totalBarang = 0;
    while (fscanf(fp, "%d %s %s %d %f %f", &barangList[totalBarang].id, barangList[totalBarang].nama, barangList[totalBarang].kategori, &barangList[totalBarang].stok, &barangList[totalBarang].harga, &barangList[totalBarang].diskon) == 6) {
        totalBarang++;
    }
    fclose(fp);
}

void saveBarangToFile() {
    FILE *fp = fopen("barang.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < totalBarang; i++) {
        fprintf(fp, "%d %s %s %d %.2f %.2f\n", barangList[i].id, barangList[i].nama, barangList[i].kategori, barangList[i].stok, barangList[i].harga, barangList[i].diskon);
    }

    fclose(fp);
}


void tambahBarang() {
    if (totalBarang >= MAX_BARANG) {
        printf("Stok barang penuh!\n");
        return;
    }
    
    Barang b;
    printf("Masukkan ID Barang: ");
    scanf("%d", &b.id);
    printf("Masukkan Nama Barang: ");
    scanf("%s", b.nama);
    printf("Masukkan Kategori Barang: ");
    scanf("%s", b.kategori);
    printf("Masukkan Stok Barang: ");
    scanf("%d", &b.stok);
    printf("Masukkan Harga Barang: ");
    scanf("%f", &b.harga);
    printf("Masukkan Diskon Barang (dalam persen): ");
    scanf("%f", &b.diskon);

    barangList[totalBarang++] = b;
    saveBarangToFile();
    printf("Barang berhasil ditambahkan!\n");
}

// Fungsi untuk menghapus barang dari daftar berdasarkan ID
void hapusBarang(int idBarang) {
    int found = 0; // Flag untuk melacak apakah barang ditemukan

    for (int i = 0; i < totalBarang; i++) {
        if (barangList[i].id == idBarang) {
            found = 1;

            // Geser elemen setelah barang yang akan dihapus
            for (int j = i; j < totalBarang - 1; j++) {
                barangList[j] = barangList[j + 1];
            }

            totalBarang--; // Kurangi jumlah total barang
            printf("Barang dengan ID %d berhasil dihapus!\n", idBarang);
            break;
        }
    }

    if (!found) {
        printf("Barang dengan ID %d tidak ditemukan!\n", idBarang);
    }
    // Simpan ulang data barang ke file
    saveBarangToFile();
}

// Fungsi untuk mengurangi stok barang
void kurangiStok() {
    int id, jumlah;
    printf("Masukkan ID Barang yang stoknya ingin dikurangi: ");
    scanf("%d", &id);
    printf("Masukkan jumlah pengurangan stok: ");
    scanf("%d", &jumlah);

    int found = 0;
    for (int i = 0; i < totalBarang; i++) {
        if (barangList[i].id == id) {
            found = 1;
            if (barangList[i].stok < jumlah) {
                printf("Stok tidak mencukupi!\n");
                return;
            } else {
                barangList[i].stok -= jumlah;
                printf("Stok berhasil dikurangi!\n");
            }
            break;
        }
    }
    
    if (!found) {
        printf("Barang tidak ditemukan!\n");
    }
    saveBarangToFile();
}

void lihatBarang() {
    printf("Daftar Barang: \n");
    for (int i = 0; i < totalBarang; i++) {
        printf("ID: %d, Nama: %s, Kategori: %s, Stok: %d, Harga: %.2f, Diskon: %.2f%%\n",
               barangList[i].id, barangList[i].nama, barangList[i].kategori,
               barangList[i].stok, barangList[i].harga, barangList[i].diskon);
    }
}