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



//heapsort


void heapSort(logh* a){
    int n = a->size;
    int l = (n / 2) + 1;
    int r = n;
    int k;
    int j;
    measureh s;
    
    while(r >= 2){
        if(l > 1){
            l--;
            j = l;
        }
        else{
            r--;
            j = l;
        }
    
        s.timestamp.year = a->measurement[j].timestamp.year;
        s.timestamp.month = a->measurement[j].timestamp.month;
        s.timestamp.day = a->measurement[j].timestamp.day;
        s.timestamp.hour = a->measurement[j].timestamp.hour;
        s.timestamp.minute = a->measurement[j].timestamp.minute;
        s.timestamp.sec = a->measurement[j].timestamp.sec;
        s.hum = a->measurement[j].hum;
        
        while(2 * j <= r){
            k = 2 * j;
            if(k < r && a->measurement[k].hum < a->measurement[k + 1].hum){
                k++;
            }
            if(s.hum < a->measurement[k].hum) {
                a->measurement[j].timestamp.year = a->measurement[k].timestamp.year;
                a->measurement[j].timestamp.month = a->measurement[k].timestamp.month;
                a->measurement[j].timestamp.day = a->measurement[k].timestamp.day;
                a->measurement[j].timestamp.hour = a->measurement[k].timestamp.hour;
                a->measurement[j].timestamp.minute = a->measurement[k].timestamp.minute;
                a->measurement[j].timestamp.sec = a->measurement[k].timestamp.sec;
                a->measurement[j].hum = a->measurement[k].hum;
                j = k;
            }
            else{
                a->measurement[j].timestamp.year = s.timestamp.year;
                a->measurement[j].timestamp.month = s.timestamp.month;
                a->measurement[j].timestamp.day = s.timestamp.day;
                a->measurement[j].timestamp.hour = s.timestamp.hour;
                a->measurement[j].timestamp.minute = s.timestamp.minute;
                a->measurement[j].timestamp.sec = s.timestamp.sec;
                a->measurement[j].hum = s.hum;

            }
        }
    }
}



//vriskw ti megisth ugrasia


int maxHum(logh* a){
    int n = a->size;
    heapSort(a);
    return a->measurement[n].hum;
}

//counting sort


void countingSort(logh* a){
    
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
        count[i] = count[i] + count[i - 1];
    }
    for(j = n; j > 0; j--){
        sorted[count[a->measurement[j].hum]].hum = a->measurement[j].hum;
        count[a->measurement[j].hum] = count[a->measurement[j].hum] - 1;
    }
}








//binary interpolation search

void bis(time ts, logt* a){
    
    int n = a->size;
    
    int left = 1;
    int right = n;
    
    int sqr = sqrt(right - left);
    
    long int next = (((ts.together - a->measurement[left].timestamp.together) / a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
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
        printf("i thermokrasia pou anhkei sthn hmeromhnia %ld einai %f\n", ts.together, a->measurement[next].temp);
    }
    else printf("h hmeromhnia %ld den uparxei sti lista\n", ts.together);
}















