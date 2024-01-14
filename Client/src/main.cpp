#include <iostream>
#include "vec3.h"
#include "color.h"
int main(){

    constexpr int imgWidth = 256, imgHeight = 256;
    std::string header = "P3";
    std::string dimensions = std::to_string(imgWidth) + " " + std::to_string(imgHeight);
    std::string colorDepth = "255";

    std::cout << header << "\n" << dimensions << "\n" << colorDepth << "\n";

    for(int r = 0; r < imgHeight; r++){
        std::clog << "\rScanlines remaining: " << (imgHeight - r) << ' ' << std::flush;
        for(int c = 0; c < imgWidth; c++){
            // For each cell, we need an rgb output
            Color3 curCellColor = {
                (double) r / imgHeight,
                (double) c / imgWidth,
                0
            };
            write_color(std::cout, curCellColor);
        }
    }
    std::clog << "\rDone.                 \n";
}