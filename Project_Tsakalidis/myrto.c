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


void countingSort(logh* a) {
    
    measureh sorted[a->size];
    
    int n = a->size; //to size twn A kai B
    int k = maxHum(a); //to size tou count
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


void heapSort(logh* a){
	int n = a->size;
	int l = (n / 2) + 1;
	int r = n;
	int k;
	int j;
	int s;
	
	while(r >= 2){
		if(l > 1){
			l--;
			j = l;
		}
		else{
			r--;
			j = l;
		}
	
		s = a->measurement[j].hum;
	
		while(2 * j <= r){
			k = 2 * j;
			if(k < r && a->measurement[k].hum < a->measurement[k + 1].hum){
				k++;
			}
			if(s < a->measurement[k].hum) {
				a->measurement[j].hum = a->measurement[k].hum;
				j = k;
			}
			else a->measurement[j].hum = s;
		}
	a->measurement[j].hum = s;
	}
}

int maxHum(logh* a){
	int n = a->size;
	heapSort(a);
	return a->measurement[n].hum;
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















