#include <iostream>

int main(){

    constexpr int imgWidth = 32, imgHeight = 32;
    std::string header = "P3";
    std::string dimensions = std::to_string(imgWidth) + " " + std::to_string(imgHeight);
    std::string colorDepth = "255";

    std::cout << header << "\n" << dimensions << "\n" << colorDepth << "\n";

    for(int r = 0; r < imgHeight; r++){
        for(int c = 0; c < imgWidth; c++){
            // For each cell, we need an rgb output
            int red = 255.99 * (double)(r / (double)imgHeight);
            int green = 255.99 * (double)(c / (double)imgWidth);
            int blue = 255.99 * (double)((r+c) / (double)(imgHeight + imgWidth));
            std::cout << red << ' ' << green << ' '<< blue << ' ';
        }
        std::cout << "\n";
    }

}