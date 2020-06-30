//
//  main.c
//  Project_Domes
//
//  Created by Μυρτώ Δεληγιάννη, Ορέστης Σπυριδάκης, Ιωάννης Λουδάρος, Χριστίνα Κρατημένου on 21/5/20.
//  Copyright © 2020 Ιωάννης Λουδάρος, Χριστίνα Κρατημένου, Μυρτώ Δεληγιάννη, Ορέστης Σπυριδάκης . All rights reserved.
//

#include <stdio.h>
#include "myrto.h"
//#include "koutou.h"
//#include "orestis.h"
#include "johnnylouds.h"
#include <time.h>

int main()
{
   
    //Εδώ θα χρειαστεί να βάλετε το μονοπάτι στο οποίο βρίσκονται τα αρχεία από τα οποία χρειάζεται να τραβηχτούν τα δεδομένα 
    chdir("/Users/giannisloudaros/Documents/Code/HW/4th Semester/Project Δομές/Project_Tsakalidis/Project_Tsakalidis");
    logh test;
    loadh(&test);
    logh h;
    printlogh(test);
    char end='n'; //μεταβλητή ελέγχου εξόδου προγράμματος
    
    
    printf("Καλώς ορίσατε στο καλύτερο Project στις Δομές Δεδομένων\n Από τους: Χριστίνα Κρατημένου \t Λουδάρος Ιωάννης \t Ορέστης Σπυριδάκης \t Μυρτώ Δεληγιάννη\n (Για να συνεχίσεις πάτα ENTER)");
    
    getchar();
    
    do{
       printf("Ποιο μέρος του Project θα ήθελες να χρησιμοποιήσεις;\n 1. Μέρος Πρώτο\n 2. Μέρος Δεύτερο\n 3. Έξοδος\n");
    
    //Ο χρήστης επιλέγει ποιο μέρος του project θέλει να εξετάσει
    int choice;
    int dump;
    do{
        
        
        scanf("%d",&choice);
        dump=getchar();
        if ((choice!=1) && (choice!=2) && (choice!=3)) printf("Πρέπει να επιλέξεις 1, 2 ή 3\n");
        
    }while((choice!=1) && (choice!=2)&& (choice!=3));
    
    switch (choice) {
            
        case 1: // Ο χρήστης επιλέγει το πρώτο μέρος του Project
            printf("Έχεις επιλέξει το πρώτο μέρος του Project\n");
            
            
            do{ //Τώρα ο Χρήστης επιλέγει το ερώτημα του πρώτου μέρους που τον ενδιαφέρει
                    printf("Ποιο ερώτημα σε ενδιαφέρει;\n 1. Ερώτημα (1)\n 2. Ερώτημα (2)\n 3. Ερώτημα (3)\n 4. Ερώτημα (4)\n 5. Πίσω\n");
                    scanf("%d",&choice);
                    dump=getchar();
                    if(choice>5 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                }while(choice>5 || choice<1);
                   
            switch (choice) {
                    
                case 1: // Quick Sort και Merge Sort
                    
                    break;
                case 2: // Heap Sort και Counting Sort
                    passlogh(&test, &h);
                   // heapSort(&h);
                    countingSort(&h);
                    printlogh(h);
                    
                    break;
                case 3: // Δυαδική Αναζήτηση και Αναζήτηση με Παρεμβολή
                    
                    
                    
                    break;
                    
                case 4: // Δυαδική Αναζήτηση Παρεμβολής
                    
                    printf("Σε ποια στιγμή είναι η μέτρηση που ψάχνεις;\n");
                    timej usersearch;
                    usersearch.year=2014;
                    usersearch.sec=0;
                    printf("Μήνας:");
                    scanf("%d",&usersearch.month);
                    printf("Μέρα:");
                    scanf("%d",&usersearch.day);
                    printf("Ώρα:");
                    scanf("%d",&usersearch.hour);
                    printf("Λεπτό:");
                    scanf("%d",&usersearch.minute);
                    usersearch.together=(long)100000000* (long)usersearch.year+(long)1000000*usersearch.month+(long)usersearch.day+100*usersearch.hour+usersearch.minute;
                    
                    
                    do{
                        printf("Θέλεις να ψάξεις:\n 1.Μόνο Θερμοκρασία\n 2.Μόνο Υγρασία\n 3.Και τα δύο\n");
                        scanf("%d",&choice);
                        dump=getchar();
                        if(choice>3 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                    }while(choice>5 || choice<1);
                    
                    switch (choice) {
                        case 1://Μόνο Θερμοκρασία
                           // bist(usersearch, <#logt *a#>);
                            break;
                            
                        case 2://Μόνο Υγρασία
                           // bish(usersearch, <#logh *a#>);
                            break;
                            
                        case 3://Και τα δύο
                           // bish(usersearch, <#logh *a#>);
                           // bist(usersearch, <#logt *a#>);
                            break;
                    }
                    
                    break;
                    
                    
                case 5:
                    break;
                    
                    }
            
            break;
        case 2: //Ο χρήστης επιλέγει το δεύτερο μέρος του Project
           
            
            do{ //Τώρα ο Χρήστης επιλέγει το ερώτημα του δεύτερου μέρους που τον ενδιαφέρει
                    printf("Ποιο ερώτημα σε ενδιαφέρει;\n 1. Ερώτημα (Α)\n 2. Ερώτημα (Β)\n 3. Ερώτημα (Γ)\n 4. Πίσω\n");
                    scanf("%d",&choice);
                    dump=getchar();
                    if(choice>5 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                }while(choice>5 || choice<1);
            
            switch (choice) {
                    
                case 1: // Δυαδικό Δέντρο Αναζήτησης ως προς μέρα
                    
                    break;
                case 2: // Δυαδικό Δέντρο ως προς μέτρηση
                    
                    
                    
                    break;
                case 3: // Hashing
                    
                    
                    
                    break;
                    
                case 4: // Πίσω
                    
                    break;
                    
                    
                    
            }
            
            break;
            
        case 3: //Έξοδος από το πρόγραμμα
            
            printf("Είσαι σίγουρος ότι θέλεις να τερματιστεί το πρόγραμμα;(y/n)\n");
            end=getchar();
            break;
            
    }
        
    }while (end!='y');
    
    
    printf("Φιλάκιααα <3\n");
    
    return 0;
    
    
}


