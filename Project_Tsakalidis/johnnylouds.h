//
//  johnnylouds,h
//  Project_Tsakalidis
//
//  Εδώ υπάρχει ο parser για την μεταφορά των δεδομένων του αρχείου σε πίνακα
//  Επίσης εδώ υπάρχει η δήλωση των καινούργιων τύπων "time","measuret" & "measureh"

#ifndef johnnylouds_h
#define johnnylouds_h



//Χρόνος, για την εύκολη διαχείρηση των timestamps, ενδιαφέρον έχει το int together, σκοπός του είναι να κάνει ευκολότερο το sorting
typedef struct{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int together;
} time;



//Τύποι δεδομένων για την καταγραφή των μετρήσεων. Ένας από τους δύο θα μπορούσε να παραληφθεί αλλά χρησιμοποιούνται για λόγους ευαναγνωσιμότητας
typedef struct{
    int temp;
    time timestamp;
} measuret;

typedef struct{
    int hum;
    time timestamp;
} measureh;

typedef struct{
    measureh* measurement;
    int size;
} logh;

typedef struct{
    measuret* measurement;
    int size;
} logt;




//Parser Δεδομένων, αυτό το τμήμα του κώδικα έχει ως στόχο την ανάγνωση του αρχείου και την εισαγωγή των δεδομένων στο πρόγραμμα
void loadh(FILE*,logh);
void loadt(FILE*,logt);


#endif johnnylouds_h
