#include <iostream>
#include <vec3.h>
#include <color.h>
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
            Color3 curCellColor = {
                r < imgHeight / 4 ? 0 : (double) r / imgHeight,
                c < imgWidth / 4 ? 0 :(double) c / imgWidth,
                0
            };
            write_color(std::cout, curCellColor);
        }
    }
    std::clog << "\rDone.                 \n";
}