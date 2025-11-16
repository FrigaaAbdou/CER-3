#ifndef FORME_HPP
#define FORME_HPP

#include <string>

class Forme {
public:
    virtual ~Forme() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string afficherInfo() const = 0;
};

class Polygone : public Forme {
public:
    ~Polygone() override = default;
    double area() const override = 0;
    double perimeter() const override = 0;
    std::string afficherInfo() const override = 0;
};

#endif // FORME_HPP
