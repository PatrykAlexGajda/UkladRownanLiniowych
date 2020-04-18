#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

int main(){

  std::cout << std::endl << "Start programu " << std::endl << std::endl;

  Macierz A;
  Wektor b;
  Wektor Rozw;

  std::cin >> A >> b;

  UkladRownanLiniowych UklRown(A, b);

  std::cout << UklRown << std::endl;

  Rozw = UklRown.Oblicz();

  std::cout << "Rozwiazania ukladu rownan to: " << std::endl;

  std::cout << Rozw << std::endl;

  return 0;
}
