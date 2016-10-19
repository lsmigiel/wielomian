 
///Lukasz Smigielski, 2AiR, data powstania 4.11.2015
///Obiekty klasy Wielomian reprezentuja wielomiany stopnia maksymalnie 3.
#include <iostream>
#include "wielomian.h"
using namespace std;

int main()
{

    Wielomian w1("w1"  , 3,-5, 1, 2);
    Wielomian w2("w2"  , 0, 7, 3,-7);
    Wielomian w3("w3"  , 0, 0,-5, 2); //w trakcie dzialania programu zmienia wartosc
    Wielomian w4("w4"  , 0, 0, 0, 7); //w trakcie dzialania programu zmienia wartosc
    Wielomian w5("w5"  , 0, 0, 0, 0);
    Wielomian w6("w6"  , 9, 0, 0, 0);
    Wielomian w7("w7"  , 0, 4, 0, 0);
    Wielomian w8("w8"  , 0, 0, 8, 0);//w trakcie dzialania programu zmienia wartosc
    Wielomian w9("w9"  , 0, 7, 3,-7); //==w2
    Wielomian w10("w10", 3,-5, 1, 2); //==w1
    cout << endl;


    cout << "####Badanie identycznosci: w1 i w2  oraz  w9 i w2:\n";
    if(w1 == w2)
        cout << "w1 i w2 sa rowne; ";
    else if(w1 != w2)
        cout << "w1 i w2 sa nierowne; ";
    if(w9 == w2)
        cout << "w9 i w2 sa rowne;\n";
    else if(w9 != w2)
        cout << "w9 i w2 sa nierowne;\n";

    cout << "\n####Dodawanie:\n";
    cout << "w1 + w2 = " << w1 + w2 << endl;
    cout << "w1 + w5 = " << w1 + w5 << endl;
    cout << "w3 += w1; ";
    w3 += w1;
    cout << "Teraz w3 = " << w3 << endl;

    //od tego momentu w3 ma juz inna wartosc!

    cout << "\n####Odejmowanie:\n";
    cout << "w1 - w2 = " << w1-w2 << endl;
    cout << "w10 - w1 = " << w10 - w1 << endl;
    cout << "w4 -= w7; ";
    w4 -= w7;
    cout << "Teraz w4 = " << w4 << endl;

    //od tego momentu w4 ma inna wartosc!

    cout << "\n###Mnozenie:\n";
    cout << "w8*w9 = " << w8*w9 << endl;
    cout << "w1*w5 = " << w1*w5 << endl;
    cout << "w8*=w7; ";
    w8*=w7;
    cout << "Teraz w8 = " << w8 << endl;

    //od tego momentu w8 ma inna wartosc



    cout << endl;
    return 0;
}
