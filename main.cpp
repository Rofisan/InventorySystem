#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector <vector<string>> items{{"knive", "2"}, {"sword", "8"}, {"mace", "5"}};
    vector <vector<string>> inventory;
    vector <vector<string>>::iterator iter1;
    vector <string>::iterator iter2;

    unsigned int maksInventory = 0;
    long int maksItem = items.size();
    unsigned int pilihan = 0;
    unsigned int itemTerpilih = 0;
    unsigned int jumlahInventory = 0;
    unsigned int hapus = 0;
    char lagi = 'y';

    cout << "Jumlah item tersedia: " << maksItem << endl;
    cout << "Kapasitas maksimaliInventory: "; cin >> maksInventory; cout << endl;

    while (lagi == 'y'){
        hapus = 0;

        cout << "System Inventory" << endl;
        cout << "1. Tampilkan inventory" <<endl;
        cout << "2. Hapus item" << endl;
        cout << "3. Tambah item" << endl;
        cout << "Pilihan anda: "; cin >> pilihan; cout << endl;

        switch(pilihan){
            case 1: {
                if(inventory.empty()){
                    cout << "Inventory Kosong !" << endl << endl;
                }else{
                    cout << "Isi inventory: " << endl;
                    for(iter1 = inventory.begin(); iter1 != inventory.end(); ++iter1){
                        for(iter2 = iter1->begin(); iter2 != iter1->end(); iter2++){
                            cout << *iter2 << " ";
                        }
                        cout << endl;
                    }
                 cout << endl;
                }
            break;
            }
            case 2: {
                if(jumlahInventory <= 0){
                    cout << "Anda belum memiliki item !" << endl;
                }else{
                    cout << "Hapus item ke-: "; cin >> hapus;
                    if(hapus > jumlahInventory){
                        cout << "Item yang akan di hapus tidak ada" << endl;
                    }else{{
                        inventory.erase(inventory.begin() + (hapus - 1));
                        jumlahInventory--;
                        cout << "Jumlah inventory sekarang: " << jumlahInventory << endl << endl;
                    }
                }
            }
            break;
            }
            case 3: {
                if(jumlahInventory >= maksInventory){
                    cout << "Inventory penuh !" << endl;
                }else{
                    srand((unsigned)time(0));
                    itemTerpilih = (rand() % maksItem);
                    cout << "Anda mendapat: " << items[itemTerpilih][0] << " . Stat: " << items[itemTerpilih][1] << endl;

                    inventory.push_back(vector<string>({items[itemTerpilih][0]}));
                    inventory[jumlahInventory].push_back(items[itemTerpilih][1]);
                    jumlahInventory++;
                    cout << "Jumlah inventory Sekarang: " << jumlahInventory << endl << endl;
                }
            break;
            }
        }
    }
    cout << "\nMasih ingin menggunakan menu inventory [y/n] ? "; cin >> lagi;
    cout << endl;
}
