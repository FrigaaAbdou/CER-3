#include "Rectangle.hpp"

#include <sstream>

Rectangle::Rectangle(double largeur, double longueur)
    : largeur_(largeur), longueur_(longueur) {}

double Rectangle::area() const {
    return largeur_ * longueur_;
}

double Rectangle::perimeter() const {
    return 2.0 * (largeur_ + longueur_);
}

std::string Rectangle::afficherInfo() const {
    std::ostringstream oss;
    oss << "Rectangle(largeur=" << largeur_ << ", longueur=" << longueur_ << ")";
    oss << " aire=" << area();
    oss << " perimetre=" << perimeter();
    return oss.str();
}
