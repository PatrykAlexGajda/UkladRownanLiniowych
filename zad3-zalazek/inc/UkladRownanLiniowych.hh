#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

class UkladRownanLiniowych {

  Macierz A;
  Wektor b;

public:

  UkladRownanLiniowych(){
    Macierz A();
    Wektor b();  
  }

  UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), b(bb){
    A = AA;
    b = bb;
  }

  const Macierz & get_A() const{
    return A;
  }
  const Wektor & get_b() const{
    return b;
  }
  void set_A(const Macierz & AA){
    A=AA;    
  }
  void set_b(const Wektor & bb){
    b=bb;
  }

  Wektor Oblicz() const;
};

std::istream & operator >> (std::istream &strm, UkladRownanLiniowych &UklRown);

std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych &UklRown);

#endif

