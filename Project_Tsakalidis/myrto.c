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
    int i, j, x, root;
    measureh t; //temp


    //creating max heap array
    for(i = 1; i < a->size; i++){
        x = i;
        do{
            root = (x - 1) / 2;

            if(a->measurement[root].hum < a->measurement[x].hum){

                //temp = a[root]
                t.timestamp.year = a->measurement[root].timestamp.year;
                t.timestamp.month = a->measurement[root].timestamp.month;
                t.timestamp.day = a->measurement[root].timestamp.day;
                t.timestamp.hour = a->measurement[root].timestamp.hour;
                t.timestamp.minute = a->measurement[root].timestamp.minute;
                t.timestamp.sec = a->measurement[root].timestamp.sec;
                t.hum = a->measurement[root].hum;
                
                //a[root] = a[x]
                a->measurement[root].timestamp.year = a->measurement[x].timestamp.year;
                a->measurement[root].timestamp.month = a->measurement[x].timestamp.month;
                a->measurement[root].timestamp.day = a->measurement[x].timestamp.day;
                a->measurement[root].timestamp.hour = a->measurement[x].timestamp.hour;
                a->measurement[root].timestamp.minute = a->measurement[x].timestamp.minute;
                a->measurement[root].timestamp.sec = a->measurement[x].timestamp.sec;
                a->measurement[root].hum = a->measurement[x].hum;

                //a[x] = temp
                a->measurement[x].timestamp.year = t.timestamp.year;
                a->measurement[x].timestamp.month = t.timestamp.month;
                a->measurement[x].timestamp.day = t.timestamp.day;
                a->measurement[x].timestamp.hour = t.timestamp.hour;
                a->measurement[x].timestamp.minute = t.timestamp.minute;
                a->measurement[x].timestamp.sec = t.timestamp.sec;
                a->measurement[x].hum = t.hum;

            }

            x = root;

        }while(x != 0);

    }
    
    
    
    for(j = a->size - 1; j >= 0; j--){

        //temp = a[0]
        t.timestamp.year = a->measurement[0].timestamp.year;
        t.timestamp.month = a->measurement[0].timestamp.month;
        t.timestamp.day = a->measurement[0].timestamp.day;
        t.timestamp.hour = a->measurement[0].timestamp.hour;
        t.timestamp.minute = a->measurement[0].timestamp.minute;
        t.timestamp.sec = a->measurement[0].timestamp.sec;
        t.hum = a->measurement[0].hum;

        //a[0] = a[j]
        a->measurement[0].timestamp.year = a->measurement[j].timestamp.year;
        a->measurement[0].timestamp.month = a->measurement[j].timestamp.month;
        a->measurement[0].timestamp.day = a->measurement[j].timestamp.day;
        a->measurement[0].timestamp.hour = a->measurement[j].timestamp.hour;
        a->measurement[0].timestamp.minute = a->measurement[j].timestamp.minute;
        a->measurement[0].timestamp.sec = a->measurement[j].timestamp.sec;
        a->measurement[0].hum = a->measurement[j].hum;

        //a[j] = temp
        a->measurement[j].timestamp.year = t.timestamp.year;
        a->measurement[j].timestamp.month = t.timestamp.month;
        a->measurement[j].timestamp.day = t.timestamp.day;
        a->measurement[j].timestamp.hour = t.timestamp.hour;
        a->measurement[j].timestamp.minute = t.timestamp.minute;
        a->measurement[j].timestamp.sec = t.timestamp.sec;
        a->measurement[j].hum = t.hum;

        root = 0;

        do{
            x = 2 * root + 1;

            if(x < j - 1 && (a->measurement[x].hum < a->measurement[x + 1].hum)) x++;

            if(x < j && (a->measurement[root].hum < a->measurement[x].hum)){

                //temp = a[root]
                t.timestamp.year = a->measurement[root].timestamp.year;
                t.timestamp.month = a->measurement[root].timestamp.month;
                t.timestamp.day = a->measurement[root].timestamp.day;
                t.timestamp.hour = a->measurement[root].timestamp.hour;
                t.timestamp.minute = a->measurement[root].timestamp.minute;
                t.timestamp.sec = a->measurement[root].timestamp.sec;
                t.hum = a->measurement[root].hum;

                //a[root] = a[x]
                a->measurement[root].timestamp.year = a->measurement[x].timestamp.year;
                a->measurement[root].timestamp.month = a->measurement[x].timestamp.month;
                a->measurement[root].timestamp.day = a->measurement[x].timestamp.day;
                a->measurement[root].timestamp.hour = a->measurement[x].timestamp.hour;
                a->measurement[root].timestamp.minute = a->measurement[x].timestamp.minute;
                a->measurement[root].timestamp.sec = a->measurement[x].timestamp.sec;
                a->measurement[root].hum = a->measurement[x].hum;

                //a[x] = temp
                a->measurement[x].timestamp.year = t.timestamp.year;
                a->measurement[x].timestamp.month = t.timestamp.month;
                a->measurement[x].timestamp.day = t.timestamp.day;
                a->measurement[x].timestamp.hour = t.timestamp.hour;
                a->measurement[x].timestamp.minute = t.timestamp.minute;
                a->measurement[x].timestamp.sec = t.timestamp.sec;
                a->measurement[x].hum = t.hum;

            }

            root = x;

        }while (x <= j);
      
    }
    
    printlogh(*a);

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




//dentro

typedef struct node{
    long int key;
    struct node* left;
    struct node* right;
}node;

// A utility function to create a new BST node
node *newNode(long int item){
    node *temp =  (node *)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%ld \n", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
node* insert(node* node, long int key){
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

void createBST(logt* a){
	int i;
	struct node *root = NULL;
	for(i = 0; i < a->size; i++){
		long int k = a->measurement[i].timestamp.together;
		insert(root, k);
	}
}
