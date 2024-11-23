#include <stdio.h>
#include "header.h"

#define MAX_BARANG 100

Transaksi transaksiList[MAX_BARANG]; // Array untuk menyimpan transaksi
int totalTransaksi = 0; // Total transaksi yang ada

void loadTransaksiFromFile() {
    FILE *fp = fopen("transaksi.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    totalTransaksi = 0;
    while (fscanf(fp, "%d %d %d %d %f", &transaksiList[totalTransaksi].id, 
                                        &transaksiList[totalTransaksi].memberId, 
                                        &transaksiList[totalTransaksi].barangId,
                                        &transaksiList[totalTransaksi].jumlah, 
                                        &transaksiList[totalTransaksi].total) == 5) {
        totalTransaksi++;
    }

    fclose(fp);
}

void saveTransaksiToFile() {
    FILE *fp = fopen("transaksi.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < totalTransaksi; i++) {
        fprintf(fp, "%d %d %d %d %.2f\n", transaksiList[i].id, transaksiList[i].memberId, transaksiList[i].barangId, transaksiList[i].jumlah, transaksiList[i].total);
    }

    fclose(fp);
}

void inisialisasiBarang() {
    // Inisialisasi barangList dengan data
    totalBarang = 3; // Misalnya, ada 3 barang
    barangList[0] = (Barang){1, "Barang A", "Kategori 1", 10, 10000, 0}; // Barang 1
    barangList[1] = (Barang){2, "Barang B", "Kategori 2", 5, 20000, 10}; // Barang 2
    barangList[2] = (Barang){3, "Barang C", "Kategori 3", 0, 15000, 5}; // Barang 3
}

void bayar() {
    int memberId, barangId, jumlah;
    printf("Masukkan ID Member: ");
    scanf("%d", &memberId);
    printf("Masukkan ID Barang: ");
    scanf("%d", &barangId);
    printf("Masukkan Jumlah: ");
    scanf("%d", &jumlah);

    // Cari barang
    for (int i = 0; i < totalBarang; i++) {
        if (barangList[i].id == barangId) {
            if (barangList[i].stok < jumlah) {
                printf("Stok tidak cukup!\n");
                return;
            }
            barangList[i].stok -= jumlah; // Kurangi stok
            float total = barangList[i].harga * jumlah;
            float diskon = (barangList[i].diskon / 100) * total;
            total -= diskon; // Hitung total setelah diskon

            // Simpan transaksi
            Transaksi t = {totalTransaksi + 1, memberId, barangId, jumlah, total};
            transaksiList[totalTransaksi++] = t;
            saveTransaksiToFile();

            // Tambah poin ke member
            tambahPoin(memberId, (int)(total / 100)); // 1 poin untuk setiap 100 yang dibelanjakan
            saveBarangToFile();

            printf("Pembayaran berhasil! Total setelah diskon: %.2f\n", total);
            return;
        }
    }
    printf("Barang tidak ditemukan!\n");
}