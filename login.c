#include <stdio.h>
#include <string.h>
#include "header.h"

// Implementasi menu admin
void menuAdmin() {
    int pilihan, idBarang;
    do {
        printf("\n=== Menu Admin ===\n");
        printf("1. Tambah Barang\n");
        printf("2. Lihat Barang\n");
        printf("3. Tambah Member\n");
        printf("4. Lihat Member\n");
        printf("5. Tambah Poin Member\n");
        printf("6. Kurangi Stok Barang\n");
        printf("7. Hapus Barang\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBarang();
                break;
            case 2:
                lihatBarang();
                break;
            case 3:
                tambahMember();
                break;
            case 4:
                lihatMember();
                break;
            case 5: {
                int memberId, poin;
                printf("Masukkan ID Member: ");
                scanf("%d", &memberId);
                printf("Masukkan jumlah poin yang ingin ditambahkan: ");
                scanf("%d", &poin);
                tambahPoin(memberId, poin);
                break;
            }
            case 6:
                kurangiStok();
                break;
            case 7:
                printf("Masukkan ID barang yang ingin dihapus: ");
                scanf("%d", &idBarang);
                hapusBarang(idBarang);
                break;
            case 8:
                laporanPenjualan();
                break;
            case 9:
                printf("Keluar dari Menu Admin.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 9);
}

// Implementasi menu pembeli
void menuPembeli() {
    int pilihan;
    do {
        printf("\n=== Menu Pembeli ===\n");
        printf("1. Lihat Barang\n");
        printf("2. Bayar\n");
        printf("3. Lihat Member\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                lihatBarang();
                break;
            case 2:
                bayar();
                break;
            case 3:
                lihatMember();
                break;
            case 4:
                printf("Keluar dari Menu Pembeli.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}

// Implementasi login
void login() {
    char username[20], password[20];
    printf("=== Login ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "Kelompok9") == 0 && strcmp(password, "Admin") == 0) {
        printf("Login berhasil sebagai Admin.\n");
        menuAdmin();
    } else if (strcmp(username, "Fulan") == 0 && strcmp(password, "Pembeli") == 0) {
        printf("Login berhasil sebagai Pembeli.\n");
        menuPembeli();
    } else {
        printf("Username atau Password salah!\n");
    }
}
