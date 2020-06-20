//
//  myrto.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης heapsort(), countingsort()
//  Και ο αλγόριθμος αναζήτησης bistimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3

#ifndef myrto_h
#define myrto_h

#include "johnnylouds.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//heapsort

void heapSort(logh* a);
int maxHum(logh* a); //vriskei ti megaluteri ugrasia




//counting sort


void countingSort(logh* a);


//binary interpolation search

void bis(time ts, logh* a);
















#endif 
