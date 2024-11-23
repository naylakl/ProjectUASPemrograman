#ifndef HEADER_H
#define HEADER_H

// Konstanta
#define MAX_BARANG 100
#define MAX_MEMBER 50
#define MAX_NAMA 50
#define MAX_KATEGORI 30

// Struktur Data
typedef struct {
    int id;
    char nama[MAX_NAMA];
    char kategori[MAX_KATEGORI];
    int stok;
    float harga;
    float diskon; // Diskon dalam persen
} Barang;

typedef struct {
    int id;
    char nama[MAX_NAMA];
    int poin;
} Member;

typedef struct {
    int id;
    int memberId;
    int barangId;
    int jumlah;
    float total;
} Transaksi;

// Deklarasi Variabel Global
extern Barang barangList[MAX_BARANG]; // Deklarasi array barangList
extern int totalBarang;               // Deklarasi totalBarang

extern Member memberList[MAX_MEMBER]; // Deklarasi array memberList
extern int totalMember;               // Deklarasi totalMember

extern Transaksi transaksiList[MAX_BARANG]; // Deklarasi array transaksiList
extern int totalTransaksi;                  // Deklarasi totalTransaksi

// Fungsi Utama
void login();             // Fungsi login
void menuAdmin();         // Menu admin
void menuPembeli();       // Menu pembeli

// Fungsi Barang
void tambahBarang();      // Tambah barang baru
void kurangiStok();       // Kurangi stok barang
void hapusBarang(int idBarang); // Hapus barang berdasarkan ID
void lihatBarang();       // Lihat daftar barang

// Fungsi Member
void tambahMember();      // Tambah member baru
void lihatMember();       // Lihat daftar member
void tambahPoin(int memberID, int poin); // Tambah poin member


// Fungsi Transaksi
void bayar();             // Proses pembayaran
void laporanPenjualan();  // Lihat laporan penjualan

// Fungsi I/O File
void loadBarangFromFile();     // Muat barang dari file
void saveBarangToFile();       // Simpan barang ke file
void loadMemberFromFile();     // Muat member dari file
void saveMemberToFile();       // Simpan member ke file
void loadTransaksiFromFile();  // Muat transaksi dari file
void saveTransaksiToFile();    // Simpan transaksi ke file

#endif // HEADER_H

