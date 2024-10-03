let javascript = true;
// Ganti dengan kondisi apakah JavaScript dipilih

let python = true; 
// Ganti dengan kondisi apakah Python dipilih

let cpp = false; 
// Ganti dengan kondisi apakah C++ dipilih

let languageCount = 0;
if (javascript) {
  proses++;
}
if (pythonSelected) {
  proses++;
}

if (cpp) {
  proses++;
}

if (proses > 1) {
  console.log("Pilihan ganda");
} else {
  console.log("Pilih minimal satu");
}
