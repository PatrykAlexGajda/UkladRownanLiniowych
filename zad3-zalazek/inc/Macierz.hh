#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

class Macierz {
  
    Wektor tab[ROZMIAR];

  public:

    Macierz();

    Macierz(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3);

    Macierz(Wektor W1, Wektor W2, Wektor W3);

    const Wektor & operator[] (int indeks) const{
      return tab[indeks];
    }
    Wektor & operator[] (int indeks){
      return tab[indeks];
    }

    const double & operator() (int ind1, int ind2) const{
      return tab[ind1][ind2];
    }
    double & operator() (int ind1, int ind2){
      return tab[ind1][ind2];
    }

    double WyznacznikLaplace() const;
    const Macierz Transpozycja() const;
    const Macierz Odwrotnosc() const;
    Macierz operator + (const Macierz & W) const; 
    Macierz operator - (const Macierz & W) const; 
    Macierz operator * (const Macierz & W) const; 
    Wektor operator * (const Wektor & W) const;
};

std::istream& operator >> (std::istream &Strm, Macierz &M);

std::ostream& operator << (std::ostream &Strm, const Macierz &M);

#endif
