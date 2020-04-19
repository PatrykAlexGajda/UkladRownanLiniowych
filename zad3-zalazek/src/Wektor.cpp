#include "Wektor.hh"

//Metoda zezwla na dostep do elementu indeks tablicy ewktora 
double & Wektor::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) { // Blad w przypadku podania zlego indeksu
      std::cerr << "BLAD: Zly indeks wektora."; 
      exit(1);
    }
    return tab[indeks];
}

// Przeciazenie operatora dodawania dwoch wektorow
// Zwraca wynik dodania wektora klasy z wektorem podanym w argumencie
Wektor Wektor::operator + (const Wektor & W2) const{

    Wektor wynik;
    wynik.tab[0] = tab[0] + W2.tab[0];
    wynik.tab[1] = tab[1] + W2.tab[1];
    wynik.tab[2] = tab[2] + W2.tab[2];
    return wynik;
}

// Przeciazenie operatora odejmowania wektora od wektora
// Zwraca wynik odejmowania wektora podanego w argumencie od wektora klasy
Wektor Wektor::operator - (const Wektor & W2) const{

    Wektor wynik;

    wynik.tab[0] = tab[0] - W2.tab[0];
    wynik.tab[1] = tab[1] - W2.tab[1];
    wynik.tab[2] = tab[2] - W2.tab[2];

    return wynik;
}


// Przeciazenie operatora wczytywania wektora
// Podstawia wczytane dane pod kolejne elementy wektora i zwraza strumien wejsciowy
std::istream & operator >> (std::istream &Strm, Wektor &W)
{
    Strm >> W[0] >> W[1] >> W[2];
    return Strm;
}

// Przeciazenie operatora wyswietlania dla wektora
// Wyswietla kolejne elementy wektora i zwraca strumien wyjsciowy
std::ostream & operator << (std::ostream &Strm, const Wektor &W)
{
    Strm << W[0] << "\t" <<W[1] << "\t" << W[2] << std::endl;
    return Strm;
}





