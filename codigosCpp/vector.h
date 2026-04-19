#pragma once

namespace poo {

class Vector {

public:
    Vector(double x, double y, double z);

    double getX();
    double getY();
    double getZ();

private:
    double x;
    double y;
    double z;
};

// funciones del namespace
Vector suma(Vector v1, Vector v2);
Vector resta(Vector v1, Vector v2);
Vector producto(double e, Vector v1);

}