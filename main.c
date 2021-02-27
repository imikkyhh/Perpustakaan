#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>


int i, b, nama;

typedef struct
{
	char nama[50];
	char buku[50];
	char kode[20];
	char tglpinjam[10];

}perpus;

typedef struct
{
	char nama[50];
	char nis[50];
	char kelas[20];
	char jurusan[10];

}data;

data siswa[50];
perpus buku[50];

int main(){
    login();
}

void login()
{
    char username[]="admin", password[]="admin", id[8], p[6];
    int n=1, x, y;

    do{
         printf("Username:");
         scanf("%s", &id);
         x=strcmp(id, username);
        if(x==0){
         printf("Password:");
         readPass(p);
         y=strcmp(p, password);
         if(y==0){
            system("cls");
            mainMenu();
         }else{
             system("cls");
             printf("Password yang anda masukkan salah\n");
             login();
         }
        }else {
            system("cls");
            printf("Username yang anda masukkan salah!\n");
            login();
            system("cls");
            getch();
            n++;}

         if(n>5){
          printf("\nAccess Denied");
          getch();
          }
            }while (n<=5);

    }

    void readPass(char *temp)
{
    int key=0,index=0;
    do{
        key=getch();
        switch (key){
            case 0:
            case 224:
                getch();
                break;
            case '\b':
                if(index>0){
                    index=index-1;
                    temp[index] = 0;
                    printf("\b \b");
                }
                break;
            default:
                if(key>31&&key<127){
                    temp[index]=key;
                    index = index + 1;
                    printf("*");
                }
        }
    } while(key!=13);
    temp[index]='\0';
}

mainMenu(){
    waktu();
    printf("List Menu:\n\n");
    printf("1. Peminjaman Buku\n2. Pengembalian Buku\n3. Tambahkan Siswa\n4. Tambahkan Buku\n5. Logout");
    printf("\n\nPilih nomor : ");
    scanf("%d",&i);
    switch(i){
    case 1:system("cls");pbuku();break;
    case 2:system("cls");kbuku();break;
    case 3:system("cls");addAnggota();break;
    case 4:system("cls");addBuku();break;
    case 5:system("cls");system("exit");
    }
}

pbuku(){
	FILE*pinjambuku;
	int kode;
	pinjambuku = fopen("pinjambuku.txt","a+");
	{
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
		printf("Nama:"); fflush(stdin); gets(buku[i].nama);
		printf("\nKode Buku :");scanf("%s",&buku[i].kode);
		fprintf(pinjambuku,"\nJudul : %s\n",buku[i].buku);
		fprintf(pinjambuku,"Kode : %s\n",buku[i].kode);
		fprintf(pinjambuku,"Tanggal Pinjam : %02d-%02d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	}

	fclose(pinjambuku);
}

kbuku(){
    FILE * peminjam;
        char buffer[30], c;

        peminjam = fopen("peminjam.txt", "r");
        printf("Daftar Peminjam\n");
        fgets(buffer, 50, peminjam);
        printf("%s\n", buffer);
        fclose(peminjam);
        return 0;
    }
addBuku(){
    printf("Tambahkan Buku");
    scanf("%d");
    }

addAnggota(){
    FILE*anggota;
	anggota = fopen("DATA SISWA.txt","a+");
	{
		printf("NIS:"); fflush(stdin); gets(siswa[i].nis);
		printf("NAMA:");scanf("%s",&siswa[i].nama);
		printf("KELAS:");scanf("%s",&siswa[i].kelas);
		printf("JURUSAN:");scanf("%s",&siswa[i].jurusan);
		fprintf(anggota,"NIS : %s\n",siswa[i].nis);
		fprintf(anggota,"Nama : %s\n",siswa[i].nama);
		fprintf(anggota,"Kelas : %s\n",siswa[i].kelas);
		fprintf(anggota,"Jurusan : %s\n",siswa[i].jurusan);
		system("cls");
		printf("\tBERHASIL MENAMBAHKAN SISWA\n");
        printf("\n\tNIS\t: %s\n",siswa[i].nis);
        printf("\tNAMA\t: %s\n",siswa[i].nama);
        printf("\tKelas\t: %s %s\n",siswa[i].kelas,siswa[i].jurusan);
	}

	fclose(anggota);
}

waktu(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Selamat datang di E-Library SMKN 2 Temanggung!\t\t\t\tTanggal: %02d-%02d-%d \n\t\t\t\t\t\t\t\t\tJam: %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
