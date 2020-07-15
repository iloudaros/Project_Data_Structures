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
    logt tt;
    node* r = NULL;
    node* r2 = NULL;
    node* result = NULL;
    takedayst(temps, &tt);
    r=createBST(&tt);
    
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
            system("clear");
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
                    
                    //############ Mergesort #############
                    
                    start = clock();
                        
                    mergesortt(&t,0,t.size-1);

                    mend = clock();
                    
                    time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                    printlogt(t);
                    printf("\nΟ MergeSort χρειάστηκε %lf δευτερόλεπτα\n\n Για να δεις πόσο χρόνο κάνει ο QuickSort πάτησε (ENTER)",time_taken);
                    
                    
                    getchar();
                    
                    
                    //########### Quicksort #############
                    passlogt(&temps, &t); //Κάνουμε reset το log μας ώστε να ξαναγίνει sort

                    start = clock();

                    quick_sort(&t, 0, t.size-1);
                    mend = clock();
                    
                    time_taken2 = ((double) (mend - start)) / CLOCKS_PER_SEC;
                    printlogt(t);
                    printf("\nΟ Quicksort χρειάστηκε %lf δευτερόλεπτα\nΟ Mergesort χρειάστηκε %lf δευτερόλεπτα\nΣυνεπώς καταλαβαίνουμε ότι ο Mergesort είναι γρηγορότερος κατά %lf δευτερόλεπτα\n\n Για να συνεχίσεις πάτησε (ENTER)",time_taken2,time_taken,time_taken2-time_taken);
                    
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
                    printf("\nΟ Heapsort χρειάστηκε %lf δευτερόλεπτα\n\n Για να δεις πόσο χρόνο κάνει ο Countingsort πάτησε (ENTER)",time_taken);
                    
                    
                    getchar();
                    
                    
                    //########### Countingsort #############
                    passlogh(&test, &h); //Κάνουμε reset το log μας ώστε να ξαναγίνει sort

                    start = clock();

                    countingSort(&h);
                    
                    mend = clock();
                    
                    time_taken2 = ((double) (mend - start)) / CLOCKS_PER_SEC;
                    printlogh(h);
                    printf("\nΟ Countingsort χρειάστηκε %lf δευτερόλεπτα\nΟ Heapsort χρειάστηκε %f δευτερόλεπτα\nΣυνεπώς καταλαβαίνουμε ότι ο Countingsort είναι γρηγορότερος κατά %lf δευτερόλεπτα\n\n Για να συνεχίσεις πάτησε (ENTER)",time_taken2,time_taken,time_taken-time_taken2);
                    
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
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %lf δευτερόλεπτα",time_taken);
                            if (result1==-5) printf("\nΔεν υπάρχει αυτή η μέτρηση :/");
                            else printf("\nΘερμοκρασία :%02.02f",result1);
                            
                            
                            
                            start = clock();
                            
                            float result2 = interpolationSearcht(&t, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα",time_taken);
                            if (result2==-5) printf("\nΔεν υπάρχει αυτή η μέτρηση :/");
                            else printf("\nΘερμοκρασία :%02.02f",result2);
                            
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
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %lf δευτερόλεπτα",time_taken);
                            if (result==-5) printf("\nΔεν υπάρχει αυτή η μέτρηση :/");
                            else printf("\nΥγρασία :%i",result);
                            
                            start = clock();
                            
                            result = interpolationSearchh(&h, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα",time_taken);
                            if (result==-5) printf("\nΔεν υπάρχει αυτή η μέτρηση :/");
                            else printf("\nΥγρασία :%i",result);
                            
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
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %lf δευτερόλεπτα\n",time_taken);
                            if (result1==-5) printf("Δεν υπάρχει αυτή η μέτρηση :/\n");
                            else printf("Θερμοκρασία :%0.02f\n",result1);
                            
                            
                            
                            start = clock();
                            
                            float result2 = interpolationSearcht(&t, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n",time_taken);
                            if (result2==-5) printf("Δεν υπάρχει αυτή η μέτρηση :/\n");
                            else printf("Θερμοκρασία :%02.02f\n",result2);
                            
                            
                            //######Υγρασία#######

                            
                            timesorth(&h);

                            start = clock();
                            
                            int result = binarySearchh(&h, usersearch.together, 0, t.size);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυαδική Αναζήτηση χρειάστηκε %lf δευτερόλεπτα\n",time_taken);
                            if (result==-5) printf("Δεν υπάρχει αυτή η μέτρηση :/\n");
                            else printf("Υγρασία :%i\n",result);
                            
                            start = clock();
                            
                            result = interpolationSearchh(&h, usersearch.together);
                            
                            mend = clock();
                            
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n",time_taken);
                            if (result==-5) printf("Δεν υπάρχει αυτή η μέτρηση :/\n");
                            else printf("Υγρασία :%i\n",result);
                            
                            
                            
                            
                            
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
                    }while(choice>3 || choice<1);
                    
                    switch (choice) {
                        case 1://Μόνο Θερμοκρασία
                            passlogt(&temps, &t);
                           
                            printf("Η Δυική Αναζήτηση Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bist(usersearch, &t);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυική Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);
                            
            
                            
                            printf("Η Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bistv(usersearch, &t);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);
                            
                            break;
                            
                        case 2://Μόνο Υγρασία
                            passlogh(&test, &h);
                            printf("Η Δυική Αναζήτηση Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bish(usersearch, &h);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυική Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);
                            
                            printf("Η Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bishv(usersearch, &h);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);

                            break;
                            
                        case 3://Και τα δύο
                            passlogh(&test, &h);
                            passlogt(&temps, &t);
                            printf("Η Δυική Αναζήτηση Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bish(usersearch, &h);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυική Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);

                            
                            printf("Η Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bishv(usersearch, &h);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);

                            
                            printf("Η Δυική Αναζήτηση Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bist(usersearch, &t);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Δυική Αναζήτηση Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);

                            
                            printf("Η Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής επέστρεψε:\n");
                            
                            start = clock();
                            bistv(usersearch, &t);
                            mend = clock();
                            time_taken = ((double) (mend - start)) / CLOCKS_PER_SEC;
                            printf("\nΗ Παραλλαγή της Δυικής Αναζήτησης Παρεμβολής χρειάστηκε %lf δευτερόλεπτα\n\n",time_taken);

                            
                            
                            printf("(Για να συνεχίσεις πάτα ENTER)\n");
                            getchar();
                            
                            break;
                    }
                    }
                    
                    break;
                    
                    
                case 5:
                    break;
                    
                    }
            
            break;
        case 2: //Ο χρήστης επιλέγει το δεύτερο μέρος του Project
           system("clear");
            printf("Έχεις επιλέξει το δεύτερο μέρος του Project\n");
            
            
            do{ //Τώρα ο Χρήστης επιλέγει το ερώτημα του δεύτερου μέρους που τον ενδιαφέρει
                    printf("Ποιο ερώτημα σε ενδιαφέρει;\n 1. Ερώτημα (Α)\n 2. Ερώτημα (Β)\n 3. Ερώτημα (Γ)\n 4. Πίσω\n");
                    scanf("%d",&choice);
                    dump=getchar();
                    if(choice>5 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                }while(choice>5 || choice<1);
            
            switch (choice) {
                    
                case 1: // Δυαδικό Δέντρο Αναζήτησης ως προς μέρα
                    system("clear");
                        do{
                            printf("1. Απεικόνιση Δένδρου\n2. Αναζήτηση Θερμοκρασίας βάσει ημέρας\n3. Τροποποίηση Θερμοκρασίας ημέρας\n4. Διαγραφή Εγγραφής\n5. Επαρχικοποίηση Δέντρου\n 6.Έξοδος\n");
                            scanf("%d",&choice);
                            dump=getchar();
                            if(choice>6 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                        }while(choice>6 || choice<1);
                    
                        switch (choice) {
                            case 1: //Η απεικόνιση του δένδρου με ενδοδιατεταγμένη διάσχιση:
                            
                                inorder(r);
                            
                                break;
                            case 2://Αναζήτηση Μέσης Θερμοκρασίας βάσει Ημέρας
                                {
                                ask4day(&usersearch);
                                float result = findTemp(r, usersearch);
                                if (result == -5) printf("Δεν υπάρχει αυτή η μέτρηση :/\n");
                                else printf("Θερμοκρασία :%0.02f\n", result);
                                }
                                break;
                            case 3://Τροποποίηση Μέσης Θερμοκρασίας που αντιστοιχεί σε συγκεκριμένη μερα
                                {
                                float c;
                            
                                ask4day(&usersearch);
                                printf("Ποια είναι η νέα μέση θερμοκρασία;\n");
                                scanf("%f", &c);
                                
                                changeTemp(r, usersearch, c);
                            
                                float check = findTemp(r, usersearch);
                            
                                if (check == -5) printf("Η αλλαγή απέτυχε :/\n");
                                else if(check == c) printf("Η αλλαγή πέτυχε, Νέα Θερμοκρασία :%0.02f\n", c);
                            
                            
                            
                                }
                            
                                printf("(Για να συνεχίσεις πάτα ENTER)\n");
                                getchar();
                            
                                break;
                            case 4://Διαγραφή μιας εγγραφής που αντιστοιχεί σε συγκεκεριμένη ημέρα
                            
                                printf("Ψάξε την ημέρα που θες να διαγράψεις.\n");
                                ask4day(&usersearch);
                            
                                r = delete(r, usersearch);
                            
                                printf("Το νέο δέντρο είναι:\n");
                                inorder(r);
    
                                break;
                            
                            
                            case 5:
                                r=createBST(&tt);
                                printf("Το δέντρο επαναρχικοποιήθηκε.");
                                break;
                            
                            case 6:
                            
                                break;
                            
                            
                            }
                            
                            
                    break;
                case 2: // Δυαδικό Δέντρο ως προς μέτρηση
                            r2 = createBSTtemp(&tt);
                            system("clear");
                            do{
                            printf("1. Εύρεση Μέρας/Ημερών με την Ελάχιστη Μέση Θερμοκρασία\n2. Εύρεση Μέρας/Ημερών με την Μέγιστη Μέση Θερμοκρασία\n3.Έξοδος\n");
                            scanf("%d",&choice);
                            dump=getchar();
                            if(choice>3 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                            }while(choice>3 || choice<1);
                    
                    
                        switch (choice) {
                            case 1: //Εύρεση Μέρας/Ημερών με την Ελάχιστη Μέση Θερμοκρασία
                            {
                                result = minValueNode(r2);
                                printf("Η Ελάχιστη Μέση Θερμοκρασία εμφανίζεται: %d/%d/%d Temperature: %f", result->data.timestamp.day, result->data.timestamp.month, result->data.timestamp.year, result->data.temp);
                            }
                        
                                break;
                            case 2://Εύρεση Μέρας/Ημερών με την Μέγιστη Μέση Θερμοκρασία
                            {
                                result = maxValueNode(r2);
                                printf("Η Μέγιστη Μέση Θερμοκρασία εμφανίζεται: %d/%d/%d Temperature: %f", result->data.timestamp.day, result->data.timestamp.month, result->data.timestamp.year, result->data.temp);
                            }
                                break;
                            case 3://Έξοδος
                                break;
                            }
                    
                    
                    break;
                case 3: // Hashing
                    
                {
                    hashtable l;
                    l.table=NULL;
                    l.eleCount=19;
                    
                    
                    for (int i=0; i<tt.size; i++) insertToHash(tt.measurement[i],&l);
                    
                    do{
                    printf("1. Αναζήτηση μέσης θερμοκρασίας βάσει της ημέρας\n2. Τροποποίηση εγγραφής βάσει μέρας\n3.Διαγραφή εγγραφής\n4. Έξοδος");
                    scanf("%d",&choice);
                    dump=getchar();
                    if(choice>4 || choice<1) printf("Πρέπει να επιλέξεις από τα παρακάτω...\n");
                    }while(choice>4 || choice<1);
                    
                    switch (choice) {
                            
                        case 1: //1. Αναζήτηση μέσης θερμοκρασίας βάσει της ημέρας
                            ask4day(&usersearch);
                            searchInHash(usersearch.together,&l);
                            break;
                        case 2: //2. Τροποποίηση εγγραφής βάσει μέρας
                            ask4day(&usersearch);
                            float c;
                            printf("Ποια είναι η νέα μέση θερμοκρασία;\n");
                            scanf("%f", &c);
                            changeInHash(usersearch.together, c, &l);
                            
                            break;
                        case 3: //3. Διαγραφή εγγραφής
                            ask4day(&usersearch);
                            deleteFromHash(usersearch.together, &l);
                            
                            break;
                        case 4: //4. Έξοδος
                           
                            break;
                    }
                }
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


