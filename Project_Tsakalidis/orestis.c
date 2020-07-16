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



//################### PART 2 #######################


//Structs



typedef struct nodeO{
    measuret data;
    struct nodeO* next;
    long int key;

} nodeO;


typedef struct{
    nodeO* head;
    int count;
} hash;

typedef struct{
    hash* table;
    int eleCount;
} hashtable;




nodeO * createNode(measuret input) {
    nodeO* newnode;
    newnode = (nodeO *) malloc(sizeof(nodeO));
    passmeasurementt(&input, &newnode->data);
    newnode->next = NULL;
    newnode->key = input.timestamp.together;
    return newnode;
}



//Helper function for hashing

int digitsum(long int key)
{
    long int temp = key/10000;
    char c = '-';
    
    int sum = 0;
    int m;
    
    
    while (temp>0)
    {
        m = temp%10;
        sum = sum + m;
        temp = temp/10;
    }
    
    int result = (int)sum+2*(int)c;
    
    return result;
}


void insertToHash(measuret input,hashtable* a) {
    int hashIndex = digitsum(input.timestamp.together) % a->eleCount;
    nodeO *newnode = createNode(input);
    
    /* head of list for the bucket with index "hashIndex" */
    if (!a->table[hashIndex].head) {
        a->table[hashIndex].head = newnode;
        a->table[hashIndex].count = 1;
        return;
        }
    
    /* adding new node to the list */
    newnode->next = (a->table[hashIndex].head);
   
    a->table[hashIndex].head = newnode;
    a->table[hashIndex].count++;
    return;
    }

void deleteFromHash(long int key, hashtable* a) {
    /* find the bucket using hash index */
    int hashIndex = digitsum(key) % a->eleCount, flag = 0;
    nodeO *temp, *myNode;
    /* get the list head from current bucket */
    myNode = a->table[hashIndex].head;
    if (!myNode) {
        printf("Η Μέτρηση δεν βρέθηκε\n");
        return;
    }
    temp = myNode;
    while (myNode != NULL) {
        /* delete the node with given key */
        if (myNode->key == key) {
            flag = 1;
            if (myNode == a->table[hashIndex].head)
                a->table[hashIndex].head = myNode->next;
            else
                temp->next = myNode->next;

            a->table[hashIndex].count--;
            free(myNode);
            break;
        }
        temp = myNode;
        myNode = myNode->next;
    }
    if (flag)
        printf("Η διαγραφή ολοκληρώθηκε\n");
    else
        printf("Η Μέτρηση δεν βρέθηκε\n");
    return;
    }

    void searchInHash(long int key, hashtable* a) {
        int hashIndex = digitsum(key) % a->eleCount, flag = 0;
        nodeO *myNode;
        myNode = a->table[hashIndex].head;
        if (!myNode) {
            printf("Η Μέτρηση δεν βρέθηκε\n");
            return;
        }
        while (myNode != NULL) {
            if (myNode->key == key) {
                printf("Key  : %ld\n-->\tDate: %d/%d/%d Temperature: %f\n", myNode->key,myNode->data.timestamp.day, myNode->data.timestamp.month, myNode->data.timestamp.year, myNode->data.temp);
                flag = 1;
                break;
            }
        myNode = myNode->next;
        }
        if (!flag)
            printf("Η Μέτρηση δεν βρέθηκε\n");
        return;
    }

    void changeInHash(long int key,float change, hashtable* a) {
        int hashIndex = digitsum(key) % a->eleCount, flag = 0;
        nodeO *myNode;
        myNode = a->table[hashIndex].head;
        if (!myNode) {
            printf("Η Μέτρηση δεν βρέθηκε\n");
            return;
        }
        while (myNode != NULL) {
            if (myNode->key == key) {
                myNode->data.temp=change;
                flag = 1;
                break;
            }
        myNode = myNode->next;
        }
        if (!flag)
            printf("Η Μέτρηση δεν βρέθηκε\n");
        return;
    }

   /* void display(hashtable* a) {
        nodeO *myNode;
        int i;
        for (i = 0; i < a->eleCount; i++) {
            if (a->table[i].count == 0)
                continue;
            myNode = a->table[i].head;
            if (!myNode)
                continue;
            printf("\nΜέτρηση στην θέση %d του πίνακα Κατακερματισμού:\n", i);
            printf("Measurement      Date   \n");
            printf("--------------------------------\n");
            while (myNode != NULL) {
                printf("%02.02f\t\t%02d/%02d/%04d", myNode->data.temp,myNode->data.timestamp.day,myNode->data.timestamp.month,myNode->data.timestamp.year);
                myNode = myNode->next;
            }
        }
        return;
    }
    
    */






