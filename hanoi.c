
/* -------------------------------------------------------------------------- 
   Dateiname:   hanoi.c
   Aufgabe:     Textbasierte Simulation der Tuerme von Hanoi
   Version:     1.0 (c) 1992-2017 FHDW Software Development Group
   -------------------------------------------------------------------------- */

#define LOWERLIMIT  1
#define UPPERLIMIT 12
   
#include <stdio.h>
#include <stdlib.h>

void Hanoi(int,int,int);

int main(int argc, char **argv)
{
    int n=0; /* Anzahl der Scheiben */
    
    /* Ein Aufrufparameter - Anzahl der Scheiben - obligatorisch! */
    if (argc != 2)
    {
        printf("usage: hanoi <slices> \n");
        return EXIT_FAILURE;
    }

    /* Anzahl zwischen LOWER- und UPPERLIMIT ? */
    n = atoi(argv[1]);
    if (n < LOWERLIMIT  ||  n > UPPERLIMIT)
    {
        printf("Anzahl der Scheiben muss zwischen %d und %d liegen!\n",
            LOWERLIMIT,UPPERLIMIT);
        return EXIT_FAILURE;            
    }

    printf("Eingabe: %d Scheibe(n).\n",n);
    Hanoi(n,1,2); /* Turm der Hoehe n von Stange 1 auf Stange 2 */
    
    return EXIT_SUCCESS; 

} /* end main */ 


void Hanoi(int n, int von, int nach)
{
    static int zaehler = 0;
    int hilf = 6 - nach - von; /* Nr. der Hilfsstange */

    /* Turm der Hoehe n-1 wird von "von" nach "hilf" bewegt */
    if (n > 1)
    {
        Hanoi(n-1,von,hilf);
    }
    
    /* Groesste Scheibe geht von "von" nach "nach" */
    printf("%5d: Bewege Scheibe von %d nach %d.\n",++zaehler,von,nach);
    
    /* Turm der Hoehe n-1 wird von "hilf" nach "nach" bewegt */
    if (n > 1)
    {
        Hanoi(n-1,hilf,nach);
    }
    
} /* end Hanoi */

/* end of file hanoi.c */

