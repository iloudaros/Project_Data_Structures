//
//  myrto.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης heapsort(), countingsort()
//  Και ο αλγόριθμος αναζήτησης bistimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3

#ifndef myrto.h
#define myrto.h


#include<stdio.h>
#include<stdlib.h>

//counting sort

//xreiazomai akoma mia sunarthsh pou tha vriskei to megalutero stoixeio tou pinaka wste na pernaw sthn k to size tou count
void countingSort(int arrayA[], int count[], int arrayB[]) {
	int n; //to size twn A kai B
	int k; //to size tou count
	int i, j;
	for(i = 0; i < k; i++){
		count[i] = 0;
	}
	for(j = 0; j < n; j++){
		count[arrayA[j]] = count[arrayA[j]] + 1;
	}
	for(i = 1; i < k; i++){
		count[i] = count[i] + count[i-1];
	}
	for(j = n; j > 0; j--){
		arrayB[count[arrayA[j]]] = arrayA[j];
		count[arrayA[j]] = count[arrayA[j]] - 1; 
	}
}

item = heapArray[i]; //to periexomeno tis thesis i sti metavlhth item
	
	//oso uparxei ena stoixeio sti thesi j
	while(j <= n){
		//sugkrinw to stoixeio tis j me to epomeno an uparxei
		if(j < n && heapArray[j] < heapArray[j+1]){
			j++;
		}
		if(item >= heapArray[j]){
			break;
		}
		heapArray[j/2] = heapArray[j];
		j = 2 * j;
	}
	heapArray[j/2] = item;
}

void heapify(int array[], int n){
	int i;
	for(i = n/2; i >= 1; i--){
		adjust(array, i, n);
	}
}

void heapSort(int array[], int n){
	int i;
	heapify(array, n);
	int temp;
	for(i = n; i >= 2; i--){
		temp = array[1];
		array[1] = array[i];
		adjust(array, 1 ,i-1);
		array[i] = temp;
	}
}
















#endif myrto.h
