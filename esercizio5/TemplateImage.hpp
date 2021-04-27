//
// Created by Gengisgat on 09/04/2021.
//

#ifndef UNTITLED17_TEMPLATEIMAGE_HPP
#define UNTITLED17_TEMPLATEIMAGE_HPP
#include <iostream>

template <typename T>
class TemplateImage {
public:
    TemplateImage(int righe, int colonne) : matrix(new T[3 * righe * colonne]), height(righe), width(colonne) {
        for (int i = 0; i < righe * colonne * 3; i++) {
            matrix[i] = 0;
        }

    }

    virtual ~TemplateImage() {
        delete[] matrix;
    }

    TemplateImage(TemplateImage &copy);

    TemplateImage<T> &operator=(const TemplateImage<T> &right);

    void set(const int &x, const int &y, const T &r, const T &g, const T &b);

    void printPixel(const int &x, const int &y);

    T get(const int &x, const int &y);

    T *matrix;
    int height, width;

private:


};

template<typename T>
void TemplateImage<T>::printPixel(const int &x,
                                  const int &y) {  //x e y sono da intendersi come coordinate cartesiane dell'immagine
    if (y < 0 || y >= height || x < 0 || x >= width)
        throw std::out_of_range("le coordinate inserite sono sbagliate!");
    std::cout << "[" << (int) matrix[x * width * 3 + y * 3] << " , " << (int) matrix[x * width * 3 + y * 3 + 1] << " , "
              << (int) matrix[x * width * 3 + y * 3 + 2]
              << "]";


}

template<typename T>
void TemplateImage<T>::set(const int &x, const int &y, const T &r, const T &g, const T &b) {
    if (y < 0 || y >= height || x < 0 || x >= width)
        throw std::out_of_range("le coordinate inserite sono sbagliate!");
    if (r < 0 || g < 0 || b < 0)
        throw std::invalid_argument("il valore dei pixel non e' accettabile!");

    matrix[x * (width * 3) + y * 3] = r;
    matrix[x * (width * 3) + y * 3 + 1] = g;
    matrix[x * (width * 3) + y * 3 + 2] = b;

}


template<typename T>
TemplateImage<T>::TemplateImage(TemplateImage &copy) {
    this->operator=(copy);
}

template<typename T>
T TemplateImage<T>::get(const int &x, const int &y) {
    if (x < 0 || x >= height || y < 0 || y >= width * 3)
        throw std::out_of_range("le coordinate inserite sono sbagliate!");
    return matrix[width * x + x];
}

template<typename T>
TemplateImage<T> &TemplateImage<T>::operator=(const TemplateImage<T> &right) {
    if (this != &right) {
        if (matrix)
            delete[] matrix;
        matrix = new T[right.height * right.width * 3];
        height = right.height;
        width = right.width;
        for (int i = 0; i < height * width * 3; i++) {
            this->matrix[i] = right.matrix[i];
        }
    }
    return *this;
}

#endif //UNTITLED17_TEMPLATEIMAGE_HPP
