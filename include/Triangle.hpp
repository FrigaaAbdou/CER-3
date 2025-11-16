#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Polygone {
public:
    Triangle(double a, double b, double c);

    double area() const override;
    double perimeter() const override;
    std::string afficherInfo() const override;

private:
    double coteA_;
    double coteB_;
    double coteC_;
};

#endif // TRIANGLE_HPP
