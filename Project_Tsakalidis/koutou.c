#include <stdio.h>
#include <stdlib.h>
#include "myrto.h"
#include "johnnylouds.h"


//MERGESORT

void merge(logt* p,int min,int mid,int max)
{
  measuret tmp[p->size];
  int i,j,k,m;
  j=min;
  m=mid+1;
    
  for(i=min; j<=mid && m<=max ; i++)
  {
      if(p->measurement[j].temp <= p->measurement[m].temp)
     {
         passmeasurementt(&p->measurement[j], &tmp[i]);
         j++;
     }
     else
     {
         passmeasurementt(&p->measurement[m], &tmp[i]);
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         passmeasurementt(&p->measurement[k], &tmp[i]);
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
         passmeasurementt(&p->measurement[k], &tmp[i]);
        i++;
     }
  }
    for(k=min; k<=max; k++){
        passmeasurementt(&tmp[k],&p->measurement[k]);
   
    }
}



void mergesortt(logt* p,int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   mergesortt(p,min,mid);
   mergesortt(p,mid+1,max);
   merge(p,min,mid,max);
 }
}



//QUICKSORT
 
 
 void quick_sort(logt* p,int first,int last)
 {
     int pivot,j,i;
     if(first<last)
     {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(p->measurement[i].temp<=p->measurement[pivot].temp && i<last)
                 i++;
             while(p->measurement[j].temp>p->measurement[pivot].temp)
                 j--;
             if(i<j)
             {
                 swapt(&p->measurement[i], &p->measurement[j]);
             }
         }

         swapt(&p->measurement[pivot], &p->measurement[j]);
         quick_sort(p,first,j-1);
         quick_sort(p,j+1,last);
     }
 }
 
 



//Orizetai to pivot(prwto stoixeio) topotheteitai sthn swsth thesh,
//deksia apo auto topothetountai ta megalutera stoixeia kai
//aristera apo auto topothetountai ta mikrotera stoixeia

int partition(logt* p, int low, int high )
{
	int i= (low-1);
    float pivot = p->measurement[1].temp;   /// Antikeimeno tou partitioning

    
    for (int j = low; j <= high- 1; j++) 
    { 
         
        if (p->measurement[j].temp < pivot) // An to trexon stoixeio einai mikrotero tou pivot
        { 
            i++;     
            swapt(&p->measurement[i], &p->measurement[j]);
        } 
    } 
    swapt(&p->measurement[i + 1], &p->measurement[high]);
    return (i + 1); 
}

void quickSort(logt* p, int low, int high )  //H sunarthsh pou ousiastika ulopoiei to sortarisma
{
    
	if (low<high) 
	{
        int par = partition(p, low, high);
		quickSort(p, low, par-1);
		quickSort(p, par+1, high);    
    }

}



//Δέντρο

/* A utility function to insert a new node with given key in BST */
node* inserttemp(node* node, measuret data){
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);

    /* Otherwise, recur down the tree */
    if (data.temp < node->data.temp)
        node->left = inserttemp(node->left, data);
    else if (data.temp > node->data.temp)
        node->right = inserttemp(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

node* createBSTtemp(logt* a){
    int i;
    struct node *root = NULL;
    for(i = 0; i < a->size; i++){
        root=inserttemp(root, a->measurement[i]);
    }
    
    return root;
}









node* maxValueNode(node* node){
    struct node *current = node;
    
    while(current && current->right != NULL){
        current = current->right;
    }
    return current;
}
