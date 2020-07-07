//
//  main.c
//  Project_Domes
//
//  Created by Μυρτώ Δεληγιάννη, Ορέστης Σπυριδάκης, Ιωάννης Λουδάρος, Χριστίνα Κρατημένου on 21/5/20.
//  Copyright © 2020 Ιωάννης Λουδάρος, Χριστίνα Κρατημένου, Μυρτώ Δεληγιάννη, Ορέστης Σπυριδάκης . All rights reserved.
//

#include <stdio.h>
#include "myrto.h"
#include "koutou.h"
#include "orestis.h"
#include "johnnylouds.h"
#include <time.h>

int main()
{
    
    
    
    
    system("clear");
    //Εδώ θα χρειαστεί να βάλετε το μονοπάτι στο οποίο βρίσκονται τα αρχεία από τα οποία χρειάζεται να τραβηχτούν τα δεδομένα 
    chdir("/Users/giannisloudaros/Documents/Code/HW/4th Semester/Project Δομές/Project_Tsakalidis/Project_Tsakalidis");
    logh test;
    loadh(&test);
    logh h;
    
    logt temps;
    loadt(&temps);
    logt t;
    
    timej usersearch;//Γενική μεταβλητή για αναζητήσεις
   
    
    char end='n'; //μεταβλητή ελέγχου εξόδου προγράμματος
    
    //Μεταβλητές που θα χρησιμοποιούμε για τις μετρήσεις μας
    clock_t start, mend;
    double time_taken;
    double time_taken2;

    
    printf("Καλώς ορίσατε στο καλύτερο Project στις Δομές Δεδομένων\n Από τους: Χριστίνα Κρατημένου \t Λουδάρος Ιωάννης \t Ορέστης Σπυριδάκης \t Μυρτώ Δεληγιάννη\n (Για να συνεχίσεις πάτα ENTER)");
    
    getchar();
    
    do{
        
       system("clear");
       printf("Ποιο μέρος του Project θα ήθελες να χρησιμοποιήσεις;\n 1. Μέρος Πρώτο\n 2. Μέρος Δεύτερο\n 3. Έξοδος\n");
    
    //Ο χρήστης επιλέγει ποιο μέρος του project θέλει να εξετάσει
    int choice;
    int dump; // Μεταβλητή που θα χρησιμοποιήσουμε για να καθαρίζουμε το Buffer
        
        
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
                    
                case 1: // ############### Quick Sort και Merge Sort #################
                    passlogt(&temps, &t);
                    mergesortt(&t,0,t.size-1);
                    printlogt(t);
                    
                    
                    printf("\nΓια να συνεχίσεις πάτησε (ENTER)");
                    getchar();
                    
                    break;
                case 2: // Heap Sort και Counting Sort
                    
                    //############ Heapsort #############
                    passlogh(&test, &h);
                    
                    start = clock();
                        
                    heapSort(&h);
                    
                    mend = clock();
                    
                    time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                    printlogh(h);
                    printf("\nΟ Heapsort χρειάστηκε %f δευτερόλεπτα\n\n Για να δεις πόσο χρόνο κάνει ο Countingsort πάτησε (ENTER)",time_taken);
                    
                    
                    getchar();
                    
                    
                    //########### Countingsort #############
                    passlogh(&test, &h); //Κάνουμε reset το log μας ώστε να ξαναγίνει sort

                    start = clock();

                    countingSort(&h);
                    
                    mend = clock();
                    
                    time_taken2 = ((double) (mend - start)) / CLOCKS_PER_SEC;
                    printlogh(h);
                    printf("\nΟ Countingsort χρειάστηκε %f δευτερόλεπτα\nΟ Heapsort χρειάστηκε %f δευτερόλεπτα\nΣυνεπώς καταλαβαίνουμε ότι ο Countingsort είναι γρηγορότερος κατά %f δευτερόλεπτα\n\n Για να συνεχίσεις πάτησε (ENTER)",time_taken2,time_taken,time_taken-time_taken2);
                    
                    getchar();
                    
                    break;
                case 3: //################ Δυαδική Αναζήτηση και Αναζήτηση με Παρεμβολή ######################
                    
                    passlogh(&test,&h);
                    passlogt(&temps,&t);
                    
                    ask4date(&usersearch);

            
                    do{
                        printf("Θέλεις να ψάξεις:\n 1.Μόνο Θερμοκρασία\n 2.Μόνο Υγρασία\n 3.Και τα δύο\n");
                        scanf("%d",&choice);
                        dump=getchar();
                        if(choice>3 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                    }while(choice>5 || choice<1);
                    
                    switch (choice) {
                        case 1://Μόνο Θερμοκρασία
                        {
                                                        
                            timesortt(&t);

                            start = clock();
                            
                            float result1 = binarySearcht(&t, usersearch.together, 0, t.size);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %f δευτερόλεπτα\n\n Για να δεις πόσο χρόνο χρειάστηκε η Αναζήτηση Παρεμβολής πάτησε (ENTER)",time_taken);
                            if (result1==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Θερμοκρασία :%0.2f",result1);
                            
                            
                            
                            start = clock();
                            
                            int result2 = interpolationSearcht(&t, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %f δευτερόλεπτα\n",time_taken);
                            if (result2==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Θερμοκρασία :%i",result2);
                            
                            printf("\nΓια να συνεχίσεις πάτησε (ENTER)");
                            getchar();
                        }
                            break;
                            
                        case 2://Μόνο Υγρασία
                        {
                            timesorth(&h);

                            start = clock();
                            
                            int result = binarySearchh(&h, usersearch.together, 0, t.size);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %f δευτερόλεπτα\n\n Για να δεις πόσο χρόνο χρειάστηκε η Αναζήτηση Παρεμβολής πάτησε (ENTER)",time_taken);
                            if (result==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Υγρασία :%i",result);
                            
                            start = clock();
                            
                            result = interpolationSearchh(&h, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %f δευτερόλεπτα",time_taken);
                            if (result==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Υγρασία :%i",result);
                            
                            printf("\nΓια να συνεχίσεις πάτησε (ENTER)");
                            getchar();
                        }
                            
                            break;
                            
                        case 3://Και τα δύο
                        {
                            
                            //######Θερμοκρασία#######
                            timesortt(&t);

                            start = clock();
                            
                            float result1 = binarySearcht(&t, usersearch.together, 0, t.size);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %f δευτερόλεπτα\n\n Για να δεις πόσο χρόνο χρειάστηκε η Αναζήτηση Παρεμβολής πάτησε (ENTER)",time_taken);
                            if (result1==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Θερμοκρασία :%0.2f",result1);
                            
                            
                            
                            start = clock();
                            
                            int result2 = interpolationSearcht(&t, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %f δευτερόλεπτα\n",time_taken);
                            if (result2==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Θερμοκρασία :%i",result2);
                            
                            
                            //######Υγρασία#######

                            
                            timesorth(&h);

                            start = clock();
                            
                            int result = binarySearchh(&h, usersearch.together, 0, t.size);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %f δευτερόλεπτα\n\n Για να δεις πόσο χρόνο χρειάστηκε η Αναζήτηση Παρεμβολής πάτησε (ENTER)",time_taken);
                            if (result==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Υγρασία :%i",result);
                            
                            start = clock();
                            
                            result = interpolationSearchh(&h, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %f δευτερόλεπτα",time_taken);
                            if (result==-1) printf("Δεν υπάρχει αυτή η μέτρηση :/");
                            else printf("Υγρασία :%i",result);
                            
                            
                            
                            
                            
                            printf("\nΓια να συνεχίσεις πάτησε (ENTER)");
                            getchar();
                        
                            
                            
                        }
                           
                            break;
                    }
                    
                    
                    break;
                    
                case 4: //############## Δυαδική Αναζήτηση Παρεμβολής ###############
                    
                    passlogt(&temps, &t);
                {
                    ask4date(&usersearch);
                                        
                    do{
                        printf("Θέλεις να ψάξεις:\n 1.Μόνο Θερμοκρασία\n 2.Μόνο Υγρασία\n 3.Και τα δύο\n");
                        scanf("%d",&choice);
                        dump=getchar();
                        if(choice>3 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                    }while(choice>5 || choice<1);
                    
                    switch (choice) {
                        case 1://Μόνο Θερμοκρασία
                            passlogt(&temps, &t);
                            bist(usersearch, &t);
                            break;
                            
                        case 2://Μόνο Υγρασία
                            passlogh(&test, &h);
                            bish(usersearch, &h);
                            break;
                            
                        case 3://Και τα δύο
                            passlogh(&test, &h);
                            passlogt(&temps, &t);
                            bish(usersearch, &h);
                            bist(usersearch, &t);
                            break;
                    }
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


