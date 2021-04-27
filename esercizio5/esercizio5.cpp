#include <iostream>
#include "exception"
#include "TemplateImage.hpp"


//ESERCIZIO 5 (CLASSE IMMAGINE)

int main() {
    TemplateImage<int> image1(3, 3);
    image1.set(1, 2, 4, 5, 6);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            image1.printPixel(i, j);
        }
        std::cout << std::endl;
    }

}
