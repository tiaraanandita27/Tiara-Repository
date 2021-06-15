#include <iostream>
#include <conio.h>
#include<istream>
#include"Multi.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    int Pilihan;

    do {

        cout<<" -----------------------------------------------------------------   "<<endl;
        cout<<" |                      DATA ALAT TRANSPORT                      |   "<<endl;
        cout<<" |  1. Penambahan Data Alat Angkutan                             |   "<<endl;
        cout<<" |  2. Penambahan Data Daerah                                    |   "<<endl;
        cout<<" |  3. Tambah Relasi Alat Angkutan dan Daerah                    |   "<<endl;
        cout<<" |  4. delete Data Alat Angkutan                                 |   "<<endl;
        cout<<" |  5. delete Data Daerah                                        |   "<<endl;
        cout<<" |  6. Tampilkan Data Keseluruhan                                |   "<<endl;
        cout<<" |  7. Data Daerah bisa dilalui oleh alat angkutan tertentu      |   "<<endl;
        cout<<" |  8. Data Alat Angkutan bisa mengunjungi daerah tertentu       |   "<<endl;
        cout<<" |  9. Tampilkan data daerah yang paling mudah dan paling sulit  |   "<<endl;
        cout<<" |  0. EXIT                                                      |   "<<endl;
        cout<<" -----------------------------------------------------------------   "<<endl;
        cout<<" Masukan Pilihan Anda : ";
        cin>> Pilihan;
        switch(Pilihan)
        {
        case 1:
            PenambahanAlatAngkut(L);
            break;

        case 2:
            penambahanDataDaerah(L);
            break;

        case 3 :
            relasiTransport(L);
            break;


        case 4 :
            deleteAlatAngkutan(L);
            break;

        case 5:
            deleteDataDaerah(L);
            break;

        /*case 6:
            system("CLS");

            cout<< "||  Data Alat Transport ||" <<endl; **/

        case 7:
            TampilDataDaerahTertentu(L);
            break;

        case 8:
            TampilkanAlatTertentu(L);
            break;


        /*case 9:**/

        case 0:
            break;
        default :
            cout<<" Kode Yang Anda Masukan Tidak Tersedia";
        }
    }
    while(Pilihan != 0);
    cout<<" ";
    cout<<"\n     |          XieXie, Terimakasih, Kamsahamnida          |";
    cout<<"\n     |                Salma Syakirah Abnaz                 |";
    cout<<"\n     |              Tiara Anandita Ramadhani               |";
    cout<<" ";

    return 0;
}
