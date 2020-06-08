//
//  johnnylouds.c
//  Project_Tsakalidis
//
//  Created by Ioannis Loudaros on 5/6/20.
//  Copyright © 2020 Ιωάννης Λουδάρος. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//Χρόνος, για την εύκολη διαχείρηση των timestamps, ενδιαφέρον έχει το int together, σκοπός του είναι να κάνει ευκολότερο το sorting
typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int sec;
    long int together;
} time;



//Τύποι δεδομένων για την καταγραφή των μετρήσεων. Ένας από τους δύο θα μπορούσε να παραληφθεί αλλά χρησιμοποιούνται για λόγους ευαναγνωσιμότητας
typedef struct{
    float temp;
    time timestamp;
} measuret;

typedef struct{
    int hum;
    time timestamp;
} measureh;


//Τύποι δεδομένων για την διατήρηση πολλών μετρήσεων των παραπάνω τύπων
typedef struct{
    measureh* measurement;
    int size;
} logh;

typedef struct{
    measuret* measurement;
    int size;
} logt;







//Οι Parsers

void loadh(logh* log){
   
    //Άνοιγμα αρχείου
    FILE *fp;
    printf("Opening \"hum.txt\"...\n");
    fp = fopen("hum.txt", "r");
    
    //Έλεγχος αρχείου
    if (fp==NULL) printf("Something is wrong with this file\n");
        else printf("Opened");
        
    
    
    //Προετοιμασία ανάγνωσης πρώτης μέτρησης
    printf("Creating a new entry\n");
    char c = '\0' ;
    log->size=1;
    printf("Loading Data\n");
    
    
    while (c!=EOF)
    {
        
        
        printf("Measurement %d\n",log->size);
        
        //Κάνε χώρο μέσα στον πίνακα ώστε να μπει η επόμενη μέτρηση
        (*log).measurement=(measureh *)realloc((*log).measurement, (*log).size*sizeof(measureh));
        
       //Φτάσε μέχρι την αρχή της εγγραφής (Αν τελειώσει το αρχείο βγες από το loop)
        while (c!='"')
        {
                c=getc(fp);
                if (c==EOF)
                {
                    log->size--;
                    goto done;
                    
                }
        }
        
        //Διάβασε την ημερομηνία
    fscanf(fp,"%4d-%2d-%2dT%2d:%2d:%2d",&log->measurement[log->size-1].timestamp.year,&log->measurement[log->size-1].timestamp.month,&log->measurement[log->size-1].timestamp.day,&log->measurement[log->size-1].timestamp.hour,&log->measurement[log->size-1].timestamp.minute,&log->measurement[log->size-1].timestamp.sec);
        
        log->measurement[log->size-1].timestamp.together=100000000* (long)log->measurement[log->size-1].timestamp.year+(long)1000000*log->measurement[log->size-1].timestamp.month+(long)10000*log->measurement[log->size-1].timestamp.day+100*log->measurement[log->size-1].timestamp.hour+log->measurement[log->size-1].timestamp.minute;
        
        //Πήγαινε στην μέτρηση
    c=getc(fp);
        c='0';
    while (c!='"') c=getc(fp);
        
        //Διάβασε την μέτρηση
    fscanf(fp, "%2d",&log->measurement[log->size-1].hum);
    log->size++;
    c=getc(fp);
     c='0';
    }
    
done:

    fclose(fp);
printf("Done\n");
    
    
    return;
    
    
}
