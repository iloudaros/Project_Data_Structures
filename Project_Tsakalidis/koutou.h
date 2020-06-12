
//  koutou.h
//  Project_Tsakalidis
//  mergesort(), quicksort(), bis2timesearch()

#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <stdbool.h>
#include "johnnylouds.h"

//MERGESORT

void split(logt* p); 

void merge(logt* p,int max,int mid,int min);

void mergeSort(logt* p,int max,int min);

//QUICKSORT

void swap( int *a, int *b );

int partition( int *a, int low, int high );

void quickSort( int *a, int low, int high ); 

#endif koutou_h
