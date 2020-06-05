//
//  johnnylouds,h
//  Project_Tsakalidis
//
//  Εδώ υπάρχει ο parser για την μεταφορά των δεδομένων του αρχείου σε πίνακα
//  Επίσης εδώ υπάρχει η δήλωση των καινούργιων τύπων "measuret" & "measureh"

#ifndef johnnylouds_h
#define johnnylouds_h


typedef struct{
    int year
    int month
    int day
    int hour
    int minute
    int together
} time;

typedef struct{
    int temp
    int timestamp
} measuret;

typedef struct{
    int hum
    int timestamp
} measureh;

#endif johnnylouds_h
