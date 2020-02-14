/**
#include <iostream>
#include "tubes.h"
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
    bool exit = false;
    while(!exit){
        int pil;
        listPeng P;
        listFur F;
        char cari[20];
        adrPeng N;
        adrFur M;
        pengrajin x;
        furniture y;
        cout<<"========================"<<endl;
        cout<<"Main Menu"<<endl;
        cout<<"========================"<<endl;
        cout<<"0.print info"<<endl;
        cout<<"1.create list pengrajin"<<endl;
        cout<<"2.insert pengrajin"<<endl;
        cout<<"3.delete pengrajin"<<endl;
        cout<<"4.find pengrajin"<<endl;
        cout<<"5.create list furniture"<<endl;
        cout<<"6.create furniture"<<endl;
        cout<<"7.delete furniture"<<endl;
        cout<<"8.find pengrajin"<<endl;
        cout<<"10.check list peng"<<endl;
        cout<<"11.check list fur"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"choice : ";
        cin>>pil;
        system("CLS");
        switch(pil){
        case 0:
            cout<<"1.print pengrajin"<<endl;
            cout<<"2.print furniture"<<endl;
            cout<<"3.print all"<<endl;
            cout<<"--------------------"<<endl;
            cout<<"Pilihan\t : ";
            cin>>pil;
            system("CLS");
            if(pil==1){
                printPengrajin(P);
            }
            else if(pil==2){
                printAllFurniture(F);
            }
            else{
                cout<<"Pengrajin tidak ditemukan"<<endl;
            }
            cout<<"done"<<endl;
            break;
        case 1:
            createListPeng(P);
            cout<<"done"<<endl;
            break;
        case 2:
            cout<<"Masukkan Nama\t: ";
            //cin>>x.nama;
            cin.ignore();
            cin.getline(x.nama,sizeof(x.nama));
            cout<<"Asal\t\t: ";
            cin>>x.asal;
            N = createElmPeng(x);
            insertPeng(P,N);
            cout<<"done"<<endl;
            break;
        case 3:
            printPengrajin(P);
            cout<<"pengrajin yang mau dihapus : ";
            cin.ignore();
            cin.getline(cari,sizeof(cari));
            system("CLS");
            N = searchPeng(cari,P);
            if(N!=nil){
                delPeng(P,N);
                cout<<"done"<<endl;
            }
            else{
                cout<<"Tidak ada data"<<endl;
            }
            break;
        case 4:
            cout<<"data yang ingin dicari"<<endl;
            cin>>cari;
            N = searchPeng(cari,P);
            if(N!=nil){
                cout<<infoPeng(N).nama<<endl;
            }
            else{
                cout<<"data tidak ditemukan"<<endl;
            }
            break;
        case 5:
            createListFur(F);
            cout<<"done"<<endl;
            break;
        case 6:
            cout<<"nama furniture : ";
            cin>>y.nama;
            cout<<"jenis : ";
            cin>>y.jenis;
            M = createElmFur(y);
            insertFur(F,M);
            cout<<"done"<<endl;
            break;
        case 7:
            cout<<"furniture yang mau dihapus : ";
            cin>>cari;
            M = searchFur(cari,F);
            if(M!=nil){
                delFur(F,M);
                cout<<"done"<<endl;
            }
            else{
                cout<<"Furniture tidak ditemukan"<<endl;
            }
            break;
        case 8:
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
        case 10:
            if(isEmpty(P)){
                cout<<"kosong"<<endl;
            }
            else{
                cout<<"terisi"<<endl;
            }
            break;
        case 11:
            if(isEmpty(F)){
                cout<<"kosong"<<endl;
            }
            else{
                cout<<"terisi"<<endl;
            }
            break;
        case 12:
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
            break;
        case 13:
            cout<<"pengrajin yang ingin dilihat relasinya"<<endl;
            cin>>cari;
            N = searchPeng(cari,P);
            printRel(N);
            break;
        default:
            cout<<"kode salah"<<endl;
            exit = true;
        }
    }

    return 0;
}

**/
