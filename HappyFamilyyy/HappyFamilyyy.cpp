#include "HappyFamilyyy.h"

void createOrtu(ListOrtu &L){
    firstortu(L) = NULL;
    lastortu(L) = NULL;
}

adrortu createelementOrtu(infotypeortu x){
    adrortu P = new elementortu;
    infoortu(P) = x;
    nextortu(P) = NULL;
    prevortu(P) = NULL;
    return P;
}

void insertOrtu(ListOrtu &L, adrortu P){
    if (firstortu(L) == NULL){
        insertfirstOrtu(L, P);
    }else{
        adrortu Q = firstortu(L);
        adrortu Prec = NULL;
        while(infoortu(Q).namaortu < infoortu(P).namaortu && nextortu(Q) != firstortu(L)){
            Prec = Q;
            Q = next(Q);
        }

        if(nextortu(Q) != firstortu(L) && Prec != NULL){
            insertafterOrtu(L, P, Prec);
        }else{
            if(infoortu(Q).namaortu > infoortu(P).namaortu){
                insertfirstOrtu(L, P);
            }else{
                insertfirstOrtu(L,P);
            }

        }
    }
}

void insertfirstOrtu(ListOrtu &L, adrortu P){
    if (firstortu(L) == NULL){
        firstortu(L) = P;
        lastortu(L) = P;
    } else {
        nextortu(P) = firstortu(L);
        prevortu(firstortu(L)) = P;
        firstortu(L) = P;
        prevortu(P) = lastortu(L);
        nextortu(lastortu(L)) = P;
    }
}

void insertlastOrtu(ListOrtu &L, adrortu P){
    if (firstortu(L) == NULL){
        firstortu(L) = P;
        lastortu(L) = P;
    } else {
        nextortu(lastortu(L)) = P;
        prevortu(P) = lastortu(L);
        lastortu(L) = P;
        nextortu(P) = firstortu(L);
        prevortu(firstortu(L)) = P;
    }
}

void insertafterOrtu(ListOrtu &L, adrortu Prec, adrortu P){
    if (firstortu(L) == NULL){
        firstortu(L) = P;
        lastortu(L) = P;
    } else {
        nextortu(P) = nextortu(Prec);
        prevortu(nextortu(Prec)) = P;
        nextortu(Prec) = P;
        prevortu(P) = Prec;
    }
}

void deletefirstOrtu(ListOrtu &L, adrortu &P){
    if (firstortu(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (firstortu(L) == lastortu(L)){
        P = firstortu(L);
        firstortu(L) = NULL;
        lastortu(L) = NULL;
    } else {
        P = firstortu(L);
        firstortu(L) = nextortu(P);
        nextortu(P) = NULL;
        prevortu(firstortu(L)) = lastortu(L);
        nextortu(lastortu(L)) = firstortu(L);
    }
}

void deletelastOrtu(ListOrtu &L, adrortu &P){
    if (firstortu(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (firstortu(L) == lastortu(L)){
        P = firstortu(L);
        firstortu(L) = NULL;
        lastortu(L) = NULL;
    } else {
        P = lastortu(L);
        lastortu(L) = prevortu(P);
        prevortu(P) = NULL;
        nextortu(lastortu(L)) = firstortu(L);
        prevortu(firstortu(L)) = lastortu(L);
    }
}

void deleteafterOrtu(ListOrtu &L, adrortu Prec, adrortu &P){
    if (firstortu(L) == NULL){
        cout << "List Kosong" << endl;
    } else if (firstortu(L) == lastortu(L)){
        P = firstortu(L);
        firstortu(L) = NULL;
        lastortu(L) = NULL;
    } else {
        P = nextortu(Prec);
        nextortu(Prec) = nextortu(P);
        prevortu(nextortu(P)) = Prec;
        nextortu(P) = NULL;
        prevortu(P) = NULL;
    }
}

adrortu searchOrtu(ListOrtu L, string namaortu2){
    adrortu P = firstortu(L);
    while(P != NULL){
        if(infoortu(P).namaortu == namaortu2){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

adrortu CariOrtuTertentu(ListOrtu L, string namaortu){
    adrortu P = firstortu(L);
    while(P != NULL){
        if(infoortu(P).namaortu == namaortu){
            return P;
        }
        P = nextortu(P);
    }
    return NULL;
}

void showOrangTua(ListOrtu &L){
    adrortu P = firstortu(L);
    int i = 1;
    if(firstortu(L) == NULL){
        cout<<"Data Tidak Ada"<<endl;
    }else{
        while(nextortu(P) != firstortu(L)){
            cout<<i<<"."<<infoortu(P).namaortu<<endl;
            cout<<i<<"."<<infoortu(P).Usiaortu<<endl;
            cout<<i<<"."<<infoortu(P).Tunjangan<<endl;
            P = nextortu(P);
            i++;
        }
        cout<<infoortu(P).namaortu<<endl;
        cout<<infoortu(P).Usiaortu<<endl;
        cout<<infoortu(P).Tunjangan<<endl;
    }
}

void createAnak(ListAnak &L){
    firstAnak(L) = NULL;
}

adrAnak createelementAnak(infotypeAnak x){
    adrAnak P = new elementAnak;
    infoAnak(P) = x;
    nextAnak(P) = NULL;
    return P;
}

void insertFirstAnak(ListAnak &L, adrAnak P){
    if(firstAnak(L) == NULL){
        firstAnak(L) = P;
    }else{
        nextAnak(P) = firstAnak(L);
        firstAnak(L) = P;
    }
}

void insertLastAnak(ListAnak &L, adrAnak P){
    adrAnak Q;
    if(firstAnak(L) == NULL){
        firstAnak(L) = P;
    }else{
        Q = firstAnak(L);
        while(nextAnak(Q) != NULL){
            Q = nextAnak(Q);
        nextAnak(Q) = P;
        }
    }
}

void insertAfteAnak(ListAnak &L, adrAnak Prec, adrAnak P){
    nextAnak(P) = nextAnak(Prec);
    nextAnak(Prec) = P;
}

void deleteFirstAnak(ListAnak &L, adrAnak &P){
    if(firstAnak(L) == NULL){
        cout<<"Data Tidak Ada"<<endl;
    }else if(nextAnak(firstAnak(L)) == firstAnak(L)){
        P = firstAnak(L);
        firstAnak(L) = NULL;
    }else{
        adrAnak Q = firstAnak(L);
        while(nextAnak(Q) != firstAnak(L)){
            Q = nextAnak(Q);
        }
        P = firstAnak(L);
        firstAnak(L) = nextAnak(P);
        nextAnak(Q) = firstAnak(L);
        nextAnak(P) = NULL;
    }
}

void deleteLastAnak(ListAnak &L, adrAnak &P){
    if(firstAnak(L) == NULL){
        cout<<"Data Tidak Ada"<<endl;
    }else if(nextAnak(firstAnak(L)) == firstAnak(L)){
        P = firstAnak(L);
        firstAnak(L) = NULL;
    }else{
        adrAnak Q = firstAnak(L);
        while(nextAnak(nextAnak(Q)) != firstAnak(L)){
            Q = nextAnak(Q);
        }
        P = nextAnak(Q);
        nextAnak(Q) = firstAnak(L);
        nextAnak(P) = NULL;
    }
}

void deleteAfterAnak(ListAnak &L, adrAnak Prec, adrAnak &P){
    P = nextAnak(Prec);
    nextAnak(Prec) = nextAnak(P);
    nextAnak(P) = NULL;
}

void insertAnak(ListAnak &L, adrAnak P){
    if(firstAnak(L) == NULL){
        insertFirstAnak(L,P);
    }else{
        adrAnak Q = firstAnak(L);
        adrAnak Prec = NULL;
        while(infoAnak(Q).nama < infoAnak(P).nama && nextAnak(Q) != firstAnak(L)){
            Prec = Q;
            Q = nextAnak(Q);
        }

        if(nextAnak(Q) != NULL && Prec != NULL){
            insertAfteAnak(L, Prec, P);
        }else{
            if(infoAnak(Q).nama > infoAnak(P).nama){
                insertFirstAnak(L,P);
            }else{
                insertLastAnak(L,P);
            }

        }
    }
}
adrAnak searchAnak(ListAnak L, string nama2){
    if(firstAnak(L) != NULL){
        adrAnak P = firstAnak(L);
        while(nextAnak(P) != firstAnak(L) && infoAnak(P).nama != nama2){
            P = nextAnak(P);
        }
        if(infoAnak(P).nama == nama2){
            //jika ditemukan
            return P;
        }else{
            //jika tidak ditemukan
            return NULL;
        }
    }else{
        return NULL;
    }
}

void showanak(ListAnak &L){
    adrAnak P = firstAnak(L);
    int i = 1;
    while(nextAnak(P) != firstAnak(L)){
        cout<<i<<"."<<infoAnak(P).nama<<endl;
        cout<<i<<"."<<infoAnak(P).Usia<<endl;
        P = nextAnak(P);
    }
    cout<<i<<"."<<infoAnak(P).nama<<endl;
    cout<<i<<"."<<infoAnak(P).Usia<<endl;
}


void createRelasi(list_relasi &L){
    firstRelasi(L) = NULL;
    lastRelasi(L) = NULL;
}

adr_relasi createelementRelasi(adrortu parentP, adrAnak childP){
    adr_relasi P = new elm_relasi;
    nextortu(P) = parentP;
    nextAnak(P) = childP;
    nextRelasi(P) = NULL;
    prevRelasi(P) = NULL;
    return P;
}

void insertRelasi(list_relasi &L, adr_relasi P){
    if (firstRelasi(L) == NULL){
        firstRelasi(L) = P;
        lastRelasi(L) = P;
    }
    else{
        nextRelasi(lastRelasi(L)) = P;
        prevRelasi(P) = lastRelasi(L);
        lastRelasi(L) = P;
    }
}

void insertFirstRelasi(list_relasi &L, adr_relasi P){
    if(firstRelasi(L) == NULL){
        firstRelasi(L) = P;
        lastRelasi(L) = P;
    }else{
        nextRelasi(P) = firstRelasi(L);
        prevRelasi(firstRelasi(L)) = P;
        firstRelasi(L) = P;
    }
}

void insertLastRelasi(list_relasi &L, adr_relasi P){
    if(firstRelasi(L) == NULL){
        firstRelasi(L) = P;
        lastRelasi(L) = P;
    }else{
        nextRelasi(lastRelasi(L)) = P;
        prevRelasi(P) = lastRelasi(L);
        lastRelasi(L) = P;
    }
}

void insertAfterRelasi(list_relasi &L, adr_relasi Prec, adr_relasi P){
    if(firstRelasi(L) != NULL){
        nextRelasi(P) = nextRelasi(Prec);
        prevRelasi(P) = Prec;
        nextRelasi(Prec) = P;
        prevRelasi(nextRelasi(P)) = P;
    }
}

void deleteFirstRelasi(list_relasi &L, adr_relasi &P){
    if(firstRelasi(L) != NULL){
        P = firstRelasi(L);
        firstRelasi(L) = nextRelasi(P);
        nextRelasi(P) = NULL;
        prevRelasi(firstRelasi(L)) = NULL;
    }
}

void deleteLastRelasi(list_relasi &L, adr_relasi &P){
    if(firstRelasi(L) != NULL){
        P = lastRelasi(L);
        lastRelasi(L) = prevRelasi(P);
        prevRelasi(P) = NULL;
        nextRelasi(lastRelasi(L)) = NULL;
    }
}

void deleteAfterRelasi(list_relasi &L, adr_relasi Prec, adr_relasi &P){
    if(firstRelasi(L) != NULL){
        P = nextRelasi(Prec);
        nextRelasi(Prec) = nextRelasi(P);
        prevRelasi(nextRelasi(P)) = Prec;
        nextRelasi(P) = NULL;
        prevRelasi(P) = NULL;
    }
}

adr_relasi searchRelasi(list_relasi L, adrortu ort, adrAnak ank){
    adr_relasi P = firstRelasi(L);
    while(P != NULL){
        if(nextortu(P) == ort && nextAnak(P) == ank){
            return P;
        }
        P = nextRelasi(P);
    }
    return NULL;
}

void showRelasi(list_relasi &L){
    adr_relasi P = firstRelasi(L);
    while (P != NULL)
    {
        cout << "Nama Orang Tua : " << infoortu(nextortu(P)).namaortu << "->>";cout << "Nama Anak : " << infoAnak(nextAnak(P)).nama << endl;
        P = nextRelasi(P);
    }

    cout << "Nama Orang Tua : " << infoortu(nextortu(P)).namaortu << "->>";cout << "Nama Anak : " << infoAnak(nextAnak(P)).nama << endl;
}

void showanakdanorangtua(ListOrtu LO, list_relasi LR){
    adrortu P = firstortu(LO);
    while(nextortu(P) != firstortu(LO)){
        cout<<infoortu(P).namaortu<<" : "<<endl;
        adr_relasi R = firstRelasi(LR);
        while(R != NULL){
            if(nextortu(R) == P){
                //cout<<infoRelasi(nextAnak(R)).nama<<endl; ??
            }
            R = nextRelasi(R);
        }
        cout<<endl;
        P  = nextortu(P);
    }
}

int hitungAnakdariOrangtua(list_relasi LR, string x){
    int count = 0;
    adr_relasi P = firstRelasi(LR);
    while(P != NULL){
        if(infoAnak(nextAnak(P)).nama == x){
            count++;
        }
        P = nextRelasi(P);
    }
    return count;
}

void showTunjanganTerbanyak(ListOrtu LP, list_relasi LR){
    int max = 99999;
    string nama = "";

    if(firstortu(LP) != NULL && firstRelasi(LR) != NULL){
        adrortu O = firstortu(LP);
        int cout = 0;
        while(nextortu(O) != firstortu(LP)){
            adr_relasi R = firstRelasi(LR);
            while(nextRelasi(R) != NULL){
                if(nextortu(R) != NULL){
                    cout++;
                }
                R = nextRelasi(R);
            }

            if(cout > max){
                nama = infoortu(O).namaortu;
            }
            O = nextortu(O);
        }

        adr_relasi R = firstRelasi(LR);
        while(nextRelasi(R) != NULL){
            if(nextortu(R) == O){
                cout++;
            }
            R = nextRelasi(R);
        }
        if(cout<max){
            nama = infoortu(O).namaortu;
        }
    }
    if(nama != ""){
        cout<<"Orang Tua dengan Tunjangan Terbanyak : "<<nama<<endl;
    }else{
        cout<<"Tidak Ada Data " << endl;
    }
}
