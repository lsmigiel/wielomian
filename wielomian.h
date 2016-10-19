
#include <iostream>

using namespace std;

class Wielomian
{
   private:

    int *a, *b, *c, *d;    ///wspolczynniki wielomianu ax^3 + bx^2 + cx + d
    int deg; ///stopien wielomianu
    string nazwa;  ///nazwa wielomianu

public:


//    static int ile; ///zlicza ile utworzono obiektow
    Wielomian();
    Wielomian(string tekst, int a2, int b2, int c2, int d2);  ///konstruktor
    ~Wielomian(void);             ///destruktor

    friend ostream& operator<<(ostream & os, const Wielomian & w1); ///Funkcja zwraca referencjÄ™ do klasy ostream, aby mozliwe bylo
                                                                    ///kaskadowe wywolanie operatora, np: cout << w1 << "jest wielomianem";
    Wielomian& operator=(const Wielomian & w1);

    bool operator==(const Wielomian & w1);
    bool operator!=(const Wielomian & w1);

    Wielomian operator+(const Wielomian & skladnik);
    void operator+=(const Wielomian & skladnik);

    Wielomian operator-(const Wielomian & skladnik);
    void operator-=(const Wielomian & skladnik);


    Wielomian& operator*=(const Wielomian & skladnik);



};

Wielomian operator*(const Wielomian & skladnik, const Wielomian& skladnik2);
