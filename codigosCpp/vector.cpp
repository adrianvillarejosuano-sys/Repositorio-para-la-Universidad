//archivo : vector.cpp
#include "vector.h"

namespace poo{

    Vector::Vector (double x , double y , double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;

    }

    double Vector::getX(){
        return x;
    }

    double Vector::getY(){
        return y;
    }

    double Vector::getZ(){
        return z;
    }

    Vector suma (Vector v1, Vector v2) 
    {
    return Vector {v1.getX() + v2.getX(),
    v1.getY() + v2.getY(),
    v1.getZ() + v2.getZ() };
    }

    Vector resta (Vector v1, Vector v2) 
    {
    return Vector {v1.getX() - v2.getX(),
    v1.getY() - v2.getY(),
    v1.getZ() - v2.getZ() };
    }
    Vector producto (double e, Vector v) 
    {
    return Vector {e * v.getX(),
    e * v.getY(),
    e * v.getZ() };
    }

};