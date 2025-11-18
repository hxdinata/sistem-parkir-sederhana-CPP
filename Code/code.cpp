#include <iostream>                                 // Library untuk input/output standar C++
#include <cstring>                                  // Library untuk manipulasi string C seperti strcpy, strncpy
#include <ctime>                                    // Library untuk penggunaan waktu (time, ctime)

using namespace std;                                // Menggunakan namespace std, agar tidak perlu menulis std:: setiap akses fungsi/objek standar

// Definisi struktur data untuk transaksi parkir
struct Trx {
    int type, lama, biaya;     // type: jenis kendaraan, lama: jam parkir, biaya: biaya parkir
    char plat[20];             // plat: plat nomor kendaraan, maksimal 19 karakter + '\0'
    char tgl_masuk[30];        // tgl_masuk: tanggal dan waktu masuk sebagai string
};

int main() {
    Trx trx[100];         // Array untuk menyimpan max 100 data transaksi
    int m = -1;           // Index transaksi terakhir (-1 artinya belum ada data)
    char yn;              // Untuk menampung jawaban user (y/n) pada input "tambah data lagi"

    // === LOGIN SEDERHANA ===
    do {
        string user, pass;                               // Variabel untuk username dan password input
        cout << "==== LOGIN SISTEM PARKIR ====\n";
        cout << "Username: "; cin >> user;               // Input username
        cout << "Password: "; cin >> pass;               // Input password
        if (user != "admin" || pass != "123") {          // Cek user & pass
            cout << "Login gagal! Coba lagi.\n";
        } else {
            cout << "Login berhasil!\n\n";
            break;                                       // Keluar dari loop jika benar
        }
    } while (true);                                      // Ulangi login jika gagal

    // === MENU UTAMA ===
    do {
        int pil;                                         // Pilihan menu
        cout << "=== SISTEM PARKIR ===\n";
        cout << "1. Transaksi\n2. Laporan\n3. Exit\nPilih menu: ";
        cin >> pil;                                      // Input menu

        if (pil == 1) {                                  // Menu 1: Transaksi
            m++;                                         // Naikkan nomor index transaksi
            cout << "Plat nomor       : "; cin >> trx[m].plat;  // Input plat kendaraan
            cout << "Tipe kendaraan (1=motor/2=mobil): "; cin >> trx[m].type; // Input tipe
            cout << "Lama parkir (jam): "; cin >> trx[m].lama;  // Input durasi jam parkir

            time_t waktu = time(nullptr); // Ambil waktu saat ini (detik sejak epoch)
            // Salin string waktu (ctime) ke tgl_masuk, atur batas agar tidak overflow buffer
            strncpy(trx[m].tgl_masuk, ctime(&waktu), sizeof(trx[m].tgl_masuk)-1);
            trx[m].tgl_masuk[sizeof(trx[m].tgl_masuk)-1] = '\0'; // Pastikan null-terminated

            // Hitung biaya sesuai tipe & lama parkir
            if (trx[m].type == 1) {       // Jika motor
                trx[m].biaya = (trx[m].lama < 6) ? trx[m].lama * 2000 : 12000;
            } else if (trx[m].type == 2) {// Jika mobil
                trx[m].biaya = (trx[m].lama < 6) ? trx[m].lama * 4000 : 24000;
            } else {
                trx[m].biaya = 0;         // Tipe salah, biaya jadi nol
            }

            // Cetak struk
            cout << "\n==== STRUK PARKIR ====\n";
            cout << "Plat   : " << trx[m].plat << endl;
            cout << "Tipe   : " << (trx[m].type == 1 ? "Motor" : "Mobil") << endl;
            cout << "Lama   : " << trx[m].lama << " jam\n";
            cout << "Biaya  : Rp " << trx[m].biaya << endl;
            cout << "Tanggal: " << trx[m].tgl_masuk; // Sudah bernilai \n di akhir
            cout << "======================\n";
            cout << "Tambah data lagi (y/n)? "; cin >> yn; // Input ingin tambah lagi atau tidak
        }
        else if (pil == 2) {              // Menu 2: Laporan
            int total = 0;                // Untuk menampung total seluruh pendapatan
            cout << "\n======= LAPORAN =======\n";
            // Cetak data transaksi satu per satu
            for (int i = 0; i <= m; i++) {
                cout << i+1 << ". ";
                cout << trx[i].plat << ", "                                 // Plat nomor
                     << (trx[i].type == 1 ? "Motor" : "Mobil") << ", "      // Tipe kendaraan
                     << trx[i].lama << " jam, Rp " << trx[i].biaya << ", "  // Jam dan biaya
                     << trx[i].tgl_masuk;                                   // Tanggal masuk
                total += trx[i].biaya;                                      // Total biaya
            }
            cout << "\nTotal Pendapatan: Rp " << total << endl;
            cout << "======================\n";
            cout << "Kembali ke menu utama (tekan apa saja)...\n";
            cin.ignore(); cin.get();   // Tunggu Enter dari user agar bisa baca laporan dulu
        }
        else if (pil == 3) {           // Menu 3: Exit/Keluar
            cout << "Terima kasih! Keluar dari program.\n";
            break;                     // Akhiri loop utama dan program selesai
        }
        else {                         // Input menu invalid
            cout << "Menu tidak valid. Silakan ulangi.\n";
        }

    } while (true);                    // Ulangi terus sampai user memilih exit

    return 0;                          // Program selesai, keluar dengan sukses
}
