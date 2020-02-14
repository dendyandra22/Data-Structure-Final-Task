#include "tubes.h"

adrRel createElmRel(){
    adrRel R = new elmRel;
    fur(R) = nil;
    nextRel(R) = nil;
    return R;
}

void createRelation(adrPeng &P,adrFur F){
    adrRel R = createElmRel();
    fur(R) = F;
    if(isRelEmpty(P)){
        rel(P) = R;
    }
    else{
        adrRel q = rel(P);
        while(nextRel(q)!=nil){
            q = nextRel(q);
        }
        nextRel(q) = R;
    }

}

void printRel(adrPeng P){
    if(isRelEmpty(P)){
        cout<<"Relasi Kosong"<<endl;
    }
    else{
        adrRel a = rel(P);
        while(a!=nil){
            adrFur x = fur(a);
            printFurniture(x);
            cout<<endl;
            a = nextRel(a);
        }
    }
}

void countRel(listPeng P){
    adrPeng X = first(P);
    int n = 0;
    adrPeng maxPeng;
    int nMax = 0;
    while(X!=nil){
        n = 0;
        if(isRelEmpty(X)){
            X = next(X);
        }
        else{
            adrRel r = rel(X);
            while(r!=nil){
                n++;
                r = nextRel(r);
            }
            if(n>=nMax){
                maxPeng = X;
                nMax = n;
            }
            X = next(X);

        }
    }
    cout<<"pengrajin dengan furniture terbanyak : "<<infoPeng(maxPeng).nama<<endl;
    cout<<"jumlah : "<<nMax<<" furniture"<<endl;

}

bool isRelEmpty(adrPeng P){
    return rel(P)==nil;
}

void delRel(adrPeng &p,string cari){
    if(!isRelEmpty(p)){
            adrRel s,r;
            r = rel(p);
            adrFur f = fur(r);
            while(r!=nil&&cari!=infoFur(f).nama){
                s = r;
                r = nextRel(r);
            }
            if(cari==infoFur(f).nama){
                if(r==rel(p)){
                    rel(p) = nil;
                    delete r;
                }
                else{
                    nextRel(s) = nextRel(r);
                    nextRel(r) = nil;
                    delete r;
                }
            }
    }
}

void relMenu(){
        cout<<"========================"<<endl;
        cout<<"Relation Menu"<<endl;
        cout<<"========================"<<endl;
        cout<<"1.create new relation"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"choice : ";

}
