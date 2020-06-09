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
#include<math.h>

//counting sort

//xreiazomai akoma mia sunarthsh pou tha vriskei to megalutero stoixeio tou pinaka wste na pernaw sthn k to size tou count
void countingSort(int A[], int count[], int B[]) {
	int n; //to size twn A kai B
	int k; //to size tou count
	int i, j;
	for(i = 0; i < k; i++){
		count[i] = 0;
	}
	for(j = 0; j < n; j++){
		count[A[j]] = count[A[j]] + 1;
	}
	for(i = 1; i < k; i++){
		count[i] = count[i] + count[i-1];
	}
	for(j = n; j > 0; j--){
		B[count[A[j]]] = A[j];
		count[A[j]] = count[A[j]] - 1; 
	}
}




//heapsort

void adjust(int heapArray[], int i, int n){
	int j = (2 * i);	//j is left child of i
	int item = heapArray[i]; //to periexomeno tis thesis i sti metavlhth item
	
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




//binary interpolation search

void access(int ts, int a[]){
	
	int n; //o arithmos twn timestamps/twn metrhsewn
	
	int left = 1;
	int right = n;
	
	int sqr = sqrt(right - left);
	
	int next = (((ts - a[left]) / a[right] - a[left]) * (right - left));
	while(ts != a[next] && left < right){
		int i=0;
		if(ts >= a[next]){
			while(ts > a[next + i * sqr]){
				i++;
				right = i * sqr;
				left = (i - 1) * sqr;
			}
		}
		else if(ts <= a[next]){
			while(ts > a[next - i * sqr]){
				i++;
				right = (i - 1) * sqr;
				left = i * sqr;
			}
		}
		next = ((ts - a[left]) / (a[right] - a[left]) * (right - left));
	}
	if(ts == a[next]){
		printf("to stoixeio %d vrisketai sti thesi %d\n", ts, next);
	}
	else printf("to stoixeio %d den uparxei sti lista\n", ts);
}

















#endif myrto.h
