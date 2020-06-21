//
//  main.c
//  Project_Domes
//
//  Created by Μυρτώ Δελυγιάννη, Ορέστης Σπυριδάκης, Ιωάννης Λουδάρος, Χριστίνα Κρατημένου on 21/5/20.
//  Copyright © 2020 Ιωάννης Λουδάρος, Χριστίνα Κρατημένου, Μυρτώ Δελυγιάννη, Ορέστης Σπυριδάκης . All rights reserved.
//

#include <stdio.h>
#include "myrto.h"
//#include "koutou.h"
#include "orestis.h"
#include "johnnylouds.h"

int main()
{
    
    
    //Εδώ θα χρειαστεί να βάλετε το μονοπάτι στο οποίο βρίσκονται τα αρχεία από τα οποία χρειάζεται να τραβηχτούν τα δεδομένα 
    chdir("/Users/giannisloudaros/Documents/Code/HW/4th Semester/Project Δομές/Project_Tsakalidis/Project_Tsakalidis");
    
    
    
    
    logt test;
    loadt(&test);
    
    logt testdays;
    takedayst(test, &testdays);
    
    for (int i=0; i<testdays.size; i++) {
        printf(" %d Time: %d %d, Measurement: %f\n",i,testdays.measurement[i].timestamp.day,testdays.measurement[i].timestamp.month,testdays.measurement[i].temp);
    }
    
  
    
    return 0;
    
    


}
