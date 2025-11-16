#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

class Rectangle : public Polygone {
public:
    Rectangle(double largeur, double longueur);

    double area() const override;
    double perimeter() const override;
    std::string afficherInfo() const override;

protected:
    double largeur_;
    double longueur_;
};

#endif // RECTANGLE_HPP
