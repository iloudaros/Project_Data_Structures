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
    int j = 0;
    measureh t; //temp
    measureh s;
    
    while(r >= 2){
        if(l > 1){
            l--;
            j = l;
        }
        else{
             passtime(&(a->measurement[1].timestamp), &(t.timestamp));
        	t.hum = a->measurement[1].hum;
        	
            passtime(&(a->measurement[1].timestamp), &(a->measurement[j].timestamp));
        	a->measurement[1].hum = a->measurement[j].hum;

            passtime(&(a->measurement[j].timestamp), &(t.timestamp));
        	a->measurement[j].hum = t.hum;
        	
        
            r--;
            j = l;
        }
    
        s.hum = a->measurement[j].hum;
        
        while(2 * j <= r){
            k = 2 * j;
            if(k < r && a->measurement[k].hum < a->measurement[k + 1].hum){
                k++;
            }
            if(s.hum < a->measurement[k].hum) {
                passtime(&(a->measurement[j].timestamp), &(a->measurement[k].timestamp));
                a->measurement[j].hum = a->measurement[k].hum;
                j = k;
            }
            else{
                goto E;

            }
        }
    }
    E:
        passtime(&(a->measurement[j].timestamp), &(s.timestamp));
        a->measurement[j].hum = s.hum;
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
