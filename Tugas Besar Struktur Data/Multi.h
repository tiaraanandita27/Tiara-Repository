#ifndef MULTI_H_INCLUDED
#define MULTI_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <string>
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define info(P)  P->info
#define next(P)  P->next

#define firstC(L) ((L).firstC)
#define LastC(L) ((L).LastC)
#define nextC(P)  P->nextC
#define infoC(P)  P->infoC
#define NIL NULL
#define prev(P) P->prev

#define firstR(L) ((L).firstR)
#define LastR(L) ((L).LastR)
#define relasi(P) P->relasi
#define infoR(P) P-> infoR
#define nextR(P) P-> nextR

using namespace std;

typedef string infotype;
typedef struct elmP *adr_P;
typedef struct elmC *adr_C;
typedef struct elmR *adr_R;

struct elmP {
    infotype info;
    adr_P next;
};
struct elmC {
    infotype infoC;
    adr_C nextC;
    adr_C prev;
};

struct elmR {
    infotype infoR;
    adr_R nextR;
    adr_R prevR;
};
struct List{
    adr_P First;
    adr_P Last;
    adr_C firstC;
    adr_C LastC;
    adr_R firstR;
    adr_R LastR;
};

void CreateList(List &L);
adr_P alokasi(infotype K);
void insertDataDaerah(List &L, adr_P P );
void penambahanDataDaerah(List &L);
void deleteDataDaerah(List &L);
adr_P cariDataDaerah(infotype K, List &L);
void TampilDataDaerahTertentu(List L);

adr_C alokasiAngkutan(infotype K);
void insertAngkutan(adr_C C, List &L);
void PenambahanAlatAngkut(List &L);
adr_C CariAngkutan(infotype K,List &L);
void deleteAlatAngkutan(List &L);
void TampilkanAlatTertentu(List L);

void TampilkanSeluruhData(List L);

adr_R alokasiR(infotype K);
void insertLastRelasi(List &L, adr_R R);
void relasiTransport(List L);
/*void perbandinganDataDaerah(List L, DataDaerah P);**/

#endif // MULTI_H_INCLUDED
