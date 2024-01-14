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

    std::string header = "P3";
    std::string dimensions = std::to_string(imgWidth) + " " + std::to_string(imgHeight);
    std::string colorDepth = "255";

    std::cout << header << "\n" << dimensions << "\n" << colorDepth << "\n";

    for(int r = 0; r < imgHeight; r++){
        std::clog << "\rScanlines remaining: " << (imgHeight - r) << ' ' << std::flush;
        for(int c = 0; c < imgWidth; c++){
            // For each cell, we need an rgb output
            Vec3 direction = {
                static_cast<_PrecisionType>(r),
                static_cast<_PrecisionType>(c),
                static_cast<_PrecisionType>(-1)};

            Ray outputRay = Ray(cameraPosition, direction);
            Color3 resultingPixelColor = ray_color(outputRay);
            write_color(std::cout, resultingPixelColor);
        }
    }
    std::clog << "\rDone.                 \n";
}