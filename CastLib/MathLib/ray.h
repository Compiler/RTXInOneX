#pragma once

#ifndef RAY_H
#define RAY_H
#include <vec3.h>

class Ray{

private:
    Point3 _origin, _direction;
    _PrecisionType _t;

public:
    Ray() = default;
    Ray(Point3 origin, Point3 direction): _origin(origin), _direction(direction){}
    Ray(Point3& origin, Point3& direction): _origin(origin), _direction(direction){}

    Point3 at(_PrecisionType t){
        return _origin + _direction * t;
    }

};



#endif