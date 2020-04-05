#include "Macierz.hh"

Macierz::Macierz(){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            tab[i][j] = 0;
        }
}

Macierz::Macierz(double a1, double a2, double a3, double b1, double b2, double b3, double c1, double c2, double c3){

    tab[0][0] = a1, tab[0][1] = a2, tab[0][2] = a3;
    tab[1][0] = b1, tab[1][1] = b2, tab[1][2] = b3;
    tab[2][0] = c1, tab[2][1] = c2, tab[2][2] = c3;
}

Macierz::Macierz(Wektor W1, Wektor W2, Wektor W3){

    tab[0] = W1;
    tab[1] = W2;
    tab[2] = W3;
}

double Macierz::WyznacznikLaplace() const{

    return 
    (tab[0][0]*((tab[1][1]*tab[2][2])-(tab[1][2]*tab[2][1]))
    -tab[1][0]*((tab[0][1]*tab[2][2])-(tab[0][2]*tab[2][1]))
    +tab[2][0]*((tab[0][1]*tab[1][2])-(tab[0][2]*tab[1][1])));
}

const Macierz Macierz::Transpozycja() const{

    Macierz MacTr;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            MacTr[i][j] = tab[j][i];
        }

    return MacTr;
}

double Macierz::Dopelnienie(double i, double j, double m, double n, double znak){
    return znak*((i*j)-(m*n));
}

/*

const Macierz & Macierz::odwrotnosc() const{

    double det = WyznacznikLaplace();
    Macierz MacDop;
    
    MacDop[0][0] = Dopelnienie(tab[1][1], tab[2][2], tab[2][1], tab[1][2], 1);
    
}

*/

const Macierz Macierz::Odwrotnosc() const{

    double det = WyznacznikLaplace();
    Macierz MacDop;

    MacDop[0][0] = tab[1][1]*tab[2][2] - tab[1][2]*tab[2][1];
    MacDop[0][1] = -(tab[1][0]*tab[2][2] - tab[1][2]*tab[2][0]);
    MacDop[0][2] = tab[1][0]*tab[2][1] - tab[1][1]*tab[2][0];
    MacDop[1][0] = -(tab[0][1]*tab[2][2] - tab[0][2]*tab[2][1]);
    MacDop[1][1] = tab[0][0]*tab[2][2] - tab[0][2]*tab[2][0];
    MacDop[1][2] = -(tab[0][0]*tab[2][1] - tab[0][1]*tab[2][0]);
    MacDop[2][0] = tab[0][1]*tab[1][2] - tab[0][2]*tab[1][1];
    MacDop[2][1] = -(tab[0][0]*tab[1][2] - tab[1][0]*tab[0][2]);
    MacDop[2][2] = tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];

    MacDop = MacDop.Transpozycja();

    Macierz MacOdw;

    for(int i = 0; i < 3; i++ )
        for(int j = 0; j < 3; j++){
            MacOdw[i][j] = (1/det)*MacOdw[i][j];
        }

    return MacOdw;
}

const Macierz Macierz::operator + (const Macierz & M) const{
    
    Macierz wynik;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            wynik[i][j] = tab[i][j] + M[i][j];
        }
    return wynik;
}

const Macierz Macierz::operator - (const Macierz & M) const{

    Macierz wynik;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            wynik[i][j] = tab[i][j] - M[i][j];
        }
    return wynik;
}

const Macierz Macierz::operator * (const Macierz & M) const{
    Macierz wynik;
    for(int j=0;j<3;j++)
        for(int i=0;i<3;i++){
            wynik[i][j] = tab[i][0]*M[0][j]+tab[i][1]*M[1][j]+tab[i][2]*M[2][j];
        }
    return wynik;
}

const Wektor Macierz::operator * (const Wektor & W) const{

    Wektor wynik;
    for(int i=0;i<3;i++){
        wynik[i] = tab[i][0]*W[0] + tab[i][1]*W[1] + tab[i][2]*W[2];
    }
    return wynik;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &M)
{   
    Macierz M1;
    M1 = M.Transpozycja();
    return Strm << M1[0] << std::endl << M1[1] << std::endl << M1[2] << std::endl;
}

std::istream& operator >> (std::istream &Strm, Macierz &M)
{
    Strm >> M[0] >> M[1] >> M[2];
    M.Transpozycja();
    return Strm;
}
