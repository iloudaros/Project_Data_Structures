
//  koutou.h
//  Project_Tsakalidis
//  mergesort(), quicksort(), bis2timesearch()

#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <assert.h>
#include "johnnylouds.h"

//MERGESORT

void mergesortt(logt* p,int min,int max);

void merge(logt* p,int min,int mid,int max);

//QUICKSORT

void quick_sort(logt* p,int first,int last);

//BIS2SORT
void bis2sortt(logt* p);

void bis2sorth(logh* p);


#endif //koutou_h
