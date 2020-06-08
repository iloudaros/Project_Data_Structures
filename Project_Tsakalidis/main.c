//
//  main.c
//  Project_Domes
//
//  Created by Μυρτώ Δελυγιάννη, Ορέστης Σπυριδάκης, Ιωάννης Λουδάρος, Χριστίνα Κρατημένου on 21/5/20.
//  Copyright © 2020 Ιωάννης Λουδάρος, Χριστίνα Κρατημένου, Μυρτώ Δελυγιάννη, Ορέστης Σπυριδάκης . All rights reserved.
//

#include <stdio.h>
//#include "myrto.h"
//#include "koutou.h"
//#include "orestis.h"
#include "johnnylouds.h"

int main()
{
    
    
    
    chdir("/Users/giannisloudaros/Documents/Code/HW/4th Semester/Project Δομές/Project_Tsakalidis/Project_Tsakalidis");
    
    logh testlog;
    loadh(&testlog);
    
    int i;
    
    for (i=0; i<testlog.size; i++) {
        printf("--Measurment %d-- %ld,%d\n",i,(long)testlog.measurement[i].timestamp.together,testlog.measurement[i].hum);
    }
    
    
    return 0;


}
