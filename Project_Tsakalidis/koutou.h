
//  koutou.h
//  Project_Tsakalidis
//  mergesort(), quicksort(), bis2timesearch()

#ifndef koutou_h
#define koutou_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void split(*p, int max,int min) //Xwrizei to array sth mesh kathe fora
{
  	int mid;
	if(min<max)
	{
	  mid= max+(min-max)/2; //Vriskei thn mesh tou array kai to xwrizei anadromika
	  split(p,min,mid);     //To max+(min-max)/2 einai idio me to (max+min)/2 alla se pio megales times apotrepei to overflow
	  split(p,mid+1,max);
	  merge(p,min,mid,max);
	}
}

void merge(*p,int max,int mid,int min)  //Enwnei ta subarrays
{
	int i, j, k;
	int n1= mid-max+1;
	int n2= min-mid;
	int arr[];
	
	int L[n1], R[n2]; //Temp arrays
	
	for(i=0; i<n1; i++)  //Antigrafh twn dedomenwn sta temp
		L[i]= arr[max + i]; //Kserw oti douleuoume me to pointer sto array kai oxi me to idio to array
	for(j=0; j<n2; j++)     //skeftomai na to allaksw auto to 'arr' THA DOUME
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
	
void mergeSort(*p,int max,int min) //Kanei to sort twn stoixeiwn me sugkriseis kai sto telos enwnei ola ta kommatia
	{
		if(max<min)
		{
			int mid= max+(min-max)/2;
			mergeSort(p,max,mid); 
			mergeSort(p,mid+1,min); 

			merge(p,max,mid,min);
		}
	}


#endif koutou_h
