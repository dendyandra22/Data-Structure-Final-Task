#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
#include <stdlib.h>

/** pengrajin definition **/
#define infoPeng(P) P->infoPeng
#define rel(P)  P->rel
#define next(P) P->next
#define prev(P) P->prev

/** furniture definition **/
#define infoFur(P) P->infoFur
#define next(P) P->next
#define prev(P) P->prev

/** relasi definition **/
#define fur(R) R->fur
#define nextRel(R) R->nextRel


/** global definition **/
#define first(P) P.first
#define last(P) P.last
#define nil NULL

using namespace std;
typedef struct elmPeng *adrPeng;
typedef struct elmRel *adrRel;
typedef struct elmFur *adrFur;

/** pengrajin declaration **/
struct pengrajin{
    char nama[30];
    char asal[30];
};

typedef pengrajin infotypePeng;
struct elmPeng{
    infotypePeng infoPeng;
    adrRel  rel;
    adrPeng next;
    adrPeng prev;
};

struct listPeng{
    adrPeng first;
    adrPeng last;
};

void createListPeng(listPeng &P);
adrPeng createElmPeng(pengrajin x);
void insertPeng(listPeng &P,adrPeng X);
bool isEmpty(listPeng P);
void delPeng(listPeng &P,adrPeng X);
adrPeng searchPeng(string cari,listPeng P);
void printPengrajin(listPeng P);
void viewPengToPeng(listPeng P);
void pengMenu();



/** furniture declaration **/

struct furniture{
    char nama[20];
    char jenis[20];
    char bahan[20];
    char harga[20];
};
typedef furniture infotypeFur;
struct elmFur{
    infotypeFur infoFur;
    adrFur next;
    adrFur prev;
};
struct listFur{
    adrFur first;
    adrFur last;
};



void createListFur(listFur &P);
adrFur createElmFur(furniture x);
void insertFur(listFur &P,adrFur x);
bool isEmpty(listFur P);
void delFur(listFur &P,adrFur x,listPeng &q);
adrFur searchFur(string cari,listFur P);
void printFurniture(adrFur q);
void printAllFurniture(listFur P);
void viewFurPeng(listPeng P,string cari);
void countPeng(listPeng P,listFur F);
void countTwoPeng(listPeng P,listFur F);
void furMenu();

/** relasi declaration **/


typedef struct elmRel{
    adrFur fur;
    adrRel nextRel;
};

adrRel createElmRel();
void createRelation(adrPeng &P,adrFur F);
bool isRelEmpty(adrPeng P);
void countRel(listPeng P);
void printRel(adrPeng P);
void delRel(adrPeng &P,string cari);
void relMenu();


#endif // TUBES_H_INCLUDED
