#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include <stdbool.h>
#include "johnnylouds.h"


//MERGESORT

void split(logt* p) //Xwrizei to array sth mesh kathe fora
{
  	measuret sorted[a->size];
	
	int mid= a->size/2;
	int max= maxTemp(a);
	int min= logt.measurement[1]; 
	
	if(min<max)
	{
	  mid= max+(min-max)/2; //Vriskei thn mesh tou array kai to xwrizei anadromika
	  split(p,min,mid);     //To max+(min-max)/2 einai idio me to (max+min)/2 alla se pio megales times apotrepei to overflow
	  split(p,mid+1,max);
	  merge(p,min,mid,max);
	}
}

void merge(logt* p,int max,int mid,int min)  //Enwnei ta subarrays
{
	int i, j, k;
	int mid= a->size/2;
	int max= maxTemp(a);
	int min= logt.measurement[1]; 
	int n1= mid-max+1;
	int n2= min-mid;
	
	int L[n1], R[n2]; //Temp arrays
	
	for(i=0; i<n1; i++)  //Antigrafh twn dedomenwn sta temp
		L[i]= arr[max + i]; 
	for(j=0; j<n2; j++)  
		R[j]= arr[mid+1+j];
	
	i=0;
	j=0
	k=l;
	
	while (i < n1 && j < n2) //Ta temp arrays ksana sto original array
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	
	while (i < n1) //Antigrafh tuxon upoleipomenwn stoixeiwn tou L[]
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 
	
	while (j < n2) //Antigrafh tuxon upoleipomenwn stoixeiwn tou R[]
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
}
	
void mergeSort(logt* p,int max,int min) //Kanei to sort twn stoixeiwn me sugkriseis kai sto telos enwnei ola ta kommatia
	{
		if(max<min)
		{
			int mid= max+(min-max)/2;
			mergeSort(p,max,mid); 
			mergeSort(p,mid+1,min); 

			merge(p,max,mid,min);
		}
	}

//QUICKSORT

void swap( int *a, int *b ) //Utility function gia swaping
{
    assert( a != NULL );
    assert( b != NULL );

    int temp = *a;
    *a       = *b;
    *b       = temp;
}

//Orizetai to pivot(prwto stoixeio) topotheteitai sthn swsth thesh,
//deksia apo auto topothetountai ta megalutera stoixeia kai
//aristera apo auto topothetountai ta mikrotera stoixeia

int partition( int *a, int low, int high )   
{
    assert( a != NULL );

    bool flag  = false;
    int  first = low;        /// Deikths sta aristera (indice)
    int  last  = high +1;    /// Deikths sta deksia (indice)
    int  pivot = a[ low ];   /// Antikeimeno tou partitioning

    while ( !flag ) {
        while ( a[ ++first ] < pivot ) {   /// Scan left and move
            if ( first == high) flag = true;
        }
        while ( a[ --last ] > pivot ) {    /// Scan right and move
            if ( last == low ) flag  = true;
        }

        if ( first >= last ) {
            flag = true;
        }
        else {
            swap( &a[ first], &a[ last ] );
        }
    }

    swap( &a[ low ], &a[ last ] );

    return last;
}

void quickSort( int *a, int low, int high )  //H sunarthsh pou ousiastika ulopoiei to sortarisma 
{
    assert( a != NULL );

    if ( high <= low ) {
        return;
    }

    int k = partition( a, low, high );
    quickSort( a, low, k - 1 );     /// Sort left part
    quickSort( a, k + 1, high );    /// Sort right part
}

