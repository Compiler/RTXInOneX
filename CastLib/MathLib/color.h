#pragma once
#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

typedef Vec3 Color3;

void write_color(std::ostream &out, Color3& pixelColorNormal) {
    // Write the normal-translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixelColorNormal.r()) << ' '
        << static_cast<int>(255.999 * pixelColorNormal.g()) << ' '
        << static_cast<int>(255.999 * pixelColorNormal.b()) << '\n';
}

#endif