#ifndef CARRE_HPP
#define CARRE_HPP

#include "Forme.hpp"

class Carre : public Polygone {
public:
    explicit Carre(double cote);

    double area() const override;
    double perimeter() const override;
    std::string afficherInfo() const override;

private:
    double cote_;
};

#endif // CARRE_HPP
