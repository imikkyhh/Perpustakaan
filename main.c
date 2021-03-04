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
	char judul[50];
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

typedef struct
{
    char jubuku[50];
    char kobuku[50];
}list;

data siswa[50];
perpus buku[50];
list bukuwe[50];

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
    printf("1. Peminjaman Buku\n2. Pengembalian Buku\n3. Tambahkan Siswa\n4. Tambahkan Buku\n5. Daftar Buku\n6. Daftar Siswa\n7. Daftar Buku Dipinjam\n8. Logout");
    printf("\n\nPilih nomor : ");
    scanf("%d",&i);
    switch(i){
    case 1:system("cls");pbuku();break;
    case 2:system("cls");kbuku();break;
    case 3:system("cls");addAnggota();break;
    case 4:system("cls");addBuku();break;
    case 5:system("cls");dafBuku();break;
    case 6:system("cls");dafSiswa();break;
    case 7:system("cls");dbBuku();break;
    case 8:system("cls");system("exit");
    }
}

pbuku(){
	FILE*pinjambuku;
	char kode;
	pinjambuku = fopen("pinjambuku.txt","a+");
	{
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
		printf("Nama :"); fflush(stdin); gets(buku[i].nama);
		printf("Judul : ");scanf("%s",&buku[i].judul);
		printf("Kode Buku :");scanf("%s",&buku[i].kode);
		fprintf(pinjambuku,"\nNama : %s\n",buku[i].nama);
		fprintf(pinjambuku,"Judul : %s\n",buku[i].judul);
		fprintf(pinjambuku,"Kode : %s\n",buku[i].kode);
		fprintf(pinjambuku,"Tanggal Pinjam : %02d-%02d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	}

	fclose(pinjambuku);
	system("pause");
	system("cls");
	mainMenu();
}

kbuku() {
    char cb, nama;
    int cntr=0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Nama : ");scanf("%d",&nama);
    printf("\nKode Buku : ");
    scanf("%d");
    nama=nama-1;

    FILE*kb;
    kb=fopen("pinjambuku.txt","a+");
    for(i=0;i<cntr;i++){
        if(nama!=i){
            fprintf(kb,"%s#%s#%s#%d#%d#%d\n",buku[i].nama,buku[i].judul,buku[i].kode,tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900);
        }
    }
    fclose(kb);

    printf("\n\nBuku Telah Berhasil Dikembalikan Pada %d / %d / %d \n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    printf("\n\nPlease Click Enter To Back To Menu\n");
    system("pause");
    system("cls");
    mainMenu();

}
addBuku(){
    FILE*daftarbuku;
    daftarbuku = fopen("DAFTAR BUKU.txt","a+");
    {
    printf("Judul Buku:"); fflush(stdin); gets(bukuwe[i].jubuku);
    printf("Kode Buku :");scanf("%s",&bukuwe[i].kobuku);
    fprintf(daftarbuku,"Judul : %s\n",bukuwe[i].jubuku);
    fprintf(daftarbuku,"Kode : %s\n\n",bukuwe[i].kobuku);
    system("cls");
    printf("Berhasil Menambahkan %s ke Daftar Buku\n\n",bukuwe[i].jubuku);
    }
    fclose(daftarbuku);
    system("pause");
    system("cls");
    mainMenu();
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
		fprintf(anggota,"Jurusan : %s\n\n",siswa[i].jurusan);
		system("cls");
		printf("\tBERHASIL MENAMBAHKAN SISWA\n");
        printf("\n\tNIS\t: %s\n",siswa[i].nis);
        printf("\tNAMA\t: %s\n",siswa[i].nama);
        printf("\tKelas\t: %s %s\n",siswa[i].kelas,siswa[i].jurusan);
	}

	fclose(anggota);
	system("pause");
	system("cls");
	mainMenu();
}

waktu(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("Selamat datang di E-Library SMKN 2 Temanggung!\t\t\t\tTanggal: %02d-%02d-%d \n\t\t\t\t\t\t\t\t\tJam: %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

dafBuku(){
	char listbuku[50];
	FILE*dafbuk;
	dafbuk = fopen("DAFTAR BUKU.txt","r");
	printf("DAFTAR BUKU\n\n");
	while(fgets(listbuku,50,dafbuk))
	{
		printf("%s", listbuku);
	}
	fclose(dafbuk);
	system("pause");
	system("cls");
	mainMenu();
}


dafSiswa(){
    char listsiswa[50];
	FILE*dafsis;
	dafsis = fopen("DATA SISWA.txt","r");
	printf("DAFTAR SISWA\n\n");
	while(fgets(listsiswa,50,dafsis))
	{
		printf("%s", listsiswa);
	}
	fclose(dafsis);
	system("pause");
	system("cls");
	mainMenu();
}

dbBuku(){
	char listpinjam[50];
	FILE*dafbuk;
	dafbuk = fopen("pinjambuku.txt","r");
	printf("DAFTAR BUKU DIPINJAM\n\n");
	while(fgets(listpinjam,50,dafbuk))
	{
		printf("%s", listpinjam);
	}
	fclose(dafbuk);
	system("pause");
	system("cls");
	mainMenu();
}
