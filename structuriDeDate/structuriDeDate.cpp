#include "lista.h"

int main()
{

    Lista x;

    x.addStart(12);
    x.addStart(1);
    x.addStart(1234);
    x.addStart(5);


    //cout << x.head->next->data;

    

    x.addSfarsit(89);

    x.addPozitie(2, 1000);

    //stergere start

    /*cout << "INAINTE: " << endl << endl;
 
    x.afisare();

    cout << endl << endl;

    cout << "DUPA:" << endl << endl;

    x.stergereStart();

    x.afisare();
  
    cout << endl << endl;*/


    //stergere sfarsit

    /*cout << "INAINTE: " << endl << endl;
 
    x.afisare();

    cout << endl << endl;

    cout << "DUPA:" << endl << endl;

    x.stergereSfarsit();

    x.afisare();
  
    cout << endl << endl;*/


    //stergere poz

    /*cout << "INAINTE: " << endl << endl;
 
    x.afisare();

    cout << endl << endl;

    cout << "DUPA:" << endl << endl;

    x.stergerePozitie(3);

    x.afisare();
  
    cout << endl << endl;*/

    cout << "Lista: " << endl << endl;

    x.afisare();

    cout << endl << endl;
    
    cout << "Size: " << x.size();

    cout << endl << endl;
   
}