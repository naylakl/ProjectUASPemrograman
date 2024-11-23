#include <stdio.h>
#include "header.h"

Member memberList[MAX_MEMBER];
int totalMember = 0;

void loadMemberFromFile() {
    FILE *fp = fopen("member.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    totalMember = 0;
    while (fscanf(fp, "%d %s %d", &memberList[totalMember].id, memberList[totalMember].nama, &memberList[totalMember].poin) == 3) {
        totalMember++;
    }

    fclose(fp);
}

void saveMemberToFile() {
    FILE *fp = fopen("member.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < totalMember; i++) {
        fprintf(fp, "%d %s %d\n", memberList[i].id, memberList[i].nama, memberList[i].poin);
    }

    fclose(fp);
}

void tambahMember() {
    if (totalMember >= MAX_MEMBER) {
        printf("Jumlah member sudah penuh!\n");
        return;
    }

    Member m;
    printf("Masukkan ID Member: ");
    scanf("%d", &m.id);
    printf("Masukkan Nama Member: ");
    scanf("%s", m.nama);
    m.poin = 0; // Poin awal member adalah 0

    memberList[totalMember++] = m;
    saveMemberToFile();
    printf("Member berhasil ditambahkan!\n");
}

void lihatMember() {
    printf("Daftar Member: \n");
    for (int i = 0; i < totalMember; i++) {
        printf("ID: %d, Nama: %s, Poin: %d\n", memberList[i].id, memberList[i].nama , memberList[i].poin);
    }
}

void tambahPoin(int memberId, int poin) {
    int found = 0; // Flag untuk menentukan apakah member ditemukan

    for (int i = 0; i < totalMember; i++) {
        if (memberList[i].id == memberId) {
            memberList[i].poin += poin;
            printf("Poin berhasil ditambahkan! Member ID: %d, Nama: %s, Total Poin: %d\n",
                   memberList[i].id, memberList[i].nama, memberList[i].poin);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Member dengan ID %d tidak ditemukan!\n", memberId);
    }

    // Simpan perubahan poin ke file
    saveMemberToFile();
}
