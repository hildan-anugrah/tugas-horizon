

let javascript = true;
// Ganti dengan kondisi apakah JavaScript dipilih

let python = false; 
// Ganti dengan kondisi apakah Python dipilih

let cpp = false; 
// Ganti dengan kondisi apakah C++ dipilih

let proses = 0;
if (javascript) {
  proses++;
}
if (python) {
  proses++;
}

if (cpp) {
  proses++;
}

if (proses > 1) {
  console.log("Pilihan ganda");
} else if (proses = 1) {
  console.log("anda telah memilih " + proses)
}
else {
  console.log("Pilih minimal satu");
}
