//Deklarasi variabel
let javascript = false;
let python = false; 
let cpp = false; 
let proses = 0;

//Logika untuk menghitung pilihan
if (javascript) {
  proses++;
}if (python) {
  proses++;
}if (cpp) {
  proses++;
}

//pengecekan berapa banyak yang di pilih
if (proses > 1) {
  console.log("Pilihan ganda");
} else if (proses == 1) {
  console.log("anda telah memilih " + proses)
}else {
  console.warn("Pilih minimal satu");
}