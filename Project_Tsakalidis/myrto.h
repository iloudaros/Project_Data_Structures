//
//  myrto.h
//  Project_Tsakalidis
//  Εδώ υπάρχουν οι αλγόριθμοι ταξινόμισης heapsort(), countingsort()
//  Και ο αλγόριθμος αναζήτησης bistimesearch()
//  !!Φρόντισε να υπάρχει μια μικρή περιγραφή του τι κάνει ο αλγόριθμος πριν την δήλωση του <3

#ifndef myrto_h
#define myrto_h

#include "johnnylouds.h"

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//heapsort

void heapSort(logh* a);

int maxHum(logh* a); //vriskei ti megaluteri ugrasia




//counting sort


void countingSort(logh* a);


//binary interpolation search

void bish(timej ts, logh* a);
void bist(timej ts, logt* a);

//binary interpolation search variation

void bishv(timej ts, logh* h);
void bistv(timej ts, logt* t);


//dentro
typedef struct node{
    measuret data;
    struct node* left;
    struct node* right;
}node;

// A utility function to do inorder traversal of BST
void inorder(node *root);
   
/* A utility function to insert a new node with given key in BST */
node* insert(node* node, measuret data);

node* newNode(long int item);

node* minValueNode(node* node);

node* delete(node* root, measuret data);

node* createBST(logt* a);










#endif 
