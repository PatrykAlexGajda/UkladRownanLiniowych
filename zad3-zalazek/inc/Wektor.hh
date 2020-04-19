#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>

// Klasa wektora, przechowuje pole tablicy jednowymiarowej o okreslonej w ROZMIAR ilosci elementow
// Deklaruje metody operujace na tej tablicy

class Wektor {
  
    double tab[ROZMIAR];

  public:

// Konstruktor zerujacy elementy tablicy
    Wektor(){
      tab[0]=0, tab[1]=0, tab[2]=0;
    }

// Konstruktor podstawiajacy pod kolejne elementy wartosci z argumentow
    Wektor(double a, double b, double c){
      tab[0]=a, tab[1]=b, tab[2]=c;
    }

// Metoda obliczajaca dlugosc wektora
    double dlugosc() const{
      return sqrt(pow(tab[0], 2) + pow(tab[1], 2) + pow(tab[2], 2));
    }

// Metoda przeciazajaca operator mnozenia dla mnozenia wektora z klasy oraz podane jako argument (mnozenie skalarne)
    double operator * (const Wektor & W2) const{
      
      return tab[0]*W2.tab[0] + tab[1]*W2.tab[1] + tab[2]*W2.tab[2];
    }

// Metoda przeciazajaca operator indeksowania dla dotepu do elementow tablicy wektora (stale wartosci)
    const double & operator[] (int indeks) const{
      return tab[indeks];
    }

// Deklaracja metody przeciazajacej operator indeksowania
    double & operator[] (int indeks);
    
// Deklaracja metody przeciazajacej operator dodawania
    Wektor operator + (const Wektor & W2) const;
  
// Deklaracja metody przeciazajacej operator odejmowania
    Wektor operator - (const Wektor & W2) const;

};

// Deklaracja przeciazenia operatora wczytywania dlawektora
std::istream & operator >> (std::istream &Strm, Wektor &W);

// Deklaracja przeciazenia operatora wyswietlania dla wektora
std::ostream & operator << (std::ostream &Strm, const Wektor &W);


#endif
