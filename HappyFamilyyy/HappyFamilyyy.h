#ifndef HAPPYFAMILYYY_H_INCLUDED
#define HAPPYFAMILYYY_H_INCLUDED

#include <iostream>
using namespace std;

#define nextortu(P) P->nextortu
#define prevortu(P) P->prevortu
#define firstortu(L) ((L).firstortu)
#define lastortu(L) ((L).lastortu)
#define infoortu(P) P->infoortu

#define nextAnak(P) P->nextAnak
#define firstAnak(L) ((L).firstAnak)
#define infoAnak(P) P->infoAnak

#define nextRelasi(P) P->nextRelasi
#define prevRelasi(P) P->prevRelasi
#define firstRelasi(L) ((L).firstRelasi)
#define lastRelasi(L) ((L).lastRelasi)
#define infoRelasi(P) (P)->infoRelasi

//List Orangtua

struct infotypeortu{
    string namaortu;
    string Usiaortu;
    int Tunjangan;
};

typedef struct elementortu *adrortu;

struct elementortu{
    infotypeortu infoortu;
    adrortu nextortu;
    adrortu prevortu;
};

struct ListOrtu{
    adrortu firstortu;
    adrortu lastortu;
};

//List Anak

struct infotypeAnak{
    string nama;
    string Usia;
};

typedef struct elementAnak *adrAnak;

struct elementAnak{
    infotypeAnak infoAnak;
    adrAnak nextAnak;
};

struct ListAnak{
    adrAnak firstAnak;
};

//List Relasi

typedef struct elm_relasi *adr_relasi;

struct elm_relasi{
    adrortu nextortu;
    adrAnak nextAnak;
    adr_relasi nextRelasi;
    adr_relasi prevRelasi;
};

struct list_relasi{
    adr_relasi firstRelasi;
    adr_relasi lastRelasi;
};

void createOrtu(ListOrtu &L);
adrortu createelementOrtu(infotypeortu x);
void insertOrtu(ListOrtu &L, adrortu P);
void insertfirstOrtu(ListOrtu &L, adrortu P);
void insertlastOrtu(ListOrtu &L, adrortu P);
void insertafterOrtu(ListOrtu &L, adrortu Prec, adrortu P);
void deletefirstOrtu(ListOrtu &L, adrortu &P);
void deletelastOrtu(ListOrtu &L, adrortu &P);
void deleteafterOrtu(ListOrtu &L, adrortu Prec, adrortu &P);
adrortu searchOrtu(ListOrtu L, string namaortu2);
adrortu CariOrtuTertentu(ListOrtu L, string Usiaortu);
void showOrangTua(ListOrtu &L);

void createAnak(ListAnak &L);
adrAnak createelementAnak(infotypeAnak x);
void insertFirstAnak(ListAnak &L, adrAnak P);
void insertLastAnak(ListAnak &L, adrAnak P);
void insertAfteAnak(ListAnak &L, adrAnak Prec, adrAnak P);
void deleteFirstAnak(ListAnak &L, adrAnak &P);
void deleteLastAnak(ListAnak &L, adrAnak &P);
void deleteAfterAnak(ListAnak &L, adrAnak Prec, adrAnak &P);
void insertAnak(ListAnak &L, adrAnak P);
adrAnak searchAnak(ListAnak L, string nama2);
void showanak(ListAnak &L);

void createRelasi(list_relasi &L);
adr_relasi createelementRelasi(adrortu parentP, adrAnak childP);
void insertRelasi(list_relasi &L, adr_relasi P);
void insertFirstRelasi(list_relasi &L, adr_relasi P);
void insertLastRelasi(list_relasi &L, adr_relasi P);
void insertAfterRelasi(list_relasi &L, adr_relasi Prec, adr_relasi P);
void deleteFirstRelasi(list_relasi &L, adr_relasi &P);
void deleteLastRelasi(list_relasi &L, adr_relasi &P);
void deleteAfterRelasi(list_relasi &L, adr_relasi Prec, adr_relasi &P);
adr_relasi searchRelasi(list_relasi L, string x);
void showRelasi(list_relasi &L);

void showanakdanorangtua(ListOrtu LO, list_relasi LR);
int hitungAnakdariOrangtua(list_relasi LR, string x);
void showTunjanganTerbanyak(ListOrtu LP, list_relasi LR);

#endif // HAPPYFAMILYYY_H_INCLUDED
