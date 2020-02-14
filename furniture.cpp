#include "tubes.h"

void createListFur(listFur &P){
    first(P) = nil;
    last(P) = nil;
}

adrFur createElmFur(furniture x){
    adrFur P = new elmFur;
    infoFur(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void insertFur(listFur &P,adrFur x){
    if(isEmpty(P)){
        first(P) = x;
        last(P) = x;
    }
    else{
        next(last(P)) = x;
        prev(x) = last(P);
        last(P) = x;
    }

}

bool isEmpty(listFur P){
    return first(P) == nil;
}

adrFur searchFur(string cari,listFur P){
    adrFur q = first(P);
    while(q!=nil&&cari!=infoFur(q).nama){
        q=next(q);
    }
    return q;
}

void delFur(listFur &P,adrFur x,listPeng &q){
    if(!isEmpty(P)){
        if(first(P)==x&&last(P)==x){
            first(P) = nil;
            last(P) = nil;
            string del = infoFur(x).nama;
            adrPeng peng = first(q);
            while(peng!=nil){
                delRel(peng,del);
                peng = next(peng);
            }
            delete x;
        }
        else if(first(P)==x){
            first(P) = next(x);
            prev(next(x)) = nil;
            next(x) = nil;
            prev(x) = nil;
            string del = infoFur(x).nama;
            adrPeng peng = first(q);
            while(peng!=nil){
                delRel(peng,del);
                peng = next(peng);
            }
            delete x;
        }
        else if(last(P)==x){
            last(P) = prev(x);
            next(prev(x)) = nil;
            next(x) = nil;
            prev(x) = nil;
            string del = infoFur(x).nama;
            adrPeng peng = first(q);
            while(peng!=nil){
                delRel(peng,del);
                peng = next(peng);
            }
            delete x;
        }
        else{
            next(prev(x)) = next(x);
            prev(next(x)) = prev(x);
            next(x) = nil;
            prev(x) = nil;
            string del = infoFur(x).nama;
            adrPeng peng = first(q);
            while(peng!=nil){
                delRel(peng,del);
                peng = next(peng);
            }
            delete x;
        }
    }
}

void printFurniture(adrFur q){
    if(q!=nil){
        cout<<"Nama Furnitre : "<<infoFur(q).nama;
        cout<<endl;
        cout<<"Jenis : "<<infoFur(q).jenis;
        cout<<endl;
        cout<<"Bahan : "<<infoFur(q).bahan;
        cout<<endl;
        cout<<"Harga : "<<infoFur(q).harga;
        cout<<endl;
    }
    else{
        cout<<"Tidak ada furniture"<<endl;
    }
}

void printAllFurniture(listFur P){
    if(!isEmpty(P)){
        adrFur q = first(P);
        cout<<"- - - - - - - - list furniture -  - - - - - -"<<endl;
        while(q!=nil){
            cout<<"Nama Furniture : "<<infoFur(q).nama;
            cout<<endl;
            cout<<"Jenis : "<<infoFur(q).jenis;
            cout<<endl;
            cout<<"Bahan : "<<infoFur(q).bahan;
            cout<<endl;
            cout<<"Harga : "<<infoFur(q).harga;
            cout<<endl;
            q = next(q);
        }
    }
    else{
        cout<<"Tidak ada data"<<endl;
    }
}

void viewFurPeng(listPeng P,string cari){
    if(!isEmpty(P)){
        adrFur f;
        adrPeng q = first(P);
        while(q!=nil){
            if(!isRelEmpty(q)){
                adrRel r = rel(q);
                while(r!=nil){
                    f = fur(r);
                    if(cari==infoFur(f).nama){
                        r = nil;
                    }
                    else{
                        r = nextRel(r);
                    }
                }
                if(cari==infoFur(f).nama){
                    cout<<infoPeng(q).nama<<endl;
                }
            }
            q = next(q);
        }
    }
    else{
        cout<<"data pengrajin kosong"<<endl;
    }
}



void furMenu(){
        cout<<"========================"<<endl;
        cout<<"Pengrajin Menu"<<endl;
        cout<<"========================"<<endl;
        cout<<"0.print info"<<endl;
        cout<<"1.create list furniture"<<endl;
        cout<<"2.insert furniture"<<endl;
        cout<<"3.delete furniture"<<endl;
        cout<<"4.find furniture"<<endl;
        cout<<"5.check list furniture"<<endl;
        cout<<"6.view furniture creator"<<endl;
        cout<<"7.furniture dikerjakan oleh pengrajin terbanyak"<<endl;
        cout<<"8.furniture dikerjakan oleh 2 pengrajin"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"choice : ";

}
