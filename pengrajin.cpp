#include "tubes.h"

void createListPeng(listPeng &P){
    first(P) = nil;
    last(P) = nil;
}

adrPeng createElmPeng(pengrajin x){
    adrPeng P = new elmPeng;
    infoPeng(P) = x;
    rel(P) = nil;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertPeng(listPeng &P,adrPeng X){
    if(!isEmpty(P)){
        next(last(P)) = X;
        prev(X) = last(P);
        last(P) = X;
    }
    else{
        first(P) = X;
        last(P) = X;
    }

}

bool isEmpty(listPeng P){
    return first(P) == nil;
}

adrPeng searchPeng(string cari,listPeng P){
    adrPeng q = first(P);
    while(q!=nil&&cari!=infoPeng(q).nama){
        q=next(q);
    }
    return q;
}

void delPeng(listPeng &P,adrPeng X){
    //adrPeng Q;
    if(first(P)==X&&last(P)==X){
        rel(X) = nil;
        first(P) = nil;
        last(P) = nil;
        delete X;
    }
    else if(first(P)==X&&last(P)!=X){
        first(P) = next(X);
        prev(next(X)) = nil;
        next(X) = nil;
        rel(X) = nil;
        prev(X) = nil;
        delete X;
    }
    else if(first(P)!=X&&last(P)==X){
        last(P) = prev(X);
        next(prev(X)) = nil;
        prev(X) = nil;
        rel(X) = nil;
        prev(X) = nil;
        delete X;
    }
    else if(first(P)!=X&&last(P)!=X){
        next(prev(X)) = next(X);
        prev(next(X)) = prev(X);
        next(X) = nil;
        rel(X) = nil;
        prev(X) = nil;
        delete X;
    }
}

void printPengrajin(listPeng P){
    if(!isEmpty(P)){
        adrPeng q = first(P);
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        while(q!=nil){
            cout<<"Nama : "<<infoPeng(q).nama<<" ";
            cout<<endl;
            cout<<"Asal : "<<infoPeng(q).asal<<" ";
            cout<<endl;
            printRel(q);
            cout<<endl;
            q = next(q);
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
    else{
        cout<<"tidak ada data"<<endl;
    }
}

void countPeng(listPeng P, listFur F){
    adrFur y = first(F);
    adrPeng X = first(P);
    int n = 0;
    adrFur maxFur = nil;
    int nMax = 0;
    while(y!=nil){
        n = 0;
        adrPeng X = first(P);
        while(X!=nil){
            if(isRelEmpty(X)){
                X = next(X);
            }
            else{
                adrRel r = rel(X);
                while(r!=nil){
                    adrFur a = fur(r);
                    if(infoFur(y).nama==infoFur(a).nama){
                        n++;
                        r = nil;
                    }
                    else{
                        r = nextRel(r);
                    }
                }
                X = next(X);
            }
        }
        if(n>=nMax){
            maxFur = y;
            nMax = n;

        }
        y = next(y);
    }

    cout<<"furniture dengan pengrajin terbanyak : "<<infoFur(maxFur).nama<<endl;
    cout<<"jumlah : "<<nMax<<" pengrajin"<<endl;
}

void countTwoPeng(listPeng P, listFur F){
    adrFur y = first(F);
    adrPeng X = first(P);
    int n = 0;
    adrFur maxFur;
    int nMax = 0;
    while(y!=nil){
        n = 0;
        adrPeng X = first(P);
        while(X!=nil){
            if(isRelEmpty(X)){
                X = next(X);
            }
            else{
                adrRel r = rel(X);
                while(r!=nil){
                    adrFur a = fur(r);
                    if(infoFur(y).nama==infoFur(a).nama){
                        n++;
                        r = nil;
                    }
                    else{
                        r = nextRel(r);
                    }
                }
                X = next(X);
            }
        }
        if(n==2){
            maxFur = y;
            nMax=n;
        }
        y = next(y);
    }

    if(nMax==2){
        cout<<"furniture dikerjakan oleh 2 pengrajin : "<<infoFur(maxFur).nama<<endl;
    }
    else{
        cout<<"furniture dikerjakan oleh 2 pengrajin : Tidak ada"<<endl;
    }
}

void viewPengToPeng(listPeng P){
    string cari,nama;
    cout<<"nama pengrajin : ";
    cin>>nama;
    cout<<"pengrajin yang menjalin kerja sama : "<<endl;
    if(!isEmpty(P)){
        adrFur f,f2;
        adrRel r1,r2;
        adrPeng a,q;
        a = searchPeng(nama,P);
        if(a!=nil){
            r1 = rel(a);
            while(r1!=nil){
                f  = fur(r1);
                cari = infoFur(f).nama;
                q = first(P);
                while(q!=nil){
                    if(infoPeng(q).nama==nama||rel(q)==nil){
                        q = next(q);
                    }
                    else{
                        adrRel r2 = rel(q);
                        f2 = fur(r2);
                        while(r2!=nil&&cari!=infoFur(f2).nama){
                            r2 = nextRel(r2);
                            f2 = fur(r2);
                        }
                        if(cari==infoFur(f2).nama){
                            cout<<infoPeng(q).nama<<endl;
                            //q = next(q);
                        }
                        q = next(q);
                    }

                }
                r1 = nextRel(r1);
            }
        }
        else{
            cout<<"pengrajin tidak ditemukan"<<endl;
        }
    }
    else{
        cout<<"data pengrajin kosong"<<endl;
    }
}


void pengMenu(){
        cout<<"========================"<<endl;
        cout<<"Pengrajin Menu"<<endl;
        cout<<"========================"<<endl;
        cout<<"0.print info"<<endl;
        cout<<"1.create list pengrajin"<<endl;
        cout<<"2.insert pengrajin"<<endl;
        cout<<"3.delete pengrajin"<<endl;
        cout<<"4.find pengrajin"<<endl;
        cout<<"5.check list pengrajin"<<endl;
        cout<<"6.pengrajin dengan furniture terbanyak"<<endl;
        cout<<"7.hubungan pengrajin dengan pengrajin lainnya"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"choice : ";

}



/*void printAll(listPeng P){
    if(!isEmpty(P)){
        adrPeng q = first(P);
        while(q!=nil){
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"Nama pengrajin : "<<info(q).nama<<endl;
            cout<<"Asal : "<<info(q).asal<<endl;
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            //adrFur x = fur(q);
            printFurniture(x);
            q = next(q);
        }
    }
    else{
        cout<<"tidak ada data"<<endl;
    }
}*/
