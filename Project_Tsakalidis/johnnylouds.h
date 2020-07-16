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
    int sec;
    long int together;
} timej;



//Τύποι δεδομένων για την καταγραφή των μετρήσεων. Ένας από τους δύο θα μπορούσε να παραληφθεί αλλά χρησιμοποιούνται για λόγους ευαναγνωσιμότητας
typedef struct{
    float temp;
    timej timestamp;
} measuret;

typedef struct{
    int hum;
    timej timestamp;
} measureh;

typedef struct{
    measureh* measurement;
    int size;
} logh;

typedef struct{
    measuret* measurement;
    int size;
} logt;




//Parser Δεδομένων, αυτό το τμήμα του κώδικα έχει ως στόχο την ανάγνωση του αρχείου και την εισαγωγή των δεδομένων στο πρόγραμμα ανά μέτρηση
void loadh(logh*);
void loadt(logt*);

//Οι παρακάτω συναρτήσεις παίρνουν όλες τις μετρήσεις που υπάρχουν σε μια λίστα εγγραφών logh ή logt και επιστρέφουν έναν πίνακα που περιέχει μόνο τις μέσες μετρήσεις κάθε ημέρας.
void takedayst(logt log,logt* result);
void takedaysh(logh log,logh* result);

//Ειδικές συναρτήσεις για την εκτύπωση των στοιχείων ενός log
void printlogh(logh);
void printlogt(logt);



//Συναρτήσεις για την διευκόλυνση περασμάτων τιμών

void passlogh(logh*,logh*);// αντιγράφει τα περιεχόμενα του πρώτου log στο δεύτερο (για υγρασίες)
void passlogt(logt*,logt*);// αντιγράφει τα περιεχόμενα του πρώτου log στο δεύτερο (για θερμοκρασίες)

void passmeasurementh(measureh *a, measureh *b);//Αντιγράφει τα περιεχόμενα της πρώτης μέτρησης στην δεύτερη (για υγρασίες)
void passmeasurementt(measuret *a, measuret *b);//Αντιγράφει τα περιεχόμενα της πρώτης μέτρησης στην δεύτερη (για θερμοκρασίες)

//Ρουτίνες για είσοδο ημερομηνίας
void ask4date(timej* t);
void ask4day(timej* t);


//Swaps 

void swaph(measureh *a, measureh *b);
void swapt(measuret *a, measuret *b);

#endif //"johnnylouds_h"

