#include <iostream>
#include "HappyFamilyyy.h"

using namespace std;

int main()
{
    ListOrtu LO;
    ListAnak LA;
    list_relasi LR;
    createOrtu(LO);
    createAnak(LA);
    createRelasi(LR);

    adrortu OR;
    adrAnak AK;
    adr_relasi RE;

    infotypeortu ort;
    infotypeAnak ank;

    string namaOrt;
    string namaAnk;
    string Uortu;
    string Uank;
    int tunj;

    char menu = 'y';
    while(menu == 'y' || menu == 'Y') {
        cout<<endl;
        cout<< "1. Tambah data orang tua"<<endl;
        cout<< "2. Tambah data anak"<<endl;
        cout<< "3. Cari data orang tua"<<endl;
        cout<< "4. Tambah relasi anak dengan orang tua"<<endl;
        cout<< "5. Cari data orang tua yang memiliki anak tertentu"<<endl;
        cout<< "6. Hapus data orang tua dan relasinya"<<endl;
        cout<< "7. Hapus data anak pada orang tua tertentu"<<endl;
        cout<< "8. Tampilkan seluruh data orang tua dan anaknya"<<endl;
        cout<< "9. Hitung banyak anak dari orang tua tertentu"<<endl;
        cout<< "10. Tampilkan data keluarga yang memiliki tunjangan anak terbanyak"<<endl;
        cout<< "0. Keluar menu"<<endl;
        cout<<endl;
        cout<< "Masukkan opsi menu : ";
        int opsi;
        cin >> opsi;
        cout << endl;
        if(opsi == 1) {
            int jumlah = 0;
            cout<< "-----------------------" << endl;
            cout<< "Masukkan Data Orang Tua" << endl;
            cout<< "-----------------------" << endl;
            cout<< "Jumlah Data Orang Tua yang akan ditambah ? ";cin>>jumlah;
            for(int i = 0;i < jumlah;i++){
                cout<<"\nData ke-"<<i + 1<<endl;
                cout<<"Nama Orang Tua : ";
                cin>>namaAnk;
                cout<<"Usia Orang Tua : ";
                cin>>Uank;
                cout<<"Tunjangan : ";
                cin>>tunj;
            createelementOrtu(ort);
            insertOrtu(LO, OR);
            cout<<endl;
            }
        }
        else if (opsi == 2) {
            int jumlah = 0;
            cout<< "-------------------" << endl;
            cout<< "Masukkan Data Anak" << endl;
            cout<< "-------------------" << endl;
            cout<<"Jumlah Data Anak yang akan ditambah? : ";cin>>jumlah;
            for(int i = 0;i < jumlah;i++){
                cout<<"\nData ke-"<<i + 1<<endl;
                cout<<"Nama Anak : ";
                cin>>namaAnk;
                cout<<"Usia Anak : ";
                cin>>Uank;
            createelementAnak(ank);
            insertAnak(LA, AK);
            cout<<endl;
            }
        }
        else if (opsi == 3) {
            cout<< "-------------------" << endl;
            cout<< "Cari Data Orang Tua" << endl;
            cout<< "-------------------" << endl;
            cout<< "Nama Orang Tua yang dicari ? ";cin>>namaOrt;
            OR = searchOrtu(LO, namaOrt);
            if(OR) {
                cout<< "\nData Orang Tua ditemukan" << endl;
                cout<< "Nama Orang Tua : " << infoortu(OR).namaortu<<" "<<endl;
            } else {
                cout<< "\nData Orang Tua Tidak Ditemukan!!" <<endl;
            }
        }
        else if (opsi == 4) {
            cout<< "----------------------------------------" << endl;
            cout<< "Tambah Relasi Data Anak Dengan Orang Tua" << endl;
            cout<< "----------------------------------------" << endl;
            cout<< "Nama Anak : ";cin>> namaAnk;
            cout<< "Nama Orang Tua : ";cin>> namaOrt;

            OR = searchOrtu(LO, namaOrt);
            AK = searchAnak(LA, namaAnk);
            if(OR == NULL) {
                cout<< "Data Orang Tua tidak Ditemukan " << endl;
            } else if (AK == NULL){
                cout<< "Data Anak tidak Ditemukan " << endl;
            } else {
                RE = createelementRelasi(OR, AK);
                insertLastRelasi(LR,RE);
                cout<< "Berhasil Menambah Relasi" << infoortu(OR).namaortu << "dengan" << infoAnak(AK).nama <<endl;
            }
        }

        else if (opsi == 5) {
            cout<< "----------------------------" << endl;
            cout<< "Cari Data Orang Tua Tertentu" << endl;
            cout<< "----------------------------" << endl;
            cout<< "Nama Orang Tua yang dicari ? ";cin>>namaOrt;
            OR = CariOrtuTertentu(LO, namaOrt);
            if(OR) {
                cout<< "\nData Orang Tua ditemukan" << endl;
                cout<< "Nama Orang Tua : " << infoortu(OR).namaortu<<" "<<endl;
            } else {
                cout<< "\nData Orang tua Tidak Ditemukan!!" <<endl;
            }
        }
        else if (opsi == 6) {
            cout<< "----------------------------------" << endl;
            cout<< "Hapus Data Orang Tua Dan Relasinya" << endl;
            cout<< "----------------------------------" << endl;
            cout<< "Nama Orang Tua :  ";
            cin>> namaOrt;
            OR = searchOrtu(LO, namaOrt);
            if(OR == NULL) {
                cout<< "Data Orang Tua Tidak Ditemukan" << endl;
            } else {
                //menghapus parent orang tua
                if(OR == firstortu(LO)) {
                    deletefirstOrtu(LO, OR);
                } else if(OR == lastortu(LO)) {
                    deletelastOrtu(LO, OR);
                } else {
                    adrortu Prec = prevortu(OR);
                    deleteafterOrtu(LO, Prec, OR);
                }
                //menghapus relasi
                adr_relasi pR = firstRelasi(LR);
                while(pR != NULL) {
                    if(nextortu(pR) == OR) {
                        if(RE == firstRelasi(LR)) {
                            deleteFirstRelasi(LR, RE);
                        } else if(RE == lastRelasi(LR)) {
                            deleteLastRelasi(LR, RE);
                        } else {
                            adr_relasi Prec = prevRelasi(RE);
                            deleteAfterRelasi(LR, Prec, RE);
                        }
                    }
                }
                cout<< "Data Sudah Dihapus" << endl;
            }
        }
        else if (opsi == 7) {
            cout<< "---------------------------------------" << endl;
            cout<< "Hapus Data Anak Pada Orang Tua Tertentu" << endl;
            cout<< "---------------------------------------" << endl;
            cout<< "Nama Orang Tua :  ";
            cin>> namaOrt;
            OR = searchOrtu(LO, namaOrt);
            if(OR == NULL) {
                cout<< "Data Tidak Ditemukan" << endl;
            } else {
                RE = NULL;
                adr_relasi pR = firstRelasi(LR);
                while(pR != NULL) {
                    if(nextortu(pR) == OR) {
                        if(RE == firstRelasi(LR)) {
                            deleteFirstRelasi(LR, RE);
                        } else if(RE == lastRelasi(LR)) {
                            deleteLastRelasi(LR, RE);
                        } else {
                            adr_relasi Prec = prevRelasi(RE);
                            deleteAfterRelasi(LR, Prec, RE);
                        }
                    }
                }
            }
        }
        else if (opsi == 8) {
            cout<< "------------------------------------" << endl;
            cout<< "Tampilkan Data Orang Tua Dan Anaknya" << endl;
            cout<< "------------------------------------" << endl;
            showanakdanorangtua(LO,LR);
        }
        else if (opsi == 9) {
            cout<< "----------------------------------------" << endl;
            cout<< "Hitung Data Anak Dari Orang Tua Tertentu" << endl;
            cout<< "----------------------------------------" << endl;
            cout<< "Nama Orang Tua :  ";
            cin>> namaOrt;
            int jmlAnak = hitungAnakdariOrangtua(LR, namaOrt);

        }
        else if (opsi == 10) {
            cout<< "---------------------------------------------" << endl;
            cout<< "Tampilkan Data Orang Tua Dengan Tunjangan Terbanyak" << endl;
            cout<< "---------------------------------------------" << endl;
            void showTunjanganTerbanyak(ListOrtu LP, list_relasi LR);
        }
        else if (opsi == 0) {
            menu = 'N';
        }
        cout<< "Kembali Ke Menu ? [Y/N] ";
        cin>> menu;
        cout<< endl<< endl;
    }
    cout<< "program selesai";

    return 0;
}
