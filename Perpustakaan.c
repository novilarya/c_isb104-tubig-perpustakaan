#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nama[50];
	int NRP;
	int noWhatsApp;
	char password[50];
}dataUser;

char username[50];
char password[50];

dataUser tambah;
dataUser dataMhs[1000];

void header();

void menuDosen();
void loginDosen();
void signupDosen();

void meminjamBukuDosen();
void mengembalikanBukuDosen();
void menyumbangBukuDosen();

void menuMahasiswa();
void loginMahasiswa();
void signupMahasiswa();
void meminjamBukuMahasiswa();
void mengembalikanBukuMahasiswa();
void menyumbangBukuMahasiswa();

void menuPengelolaPerpustakaan();
void loginPengelolaPerpustakaan();
void signinPengelolaPerpustakaan();

void header() {
	printf("=================================================================================================\n");
	system("COLOR 6");
	printf("\n\t\tSELAMAT DATANG DI SISTEM PERPUSTRAKAAN PRODI SISTEM INFORMASI\n\n");
	system("COLOR 3");
	printf("=================================================================================================\n");
}

int main() {
	int menuAwal;

	system("COLOR 3");

	header();

	kembali:
	printf("\n\tMasuk Sebagai:\n");
	printf("\t1. Dosen\n");
	printf("\t2. Mahasiswa\n");
	printf("\t3. Pengelola Perpustakaan\n");
	printf("\tPilih (1/2/3): ");
	scanf("%d", &menuAwal);
	printf("\n=================================================================================================\n");
	printf("=================================================================================================\n");
	switch (menuAwal) {
	case 1: 
		menuDosen();
		break;
	case 2: 
		menuMahasiswa();
		break;
	case 3: 
		menuPengelolaPerpustakaan();
		break;
	default: 
		printf("Anda Salah Memilih Menu!\n"); 
		goto kembali; 
		break;
	}



	return 0;
}

void menuDosen() {
	int pilihAkun, pilihDosen;

	system("CLS");
	header();

	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\n\t1. Sudah Punya Akun");
	printf("\n\t2. Belum Punya Akun");
	printf("\n\tPilih (1/2): ");

	kembaliDosen:
	scanf("%d", &pilihAkun);
	printf("\n\n=================================================================================================\n");
	switch (pilihAkun) {
	case 1:
		loginDosen();
		break;
	case 2:
		signupDosen();
		break;
	default:
		printf("Anda Salah Memilih Menu!\n");
		goto kembaliDosen;
		break;
	}

	system("CLS");
	header();
	printf("\n=================================================================================================\n");
	printf("%s\tMenu Utama\n", username);
	printf("=================================================================================================\n");

	printf("\tApa yang hendak dilakukan?\n");
	printf("\t1. Meminjam Buku\n");
	printf("\t2. Mengembalikan Buku\n");
	printf("\t3. Menyumbang Buku\n");
	printf("Silahkan Pilih Menu: ");
	scanf("%d", &pilihDosen);
	switch (pilihDosen) {
	case 1:
		meminjamBukuDosen;
		break;
	case 2:
		mengembalikanBukuDosen;
		break;
	case 3:
		menyumbangBukuDosen;
		break;
	default:
		break;
	}

}

void loginDosen() {
	system("CLS");
	header();
	int key = 0;

	FILE* dataDosen;
	dataDosen = fopen("data dosen.txt", "a+");

	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");

loginDosen:
	printf("\tNama\t\t: ");
	scanf("%s", username);
	printf("\tPassword\t: ");
	scanf("%s", password);

	while (fscanf(dataDosen, "%s\n%d\n%d\n%s\n", tambah.nama, &tambah.NRP, &tambah.noWhatsApp, tambah.password) != EOF) {
		if ((strcmp(username, tambah.nama) == 0) && (strcmp(password, tambah.password) == 0)) {
			printf("\tAnda Berhasil Login!\n");
			key = 1;
			break;
		}
	}
	if (key != 1) {
		printf("\tUsername atau Password Anda Salah!\n");
		key = 1;
		goto loginDosen;
	}
	fclose(dataDosen);
}
void signupDosen() {
	system("CLS");
	header();
	FILE* dataDosen;
	dataDosen = fopen("data dosen.txt", "a+");

	printf("\n=================================================================================================\n");
	printf("\t\t\tSilahkan Isi Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\tNama\t\t: ");
	scanf("%s", tambah.nama);
	printf("\tNRP\t\t: ");
	scanf("%d", &tambah.NRP);
	printf("\tNomor WhatsApp\t: ");
	scanf("%d", &tambah.noWhatsApp);
	printf("\tPassword\t: ");
	scanf("%s", tambah.password);

	fprintf(dataDosen, "%s\n%d\n%d\n%s\n", tambah.nama, tambah.NRP, tambah.noWhatsApp, tambah.password);

	fclose(dataDosen);

	loginDosen();
}

void menuMahasiswa() {
	int pilihAkun;
	int pilihMenuMahasiswa;

	system("CLS");
	header();
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\n\t1. Sudah Punya Akun");
	printf("\n\t2. Belum Punya Akun");
	printf("\n\tPilih (1/2): ");

	kembaliMahasiswa:
	scanf("%d", &pilihAkun);
	printf("\n\n=================================================================================================\n");
	switch (pilihAkun) {
	case 1:
		loginMahasiswa();
		break;
	case 2:
		signupMahasiswa();
		break;
	default:
		printf("Anda Salah Memilih Menu!\n");
		goto kembaliMahasiswa;
		break;
	}

	system("CLS");
	header();
	do {

		printf("%s\t\t\tMenu Utama\n", username);
		printf("=================================================================================================\n");

		printf("\tApa yang hendak dilakukan?\n");
		printf("\t1. Meminjam Buku\n");
		printf("\t2. Mengembalikan Buku\n");
		printf("\t3. Menyumbang Buku\n");
		printf("\t4. Keluar\n");
		printf("Pilih (1/2/3/4): ");
		scanf("%d", &pilihMenuMahasiswa);
		switch (pilihMenuMahasiswa) {
		case 1:
			meminjamBukuMahasiswa();
			break;
		case 2:
			mengembalikanBukuMahasiswa();
			break;
		case 3:
			menyumbangBukuMahasiswa();
			break;
		case 4:
			printf("Terima Kasih Telah Menggunakan Sistem Ini!\n");
			break;
		default:
			printf("Anda Salah Memilih Menu!\n");
			break;
		}
	} while (pilihMenuMahasiswa != 4);

}

void loginMahasiswa() {
	system("CLS");
	header();
	int key = 0;

	FILE* dataMahasiswa;
	dataMahasiswa = fopen("data mahasiswa.txt", "a+");

	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");

loginMahasiswa:
	printf("\tNama\t\t: ");
	scanf("%s", username);
	printf("\tPassword\t: ");
	scanf("%s", password);

	while (fscanf(dataMahasiswa, "%s\n%d\n%d\n%s\n", tambah.nama, &tambah.NRP, &tambah.noWhatsApp, tambah.password) != EOF) {
		if ((strcmp(username, tambah.nama) == 0) && (strcmp(password, tambah.password) == 0)) {
			printf("\tAnda Berhasil Login!\n");
			key = 1;
			break;
		}
	}
	if (key != 1) {
		printf("\tUsername atau Password Anda Salah!\n");
		key = 1;
		goto loginMahasiswa;
	}
	fclose(dataMahasiswa);
}
void signupMahasiswa() {
	system("CLS");
	header();
	FILE* dataMahasiswa;
	dataMahasiswa = fopen("data mahasiswa.txt", "a+");

	printf("\n=================================================================================================\n");
	printf("\t\t\tSilahkan Isi Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\tNama\t\t: ");
	scanf("%s", tambah.nama);
	printf("\tNRP\t\t: ");
	scanf("%d", &tambah.NRP);
	printf("\tNomor WhatsApp\t: ");
	scanf("%d", &tambah.noWhatsApp);
	printf("\tPassword\t: ");
	scanf("%s", tambah.password);

	fprintf(dataMahasiswa, "%s\n%d\n%d\n%s\n", tambah.nama, tambah.NRP, tambah.noWhatsApp, tambah.password);

	fclose(dataMahasiswa);

	loginMahasiswa();
}

void menuPengelolaPerpustakaan() {
	int pilihAkun;

	system("CLS");
	header();
	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\n\t1. Sudah Punya Akun");
	printf("\n\t2. Belum Punya Akun");
	printf("\n\tPilih (1/2): ");

	kembaliPengelolaPerpustakaan:
	scanf("%d", &pilihAkun);
	printf("\n\n=================================================================================================\n");
	switch (pilihAkun) {
	case 1:
		loginPengelolaPerpustakaan();
		break;
	case 2:
		signinPengelolaPerpustakaan();
		break;
	default:
		printf("Anda Salah Memilih Menu!\n");
		goto kembaliPengelolaPerpustakaan;
		break;
	}

	system("CLS");
	header();
	printf("\n=================================================================================================\n");
	printf("XXXXXXX-NAMA-XXXXXXX\tMenu Utama\n");
	printf("=================================================================================================\n");
	printf("\tApa yang hendak dilakukan?\n");
	printf("\t1. Meminjam Buku\n");
	printf("\t2. Mengembalikan Buku\n");
	printf("\t3. Menyumbang Buku\n");
	printf("\t4. Mengecek Data Peminjaman Buku\n");
}

void loginPengelolaPerpustakaan() {
	system("CLS");
	header();
	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\tNama\t\t: \n");
	printf("\tPassword\t: \n");
}
void signinPengelolaPerpustakaan() {
	system("CLS");
	header();
	printf("\n=================================================================================================\n");
	printf("\t\t\tSilahkan Isi Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\tNama\t\t: \n");
	printf("\t!!NRP\t\t: \n");
	printf("\tNomor WhatsApp\t: \n");
	printf("\tPassword\t: \n");
	loginPengelolaPerpustakaan();
}

void meminjamBukuMahasiswa() {
	int pilihanBuku;
	char *pilihanJenisBuku;
	system("CLS");
	header();
	printf("%s\t\t\tMeminjam Buku\n", username);
	printf("=================================================================================================\n");
	printf("\tPilih Jenis Buku yang Hendak dipinjam\n");
	printf("\t1. Tugas Akhir\n");
	printf("\t2. KP\n");
	printf("\t3. SIP\n");
	printf("\t4. MBKM\n");
	printf("\t5. PAP\n");
	printf("\t6. PEM\n");
	printf("\t7. DB\n");
	printf("\t8. Kembali\n");
	printf("\tSilahkan Tulis Sesuai Menu (TA): ");
	scanf("%d", &pilihanBuku);
	switch (pilihanBuku) {
	case 1: 
	{
		char pilihanJenisBuku[] = "Tugas Akhir";
	}
		break;
	case 2: {
		char pilihanJenisBuku[] = "KP";
	}
		break;
	case 3: {
		char pilihanJenisBuku[] = "SIP";
	}
		break;
	case 4: {
		char pilihanJenisBuku[] = "MBKM";
	}
		break;
	case 5: {
		char pilihanJenisBuku[] = "PAP";
	}
		break;
	case 6: {
		char pilihanJenisBuku[] = "PEM";
	}
		break;
	case 7: {
		char pilihanJenisBuku[] = "DB";
	}
		break;
	case 8: {

	}
		break;
	default:
		printf("Anda Salah Memilih Menu!\n");
		break;
	}while (pilihanBuku != 8);


	printf("\n=================================================================================================\n");
	printf("\tJenis Buku\t: ");
	printf("%s\n", pilihanJenisBuku);
	printf("=================================================================================================\n");
	printf("Kode Buku\t|\tNama Buku\t\t|\tPenyusun\t\t|\tStatus\n");
	printf("=================================================================================================\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("XXXX-XXXXXXXXX\t|\tXXXXX-NAMA BUKU-XXXXX\t|\tXXXXX-NAMA-XXXXX\t|\tTersedia\n");
	printf("=================================================================================================\n");
	printf("\tSilahkan Ketik Sesuai Kode Buku (Tanpa -): \n");
	printf("=================================================================================================\n");
	printf("\tTanggal Pinjam (DDMMYYYY)\t: \n");
	printf("\tTanggal Pengembalian (DDMMYYYY)\t: \n");
	printf("=================================================================================================\n");
	printf("\tSilahkan Datang Ke Perpustakaan Secara Langsung Untuk Meminjam Buku!\t\n");
	printf("=================================================================================================\n");
}
void mengembalikanBukuMahasiswa() {
	system("CLS");
	header();
	printf("%s\t\t\tMengembalikan Buku\n", username);
	printf("=================================================================================================\n");
	printf("Kode Buku\t: \n");
	printf("=================================================================================================\n");
	printf("\tSilahkan Datang Ke Perpustakaan Secara Langsung Untuk Mengembalikan Buku!\t\n");
	printf("=================================================================================================\n");
}
void menyumbangBukuMahasiswa() {
	system("CLS");
	header();
	printf("%s\t\t\Menyumbang Buku\n", username);
	printf("=================================================================================================\n");
	printf("\tPilih Jenis Buku yang Hendak dipinjam\n");
	printf("\t1. TA\n");
	printf("\t2. KP\n");
	printf("\t3. SIP\n");
	printf("\t4. MBKM\n");
	printf("\t5. PAP\n");
	printf("\t6. PEM\n");
	printf("\t7. DB\n");
	printf("\t8. Kembali\n");
	printf("Jenis Buku(TA)\t: \n");
	printf("Kode Buku\t: \n");
	printf("Judul Buku\t: \n");
	printf("Penyusun Buku\t: \n");
	printf("=================================================================================================\n");
	printf("\tSilahkan Datang Ke Perpustakaan Secara Langsung Untuk Menyumbang Buku!\t\n");
	printf("=================================================================================================\n");
}

