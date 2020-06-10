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

void swap(int *a, int *b);

  
void timesort(logh* p);//kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi


int binarySearch(logh* p, int x, int l, int h);//psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi


int interpolationSearch(logh* p, int x);



#endif orestis_h
