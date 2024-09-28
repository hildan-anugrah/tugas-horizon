#include <iostream>
using namespace std;

void menu() {
  cout << "\nTOOLS KELOMPOK 1 \n \n1.Penjumlahan \n2.Mencari Luas persegi panjang \n3.Mencari Rata-rata \n4.Keluar \n \nMasukan Nomer TOOLS yang akan di jalankan :  "; 
}
void penjumlahan() {
    system("clear");
    cout << "\n=================================================== \n";
    cout << "\nTOOLS PENJUMLAHAN KELOMPOK 1 \n";
   int angkapertama;
   cout << "Masukan angka pertama : ";
   cin >> angkapertama;
   int angkakedua;
   cout << "Masukan angka kedua : ";
   cin >> angkakedua;
   int penjumlahan = angkapertama+angkakedua;
   cout << "Masil penjumlahan : "<<penjumlahan;
   cout << "\n\n=================================================== \n";
}

void luas(){
    system("clear");
    cout << "\n=================================================== \n";
    cout << "\nTOOLS MENCARI NILAI LUAS PERSEGI PANJANG KELOMPOK 1\n";
	float panjang, lebar;
	cout << "Masukkan panjang : ";
	cin >> panjang;
	cout << "Masukkan lebar : ";
	cin >> lebar;
	cout << "Luas persegi panjang : " << panjang * lebar << endl;
    cout << "\n\n=================================================== \n";
}

void rata() {
   system("clear");
   cout << "\n=================================================== \n";
   cout << "\nTOOLS MENCARI NILAI RATA-RATA KELOMPOK 1" << endl;
   float satu, dua, tiga, hasil;
   const int jumlahelemen= 3;
   cout << "Masukan angka pertama : ";
   cin >> satu;
   cout << "Masukan angka keDua : ";
   cin >> dua;
   cout << "Masukan angka keTiga : ";
   cin >> tiga;
   hasil = (satu + dua + tiga)/ jumlahelemen;
   cout << "Hasil Rata-rata adalah : "<< hasil << endl;
   cout << "\n=================================================== \n";
    }
int main() {
    int tools;
    do {
       menu();
       cin >> tools;
       switch(tools) 
         {
           case 1:
               penjumlahan();
               break;
           case 2:
               luas();
               break;
           case 3:
               rata();
               break;
	   case 4:
    	   system("clear");  
    	           cout << "\n=================================================== \n";
    	           cout << "TERIMAKASIH TELAH MENGGUNAKAN TOOLS. \n";
	  } 
       } while (tools!=4);
    return 0;
}
