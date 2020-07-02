//
//  orestis.c
//  Project_Tsakalidis
//
//  Created by Ioannis Loudaros on 10/6/20.
//  Copyright © 2020 Ιωάννης Λουδάρος. All rights reserved.
//

#include <stdio.h>
//
//  orestis.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης timesort(), bintimesearch(), intertimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3



#include <stdio.h>
#include <stdlib.h>
#include "johnnylouds.h"



//TIMESORT

void swap(measureh *a, measureh *b)
{
    measureh temp = *a;
    a->hum=b->hum;
    a->timestamp.year=b->timestamp.year;
    a->timestamp.month=b->timestamp.month;
    a->timestamp.day=b->timestamp.day;
    a->timestamp.minute=b->timestamp.minute;
    a->timestamp.hour=b->timestamp.hour;
    a->timestamp.sec=b->timestamp.sec;
    a->timestamp.together=b->timestamp.together;
    
    b->hum=temp.hum;
    b->timestamp.year=temp.timestamp.year;
    b->timestamp.month=temp.timestamp.month;
    b->timestamp.day=temp.timestamp.day;
    b->timestamp.minute=temp.timestamp.minute;
    b->timestamp.hour=temp.timestamp.hour;
    b->timestamp.sec=temp.timestamp.sec;
    b->timestamp.together=temp.timestamp.together;
    
    
}
  
void timesort(logh* p) //kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
    int n = p->size;
    int i, j, min_idx;
  
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (p->measurement[j].timestamp.together < p->measurement[min_idx].timestamp.together)
            min_idx = j;
  
        swap(&p->measurement[min_idx], &p->measurement[i]);
    }
}

//BINARY

int binarySearch(logh* p, int x, int l, int h) //psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi 
{
    int high = h-1;
    int low = 0;
    int mid;
    
    if (high >= low)
    {
        mid = low + (high - low)/2;

        if(p->measurement[mid].timestamp.together == x) //an einai sth mesh parto
        {
            return p->measurement[mid].hum;
        }
        else if (p->measurement[mid].timestamp.together > x)//psaxnw aristera
        {
            return binarySearch(p, x, low, mid-1);
        }
        else //psaxnw deksia
            return binarySearch(p, x, mid-1, high);
        }
    else //alliws ton poylo
        return -1;
    }

//INTERPOLATION

int interpolationSearch(logh* p, int x)
{
    int n = p->size;
    int low = 0;
    int high = (n - 1);
  
    while (low <= high && x >= p->measurement[low].timestamp.together && x <= p->measurement[high].timestamp.together)
    {
        if (low == high)
        {
            if (p->measurement[low].timestamp.together == x) return low;
            return -1;
        }

        //vriskw th thesh me ton typo apo to vivlio toy kyrioy tsakalidi
        int pos = low + (((double)(high - low) /
                          (p->measurement[high].timestamp.together - p->measurement[low].timestamp.together) * (x - p->measurement[low].timestamp.together)));
  
        //an to vrikame me th mia oyaoy
        if (p->measurement[pos].timestamp.together == x)
            return p->measurement[pos].hum;
  
        //an to x einai megalytero apo ayto poy vrikame des deksia
        if (p->measurement[pos].timestamp.together < x)
            low = pos + 1;
  
        //an to x einai mikrotero apo ayto poy vrikame des aristera
        else
            high = pos - 1;
    }
    return -1;
}






