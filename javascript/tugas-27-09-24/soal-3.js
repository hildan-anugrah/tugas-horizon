//Soal 3: Jika pengguna memilih JavaScript dan memiliki akun premium, tampilkan "Akses materi lanjutan". Jika salah satu tidak terpenuhi, tampilkan "Akses ditolak".

const isJavaScriptSelected = true; // Ganti dengan kondisi untuk memeriksa apakah JavaScript dipilih
const hasPremiumAccount = true; // Ganti dengan kondisi untuk memeriksa apakah pengguna memiliki akun premium

if (isJavaScriptSelected && hasPremiumAccount) {
  console.info("Akses materi lanjutan");
} else {
  console.warn("Akses ditolak");
}
