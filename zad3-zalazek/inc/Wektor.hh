#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <math.h>


class Wektor {
  
    double tab[ROZMIAR];

  public:

    Wektor(){
      tab[0]=0, tab[1]=0, tab[2]=0;
    }

    Wektor(double a, double b, double c){
      tab[0]=a, tab[1]=b, tab[2]=c;
    }

    double dlugosc() const{
      return sqrt(pow(tab[0], 2) + pow(tab[1], 2) + pow(tab[2], 2));
    }

    double operator * (const Wektor & W2) const{
      
      return tab[0]*W2.tab[0] + tab[1]*W2.tab[1] + tab[2]*W2.tab[2];
    }

    const double & operator[] (int indeks) const{
      return tab[indeks];
    }

    double & operator[] (int indeks);
    
    Wektor operator + (const Wektor & W2) const;
    Wektor operator - (const Wektor & W2) const;
    const Wektor & operator += (const Wektor & W2);
};

std::istream & operator >> (std::istream &Strm, Wektor &W);

std::ostream & operator << (std::ostream &Strm, const Wektor &W);


#endif
