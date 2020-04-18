#include "UkladRownanLiniowych.hh"

std::istream & operator >> (std::istream &strm, UkladRownanLiniowych &UklRown){
    Macierz temp_A;
    Wektor temp_b;

    strm >> temp_A >> temp_b;

    temp_A.Transpozycja();
    
    UklRown.set_A(temp_A);
    UklRown.set_b(temp_b);

    return strm;
}

std::ostream & operator << ( std::ostream &strm, const UkladRownanLiniowych &UklRown){

    std::cout << UklRown.get_A() << "\nx1\tx2\tx3\t\n\n\n" << UklRown.get_b() << std::endl;  

    return strm;
}

Wektor UkladRownanLiniowych::Oblicz() const{

    Wektor X;

    Macierz Ax1(b ,A[1], A[2]);
    Macierz Ax2(A[0], b, A[2]);
    Macierz Ax3(A[0], A[1], b);

    double WyznA = A.WyznacznikLaplace();
    double WyznAx1 = Ax1.WyznacznikLaplace();
    double WyznAx2 = Ax2.WyznacznikLaplace();
    double WyznAx3 = Ax3.WyznacznikLaplace();

    X[0] = WyznAx1/WyznA;
    X[1] = WyznAx2/WyznA;
    X[2] = WyznAx3/WyznA;


    return X;
}
