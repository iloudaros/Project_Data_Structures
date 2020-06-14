
//  koutou.h
//  Project_Tsakalidis
//  mergesort(), quicksort(), bis2timesearch()

#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include "johnnylouds.h"

//MERGESORT

void split(logt* p); 

void merge(logt* p,int max,int mid,int min);

void mergeSort(logt* p,int max,int min);

//QUICKSORT

void swap( int *a, int *b );

int partition( int *a, int low, int high );

void quickSort( int *a, int low, int high ); 

//BIS2SORT

void bis2sortt(logt* p);

void bis2sorth(logh* p);

void swaptm(measuret *a, measuret *b);

void swaphm(measureh *a, measureh *b);

#endif koutou_h
