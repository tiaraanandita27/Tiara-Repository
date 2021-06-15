#include"Multi.h"


void CreateList(List &L){
    First(L) = NULL;
    Last(L) = NULL;
    firstC(L) = NULL;
    LastC(L) = NULL;
}
adr_P alokasi(infotype K){
    adr_P P = new elmP;
    info(P) = K;
    next(P) = NULL;

    return P;
}
void insertDataDaerah(List &L, adr_P P ){
    if(First(L) == NULL){
        First(L) = P;
        Last(L) = P;
    } else {
        adr_P P = Last(L);
        next(P) = P;
        Last(L) = P;
    }
}
void penambahanDataDaerah(List &L){
    infotype DataDaerah;
    adr_P P = First(L);

    cout<< "Penambahan Data Daerah"<<endl;
    cout<<"Data Daerah : ";
    cin>>DataDaerah;
    TampilDataDaerahTertentu(L);
        while(P != NULL && info(P) != DataDaerah){
            P = next(P);
        }
        if (P == NULL){
            P = alokasi(DataDaerah);
            insertDataDaerah(L,P);
            cout<<"\nDataDaerah "<<DataDaerah <<" ditambahkan"<<endl;
        } else if (info(P) == DataDaerah){
            cout<<"nDataDaerah "<<DataDaerah <<" Terdaftar"<<endl;
        }
}
void deleteDataDaerah(List &L){
    infotype DataDaerah;
    adr_P P= First(L);
    if (P != NULL){
        cout<<" deleteDataDaerah"<<endl;
        cin>>DataDaerah;
        P = cariDataDaerah(DataDaerah,L);

        if(P != NULL){
            if (P == First(L)) {
                First(L) = next(P);
                next(P) = NULL;
            } else if (P == Last(L)){
                adr_P J = First(L);
                 while (next(J) != P){
                    J = next(J);
                }
                next(J) = NULL;
                Last(L) = J;
            } else {
                adr_P J = First(L);
                while(next(J) != P){
                    J = next(J);
                }
                next(J) = next(P);
                next(P) = NULL;
            }
            delete P;
            cout<<"data dihapus"<<endl;
        } else {
            cout<< "Kosong "<<endl;
        }
    }
}
adr_P cariDataDaerah(infotype K, List &L){
        adr_P P = First(L);
        while(P!= NULL && info(P) != K)
        P = next(P);

        return P;

}
void TampilDataDaerahTertentu(List L){
    adr_P P = First(L);
    infotype DataDaerah;
    cout<<"Data Daerah:";
    cin>> DataDaerah;
    P = cariDataDaerah(DataDaerah, L);
    while (P != NULL){
        cout<<info(P)<<" ";
        P = next(P);
    }
    cout<<endl<<endl;
}
adr_C alokasiAngkutan(infotype K){
    adr_C C = new elmC;
    infoC(C) = K;
    nextC(C) = NULL;

    return C;
}
void insertAngkutan(adr_C C, List &L){
    /* insert first double linked list **/
        if(firstC(L)== NULL && LastC(L)== NULL){
            firstC(L) = C;
            LastC(L) = C;
        } else {
            nextC(C) = firstC(L);
            prev(firstC(L)) = C;
            firstC(L) = C;
        }
}
void PenambahanAlatAngkut(List &L){
    infotype AlatAngkutan;
    adr_C C = firstC(L);

    cout<<" Tambah Alat Angkut"<<endl;
    cout<<" Alat Angkut: ";
    cin>>AlatAngkutan;
    TampilkanAlatTertentu(L);

    while(C != NULL && infoC(C) != AlatAngkutan){
        C = nextC(C);
    }
    if(C ==NULL) {
        C = alokasiAngkutan(AlatAngkutan);
        insertAngkutan(C,L);
        cout<<" Nama Alat Angkutan "<<AlatAngkutan<<"ditambahkan";
    } else if (infoC(C) == AlatAngkutan){
        cout<<" Nama Alat Angkutan"<<AlatAngkutan<<"Terdaftar";

    }
}
adr_C CariAngkutan(infotype K,List &L){
        adr_C C = firstC(L);
        while(C!=NULL){
            if(infoC(C) == K){
                return C;
            }
            C = nextC(C);
        }
        return NULL;
}
void deleteAlatAngkutan(List &L){
    infotype AlatAngkutan;
    adr_C C = firstC(L);

        if ( C!= NULL){
        cout<<" deleteAlatAngkutan"<<endl;
        cin>>AlatAngkutan;
        C= CariAngkutan(AlatAngkutan,L);

        if(C != NULL){
            if (C == firstC(L)) {
                firstC(L) = nextC(C);
                nextC(C) = NULL;
            } else if (C == LastC(L)){
                adr_C G = firstC(L);
                while (nextC(G) != C){
                    G = nextC(G);
                }
                nextC(G) = NULL;
                LastC(L) = G;
            } else {
                adr_C G = firstC(L);
                while(nextC(C) != C){
                    G = nextC(G);
                }
                nextC(G) = nextC(C);
                nextC(C) = NULL;
            }
            delete C;
            cout<<"data dihapus"<<endl;
        } else {
            cout<< "Kosong"<<endl;
        }
    }
}

void TampilkanAlatTertentu(List L){
    adr_C C = firstC(L);
    infotype AlatAngkutan;
    cout<<" alat angkutan:";
    cin>> AlatAngkutan;
    C = CariAngkutan(AlatAngkutan, L);
    while (C != NULL){
        cout<<infoC(C)<<" ";
        C = nextC(C);
    }
    cout<<endl<<endl;
}

adr_R alokasiR(infotype K){
    adr_R R = new elmR;
    infoR(R) = K;
    nextR(R) = NULL;

    return R;
}
void insertLastRelasi(List &L, adr_R R){
    if(LastR(L) == NULL){
        nextR(R) = R;
        LastR(L) = R;
    }else{
        nextR(R) = nextR(LastR(L));
        nextR(LastR(L)) = R;
        LastR(L) = R;
    }
}
void relasiTransport(List L){
    infotype AlatAngkutan ;
    infotype DataDaerah ;

    adr_P P;
    adr_C C;
    adr_R R;
    cout<<"Masukan Alat Angkutan: ";
    cin>> AlatAngkutan;
    cout<< "Masukan Data Daerah:  ";
    cin>> DataDaerah;
    cout<<endl;

        P = cariDataDaerah(DataDaerah,L);
        C = CariAngkutan(AlatAngkutan,L);
     if ( P != NULL && C != NULL){
        R = alokasiR(DataDaerah);
        insertLastRelasi(L,R);
    } else {
        cout <<" alat angkut dan data daerah tidak terdaftar"<<endl;
    }
    cout<<""<<endl;
    TampilDataDaerahTertentu(L);
    TampilkanAlatTertentu(L);
}

void TampilkanSeluruhData(List L){
    adr_R R = firstR(L);
    if (R != NULL){
        cout<<infoR(R)<<" ";
        R = nextR(R);
    }
    while (R != NULL && R != firstR(L)){
        cout<<infoR(R)<<" ";
        R = nextR(R);
    }
    TampilDataDaerahTertentu(L);
    TampilkanAlatTertentu(L);
    cout<<endl;
}

/*void perbandinganDataDaerah(List L, DataDaerah D){
    int i, imin, imax;
    adr_P P, Pmin, Pmax;
    adr_C C;
    adr_R R;
    P = First(L);
    Pmin = 1000000;
    Pmax = -100000;
    while (P != NULL){
        i = 0;
        C = firstC(L);
        while (C != NULL){
            R = adr_R;
            while (R != NULL){
                if (infoR(R) == C){
                    i = i + 1;
                }
                R = nextR(R);
            }
            C = nextC(C);
        }
        if (i > imax){
            imax = i;
            Pmin = P;
        } else if (i < imin){
            imin = i;
            Pmax = C;
        }
        C = nextC(C);
    }
}**/
