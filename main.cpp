#include <iostream>
#include "tubes.h"
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    bool exit = false;
    listPeng P;
    listFur F;
    createListFur(F);
    createListPeng(P);
    while(!exit){
        int pil;
        char cari[20];
        adrPeng N;
        adrFur M;
        pengrajin x;
        furniture y;
        cout<<"========================"<<endl;
        cout<<"Main Menu"<<endl;
        cout<<"========================"<<endl;
        cout<<"1.Pengrajin Menu"<<endl;
        cout<<"2.Furniture Menu"<<endl;
        cout<<"3.Relation Menu"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"choice : ";
        cin>>pil;
        system("CLS");
        switch(pil){
        case 1:
            pengMenu();
            cin>>pil;
            switch(pil){
            case 0:
                system("CLS");
                printPengrajin(P);
                break;
            case 1:
                system("CLS");
                createListPeng(P);
                cout<<"done"<<endl;
                break;
            case 2:
                cout<<"Masukkan Nama\t: ";
                //cin.ignore();
                //cin.getline(x.nama,sizeof(x.nama));
                cin>>x.nama;
                cout<<"Asal\t\t: ";
                cin>>x.asal;
                N = createElmPeng(x);
                insertPeng(P,N);
                cout<<"done"<<endl;
                break;
            case 3:
                printPengrajin(P);
                cout<<"pengrajin yang mau dihapus : ";
                //cin.ignore();
                //cin.getline(cari,sizeof(cari));
                cin>>cari;
                system("CLS");
                N = searchPeng(cari,P);
                if(N!=nil){
                    delPeng(P,N);
                    cout<<"done"<<endl;
                }
                else{
                    cout<<"Pengrajin Tidak ada"<<endl;
                }
                break;
            case 4:
                cout<<"data yang ingin dicari"<<endl;
                cin>>cari;
                N = searchPeng(cari,P);
                if(N==nil){
                    cout<<"pengrajin tidak ditemukan"<<endl;
                }
                else{
                    cout<<infoPeng(N).nama<<endl;
                }
                break;
            case 5:
                if(isEmpty(P)){
                    cout<<"kosong"<<endl;
                }
                else{
                    cout<<"terisi"<<endl;
                }
                break;
            case 6:
                countRel(P);
                break;
            case 7:
                viewPengToPeng(P);
                break;
            default:
                cout<<"kode salah"<<endl;
            }
        break;
        /** Menu Furniture **/
        case 2:
            furMenu();
            cin>>pil;
            switch(pil){
            case 0:
                printAllFurniture(F);
                break;
            case 1:
                createListFur(F);
                break;
            case 2:
                cout<<"nama furniture : ";
                cin>>y.nama;
                cout<<"jenis : ";
                cin>>y.jenis;
                cout<<"Bahan : ";
                cin>>y.bahan;
                cout<<"Harga : ";
                cin>>y.harga;
                M = createElmFur(y);
                insertFur(F,M);
                cout<<"done"<<endl;
                break;
            case 3:
                cout<<"furniture yang mau dihapus : ";
                cin>>cari;
                M = searchFur(cari,F);
                if(M!=nil){
                    delFur(F,M,P);
                    cout<<"done"<<endl;
                }
                else{
                    cout<<"Furniture tidak ditemukan"<<endl;
                }
                break;
            case 4:
                cout<<"furniture yang ingin dicari"<<endl;
                cin>>cari;
                M = searchFur(cari,F);
                if(M!=nil){
                    cout<<infoFur(M).nama<<endl;
                }
                else{
                    cout<<"data tidak ditemukan"<<endl;
                }
                break;
            case 5:
                if(isEmpty(F)){
                    cout<<"kosong"<<endl;
                }
                else{
                    cout<<"terisi"<<endl;
                }
                break;
            case 6:
                cout<<"nama furniture : ";
                cin>>cari;
                cout<<"nama pengrajin : "<<endl;
                viewFurPeng(P,cari);
                break;
            case 7:
                countPeng(P,F);
                break;
            case 8:
                countTwoPeng(P,F);
                break;
            default:
                cout<<"kode salah"<<endl;
        }
        break;
        /** menu relasi **/
        case 3:
            relMenu();
            cin>>pil;
            switch(pil){
            case 1:
                cout<<"pengrajin yang ingin ditambah relasinya"<<endl;
                cin>>cari;
                N = searchPeng(cari,P);
                cout<<"furniture yang ingin ditambah relasinya"<<endl;
                cin>>cari;
                M = searchFur(cari,F);
                if(N!=nil&&M!=nil){
                    createRelation(N,M);
                    cout<<"relasi berhasil ditambahkan"<<endl;
                }
                else{
                    cout<<"Pengrajin atau furniture tidak ditemukan"<<endl;
                }
                break;
            case 2:
                cout<<"pengrajin yang ingin dilihat relasinya"<<endl;
                cin>>cari;
                N = searchPeng(cari,P);
                printRel(N);
                break;
            default:
                cout<<"kode salah"<<endl;
            }
        break;
        case 0:
            exit = true;
            break;

        default:
            cout<<"kode salah"<<endl;

        }
    }

    return 0;
}
