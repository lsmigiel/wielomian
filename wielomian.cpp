 
#include <iostream>
#include "wielomian.h"

using namespace std;

Wielomian::Wielomian()  ///konstruktor domyslny;
{
    a = b = c = d = NULL;
    nazwa = "no_name";
    deg = 0;
    //ile++;
    cout << "Utworzono obiekt: " << nazwa << ": " << this << endl;
}
Wielomian::Wielomian(string tekst, int a2, int b2, int c2, int d2)  ///konstruktor;
{
    a = b = c = d = NULL;
    nazwa = tekst;
    if(a2 != 0){      ///jesli rozne od zera to przydzielamy pamiec;
        a = new int;
        *a = a2;
    }
    if(b2 != 0){
        b = new int;
        *b = b2;
    }
    if(c2 != 0){
        c = new int;
        *c = c2;
    }
    if(d2 != 0){
        d = new int;
        *d = d2;
    }
    if(a != NULL)
        deg = 3;
    else if(b != NULL)
        deg = 2;
    else if(c != NULL)
        deg = 1;
    else
        deg = 0;
  //ile++;
    cout << "Utworzono " << nazwa << ": " << *this << endl;
}

Wielomian::~Wielomian(void)                     ///destruktor;
{
    cout <<"Zniszczono " << nazwa << ": " << *this << endl;
    if(a != NULL) ///jesli przydzielono pamiec, zwalniamy ja;
    {
        delete a;
        a = NULL;
    }
    if(b != NULL)
    {
        delete b;
        b = NULL;
    }
    if(c != NULL)
    {
        delete c;
        c = NULL;
    }
    if(d != NULL)
    {
        delete d;
        d = NULL;
    }

    //ile--;
}

ostream& operator<<(ostream & os, const Wielomian & w1)
{
    ///w testach sprawdzamy czy przydzielono pamiec dla wspolczynnikow, czyli po prostu czy wskazuja na NULL czy tez nie;
    if(w1.a != NULL)
        os << "(" << *(w1.a) << ")*x^3";
    if(  w1.a != NULL && (w1.b != NULL || w1.c != NULL || w1.d != NULL) )
        os << " + ";
    if(w1.b != NULL)
        os <<"(" << *(w1.b) << ")*x^2";
    if( w1.b != NULL && (w1.c != NULL || w1.d != NULL) )
        os << " + ";
    if(w1.c != NULL)
        os <<"(" << *(w1.c) << ")*x";
    if( w1.c != NULL && w1.d != NULL)
        os << " + ";
    if(w1.d != NULL)
        os <<"(" << *(w1.d) << ")";
    if(w1.a == NULL && w1.b == NULL && w1.c == NULL && w1.d == NULL)
        os << 0;

    return os;
}

Wielomian& Wielomian::operator=(const Wielomian & w1)
{
    if(this == &w1)    ///zapobiega autoprzypisaniu, czyli np w3 = w3;
        return *this;

    delete a;  ///czyscimy wszystkie wspolczynniki...
    a = NULL;
    delete b;
    b = NULL;
    delete c;
    c = NULL;
    delete d;
    d = NULL;

    if(w1.a != NULL){  ///...aby wpisac tam wspolczynniki wielomianu z prawej strony znaku = (o ile istnieja);
        a = new int;
        *a = *(w1.a);
    }
    if(w1.b != NULL){
        b = new int;
        *b = *(w1.b);
    }
    if(w1.c != NULL){
        c = new int;
        *c = *(w1.c);
    }
    if(w1.d != NULL){
        d = new int;
        *d = *(w1.d);
    }
    deg = w1.deg;
    return *this;
}

bool Wielomian::operator==(const Wielomian & w1)
{
    int wspa = 0;  ///kazda z tych czterech zmiennych informuje czy odpowiednie wspolczynniki wielomianow sa sobie rowne;
    int wspb = 0;
    int wspc = 0;
    int wspd = 0;

    ///jesli wspolczynniki istnieja i ich wartosci sa rowne, albo w ogole nie istnieja to zaznaczamy, ze wspa = 1;
    if(  ((a != NULL && w1.a != NULL) && *a == *(w1.a)) || (a == NULL && w1.a == NULL) )
        wspa = 1;
    if(  ((b != NULL && w1.b != NULL) && *b == *(w1.b)) || (b == NULL && w1.b == NULL) )
        wspb = 1;
    if(  ((c != NULL && w1.c != NULL) && *c == *(w1.c)) || (c == NULL && w1.c == NULL) )
        wspc = 1;
    if(  ((d != NULL && w1.d != NULL) && *d == *(w1.d)) || (d == NULL && w1.d == NULL) )
        wspd = 1;

    if ( wspa == 1 && wspb == 1 && wspc == 1 && wspd == 1 ) ///jesli wszystkie wspolczynniki jednoczesnie sa rowne;
        return true;
    else
        return false;
}

bool Wielomian::operator!=(const Wielomian & w1)
{
    int wspa = 0;  ///kazda z tych czterech zmiennych informuje czy odpowiednie wspolczynniki wielomianow sa sobie rowne;
    int wspb = 0;
    int wspc = 0;
    int wspd = 0;

    ///jesli wspolczynniki istnieja i ich wartosci sa rowne, albo w ogole nie istnieja to zaznaczamy, ze wspa = 1;
    if(  ((a != NULL && w1.a != NULL) && *a == *(w1.a)) || (a == NULL && w1.a == NULL) )
        wspa = 1;
    if(  ((b != NULL && w1.b != NULL) && *b == *(w1.b)) || (b == NULL && w1.b == NULL) )
        wspb = 1;
    if(  ((c != NULL && w1.c != NULL) && *c == *(w1.c)) || (c == NULL && w1.c == NULL) )
        wspc = 1;
    if(  ((d != NULL && w1.d != NULL) && *d == *(w1.d)) || (d == NULL && w1.d == NULL) )
        wspd = 1;


    if ( wspa == 0 || wspb == 0 || wspc == 0 || wspd == 0 ) ///jesli ktorykolwiek ze wspolczynnikow sie nie zgadza;
        return true;
    else
        return false;
}

Wielomian Wielomian::operator+(const Wielomian & skladnik)
{
    Wielomian suma_temp("suma_temp",0,0,0,0);
/////////////////////
    if(a != NULL || skladnik.a != NULL) ///jesli istnieje ktorys ze wspolczynnikow przy x^3 w dodawanych wielomianach...
    {
        suma_temp.a = new int;     ///...to na pewno w wyniku wspolczynnik przy tej potedze tez bedzie istnial (wiec alokujemy pamiec)...
        *(suma_temp.a) = 0;
        if(a != NULL)
            *(suma_temp.a) += *a;
        if(skladnik.a != NULL)
            *(suma_temp.a) += *(skladnik.a);
    }
    if(suma_temp.a != NULL)   ///...chyba, ze po dodaniu odpowiadajacych wspolczynnikow wynik bedzie 0;
    {
        if(*(suma_temp.a) == 0){
            delete suma_temp.a;
            suma_temp.a = NULL;
        }
    }
//////////////////////////////
    if(b != NULL || skladnik.b != NULL)
    {
        suma_temp.b = new int;
        *(suma_temp.b) = 0;
        if(b != NULL)
            *(suma_temp.b) += *b;
        if(skladnik.b != NULL)
            *(suma_temp.b) += *(skladnik.b);
    }
    if(suma_temp.b != NULL)
    {
        if(*(suma_temp.b) == 0)
        {
            delete suma_temp.b;
            suma_temp.b = NULL;
        }
    }
///////////////////////////////
    if(c != NULL || skladnik.c != NULL)
    {
        suma_temp.c = new int;
        *(suma_temp.c) = 0;
        if(c != NULL)
            *(suma_temp.c) += *c;
        if(skladnik.c != NULL)
            *(suma_temp.c) += *(skladnik.c);
    }
    if(suma_temp.c != NULL)
    {
        if(*(suma_temp.c) == 0)
        {
            delete suma_temp.c;
            suma_temp.c = NULL;
        }
    }
//////////////////////////////
    if(d != NULL || skladnik.d != NULL)
    {
        suma_temp.d = new int;
        *(suma_temp.d) = 0;
        if(d != NULL)
            *(suma_temp.d) += *d;
        if(skladnik.d != NULL)
            *(suma_temp.d) += *(skladnik.d);
    }
    if(suma_temp.d != NULL)
    {
        if(*(suma_temp.d) == 0)
        {
            delete suma_temp.d;
            suma_temp.d = NULL;
        }
    }
///////////////////////////////
    if(suma_temp.a != NULL)
        suma_temp.deg = 3;
    else if(suma_temp.b != NULL)
        suma_temp.deg = 2;
    else if(suma_temp.c != NULL)
        suma_temp.deg = 1;
    else
        suma_temp.deg = 0;

    return suma_temp;
}

void Wielomian::operator+=(const Wielomian & skladnik)
{
////////////////////a
    if(a != NULL && skladnik.a != NULL)
    {
        *a += *(skladnik.a);
        if(*a == 0) ///jesli po przypisaniu wspolczynnik a jest zerem...
        {
            delete a;      ///...zwalniamy pamiec;
            a = NULL;
        }
    }
    else if(skladnik.a != NULL) ///jesli istnieje tylko wspolczynnik wielomianu po prawej stronie operatora
    {
            a = new int;
            *a = *(skladnik.a);
    }
///////////////////b
    if(b != NULL && skladnik.b != NULL)
    {
        *b += *(skladnik.b);
        if(*b == 0)
        {
            delete b;
            b = NULL;
        }
    }
    else if(skladnik.b != NULL)
    {
            b = new int;
            *b = *(skladnik.b);
    }
/////////////////////c
    if(c != NULL && skladnik.c != NULL)
    {
        *c += *(skladnik.c);
        if(*c == 0)
        {
            delete c;
            c = NULL;
        }
    }
    else if(skladnik.c != NULL)
    {
            c = new int;
            *c = *(skladnik.c);
    }
/////////////////////d
    if(d != NULL && skladnik.d != NULL)
    {
        *d += *(skladnik.d);
        if(*d == 0)
        {
            delete d;
            d = NULL;
        }
    }
    else if(skladnik.d != NULL)
    {
            d = new int;
            *d = *(skladnik.d);
    }


    if(a != NULL)
        deg = 3;
    else if(b != NULL)
        deg = 2;
    else if(c != NULL)
        deg = 1;
    else
        deg = 0;
}

Wielomian Wielomian::operator-(const Wielomian & skladnik)
{
    Wielomian roznica_temp("roznica_temp",0,0,0,0);

///////////////////////////
    if(a != NULL || skladnik.a != NULL) ///jesli istnieje ktorys ze wspolczynnikow przy x^3 w odejmowanych wielomianach...
    {
        roznica_temp.a = new int;     ///...to na pewno w wyniku wspolczynnik przy tej potedze tez bedzie istnial (wiec alokujemy pamiec)...
        *(roznica_temp.a) = 0;
        if(a != NULL && skladnik.a != NULL)
            *(roznica_temp.a) = *a - *(skladnik.a);
        else if(skladnik.a != NULL)
            *(roznica_temp.a) = -*(skladnik.a);
        else if(a!=NULL)     ///////te 2 linijki dodalem bo nie dzialalo dla: w1-w2, gdzie w2 jest wielomianem stopnia 0;
            *(roznica_temp.a) = *a;

    }
    if(roznica_temp.a != NULL && *(roznica_temp.a) == 0)   ///...chyba, ze po odjeciu wspolczynnikow wynik bedzie 0;
    {
            delete roznica_temp.a;
            roznica_temp.a = NULL;
    }
 //////////////////////
    if(b != NULL || skladnik.b != NULL)
    {
        roznica_temp.b = new int;
        *(roznica_temp.b) = 0;
        if(b != NULL && skladnik.b != NULL)
            *(roznica_temp.b) = *b - *(skladnik.b);
        else if(skladnik.b != NULL)
            *(roznica_temp.b) = -*(skladnik.b);
        else if(b!=NULL)
            *(roznica_temp.b) = *b;
    }
    if(roznica_temp.b != NULL && *(roznica_temp.b) == 0)
    {
            delete roznica_temp.b;
            roznica_temp.b = NULL;
    }
//////////////////////////
    if(c != NULL || skladnik.c != NULL)
    {
        roznica_temp.c = new int;
        *(roznica_temp.c) = 0;
        if(c != NULL && skladnik.c != NULL)
            *(roznica_temp.c) = *c - *(skladnik.c);
        else if(skladnik.c != NULL)
            *(roznica_temp.c) = -*(skladnik.c);
        else if(c!=NULL)
            *(roznica_temp.c) = *c;
    }
    if(roznica_temp.c != NULL && *(roznica_temp.c) == 0)
    {
            delete roznica_temp.c;
            roznica_temp.c = NULL;
    }
///////////////////////////////////
    if(d != NULL || skladnik.d != NULL)
    {
        roznica_temp.d = new int;
        *(roznica_temp.d) = 0;
        if(d != NULL && skladnik.d != NULL)
            *(roznica_temp.d) = *d - *(skladnik.d);
        else if(skladnik.d != NULL)
            *(roznica_temp.d) = -*(skladnik.d);
        else if(d!=NULL)
            *(roznica_temp.d) = *d;
    }
    if(roznica_temp.d != NULL && *(roznica_temp.d) == 0)
    {
            delete roznica_temp.d;
            roznica_temp.d = NULL;
    }
/////////////////////////////////

    if(roznica_temp.a != NULL)
        roznica_temp.deg = 3;
    else if(roznica_temp.b != NULL)
        roznica_temp.deg = 2;
    else if(roznica_temp.c != NULL)
        roznica_temp.deg = 1;
    else
        roznica_temp.deg = 0;

    return roznica_temp;
}

void Wielomian::operator-=(const Wielomian & skladnik)
{
////////////////////a
    if(a != NULL && skladnik.a != NULL)
    {
        *a -= *(skladnik.a);
        if(*a == 0) ///jesli po przypisaniu wspolczynnik a jest zerem...
        {
            delete a;      ///...zwalniamy pamiec;
            a = NULL;
        }
    }
    else if(skladnik.a != NULL) ///jesli istnieje tylko wspolczynnik wielomianu po prawej stronie operatora;
    {
            a = new int;
            *a = -*(skladnik.a);
    }
///////////////////b
    if(b != NULL && skladnik.b != NULL)
    {
        *b -= *(skladnik.b);
        if(*b == 0)
        {
            delete b;
            b = NULL;
        }
    }
    else if(skladnik.b != NULL)
    {
            b = new int;
            *b = -*(skladnik.b);
    }
/////////////////////c
    if(c != NULL && skladnik.c != NULL)
    {
        *c -= *(skladnik.c);
        if(*c == 0)
        {
            delete c;
            c = NULL;
        }
    }
    else if(skladnik.c != NULL)
    {
            c = new int;
            *c = -*(skladnik.c);
    }
/////////////////////d
    if(d != NULL && skladnik.d != NULL)
    {
        *d -= *(skladnik.d);
        if(*d == 0)
        {
            delete d;
            d = NULL;
        }
    }
    else if(skladnik.d != NULL)
    {
            d = new int;
            *d = -*(skladnik.d);
    }

    if(a != NULL)
        deg = 3;
    else if(b != NULL)
        deg = 2;
    else if(c != NULL)
        deg = 1;
    else
        deg = 0;
}




Wielomian& Wielomian::operator*=(const Wielomian & skladnik)
{
    if(deg + skladnik.deg > 3)
    {
        cout << "Za duze stopnie wielomianow\n";
     //   return;
    }
    ///jesli wielomian lewy lub prawy jest zerem:
    if( (a == NULL && b == NULL && c == NULL && d == NULL) || (skladnik.a == NULL && skladnik.b == NULL && skladnik.c == NULL && skladnik.d == NULL))
    {
        if(a != NULL) ///jesli przydzielono pamiec, zwalniamy ja;
        {
            delete a;
            a = NULL;
        }
        if(b != NULL)
        {
            delete b;
            b = NULL;
        }
        if(c != NULL)
        {
            delete c;
            c = NULL;
        }
        if(d != NULL)
        {
            delete d;
            d = NULL;
        }
        return *this;
    }

    if(deg == 2 && skladnik.deg == 1)
    {
        deg = 3;

        a = new int;
        *a = *b * *(skladnik.c);

        if(skladnik.d == NULL && c == NULL)
        {
            delete b;
            b = NULL;
        }
        if(skladnik.d != NULL && c != NULL)
            *b = *b * *(skladnik.d) + *c * *(skladnik.c);
        else if (skladnik.d != NULL)
            *b = *b * *(skladnik.d);
        else if (c != NULL)
            *b = *c * *(skladnik.c);

        if( c==NULL && d!=NULL){
            c = new int;
            *c = *d * *(skladnik.c);
        }
        else if(c!=NULL && skladnik.d == NULL && d == NULL)
        {
            delete c;
            c = NULL;
        }
        else if (c!= NULL && skladnik.d != NULL && d != NULL)
            *c = *c * *(skladnik.d) + *d * *(skladnik.c);
        else if( c != NULL && skladnik.d != NULL && d == NULL)
            *c = *c * *(skladnik.d);

        if(d!=NULL && skladnik.d!=NULL)
            *d = *d * *(skladnik.d);
        else if(d!= NULL && skladnik.d==NULL)
        {
            delete d;
            d = NULL;
        }

    }

    else if(deg == 1 && skladnik.deg == 2)
    {
        deg = 3;

        a = new int;
        *a = *c * *(skladnik.b);

        if(b == NULL && (skladnik.c!=NULL || d!=NULL))
            b = new int;
        if(b!=NULL && skladnik.c == NULL && d == NULL)
        {
            delete b;
            b = NULL;
        }
        if(skladnik.c != NULL && d!=NULL)
            *b = *c * *(skladnik.c) + *d * *(skladnik.b);
        else if(skladnik.c!=NULL && d==NULL)
            *b = *c * *(skladnik.c);
        else if(skladnik.c==NULL && d!=NULL)
            *b = *d * *(skladnik.b);

        if(skladnik.d == NULL && (d==NULL || skladnik.c==NULL))
        {
            delete c;
            c = NULL;
        }
        if(d!=NULL && skladnik.d!=NULL && skladnik.c!=NULL)
            *c = *c * *(skladnik.d) + *d * *(skladnik.c);
        else if(skladnik.d != NULL && (d==NULL || skladnik.c==NULL))
            *c = *c * *(skladnik.d);
        else if(skladnik.d==NULL && d!=NULL && skladnik.c!=NULL)
            *c = *d * *(skladnik.c);


        if(d!=NULL && skladnik.d!=NULL)
            *d = *d * *(skladnik.d);
        else if(d!= NULL && skladnik.d==NULL)
        {
            delete d;
            d = NULL;
        }

    }

    else if(deg == 3 && skladnik.deg == 0)
    {
        deg = 3;

        *a = *a * *(skladnik.d);
        if(b!=NULL)
            *b = *b * *(skladnik.d);
        if(c!=NULL)
            *c = *c * *(skladnik.d);
        if(d!=NULL)
            *d = *d * *(skladnik.d);


    }

    else if(deg == 0 && skladnik.deg == 3)
    {
        deg = 3;
        a = new int;
        *a = *d * *(skladnik.a);

        if(skladnik.b != NULL)
        {
            b = new int;
            *b = *d * *(skladnik.b);
        }
        if(skladnik.c != NULL)
        {
            c = new int;
            *c = *d * *(skladnik.c);
        }
        if(skladnik.d!=NULL)
            *d = *d * *(skladnik.d);
        else if(skladnik.d == NULL)
        {
            delete d;
            d = NULL;
        }

    }

    else if(deg == 2 && skladnik.deg == 0)
    {
        deg = 2;
        *b = *b * *(skladnik.d);
        if(c!=NULL)
            *c = *c * *(skladnik.d);
        if(d!=NULL)
            *d = *d * *(skladnik.d);

    }

    else if(deg == 0 && skladnik.deg == 2)
    {
        deg = 2;
        b = new int;
        *b = *d * *(skladnik.b);
        if(skladnik.c != NULL)
        {
            c= new int;
            *c = *d * *(skladnik.c);
        }
        if(skladnik.d == NULL)
        {
            delete d;
            d = NULL;
        }
        else if(skladnik.d != NULL)
            *d = *d * *(skladnik.d);
    }

    else if(deg == 1 && skladnik.deg == 0)
    {
        deg = 1;
        *c = *c * *(skladnik.d);
        if(d!=NULL)
            *d = *d * *(skladnik.d);
    }

    else if(deg == 0 && skladnik.deg == 1)
    {
        deg = 1;
        c = new int;
        *c = *d * *(skladnik.c);
        if(skladnik.d != NULL)
            *d = *d * *(skladnik.d);
        else if(skladnik.d == NULL)
        {
            delete d;
            d = NULL;
        }

    }

    else if(deg == 1 && skladnik.deg == 1)
    {
        deg = 2;
        b= new int;
        *b = *c * *(skladnik.c);

        if(skladnik.d == NULL && d == NULL)
        {
            delete c;
            c = NULL;
        }
        if(skladnik.d != NULL && d != NULL)
            *c = *c * *(skladnik.d) + *d * *(skladnik.c);
        else if(skladnik.d != NULL && d == NULL)
            *c = *c * *(skladnik.d);
        else if(skladnik.d==NULL && d != NULL)
            *c = *d * *(skladnik.c);

        if(d!=NULL && skladnik.d != NULL)
            *d = *d * *(skladnik.d);
        if(d!=NULL && skladnik.d==NULL)
        {
            delete d;
            d = NULL;
        }
    }

    else if(deg == 0 && skladnik.deg == 0)
    {
        deg = 0;

        *d = *d* *(skladnik.d);
    }
    return *this;
}

//int Wielomian::ile = 0;

Wielomian operator*(const Wielomian & skladnik, const Wielomian& skladnik2)
{

    Wielomian iloczyn_temp("iloczyn_temp",0,0,0,0);
    iloczyn_temp = skladnik;
    iloczyn_temp *= skladnik2;

    return iloczyn_temp;
}
