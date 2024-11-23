#include <stdio.h>
#include "header.h"

int main() {
    // Load data dari file
    loadBarangFromFile();
    loadMemberFromFile();
    loadTransaksiFromFile();

    int pilihan;
    do {
        printf("\n=== Sistem Kasir Sederhana ===\n");
        printf("1. Login\n");
        printf("2. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                login(); // Fungsi login akan mengatur peran dan memanggil menu
                break;
            case 2:
                printf("Terima kasih telah menggunakan sistem kasir.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 2);

    return 0;
}

