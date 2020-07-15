//
//  orestis.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης timesort(), bintimesearch(), intertimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3

#ifndef orestis_h
#define orestis_h

#include <stdio.h>
#include <stdlib.h>
#include "johnnylouds.h"




//1st part
  
void timesortt(logt* p);//kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
void timesorth(logh* p);


int binarySearchh(logh* p, long int x, int low, int high);//psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi
int binarySearcht(logt* p, long int x, int low, int high);

int interpolationSearchh(logh* p,long int x);
int interpolationSearcht(logt* p,long int x);

//2nd part

//Structs

typedef struct{
    measuret data;
    struct nodeO* next;
    long int key;

} nodeO;


typedef struct{
    nodeO* head;
    int count;
} hash;

typedef struct{
    hash* table;
    int eleCount;
} hashtable;



int digitsum(timej measurement);

//HashTable Manipulation
void insertToHash(measuret input,hashtable* a);

void deleteFromHash(long int key, hashtable* a);

void searchInHash(long int key, hashtable* a);

void changeInHash(long int key,float change, hashtable* a);

void display(hashtable* a);

#endif //orestis_h
