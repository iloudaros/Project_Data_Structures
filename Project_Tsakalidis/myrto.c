//
//  myrto.c
//  Project_Tsakalidis
//
//  Created by Ioannis Loudaros on 10/6/20.
//  Copyright © 2020 Ιωάννης Λουδάρος. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


#include "johnnylouds.h"



//counting sort

//xreiazomai akoma mia sunarthsh pou tha vriskei to megalutero stoixeio tou pinaka wste na pernaw sthn k to size tou count
void countingSort(logh* a) {
    
    measureh sorted[a->size];
    
    int n = a->size; //to size twn A kai B
    int k; //to size tou count
    int i, j;
    int count[k];
    
    for(i = 0; i < k; i++){
        count[i] = 0;
    }
    for(j = 0; j < n; j++){
        count[a->measurement[j].hum] = count[a->measurement[j].hum] + 1;
    }
    for(i = 1; i < k; i++){
        count[i] = count[i] + count[i-1];
    }
    for(j = n; j > 0; j--){
        sorted[count[a->measurement[j].hum]].hum = a->measurement[j].hum;
        count[a->measurement[j].hum] = count[a->measurement[j].hum] - 1;
    }
}




//heapsort

void adjust(int heapArray[], int i, int n){
    int j = (2 * i);    //j is left child of i
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

void bis(time ts, logh* a){
    
    int n = a->size;
    
    int left = 1;
    int right = n;
    
    int sqr = sqrt(right - left);
    
    long next = (((ts.together - a->measurement[left].timestamp.together) / a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    while(ts.together != a->measurement[next].timestamp.together && left < right){
        int i = 0;
        if(ts.together >= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[next + i * sqr].timestamp.together){
                i++;
                right = i * sqr;
                left = (i - 1) * sqr;
            }
        }
        else if(ts.together <= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[next - i * sqr].timestamp.together){
                i++;
                right = (i - 1) * sqr;
                left = i * sqr;
            }
        }
        next = ((ts.together - a->measurement[left].timestamp.together) / (a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    }
    if(ts.together == a->measurement[next].timestamp.together){
        printf("to stoixeio %lf vrisketai sti thesi %lf\n", ts, next);
    }
    else printf("to stoixeio %lf den uparxei sti lista\n", ts);
}















