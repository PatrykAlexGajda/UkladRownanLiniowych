#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"

// Klasa ukladu rownan liniowych, przechowuje macierz glowna ukladu oraz wektor wyrazow wolnych
// Deklaruje metody operujace na polach tej klasy 

class UkladRownanLiniowych {

  Macierz A;
  Wektor b;

public:

// Konstruktor tworzacy pola wyzerowanej macierzy oraz wyzerowanego wektora
  UkladRownanLiniowych(){ 
    Macierz A();
    Wektor b();  
  }

// Konstruktor podstawiajacy wczytane dane do pol odpowiednich pol klasy
  UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), b(bb){ 
    A = AA;
    b = bb;
  }

// Daje dostep do macierzy poza metodami klasy
  const Macierz & get_A() const{ 
    return A;
  }

// Daje dostep do wektora poza metodami klasy
  const Wektor & get_b() const{
    return b;
  }

// Daje mozliwosc podstawienia wczytanej macierzy pod pole w klasie
  void set_A(const Macierz & AA){
    A=AA;    
  }

// Daje mozliwosc podstawienia wczytanego wektora pod pole w klasie
  void set_b(const Wektor & bb){
    b=bb;
  }

// Deklaracja metody wyliczajacej niewiadome ukladu rownan
  Wektor Oblicz() const;

// Deklaracja metody obliczajacej wektor bledu
  Wektor WektorBledu() const;

// Deklaracja metody obliczajace dlugosc wektora bledu
  double MiaraBledu() const;
};

// Deklaracja przeciazenia operatora wczytywania ukladu rownan
std::istream & operator >> (std::istream &strm, UkladRownanLiniowych &UklRown);

// Deklaracja przeciazenia operatora wyswietlania ukladu rownan
std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych &UklRown);

#endif

