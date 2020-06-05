//
//  orestis.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης timesort(), bintimesearch(), intertimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3

#ifndef orestis_h
#define orestis_h

#include <stdio.h>
#include <stdlib.h>



//TIMESORT

void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
}  
  
void timesort(*p, int n) //kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (p[j].time.together < p[min_idx].time.together)  
            min_idx = j;  
  
        swap(&p[min_idx].time.together, &p[i].time.together);  
    }  
}  

//BINARY

int binarySearch(*p, int x, int n) //psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
	int high = n-1;
	int low = 0;
	int mid;
	
    if high >= low
    {
        mid = low + (high - low)/2

        if p[mid].time.together == x //an einai sth mesh parto
            return mid

        elif p[mid].time.together > x //psaxnw aristera
            return binarySearch(*p, x, low, mid-1)

        else //psaxnw deksia
            return binarySearch(*p, x, mid + 1, high)

    else //alliws ton poylo
        return -1
    }
}   

//INTERPOLATION

int interpolationSearch(*p, int n, int x) 
{  
    int low = 0;
	int high = (n - 1); 
  
    // Since array is sorted, an element present 
    // in array must be in range defined by corner 
    while (low <= high && x >= p[low].time.together && x <= p[high].time.together) 
    { 
        if (low == high) 
        { 
            if (p[low].time.together == x) return low; 
            return -1; 
        } 

        //vriskw th thesh me ton typo apo to vivlio toy kyrioy tsakalidi 
        int pos = low + (((double)(high - low) / 
            (p[high].time.together - arr[low])) * (x - p[low].time.together)); 
  
        //an to vrikame me th mia oyaoy
        if (p[pos].time.together == x) 
            return pos; 
  
        //an to x einai megalytero apo ayto poy vrikame des deksia
        if (p[pos].time.together < x) 
            low = pos + 1; 
  
        //an to x einai mikrotero apo ayto poy vrikame des aristera 
        else
            high = pos - 1; 
    } 
    return -1; 
} 






#endif orestis_h
