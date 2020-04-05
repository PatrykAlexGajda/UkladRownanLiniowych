#include "Wektor.hh"

double & Wektor::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
      std::cerr << "BLAD: Zly indeks wektora.";
      exit(1);
    }
    return tab[indeks];
}

Wektor & Wektor::operator += (const Wektor & W2){
    tab[0] += W2.tab[0];
    tab[1] += W2.tab[1];
    tab[2] += W2.tab[2];
}

const Wektor & Wektor::operator + (const Wektor & W2) const{

    Wektor wynik;

    wynik.tab[0] = tab[0] + W2.tab[0];
    wynik.tab[1] = tab[1] + W2.tab[1];
    wynik.tab[2] = tab[2] + W2.tab[2];
    return wynik;
}

const Wektor & Wektor::operator - (const Wektor & W2) const{

    Wektor wynik;

    wynik.tab[0] = tab[0] - W2.tab[0];
    wynik.tab[1] = tab[1] - W2.tab[1];
    wynik.tab[2] = tab[2] - W2.tab[2];

    return wynik;
}

std::istream& operator >> (std::istream &Strm, Wektor &W)
{
    Strm >> W[0] >> W[1] >> W[2];
    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Wektor &W)
{
    return Strm << W[0] << "\t" <<W[1] << "\t" << W[2] << std::endl;
}





