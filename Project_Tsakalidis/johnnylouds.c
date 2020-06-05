//
//  johnnylouds.c
//  Project_Tsakalidis
//
//  Created by Ioannis Loudaros on 5/6/20.
//  Copyright © 2020 Ιωάννης Λουδάρος. All rights reserved.
//

#include <stdio.h>

//Χρόνος, για την εύκολη διαχείρηση των timestamps, ενδιαφέρον έχει το int together, σκοπός του είναι να κάνει ευκολότερο το sorting
typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int sec;
    int together;
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

void loadh(FILE* fp,logh* log){
    fp = fopen( "hum.txt", "r");
    char c = '\0';
    log->size=0;
    
    while (c!=EOF){
       
        
        //Διάβασε την ημερομηνία
    fscanf(fp,"%4d-%2d-%2dT%2d:%2d:%2d",&log->measurement[log->size].timestamp.year,&log->measurement[log->size].timestamp.month,&log->measurement[log->size].timestamp.day,&log->measurement[log->size].timestamp.hour,&log->measurement[log->size].timestamp.minute,&log->measurement[log->size].timestamp.sec);
        
        log->measurement[log->size].timestamp.together=100000000*log->measurement[log->size].timestamp.year+1000000*log->measurement[log->size].timestamp.month+10000*log->measurement[log->size].timestamp.day+100*log->measurement[log->size].timestamp.hour+log->measurement[log->size].timestamp.minute;
        
        //Πήγαινε στην μέτρηση
    c=getc(fp);
    while (c!='"') c=getc(fp);
        
        //Διάβασε την μέτρηση
    fscanf(fp, "%2d",&log->measurement[log->size].hum);
    log->size++;
        
        //Φτάσε μέχρι
        
        
    }
    
    
    
    
    
}
