#include <stdio.h>
#include "header.h"

// Fungsi tambahan untuk laporan penjualan
void laporanPenjualan() {
    printf("Laporan Penjualan: \n");
    for (int i = 0; i < totalTransaksi; i++) {
        printf("Transaksi ID: %d, Member ID: %d, Barang ID: %d, Jumlah: %d, Total: %.2f\n",
               transaksiList[i].id, transaksiList[i].memberId, transaksiList[i].barangId,
               transaksiList[i].jumlah, transaksiList[i].total);
    }
}
