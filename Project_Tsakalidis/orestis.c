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




//PART 1

//TIMESORT

void timesortt(logt* p) //kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
    int n = p->size;
    int i, j, min_idx;
  
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (p->measurement[j].timestamp.together < p->measurement[min_idx].timestamp.together)
            min_idx = j;
  
        swapt(&p->measurement[min_idx], &p->measurement[i]);
    }
}

void timesorth(logh* p) //kanw sort ton pinaka me vash ta timestamps gia na mporw meta na kanw binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
    int n = p->size;
    int i, j, min_idx;
  
    for (i = 0; i < n; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (p->measurement[j].timestamp.together < p->measurement[min_idx].timestamp.together)
            min_idx = j;
  
        swaph(&p->measurement[min_idx], &p->measurement[i]);
    }
}

//BINARY

int binarySearchh(logh* p, long int x, int low, int high) //psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
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
            return binarySearchh(p, x, low, mid);
        }
        else //psaxnw deksia
            return binarySearchh(p, x, mid, high);
        }
    else //alliws ton poylo
        return -5;
    }


int binarySearcht(logt* p, long int x, int low, int high) //psaxnw me vash to timestamp me th methodo binary search poy ematha apo to vivlio toy kyrioy tsakalidi
{
    int mid;
    
    if (high >= low)
    {
        mid = low + (high - low)/2;

        if(p->measurement[mid].timestamp.together == x) //an einai sth mesh parto
        {
            return p->measurement[mid].temp;
        }
        else if (p->measurement[mid].timestamp.together > x)//psaxnw aristera
        {
            return binarySearcht(p, x, low, mid);
        }
        else //psaxnw deksia
            return binarySearcht(p, x, mid, high);
        }
    else //alliws ton poylo
        return -5;
    }

//INTERPOLATION

int interpolationSearchh(logh* p, long int x)
{
    int n = p->size;
    int low = 0;
    int high = (n - 1);
  
    while (low <= high && x >= p->measurement[low].timestamp.together && x <= p->measurement[high].timestamp.together)
    {
        if (low == high)
        {
            if (p->measurement[low].timestamp.together == x) return low;
            return -5;
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
    return -5;
}



int interpolationSearcht(logt* p, long int x)
{
    int n = p->size;
    int low = 0;
    int high = (n - 1);
  
    while (low <= high && x >= p->measurement[low].timestamp.together && x <= p->measurement[high].timestamp.together)
    {
        if (low == high)
        {
            if (p->measurement[low].timestamp.together == x) return low;
            return -5;
        }

        //vriskw th thesh me ton typo apo to vivlio toy kyrioy tsakalidi
        int pos = low + (((double)(high - low) /
                          (p->measurement[high].timestamp.together - p->measurement[low].timestamp.together) * (x - p->measurement[low].timestamp.together)));
  
        //an to vrikame me th mia oyaoy
        if (p->measurement[pos].timestamp.together == x)
            return p->measurement[pos].temp;
  
        //an to x einai megalytero apo ayto poy vrikame des deksia
        if (p->measurement[pos].timestamp.together < x)
            low = pos + 1;
  
        //an to x einai mikrotero apo ayto poy vrikame des aristera
        else
            high = pos - 1;
    }
    return -5;
}



//PART 2



int digitsum(timej measurement)
{
    long int temp = measurement.together/10000;
    char c = '-';
    
    int sum = 0;
    int m;
    
    
    while (temp>0)
    {
        m = temp%10;
        sum = sum + m;
        temp = temp/10;
    }
    
    int result = (int)temp+3*(int)c;
    
    return result;
}


struct hash *hashTable = NULL;
int eleCount = 0;

struct nodeO {
    measuret data;
    long int key;
    struct nodeO *next;
};



struct hash {
struct nodeO *head;
int count;
};


struct nodeO * createNode(measuret input) {
    struct nodeO *newnode;
    newnode = (struct nodeO *) malloc(sizeof(struct nodeO));
    passmeasurementt(&input, &newnode->data);
    newnode->next = NULL;
    newnode->key = input.timestamp.together;
    return newnode;
}


void insertToHash(measuret input) {
    int hashIndex = digitsum(input.timestamp) % eleCount;
    struct nodeO *newnode = createNode(input);
    /* head of list for the bucket with index "hashIndex" */
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    
    /* adding new node to the list */
    newnode->next = (hashTable[hashIndex].head);
    /*
     * update the head of the list and no of
     * nodes in the current bucket
     */
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
    }

void deleteFromHash(long int key) {
    /* find the bucket using hash index */
    int hashIndex = key % eleCount, flag = 0;
    struct nodeO *temp, *myNode;
    /* get the list head from current bucket */
    myNode = hashTable[hashIndex].head;
    if (!myNode) {
        printf("Given data is not present in hash Table!!\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        /* delete the node with given key */
        if (myNode->key == key) {
            flag = 1;
            if (myNode == hashTable[hashIndex].head)
                hashTable[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;

            hashTable[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag)
        printf("Data deleted successfully from Hash Table\n");
    else
        printf("Given data is not present in hash Table!!!!\n");
    return;
    }

    void searchInHash(long int key) {
        int hashIndex = key % eleCount, flag = 0;
        struct nodeO *myNode;
        myNode = hashTable[hashIndex].head;
        if (!myNode) {
            printf("Search element unavailable in hash table\n");
            return;
        }
        while (myNode != NULL) {
            if (myNode->key == key) {
                printf("Key  : %ld\n-->\tDate: %d/%d/%d Temperature: %f  ", myNode->key,myNode->data.timestamp.day, myNode->data.timestamp.month, myNode->data.timestamp.year, myNode->data.temp);
                flag = 1;
                break;
            }
        myNode = myNode->next;
        }
        if (!flag)
            printf("Search element unavailable in hash table\n");
        return;
    }

    void display() {
        struct nodeO *myNode;
        int i;
        for (i = 0; i < eleCount; i++) {
            if (hashTable[i].count == 0)
                continue;
            myNode = hashTable[i].head;
            if (!myNode)
                continue;
            printf("\nData at index %d in Hash Table:\n", i);
            printf("    Key     Measurement      Date   \n");
            printf("--------------------------------\n");
            while (myNode != NULL) {
                printf("%-15ld\t%02.02f\t\t%02d/%02d/%04d",myNode->key, myNode->data.temp,myNode->data.timestamp.day,myNode->data.timestamp.month,myNode->data.timestamp.year);
                myNode = myNode->next;
            }
        }
        return;
    }






