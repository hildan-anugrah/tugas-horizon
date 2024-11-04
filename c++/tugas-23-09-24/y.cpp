#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Untuk Windows
#else
    system("clear"); // Untuk Linux/Unix/Mac
#endif
}

string formatCurrency(double amount) {
    ostringstream out;
    out << fixed << setprecision(0) << amount; // Menghilangkan desimal
    string str = out.str();

    // Menambahkan pemisah ribuan
    string formatted;
    int count = 0;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (count > 0 && count % 3 == 0) {
            formatted.insert(0, "."); // Menambahkan pemisah ribuan
        }
        formatted.insert(0, 1, str[i]);
        count++;
    }

    return "Rp" + formatted; // Mengembalikan format yang diinginkan
}

int getOption(int &PIN);

string generateRandomNumber(int length) {
    string randomNumber;
    for (int i = 0; i < length; ++i) {
        randomNumber += '0' + (rand() % 10); // Menghasilkan digit
        if ((i + 1) % 4 == 0 && (i + 1) != length) {
            randomNumber += ' '; // Menambahkan spasi setiap 4 digit
        }
    }
    return randomNumber;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed untuk generasi angka acak

    int pilihan;
    double saldo = 0.0;
    enum option { CEK_SALDO = 1, SETOR_TUNAI, TARIK_TUNAI, PEMBAYARAN, FINISH };

    int PIN = 0; // Inisialisasi PIN
    pilihan = getOption(PIN); // Meminta PIN dan mendapatkan pilihan menu

    if (pilihan == 0) {
        cout << "Akses diblokir. Program akan segera dihentikan." << endl;
        return 0;
    }

    // Loop menu utama
    while (pilihan != FINISH) {
        switch (pilihan) {
            case CEK_SALDO:
                cout << "\n========= CEK SALDO =========\n";
                cout << "\nSALDO ANDA SEKARANG : " << formatCurrency(saldo) << endl;
                break;

            case SETOR_TUNAI: {
                cout << "\n========= SETOR TUNAI =========\n";
                while (true) {
                    double amount;
                    cout << "MASUKAN TUNAI YANG INGIN ANDA SETOR : ";
                    cin >> amount;
                    clearScreen();

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input harus berupa angka.\n";
                        continue;
                    }

                    if (amount > 0) {
                        saldo += amount;
                        cout << "\nTRANSAKSI SETOR TUNAI SUKSES\n";
                        cout << "\nTOTAL SALDO ANDA SEKARANG ADALAH : " << formatCurrency(saldo) << endl;
                    } else {
                        cout << "\nNilai harus lebih dari 0.\n";
                    }

                    char depositLagi;
                    cout << "\nIngin melakukan setor tunai lagi? (y/n) : ";
                    cin >> depositLagi;
                    clearScreen();
                    if (depositLagi == 'n' || depositLagi == 'N') break;
                }
                break;
            }

            case TARIK_TUNAI: {
                cout << "\n========= TARIK TUNAI =========\n";
                while (true) {
                    double amount;
                    cout << "MASUKAN NOMINAL YANG INGIN ANDA TARIK : ";
                    cin >> amount;
                    clearScreen();

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input harus berupa angka.\n";
                        continue;
                    }

                    if (amount > 0) {
                        if (saldo >= amount) {
                            saldo -= amount;
                            cout << "\nBERHASIL TARIK TUNAI\n";
                            cout << "\nTOTAL SALDO ANDA SEKARANG ADALAH : " << formatCurrency(saldo) << endl;
                        } else {
                            cout << "\nSALDO ANDA TIDAK CUKUP.\n";
                        }
                    } else {
                        cout << "\nNilai harus lebih dari 0.\n";
                    }

                    char tarikTunaiLagi;
                    cout << "\nIngin melakukan tarik tunai lagi? (y/n) : ";
                    cin >> tarikTunaiLagi;
                    if (tarikTunaiLagi == 'n' || tarikTunaiLagi == 'N') break;
                }
                break;
            }

            case PEMBAYARAN: {
                int pembayaran;
                cout << "\n========= MENU PEMBAYARAN =========" << endl;
                cout << "1. Token Listrik" << endl;
                cout << "2. Kartu Kredit" << endl;
                cout << "3. Telkom" << endl;
                cout << "4. Air PDAM" << endl;
                cout << "5. BPJS" << endl;
                cout << "6. Kembali\n";
                cout << "Pilih menu [1-6]? : ";
                cin >> pembayaran;

                while (pembayaran != 6) { // 6 adalah BACK
                    switch (pembayaran) {
                        case 1:
                            cout << "Token Listrik Anda : " << generateRandomNumber(20) << endl;
                            break;
                        case 2:
                            // Logika untuk Kartu Kredit
                            break;
                        case 3:
                            // Logika untuk Telkom
                            break;
                        case 4:
                            // Logika untuk Air PDAM
                            break;
                        case 5:
                            // Logika untuk BPJS
                            break;
                        default:
                            cout << "Pilihan tidak ditemukan" << endl;
                            break;
                    }
                    cout << "Pilih menu [1-6]? : ";
                    cin >> pembayaran;
                }
                break;
            }

            default:
                cout << "Pilihan tidak ditemukan" << endl;
                break;
        }

        // Lanjutkan atau keluar dari transaksi
        char is_continue;
        cout << "\nIngin melakukan transaksi lain? (y/n) : ";
        cin >> is_continue;
        clearScreen();
        if (is_continue == 'y' || is_continue == 'Y') {
            pilihan = getOption(PIN);
        } else {
            break;
        }
    }

    cout << "Terimakasih telah menggunakan ATM CENTER" << endl;
    return 0;
}

int getOption(int &PIN) {
    const int myPIN = 223311;
    int input;
    int attemptCount = 0;

    // Meminta PIN
    if (PIN == 0) {
        cout << "========= SELAMAT DATANG DI ATM CENTER =========\n";
        while (attemptCount < 3) {
            cout << "SILAHKAN MASUKKAN PIN ANDA : ";
            string pinInput;
            cin >> pinInput;

            clearScreen();

            if (pinInput.length() != 6 || !all_of(pinInput.begin(), pinInput.end(), ::isdigit)) {
                cout << "Input PIN tidak valid." << endl;
                continue;
            }

            PIN = stoi(pinInput);

            // Cek PIN
            if (PIN != myPIN) {
                attemptCount++;
                cout << "\nPIN ANDA SALAH! Percobaan ke- " << attemptCount << endl;
                if (attemptCount >= 3) {
                    cout << "\nPIN ANDA DI BLOKIR\n";
                    return 0;
                }
            } else {
                break;
            }
        }
    }

    // Menu opsi
    cout << "\n========= MENU ATM =========" << endl;
    cout << "=============================" << endl;
    cout << "1. Cek Saldo" << endl;
    cout << "2. Setor Tunai" << endl;
    cout << "3. Tarik Tunai" << endl;
    cout << "4. Pembayaran" << endl;
    cout << "5. Keluar" << endl;
    cout << "=============================" << endl;
    cout << "Pilih menu [1-5]? : ";

    cin >> input;
    clearScreen();
    return input;
}
