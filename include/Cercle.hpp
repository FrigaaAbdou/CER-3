#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {
public:
    explicit Cercle(double rayon);

    double area() const override;
    double perimeter() const override;
    std::string afficherInfo() const override;

private:
    double rayon_;
};

#endif // CERCLE_HPP
