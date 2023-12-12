#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
struct akun {
 char id[25];
 int pass;
 int keberapa;
 int saldo;
};
struct Spek{
 int jmlSpekun;
 char nama[15];
};

void daftar(int jumlah, struct akun* );
void mainmenu(struct akun*);
void helpdesk(void);
void delay(int seconds);
void topup(int *saldo);
void ojek(int *saldo);
void spekun(int *saldo);
void displaySpekun(struct Spek spot[7]);
void kereta(void);
void displaykereta (int tujuan);
void bikun(void);
void jumlahbikun(void);
int main(void) {
struct akun *pUser;
 int jumlah = 0;
 int input;
 char inputS[25];
 int yesorno = 0;
 int currentuser;
 int i;

 printf("Selamat datang di TransUI !\n");
 //allocate memory for first account
 pUser = (struct akun*) calloc (1, sizeof(struct akun));
 if (pUser == NULL)
 printf("\nMemory allocation failed");

 //while loop agar ngeloop selamanya sampai user memilih input 3 (program end)
 while (1 > 0){
 printf("\n======================== INISIALISASI ========================");
 printf("\n\nMasukkan angka dari opsi yang diinginkan :\n1. Login\n2. Register\n3.Exit program\n\n> ");
 scanf("%d", &input);
 switch (input){
 case 1:
 //meminta input ID dan password dari user untuk login
 yesorno = 0;
 printf("\n\nMasukkan ID: ");
 scanf("%s", inputS);
 printf("Masukkan password: ");
 scanf("%d", &input);
 //mengecek terdapat pasangan ID dan password yang sama dalam akun-akun yang sudahterdaftar
 for (i = 0; i < jumlah; i++){
 if (strcmp(inputS, (pUser + i)->id) == 0 && input == (pUser + i)->pass){
 //jika iya, maka akun keberapanya akan disimpan dalam variabel currentuser dan diteruskan ke mainmenu
yesorno = 1;
 currentuser = i;
 }
 }
 if (yesorno == 1){
 mainmenu(pUser + currentuser);
 } else
 printf("\nID atau password salah");
 break;
 case 2:
 //saat ingin menambahkan akun, jumlah akun total juga bertambah dan pUser bertambah besar memorinya
 jumlah++;
 pUser = realloc (pUser, sizeof(struct akun) * (jumlah + 1));
 daftar(jumlah-1, pUser);
 break;
 case 3:
 printf("\nProgram ended");
 //setelah program selesai, pointer dibebaskan
 free(pUser);
 return 0;
 default:
 printf("\nInput invalid");
 }
 }
}

void daftar(int jumlah, struct akun* pUser ){
 //memasukkan informasi mengenai akun yang sedang didaftarkan
 printf("\n======================= REGISTER ============================");
 printf("\n\nMasukkan ID (no space / max. 25 character): ");
 scanf("%s", (pUser + jumlah)->id);
 printf("Masukkan password (angka): ");
 scanf("%d", &(pUser + jumlah)->pass);
 (pUser + jumlah)->keberapa = jumlah;
 (pUser + jumlah)->saldo = 0;
}
void mainmenu(struct akun* pUser){
 int input = 0;
 while (input != 7) {
 printf("\n\n========================= MAIN MENU =========================");
 //print ID dari akun yang sudah login
 printf("\n\nSelamat datang, %s", (pUser)->id);
 //print opsi main menu
 printf ("\n\nMasukkan angka dari opsi yang diinginkan :\n1. BiKun\n2. SpeKun\n3.KRL\n4. Ojek Online\n\n5. Helpdesk");
 printf("\n6. Topup Saldo\n7. Log out\n\n> ");
 scanf ("%d", &input);

 if (input == 1){
 bikun();
 } else if (input == 2){
 spekun(&(pUser)->saldo);
 } else if (input == 3){
 kereta();
 } else if (input == 4){
 ojek(&(pUser)->saldo);
 } else if (input == 5){
 helpdesk();
 } else if (input == 6){
 topup(&(pUser)->saldo);
 } else if (input == 7){
 break;
 } else
 printf("\nInvalid input!");
 }
}

void topup(int *saldo){
 int input;
 //mengisi ulang saldo menggunakan passing by reference
 printf("\n=========================== TOPUP SALDO =========================");
 printf("\n\nSaldo awal: Rp. %d", *saldo);
 printf("\nJumlah yang ingin ditopup: ");
 scanf("%d", &input);
 *saldo += input;
 printf("\nSaldo akhir: Rp. %d", *saldo);
}
void helpdesk(void){
 int pilihan = 0;
 char temp;
 printf("\n=========================== HELPDESK =========================");
 printf("\n\nProgram TransUI ini berfungsi untuk memudahkan mahasiswa UI bepergian di dalam ruang lingkup UI");
 while (pilihan != 3){
 //print pilihan menu
 printf("\n\nPilih bagian yang dibingungkan: ");
 printf("\n1) Inisialisasi ");
 printf("\n2) Main menu ");
 printf("\n3) Kembali ke main menu\n\n> ");
 scanf("%d", &pilihan);

 if (pilihan == 1){
 printf("\nInisialisasi:");
 printf("\nPada tahap ini, user diberikan 3 pilihan: login, register, end program ");
 printf("\n - Untuk masuk ke program inti, user harus login dengan memasukkan ID 0dan password akunnya");
 printf("\n - Jika belum memiliki akun, user dapat daftar dengan memilih register");
 printf("\n - Untuk mengakhiri program, user dapat memilih exit program");
 printf("\n\nPress any key to continue . . . ");
 scanf(" %c", &temp);
 } else if (pilihan == 2){
 printf("\nMain Menu: ");
 printf("\nPada tahap ini, user diberikan 4 pilihan mode transportasi: kereta, bikun, spekun, ojol");
 printf("\nUser juga diberikan opsi untuk top-up saldo yang dapat digunakan untuk membayar ojol dan opsi kembali ke inisialisasi");
 printf("\n - Kereta: menampilkan jadwal kereta untuk stasiun UI");
 printf("\n - Bikun: menampilkan jadwal bikun (bis kuning) pada setiap halte");
 printf("\n - Spekun: menampilkan ketersediaan spekun (sepeda kuning) pada setiap lokasi ");
 printf("dan opsi untuk meminjam/mengembalikan sepeda");
 printf("\n - Ojol: memesan ojek online dengan memilih pick-up location dan destination (berbayar)");
 printf("\n\nPress any key to continue . . . ");
 scanf(" %c", &temp);
 } else if (pilihan == 3){
 break;
 } else if (pilihan != 1 && pilihan != 2 && pilihan != 3)
 printf("\nInput tidak valid");
 }
}
void ojek(int *saldo){
 int input = 0;
 int input2 = 0;
 int pickup, destination;
 char temp;
 float harga;
 while (input != 2){
 printf("\n=========================== OJEK ONLINE =========================");
 printf("\n\nSaldo anda adalah: Rp. %d", *saldo);
 printf("\nJika ingin isi ulang, silakan kembali ke main-menu dan pilih opsi topup");
 //menampilkan menu dari function ojek online
 printf("\n\n1) Pesan Ojol");
 printf("\n2) Main menu\n\n> ");
 scanf("%d", &input);

 if (input == 1){
 //array yang berfungsi untuk perhitungan harga, anggap elemen pertama adalah semacam kilometer 0 seperti dalam jalan tol
 float jarak[9] = {0, 1.75, 2.25, 4.5, 7, 9.25, 12, 14, 16.25 };

 printf("\n\nTitik-titik ojek yang sudah ditentukan:");
 printf("\n1. Stasiun UI\n2. FH \n3. Masjid\n4. Balairung UI\n5. RS UI");
 printf("\n6. FMIPA\n7. Perpus UI\n8. Stadion\n9. FT/FEB");
 printf("\n\nKetik lokasi pick-up anda\n> ");
 scanf("%d", &pickup);
 printf("Ketik destinasi anda\n> ");
 scanf("%d", &destination);
 //function delay agar mendapatkan sensasi loading
 delay(3);
 //perhitungan harga adalah dengan mencari jarak antara lokasi pickup dan destinasi kemudian dikali dengan 1000
 harga = fabsf(jarak[pickup-1] - jarak[destination-1]) * 1000;
 printf("Harganya adalah Rp. %.2f", harga );

 //kalau saldonya tidak cukup, akan diminta untuk memilih antara topup atau kembali ke menu
 while (*saldo < harga){
 printf("\nSaldo anda tidak cukup!");
 printf("\n1. Topup\n2. Kembali\n\n> ");
 scanf("%d", &input2);
 if (input2 == 1)
 topup(saldo);
 else if (input2 == 2)
 break;
 else if (input2 != 1 && input2 != 2)
 printf("\nInvalid input!");
 }
 //kalau saldonya cukup, akan langsung menemukan driver
 if (*saldo > harga){
 printf("\nDriver ditemukan! ");
 *saldo -= harga;
 printf("\nSaldo anda sekarang adalah Rp. %d! Silakan menunggu di lokasi pickup",
*saldo);
 printf("\n\nPress any key to continue . . . ");
 scanf(" %c", &temp);
 }
 } else if (input != 1 && input != 2)
 printf("\nInvalid input!");
 }
}
void delay(int seconds){
 //function berfungsi untuk memberikan sensasi loading
 int millis = 1000 * seconds;
 clock_t start_time = clock();
 while (clock() < start_time + millis) ;
}
void spekun(int *saldo){
 int i, input, input2, input3;

 struct Spek spot[7];
 //Pemberian nama untuk masing-masing spot
 strcpy(spot[0].nama,"Stasiun UI ");
 strcpy(spot[1].nama,"Stasiun Pocin");
 strcpy(spot[2].nama,"Perpustakaan ");
 strcpy(spot[3].nama,"FKM ");
 strcpy(spot[4].nama,"FIB ");
 strcpy(spot[5].nama,"FMIPA ");
 strcpy(spot[6].nama,"FTeknik ");

 //randomisasi jumlah spekun pada setiap spot antara 0 - 20
 for (i = 0; i < 7; i++){
 spot[i].jmlSpekun = (rand() % (21));
 }
 //judul spekun
 printf("\n\n============================== SPEKUN ===========================");

 do{//menggunakan while loop agar program dapat berulang dengan sentinel 3 untuk exit
 displaySpekun(spot);//function yang akan menampilkan list nama-nama spot dan jumlah spekun pada spot
 printf("\n1. Meminjam");
 printf("\n2. Mengembalikan");
 printf("\n3. Exit");
 do{//menggunakan while untuk error handling jika user memasukkan input selain 1/2/3
 printf("\n\nPilih operasi yang ingin dilakukan : ");
 scanf("%d", &input);
 switch(input){
 case 1 :
 do{
 //menggunakan for loop dan if untuk mengecek apakah ada spot yang kosong agar user tidak bisa memilih spot tersebut
 for (i = 0; i < 7; i++){
 if(spot[i].jmlSpekun < 0) {
 spot[i].jmlSpekun++;//jumlah diincrement kembali agar tidak menampilkan jumlah minus
 printf("Spekun di spot yang anda pilih sudah habis, silahkan memilih spot lain\n\n");
 }
 }
 //mengecek jika semua spot sudah kosong agar user sudah tidak bisa meminjam lagi dan mengeluarkan dari loop
 if (spot[0].jmlSpekun == 0 && spot[1].jmlSpekun == 0 && spot[2].jmlSpekun == 0 &&
 spot[3].jmlSpekun == 0 && spot[4].jmlSpekun == 0 && spot[5].jmlSpekun == 0 &&
 spot[6].jmlSpekun == 0){
 printf("Tidak ada spekun yang tersedia");
 break;
 }
 printf("Pilih spot peminjaman : ");
 scanf("%d", &input2);

 while (*saldo < 5000){//menggunakan while agar jika saldo tidak mencukupi maka user harus topup
 printf("\n\nSaldo anda sebanyak Rp. %d", *saldo);
 printf("\nSaldo anda tidak mencukupi!");
 printf("\n1. Topup\n2. Kembali\n\n> ");
 scanf("%d", &input3);
 if (input3 == 1)
 topup(saldo);//menjalankan function topup untuk menambah saldo
 else if (input3 == 2)
 break;//akan keluar dari loop
 }
 if (*saldo > 5000){//jika saldo mencukupi maka peminjaman akan berjalan
 spot[input2-1].jmlSpekun--;//jumlah spekun pada spot yang dipilih akan dikurangi
 *saldo -= 5000;//saldo akan dipotong sebanyak 5000
 }
 if(input2 < 1 || input2 > 7)//Jika input yang dimasukkan bukan antara 1-7 maka akan menampilkan warning
 printf("Pilihan anda tidak tersedia\n");
 //error handling jika input tidak di antara 1-7 dan jika jika spekun spot yang dipilih sudah habis
 } while ( input2 < 1 || input2 > 7 || spot[0].jmlSpekun < 0 ||
spot[1].jmlSpekun < 0||spot[2].jmlSpekun < 0|| spot[3].jmlSpekun < 0 | spot[4].jmlSpekun
< 0||spot[5].jmlSpekun < 0||
 spot[6].jmlSpekun < 0 );
 break;
 case 2 :
 	
 do{
 //menggunakan for loop dan if untuk mengecek apakah ada spot yang penuh agar user tidak bisa memilih spot tersebut
 for (i = 0; i < 7; i++)
 if(spot[i].jmlSpekun > 20){
 spot[i].jmlSpekun--;
printf("Parkiran spekun di spot yang anda pilih sudah penuh, silahkanmengembalikan di spot lain\n\n");
 }
 //mengecek jika semua spot sudah penuh (max 20) agar user sudah tidak bisa mengembalikan lagi dan mengeluarkan dari loop
 if (spot[0].jmlSpekun == 20 && spot[1].jmlSpekun == 20 && spot[2].jmlSpekun
== 20 &&
 spot[3].jmlSpekun == 20 && spot[4].jmlSpekun == 20 && spot[5].jmlSpekun
== 20 &&
 spot[6].jmlSpekun == 20){
 printf("Parkiran spekun pada semua spot sudah terisi penuh\n"); break;
 }
 printf("Pilih spot pengembalian (Maksimal spekun pada 1 spot adalah 20) :");
 scanf("%d", &input2);
 spot[input2-1].jmlSpekun++;//jumlah spekun pada spot yang dipilih akan bertambah
 if(input2 < 1 || input2 > 7)//error handling jika input tidak di antara 1-7
 printf("Pilihan anda tidak tersedia\n");
 //error handling jika spot sudah penuh
 } while ( input2 < 1 || input2 > 7 || spot[0].jmlSpekun > 20 ||
spot[1].jmlSpekun > 20||spot[2].jmlSpekun > 20|| spot[3].jmlSpekun > 20 ||
spot[4].jmlSpekun > 20||spot[5].jmlSpekun > 20|| spot[6].jmlSpekun > 20 );
 break;
 case 3:
 break;//keluar dari menu spekun
 default : printf("Pilihan anda tidak tersedia\n");
 }
 } while (input < 1 || input > 3);
 if (input == 1){//jika melakukan peminjaman maka akan menampilkan sisa saldo
 printf("\nSaldo anda tersisa Rp %d\n", *saldo);
 }

 } while (input != 3);
}
void displaySpekun(struct Spek spot[7]){
 int i;
 char temp;
 printf("\n\nNo. Lokasi Jumlah\n");//menampilkan indeks tabel
 for (i = 0; i < 7; i++){
 //menampilkan nama dan jumlah spekun dari masing-masing spot
 printf("%d. %s : %d\tsepeda\n", i+1, spot[i].nama, spot[i].jmlSpekun);
 }
 printf("\nPress any key to continue . . . ");//sebagai delay agar program tidak langsung dilanjutkan, user perlu memasukkan input apapun untuk melanjutkan program
 scanf(" %c", &temp);
}
void kereta(void){
 int pilihan = 0;
 int tujuan;
 printf("\n\n========================== KERETA ===========================\n\n");
 printf ("JADWAL KRL COMMUTER LINE JABODETABEK\n");//header menu kereta
 while (pilihan != 3){
 printf ("\nMasukkan tujuan anda: \n\n");
 printf ("1. Jakarta Kota\n2. Bogor\n\nAtau:\n3. Main Menu\n\n> ");
 scanf ("%d", &pilihan); //meminta user input
 if (pilihan == 1) {//jika user input = 1
 printf ("\nJadwal KRL tujuan Jakarta Kota\n-------------------------------\n");
 tujuan = 1; //set variabel tujuan = 1
 displaykereta(tujuan);//memanggil func displaykereta
 }

 else if (pilihan == 2) {//jika user input =2
 printf ("\nJadwal KRL tujuan Bogor\n-------------------------------\n");
 tujuan = 2;//set variabel tujuan = 2
 displaykereta(tujuan);//memanggil func displaykereta
 }
 else if (pilihan != 1 && pilihan != 2 && pilihan != 3) {
 printf ("Input tidak valid!"); //error message jika input tidak valid
 }
 }
}
void displaykereta(int tujuan) {
 char temp;
 int hour [19] = {4, 5, 6, 7, 8, 9, 10, 11, 12,13, 14, 15, 16, 17, 18, 19, 20, 21, 22};
 int stamformasi [3] = {8, 10, 12};
 int i;
 int minute [9] = {10, 15, 20, 25, 33, 38, 45, 50, 57};
 int minute2 [9] = {12, 18, 24, 30, 35, 39, 48, 53, 55};
 int jumlahkereta = 19;
 printf ("\nJam Kedatangan\t\tStamformasi");//header timetable kedatangan kereta
 if (tujuan == 1){ //jika variabel tujuan = 1
 for (i = 0; i < jumlahkereta; i++){
 printf("\n%6d.%d", hour[i], minute[rand()%9]);//print jam dan menit
 printf ("\t\t%6d", stamformasi [rand()%3]);//print rangkaian / stamformasi
 }
 } else if (tujuan == 2) {//jika variabel tujuan = 2
 for (i = 0; i < jumlahkereta; i++){
 printf("\n%6d.%d", hour[i], minute2[rand()%9]);//print jam dan menit
 printf ("\t\t%6d", stamformasi [rand()%3]);
 }//print rangkaian / stamformasi
 }
 printf ("\n\nPress any key to continue . . . ");
 scanf(" %c", &temp);
}
void bikun(void){
 int loc;
 int input;

 printf("\n========================== BIKUN ===========================");//judul bikun

 while(input != 2){
 do{//main menu dari bikun
 printf("\n\n1. Jadwal Bikun\n2. Main Menu\n\n> ");
 scanf("%d", &input);//mengscan pilihan user
 if (input < 1 || input > 2)
 printf("\nInput tidak valid!");//apabila input selain 1 dan 2
 } while (input < 1 || input > 2);

 if (input == 1){
 do {
 printf("\nMasukkan lokasi Anda\n");
 printf("\n1. Stasiun UI\n2. FT\n3. Fasilkom\n4. FK\n5. FH\n\n> ");
 scanf("%d", &loc);//program akan meminta user untuk memasukkan lokasi
 if (loc < 1 || loc > 5)
 printf("\nInput tidak valid!");//apabila user menginput diluar 1-5 maka akan diprint input tidak valid dan kembali ke menu pilihan
 } while (loc < 1 || loc > 5);//program akan print lokasi yang use pilih dan melanjutkannya ke function jumlahbikun
 if (loc == 1)
 printf("\nJadwal kedatangan Bikun di Stasiun UI");
 else if (loc == 2)
 printf("\nJadwal kedatangan Bikun di FT");
 else if (loc == 3)
 printf("\nJadwal kedatangan Bikun di Fasilkom");
 else if (loc == 4)
 printf("\nJadwal kedatangan Bikun di FK");
 else if (loc == 5)

 printf("\nJadwal kedatangan Bikun di FH");

 jumlahbikun();
 }
 }
}
void jumlahbikun(){
 int i, j;
 char temp;
 srand(time(NULL));
 int berapalamalagi[6];
 int jumlahbikun = rand()%6;

 printf("\n\nTerdapat %d Bikun menuju tempat Anda:", jumlahbikun);//header dari jumlah dan waktu bikun yang akan sampai kepada user

 for (i = 0; i < jumlahbikun; i++){
 berapalamalagi[i] = rand()%20;//akan merandom waktu bikun yang akan sampai pada user
 }
 //algoritma penyortir agar menit jumlahbikun dimulai dari menit terkecil ke menit terbesar
 for (i = 0; i < jumlahbikun; i++){
 for (j = i + 1; j < jumlahbikun; j++){
 if (berapalamalagi[i] > berapalamalagi[j]){
 temp = berapalamalagi[i];
 berapalamalagi[i] = berapalamalagi[j];
 berapalamalagi[j] = temp;
 }
 }
 }
 for(i = 0; i < jumlahbikun; i++){
 printf("\n - Bikun %d akan sampai dalam %d menit", i + 1, berapalamalagi[i]);
 }
 printf ("\n\nPress any key to continue . . . ");
 scanf(" %c", &temp);//delay program jadi tidak langsung pindah dan memberi jeda pada program
}
