
//  koutou.h
//  Project_Tsakalidis
//  mergesort(), quicksort(), bis2timesearch()

#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
#include "myrto.h"
#include "johnnylouds.h"

//MERGESORT

void mergesortt(logt* p,int min,int max);

void merge(logt* p,int min,int mid,int max);

//QUICKSORT

void quick_sort(logt* p,int first,int last);

//Δέντρο

node* createBSTtemp(logt* a);

node* inserttemp(node* node, measuret data);

node* maxValueNode(node* node);

#endif //koutou_h
