//Soal 3: Jika pengguna memilih JavaScript dan memiliki akun premium, tampilkan "Akses materi lanjutan". Jika salah satu tidak terpenuhi, tampilkan "Akses ditolak".

//Deklarasi variabel
const javaScript = true;
const premium = true; 

//pengecekan premium
if (javaScript && premium) {
  console.info("Akses materi lanjutan");
} else {
  console.warn("Akses ditolak");
}
