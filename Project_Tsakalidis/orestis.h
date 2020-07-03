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


//TIMESORT



  
void timesortt(logt* p);//kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
void timesorth(logh* p);


int binarySearchh(logh* p, long int x, int l, int h);//psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi
int binarySearcht(logt* p, long int x, int l, int h);

int interpolationSearch(logh* p, int x);



#endif //orestis_h
