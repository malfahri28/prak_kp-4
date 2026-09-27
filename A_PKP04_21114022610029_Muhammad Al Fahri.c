#include <stdio.h>

#define maks_mahasiswa 5
#define jumlah_mk 3

void inputdata(char nama[][30], int nilai [][jumlah_mk],int jumlah);
float hitungratarata(int nilai[][jumlah_mk],int index);
char tentukangrade(float rata);
void tampilkanrapor(
    char nama[][30],
    int nilai[][jumlah_mk],
    float rata[],
    int jumlah
);

int main () {
    
    char nama[maks_mahasiswa][30];
    int nilai[maks_mahasiswa][jumlah_mk];
    float ratarata[maks_mahasiswa];
    int jumlah, i;
    printf("====================================================================\n");
    printf("                   SISTEM RAPOR DIGITAL\n");
    printf("====================================================================\n");
    
    printf("jumlah mahasiswa (1-%d) : ", maks_mahasiswa);
    scanf("%d", &jumlah);
    
    if(jumlah < 1 || jumlah > maks_mahasiswa){
        printf("jumlah ahasiswa tidak valid!\n");
        return 0;
    }
    inputdata(nama, nilai, jumlah);
    
    for(i = 0; i < jumlah; i++) {
        ratarata[i] = hitungratarata(nilai, i);
    }
    
    
    tampilkanrapor(nama, nilai, ratarata, jumlah);

    return 0;
}
void inputdata(char nama[][30], int nilai [][jumlah_mk], int jumlah) {
    int i,j;

    for (i = 0; i < jumlah; i++) {
        printf("\nmahasiswa ke-%d\n", i + 1);
        printf("Nama                : ");
        scanf("%29s", nama[i]);

        for (j = 0; j < jumlah_mk; j++){
            if (j == 0) {
                printf("nilai algoritma     : ");
            } else if (j == 1){
                printf("nilai pemrograman   : ");
            } else {
                printf("nilai Basis Data    : ");
            }
            scanf("%d", &nilai [i][j]);
        }
    }
} 

float hitungratarata(int nilai[][jumlah_mk], int index){
    int j, total = 0;

    for (j = 0; j < jumlah_mk; j++){
            total += nilai[index][j];
    }

    return (float) total / jumlah_mk;
}  

char tentukangrade(float rata) {
    if (rata >= 90) return 'A';
    else if (rata >= 80) return 'B';
    else if (rata >= 70) return 'C';
    else if (rata >= 60) return 'D';
    else return 'E';
}

void tampilkanrapor(
    char nama[][30],
    int nilai[][jumlah_mk],
    float ratarata[],
    int jumlah
) {
    int i, j;
    printf("\n====================================================================\n");
    printf("                          RAPOR DIGITAL\n");
    printf("\n====================================================================\n");
    
    printf("%-15s%-8s%-8s%-8s%-10s%-7s%-s\n", "nama", "Alg", "Prog", "BD", "rata-rata", "Grade", "Status");
    printf("--------------------------------------------------------------------\n");
    
    for (i = 0; i< jumlah; i++){
        printf("%-15s", nama[i]);

        for (j = 0; j < jumlah_mk; j++) {
            printf("%-8d", nilai[i][j]);
        }
        
        printf("%-10.2f%-7c", ratarata[i], tentukangrade(ratarata[i]));
        
        if (ratarata[i] >= 70){
            printf("%s", "LULUS");
        } else {
            printf("%s", "TIDAK LULUS");
        }
        printf("\n");
    }
    
    printf("====================================================================\n");
}