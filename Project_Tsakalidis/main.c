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
    
    
    
    chdir("/Users/giannisloudaros/Documents/Code/HW/4th Semester/Project Δομές/Project_Tsakalidis/Project_Tsakalidis");
    
    
    
    
    int i;
    
    
    
    logh test;
    loadh(&test);
    printf("%d\n", test.size);
    
    
    heapSort(&test);
    
    for (i=0; i<test.size; i++) {
        printf("%ld,%d\n",(long)test.measurement[i].timestamp.together,test.measurement[i].hum);
    }

    
    return 0;
    
    


}
