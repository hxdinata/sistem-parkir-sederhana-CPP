Sistem Parkir Sederhana (C++)

Deskripsi

    Proyek ini adalah implementasi sederhana sistem parkir berbasis C++ dengan antarmuka menu terminal. Cocok untuk latihan struktur data, pengelolaan antrian, dan dasar logika bisnis aplikasi parkir.

Fitur

    Menambahkan kendaraan masuk
    Mengeluarkan kendaraan saat keluar
    Menampilkan daftar kendaraan saat ini
    Menghitung/menampilkan total pendapatan (opsional)
    Penyimpanan data sementara selama program berjalan

Persyaratan

    Compiler C++ modern (g++ 7+ / clang++ / MSVC)
    Sistem operasi: Linux, macOS, atau Windows (MinGW / Visual Studio)

Cara build dan menjalankan

    Linux / macOS:
        Buka terminal di root repo.
        Compile (contoh jika semua file sumber ada di folder Code/): g++ Code/*.cpp -o sistem_parkir -std=c++17
        Jalankan: ./sistem_parkir

    Windows (MinGW):
        Buka Command Prompt atau PowerShell.
        Compile: g++ Code\*.cpp -o sistem_parkir.exe -std=c++17
        Jalankan: .\sistem_parkir.exe

Struktur direktori (contoh)

    Code/ — kode sumber utama (.cpp / .h)
    README.md — dokumentasi (file ini)
    LICENSE — lisensi (opsional)

Contoh penggunaan

    Program berjalan di terminal dan menampilkan menu interaktif.
    Pilih opsi untuk mendaftarkan kendaraan masuk (nomor plat, waktu masuk).
    Saat kendaraan keluar, pilih opsi keluarkan dengan memasukkan identitas/nomor plat; program menghitung durasi dan tarif (jika diimplementasikan).
    Lihat laporan/daftar kendaraan aktif melalui opsi menu.

Tips pengembangan

    Simpan data kendaraan menggunakan struct/class (nomor plat, waktu masuk, slot).
    Gunakan vector atau map untuk menyimpan daftar kendaraan.
    Untuk perhitungan waktu, gunakan tipe waktu standar (chrono) atau simulasikan waktu untuk pengujian.
    Tambahkan validasi input dan penanganan error sederhana.

Kontribusi

    Terima kontribusi berupa perbaikan kode, fitur baru, dokumentasi, atau perbaikan bug.
    Silakan buat issue untuk membahas perubahan besar sebelum mengirim pull request.

Lisensi

    Cantumkan lisensi yang diinginkan (mis. MIT). Jika tidak ada, tambahkan file LICENSE sesuai pilihan.

Kontak

    Untuk pertanyaan, saran, atau kontribusi, buka issue atau hubungi pemilik repo: @hxdinata
