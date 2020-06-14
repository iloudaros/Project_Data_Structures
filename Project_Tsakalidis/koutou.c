#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <assert.h>
#include "johnnylouds.h"


//MERGESORT

void split(logt* p, measuret max, measuret min) //Xwrizei to array sth mesh kathe fora
{
  	measuret* sorted[p>size];
	
	measuret mid= p->size/2;
	
	if(min<max)
	{
	  mid= max+(min-max)/2; //Vriskei thn mesh tou array kai to xwrizei anadromika
	  split(p,min,mid);     //To max+(min-max)/2 einai idio me to (max+min)/2 alla se pio megales times apotrepei to overflow
	  split(p,mid+1,max);
	  merge(p,min,mid,max);
	}
}

void merge(logt* p, measuret max,meausuret mid,measuret min)  //Enwnei ta subarrays
{
	int i, j, k, l;
	int n1= mid-max+1;
	int n2= min-mid;
	
	measuret* L[n1], R[n2]; //Temp arrays
	
	for(i=0; i<n1; i++)  //Antigrafh twn dedomenwn sta temp
		L[i]= logt.measurement[i+max];
	for(j=0; j<n2; j++)  
		R[j]= logt.measurement[j+1+mid];
	
	i=0;
	j=0;
	k=l;
	
	while (i < n1 && j < n2) //Ta temp arrays ksana sto original array
	{ 
		if (L[i] <= R[j]) 
		{ 
			(logt).measurement[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			logt.measurement[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 
	
	while (i < n1) //Antigrafh tuxon upoleipomenwn stoixeiwn tou L[]
	{ 
		logt.measurement[k] = L[i]; 
		i++; 
		k++; 
	} 
	
	while (j < n2) //Antigrafh tuxon upoleipomenwn stoixeiwn tou R[]
	{ 
		logt*.measurement[k] = R[j]; 
		j++; 
		k++; 
	} 
}
	
void mergeSort(logt* p,measuret max,measuret min) //Kanei to sort twn stoixeiwn me sugkriseis kai sto telos enwnei ola ta kommatia
	{
		if(max<min)
		{
			measuret mid= max+(min-max)/2;
			mergeSort(p,max,mid); 
			mergeSort(p,mid+1,min); 

			merge(p,max,mid,min);
		}
	}

//QUICKSORT

void swap(measuret *a, measuret *b ) //Utility function gia swaping
{
	measuret temp = *a;
    *a       = *b;
    *b       = temp;
}

//Orizetai to pivot(prwto stoixeio) topotheteitai sthn swsth thesh,
//deksia apo auto topothetountai ta megalutera stoixeia kai
//aristera apo auto topothetountai ta mikrotera stoixeia

int partition(logt* p, measuret low, measuret high )   
{
	measuret i= (low-1);
    measuret pivot = logt.measurement[1];   /// Antikeimeno tou partitioning

    
    for (int j = low; j <= high- 1; j++) 
    { 
         
        if (logt.measurement[j] < pivot) // An to trexon stoixeio einai mikrotero tou pivot
        { 
            i++;     
            swap(&logt.measurement[i], &logt.measurement[j]); 
        } 
    } 
    swap(&logt.measurement[i + 1], &logt.measurement[high]); 
    return (i + 1); 
}

void quickSort(measuret *a, measuret low, measuret high )  //H sunarthsh pou ousiastika ulopoiei to sortarisma 
{
    
	if (low<high) 
	{
    	measuret par= partition(p, low, high);
		quickSort(p, low, par-1);
		quickSort(p, par+1, high);    
    }

}




//BIS2SORT


void bis2sortt(logt* p)
{
	int n = p->size;
    int i, j, min_idx;
  
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (p->measurement[j].timestamp.together < p->measurement[min_idx].timestamp.together)
            min_idx = j;
  
        swaptm(&p->measurement[min_idx], &p->measurement[i]);
    }
}


void bis2sorth(logh* p)
{
	int n = p->size;
    int i, j, min_idx;
  
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (p->measurement[j].timestamp.together < p->measurement[min_idx].timestamp.together)
            min_idx = j;
  
        swaptm(&p->measurement[min_idx], &p->measurement[i]);
    }
}

void swaptm(measuret *a, measuret *b)
{
	measuret temp = *a;
    *a       = *b;
    *b       = temp;
}

void swaphm(measureh *a, measureh *b)
{
	measureh temp = *a;
    *a       = *b;
    *b       = temp;
}
