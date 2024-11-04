#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateRandomNumber(int length) {
    string randomNumber;
    for (int i = 0; i < length; ++i) {
        randomNumber += '0' + (rand() % 10); // Menggunakan karakter angka
        // Menambahkan spasi setiap 4 digit, kecuali yang terakhir
        if ((i + 1) % 4 == 0 && (i + 1) != length) {
            randomNumber += ' ';
        }
    }
    return randomNumber;
}
int main(){
	int pembayaran ;
	char is_continue;
	double n = 0.0, i;
	enum option{
		TOKEN_LISTRIK = 1,
		KARTU_KERIDIT,
		TELKOM,
		AIR_PDAM,
		BPJS,
		BACK
	};
	cout << "\n========= MENU PEMBAYARAN =========" << endl;
	cout << "===================================" << endl;
	cout << "1. Token Listrik" << endl;
	cout << "2. Kartu Kredit" << endl;
	cout << "3. Telkom" << endl;
	cout << "4. Air PDAM" << endl;
	cout << "5. BPJS" << endl;
	cout << "6. Kembali\n"
		"===================================" << endl;
	cout << "Pilih menu [1-6]? : ";
	cin >> pembayaran;
	while (pembayaran != BACK)
	{
		switch(pembayaran){
		case TOKEN_LISTRIK:
			srand(static_cast<unsigned int>(time(0)));
    		cout << "Token Listrik Anda : " << generateRandomNumber(20) << endl;
    		return 0;
			break;
		case KARTU_KERIDIT:
			
			break;
		case TELKOM:
			
			break;
		case AIR_PDAM:
			
			break;
		case BPJS:
			
			break;
		default:
			cout << "Pilihan tidak ditemukan" << endl;
			break;
		}
	}
}
