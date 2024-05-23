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

void menuLoginDosen();
void loginDosen();
void signupDosen();
void menuDosen();
void meminjamBukuDosen();
void mengembalikanBukuDosen();
void menyumbangBukuDosen();

void menuLoginMahasiswa();
void loginMahasiswa();
void signupMahasiswa();
void menuMahasiswa();
void meminjamBukuMahasiswa();
void mengembalikanBukuMahasiswa();
void menyumbangBukuMahasiswa();

void menuLoginPengelolaPerpustakaan();
void loginPengelolaPerpustakaan();
void signupPengelolaPerpustakaan();
void menuPengelolaPerpustakaan();
void meminjamBukuPengelolaPerpustakaan();
void mengembalikanBukuPengelolaPerpustakaan();
void menyumbangBukuPengelolaPerpustakaan();
void mengecekDataPeminjamanBuku();

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
		menuLoginDosen();
		break;
	case 2: 
		menuLoginMahasiswa();
		break;
	case 3: 
		menuLoginPengelolaPerpustakaan();
		break;
	default: 
		printf("Anda Salah Memilih Menu!\n"); 
		goto kembali; 
		break;
	}



	return 0;
}

void menuLoginDosen() {
	int pilihAkun;

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

}
void loginDosen() {
	system("CLS");
	header();
	int user = 0;
	int pass = 0;
	char temp[] = "";
	FILE* dataDosen;

	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");

	loginDosenUsername:
	printf("\tNama\t\t: ");
	scanf("%s", username);
	loginDosenPassword:
	printf("\tPassword\t: ");
	scanf("%s", password);

	if (pass == 0 && user == 1){
		if (strcmp(password, temp) == 0){
			menuDosen();
		} else {
			goto loginDosenPassword;
		}
	}

	dataDosen = fopen("data dosen.txt", "a+");
	while (fscanf(dataDosen, "%s\n%d\n%s\n", tambah.nama, &tambah.noWhatsApp, tambah.password) != EOF) {
		user = 0;
		pass = 0;
		if (strcmp(username, tambah.nama) == 0){
			user = 1;
			if (strcmp(password, tambah.password) == 0){
				pass = 1;
				menuDosen();
				break;
			} else {
				pass = 0;
				strcat(temp, tambah.password);
				break;
			}
		} else {
			if (strcmp(password, tambah.password) == 0){
				pass = 2;
				if (user == 1 && pass == 2){
					menuDosen();
				}
				fclose(dataDosen);
				printf("Username atau Pasword Anda Salah!\n");
				goto loginDosenUsername;
				break;
			} else {
				pass = 0;
				break;
			}
			
		}
	}
	if (pass == 0 && user == 1){
		printf("Password Anda Salah!\n");
		goto loginDosenPassword;
	} else if (user == 0 && pass == 0){
		printf("Username dan Pasword Anda Salah!\n");
		goto loginDosenUsername;
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
	printf("\tNomor WhatsApp\t: ");
	scanf("%d", &tambah.noWhatsApp);
	printf("\tPassword\t: ");
	scanf("%s", tambah.password);

	fprintf(dataDosen, "%s\n%d\n%s\n", tambah.nama, tambah.noWhatsApp, tambah.password);

	fclose(dataDosen);

	loginDosen();
}
void menuDosen(){
	int pilihMenuDosen;

	system("CLS");
	printf("\tAnda Berhasil Login!\n");
	header();

	do{
		printf("%s\tMenu Utama\n", username);
		printf("=================================================================================================\n");

		printf("\tApa yang hendak dilakukan?\n");
		printf("\t1. Meminjam Buku\n");
		printf("\t2. Mengembalikan Buku\n");
		printf("\t3. Menyumbang Buku\n");
		printf("\t4. Keluar\n");
		printf("Pilih (1/2/3/4): ");
		scanf("%d", &pilihMenuDosen);
		switch (pilihMenuDosen) {
		case 1:
			meminjamBukuDosen;
			break;
		case 2:
			mengembalikanBukuDosen;
			break;
		case 3:
			menyumbangBukuDosen;
			break;
		case 4:
			printf("Terima Kasih Telah Menggunakan Sistem Ini!\n");
			break;
		default:
			printf("Anda Salah Memilih Menu!\n");
			break;
		}
	}while(pilihMenuDosen != 4);
}
void meminjamBukuDosen(){

}
void mengembalikanBukuDosen(){

}
void menyumbangBukuDosen(){

}

void menuLoginMahasiswa() {
	int pilihAkun;

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

}
void loginMahasiswa() {
	system("CLS");
	header();
	int user = 0;
	int pass = 0;
	char temp[] = "";
	FILE* dataMahasiswa;

	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");

	loginMahasiswaUsername:
	printf("\tNama\t\t: ");
	scanf("%s", username);
	loginMahasiswaPassword:
	printf("\tPassword\t: ");
	scanf("%s", password);

	if (pass == 0 && user == 1){
		if (strcmp(password, temp) == 0){
			menuMahasiswa();
		} else {
			goto loginMahasiswaPassword;
		}
	}

	dataMahasiswa = fopen("data mahasiswa.txt", "a+");
	while (fscanf(dataMahasiswa, "%s\n%d\n%d\n%s\n", tambah.nama, &tambah.NRP, &tambah.noWhatsApp, tambah.password) != EOF) {
		user = 0;
		pass = 0;
		if (strcmp(username, tambah.nama) == 0){
			user = 1;
			if (strcmp(password, tambah.password) == 0){
				pass = 1;
				menuMahasiswa();
				break;
			} else {
				pass = 0;
				strcat(temp, tambah.password);
				break;
			}
		} else {
			if (strcmp(password, tambah.password) == 0){
				pass = 2;
				if (user == 1 && pass == 2){
					menuMahasiswa();
				}
				fclose(dataMahasiswa);
				printf("Username atau Pasword Anda Salah!\n");
				goto loginMahasiswaUsername;
				break;
			} else {
				pass = 0;
				break;
			}
			
		}
	}
	if (pass == 0 && user == 1){
		printf("Password Anda Salah!\n");
		goto loginMahasiswaPassword;
	} else if (user == 0 && pass == 0){
		printf("Username dan Pasword Anda Salah!\n");
		goto loginMahasiswaUsername;
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
void menuMahasiswa(){
	int pilihMenuMahasiswa;

	system("CLS");
	printf("\tAnda Berhasil Login!\n");
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

void menuLoginPengelolaPerpustakaan() {
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
		signupPengelolaPerpustakaan();
		break;
	default:
		printf("Anda Salah Memilih Menu!\n");
		goto kembaliPengelolaPerpustakaan;
		break;
	}

}
void loginPengelolaPerpustakaan() {
	system("CLS");
	header();
	int user = 0;
	int pass = 0;
	char temp[] = "";
	FILE* dataPengelolaPerpustakaan;

	printf("\n=================================================================================================\n");
	printf("\t\t\tHarap Login Terlebih Dahulu!\n");
	printf("=================================================================================================\n");

	loginPengelolaPerpustakaanUsername:
	printf("\tNama\t\t: ");
	scanf("%s", username);
	loginPengelolaPerpustakaanPassword:
	printf("\tPassword\t: ");
	scanf("%s", password);

	if (pass == 0 && user == 1){
		if (strcmp(password, temp) == 0){
			menuPengelolaPerpustakaan();
		} else {
			goto loginPengelolaPerpustakaanPassword;
		}
	}

	dataPengelolaPerpustakaan = fopen("data pengelola perpustakaan.txt", "a+");
	while (fscanf(dataPengelolaPerpustakaan, "%s\n%d\n%s\n", tambah.nama, &tambah.noWhatsApp, tambah.password) != EOF) {
		user = 0;
		pass = 0;
		if (strcmp(username, tambah.nama) == 0){
			user = 1;
			if (strcmp(password, tambah.password) == 0){
				pass = 1;
				menuPengelolaPerpustakaan();
				break;
			} else {
				pass = 0;
				strcat(temp, tambah.password);
				break;
			}
		} else {
			if (strcmp(password, tambah.password) == 0){
				pass = 2;
				if (user == 1 && pass == 2){
					menuPengelolaPerpustakaan();
				}
				fclose(dataPengelolaPerpustakaan);
				printf("Username atau Pasword Anda Salah!\n");
				goto loginPengelolaPerpustakaanUsername;
				break;
			} else {
				pass = 0;
				break;
			}
		}
	}
	if (pass == 0 && user == 1){
		printf("Password Anda Salah!\n");
		goto loginPengelolaPerpustakaanPassword;
	} else if (user == 0 && pass == 0){
		printf("Username dan Pasword Anda Salah!\n");
		goto loginPengelolaPerpustakaanUsername;
	}

	fclose(dataPengelolaPerpustakaan);
}
void signupPengelolaPerpustakaan() {
	system("CLS");
	header();
	FILE* dataPengelolaPerpustakaan;
	dataPengelolaPerpustakaan = fopen("data pengelola perpustakaan.txt", "a+");

	printf("\n=================================================================================================\n");
	printf("\t\t\tSilahkan Isi Terlebih Dahulu!\n");
	printf("=================================================================================================\n");
	printf("\tNama\t\t: ");
	scanf("%s", tambah.nama);
	printf("\tNomor WhatsApp\t: ");
	scanf("%d", &tambah.noWhatsApp);
	printf("\tPassword\t: ");
	scanf("%s", tambah.password);

	fprintf(dataPengelolaPerpustakaan, "%s\n%d\n%s\n", tambah.nama, tambah.noWhatsApp, tambah.password);

	fclose(dataPengelolaPerpustakaan);

	loginPengelolaPerpustakaan();
}
void menuPengelolaPerpustakaan(){
	int pilihMenuPengelolaPerpustakaan;

	system("CLS");
	printf("\tAnda Berhasil Login!\n");
	header();
	
	do {
		printf("%s\t\t\tMenu Utama\n", username);
		printf("=================================================================================================\n");

		printf("\tApa yang hendak dilakukan?\n");
		printf("\t1. Meminjam Buku\n");
		printf("\t2. Mengembalikan Buku\n");
		printf("\t3. Menyumbang Buku\n");
		printf("\t4. Mengecek Data Peminjaman Buku\n");
		printf("\t5. Keluar\n");
		printf("Pilih (1/2/3/4/5): ");
		scanf("%d", &pilihMenuPengelolaPerpustakaan);
		switch (pilihMenuPengelolaPerpustakaan) {
		case 1:
			meminjamBukuPengelolaPerpustakaan();
			break;
		case 2:
			mengembalikanBukuPengelolaPerpustakaan();
			break;
		case 3:
			menyumbangBukuPengelolaPerpustakaan();
			break;
		case 4:
			mengecekDataPeminjamanBuku();
			break;
		case 5:
			printf("Terima Kasih Telah Menggunakan Sistem Ini!\n");
			break;
		default:
			printf("Anda Salah Memilih Menu!\n");
			break;
		}
	} while (pilihMenuPengelolaPerpustakaan != 5);
}
void meminjamBukuPengelolaPerpustakaan(){

}
void mengembalikanBukuPengelolaPerpustakaan(){

}
void menyumbangBukuPengelolaPerpustakaan(){

}
void mengecekDataPeminjamanBuku(){

}
