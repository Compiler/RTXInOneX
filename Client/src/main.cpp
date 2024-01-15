#include <iostream>
#include <vec3.h>
#include <color.h>
#include <ray.h>

Color3 ray_color(const Ray& r) {
    Vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*Color3(1.0, 1.0, 1.0) + a*Color3(0.5 / 10.0, 0.7 / 10.0, 1.0 / 10.0);
}

int main(){

    int imgWidth = 512;
    auto aspectRatio = 16.0 / 9.0;
    int imgHeight = imgWidth / aspectRatio;

    _PrecisionType focalLen = 1.0;
    Point3 cameraPosition = {0, 0, 0};
    _PrecisionType vvpHeight = 2.0;
    _PrecisionType vvpWidth = vvpHeight * vvpWidth / (_PrecisionType)imgHeight;

    Vec3 vvpU = {vvpWidth, 0, 0};
    Vec3 vvpV = {0, vvpHeight, 0};

    Vec3 deltaU = vvpU / imgWidth;
    Vec3 deltaV = vvpV / imgHeight;

    Vec3 vvpTopLeft = cameraPosition - Vec3(0, 0, focalLen) - vvpU/2 - vvpV/2; 
    Vec3 pixel00 = vvpTopLeft + 0.5*(deltaU + deltaV);

    std::string header = "P3";
    std::string dimensions = std::to_string(imgWidth) + " " + std::to_string(imgHeight);
    std::string colorDepth = "255";

    std::cout << header << "\n" << dimensions << "\n" << colorDepth << "\n";

    for(int v = 0; v < imgHeight; v++){
        std::clog << "\rScanlines remaining: " << (imgHeight - v) << ' ' << std::flush;
        for(int u = 0; u < imgWidth; u++){
            Vec3 curPixelCenter = pixel00 + deltaU * u + deltaV * v;
            // For each cell, we need an rgb output
            Vec3 direction = curPixelCenter - cameraPosition;

            Ray outputRay = Ray(cameraPosition, direction);
            Color3 resultingPixelColor = ray_color(outputRay);
            write_color(std::cout, resultingPixelColor);
        }
    }
    std::clog << "\rDone.                 \n";
}