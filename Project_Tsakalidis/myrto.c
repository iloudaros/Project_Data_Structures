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

#include "koutou.h"
#include "johnnylouds.h"
#include "orestis.h"
#include "koutou.h"


//heapsort


void heapSort(logh* a){
    int i, j, x, root;
    measureh t; //temp


    //creating max heap array
    for(i = 0; i < a->size; i++){
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
    
    //printlogh(*a);

}





//vriskw ti megisth ugrasia


int maxHum(logh* a){
    int i;
    int max = a->measurement[0].hum;
    int n = a->size;
    for(i = 0; i < n; i++){
        if(a->measurement[i].hum > max){
            max = a->measurement[i].hum;
        }
    }
    return max;
}

//counting sort


void countingSort(logh* a){


    int n = a->size; //to size twn A kai B
    measureh sorted[n];
    int k = maxHum(a) + 1; //to size tou count
    int i, j;
    int count[k];

    for(i = 0; i < k; i++) count[i] = 0;
    
    for(j = 0; j < n; j++) count[a->measurement[j].hum]++;
    
    for(i = 1; i < k; i++) count[i] = count[i] + count[i - 1];

    for(j = n - 1; j >= 0; j--){
        sorted[count[a->measurement[j].hum]-1].hum = a->measurement[j].hum;
        sorted[count[a->measurement[j].hum]-1].timestamp.year = a->measurement[j].timestamp.year;
        sorted[count[a->measurement[j].hum]-1].timestamp.month = a->measurement[j].timestamp.month;
        sorted[count[a->measurement[j].hum]-1].timestamp.day = a->measurement[j].timestamp.day;
        sorted[count[a->measurement[j].hum]-1].timestamp.hour = a->measurement[j].timestamp.hour;
        sorted[count[a->measurement[j].hum]-1].timestamp.minute = a->measurement[j].timestamp.minute;
        sorted[count[a->measurement[j].hum]-1].timestamp.sec = a->measurement[j].timestamp.sec;
        sorted[count[a->measurement[j].hum]-1].timestamp.together = a->measurement[j].timestamp.together;
        count[a->measurement[j].hum]--;
    }
    
   // for (j = 0; j < a->size; j++) printf("%d, %ld \n",sorted[j].hum, sorted[j].timestamp.together);
    
    
    for (j = 0; j < a->size; j++){
        a->measurement[j].hum = sorted[j].hum;
        a->measurement[j].timestamp.year = sorted[j].timestamp.year;
        a->measurement[j].timestamp.month = sorted[j].timestamp.month;
        a->measurement[j].timestamp.day = sorted[j].timestamp.day;
        a->measurement[j].timestamp.hour = sorted[j].timestamp.hour;
        a->measurement[j].timestamp.minute = sorted[j].timestamp.minute;
        a->measurement[j].timestamp.sec = sorted[j].timestamp.sec;
        a->measurement[j].timestamp.together = sorted[j].timestamp.together;
        
        
    }
}








//binary interpolation search

void bish(timej ts, logh* a){
	
	timesort(a);

    int n = a->size;

    int left = 1;
    int right = n;


    long int next = (((ts.together - a->measurement[left].timestamp.together) / a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    while(ts.together != a->measurement[next].timestamp.together && left < right){
        int i = 0;
        if(ts.together >= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[(int)(next + i * sqrt(right - left))].timestamp.together){
                i++;
                right = i * sqrt(right - left);
                left = (i - 1) * sqrt(right - left);
            }
        }
        else if(ts.together <= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[(int)(next - i * sqrt(right - left))].timestamp.together){
                i++;
                right = (i - 1) * sqrt(right - left);
                left = i * sqrt(right - left);
            }
        }
        next = ((ts.together - a->measurement[left].timestamp.together) / (a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    }
    if(ts.together == a->measurement[next].timestamp.together){
        printf("Η υγρασία που ψάχνεις είναι %d\n",a->measurement[next].hum);
    }
    else printf("Δεν υπάρχει μέτρηση για την συγκεκριμένη στιγμή :/ κλαψ\n");
}



void bist(timej ts, logt* a){

	bis2sortt(a);

    int n = a->size;

    int left = 1;
    int right = n;


    long int next = (((ts.together - a->measurement[left].timestamp.together) / a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    while(ts.together != a->measurement[next].timestamp.together && left < right){
        int i = 0;
        if(ts.together >= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[(int)(next + i * sqrt(right - left))].timestamp.together){
                i++;
                right = i * sqrt(right - left);
                left = (i - 1) * sqrt(right - left);
            }
        }
        else if(ts.together <= a->measurement[next].timestamp.together){
            while(ts.together > a->measurement[(int)(next - i * sqrt(right - left))].timestamp.together){
                i++;
                right = (i - 1) * sqrt(right - left);
                left = i * sqrt(right - left);
            }
        }
        next = ((ts.together - a->measurement[left].timestamp.together) / (a->measurement[right].timestamp.together - a->measurement[left].timestamp.together) * (right - left));
    }
    if(ts.together == a->measurement[next].timestamp.together){
        printf("Η θερμοκρασία που ψάχνεις είναι %f\n",a->measurement[next].temp);
    }
    else printf("Δεν υπάρχει μέτρηση για την συγκεκριμένη στιγμή :/ κλαψ\n");
}





//dentro

typedef struct node{
    measuret data;
    struct node* left;
    struct node* right;
}node;

// A utility function to create a new BST node
node *newNode(long int item){
    node *t =  (node *)malloc(sizeof(node));
    t->data.timestamp.together = item;
    t->left = t->right = NULL;
    return t;
}

// A utility function to do inorder traversal of BST
void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%ld \n", root->data);
        inorder(root);
    }
}

/* A utility function to insert a new node with given key in BST */
node* insert(node* node, measuret data){
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data.timestamp.together);

    /* Otherwise, recur down the tree */
    if (data.timestamp.together < node->data.timestamp.together)
        node->left  = insert(node->left, data);
    else if (data.timestamp.together > node->data.timestamp.together)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

void createBST(logt* a){
	int i;
	measuret k;
	struct node *root = NULL;
	for(i = 0; i < a->size; i++){
		k.timestamp.together = a->measurement[i].timestamp.together;
		k.temp = a->measurement[i].temp;
		insert(root, k);
	}
}


