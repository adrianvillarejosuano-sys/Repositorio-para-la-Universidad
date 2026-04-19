#include <iostream>
#include <string>
#include "vector.h"

using namespace std;

int main()
{
    //variables
    double x,y,z;

    //primer vector
    cout << "escribe las coordenadas del primer vector y pulse intro \n";
    cin >> x >> y >> z ;
    poo::Vector v1{x,y,z};
    
    //segundo vector
    cout << "escribe las coordenadas del segundo vector y pulse intro \n";
    cin >> x >> y >> z ;
    poo::Vector v2{x,y,z};

    cout << "la suma es: ";
    poo::Vector v3 = suma(v1,v2);

    cout << v3.getX() << " " << v3.getY() << " " << v3.getZ() ;
}