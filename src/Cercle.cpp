#include "Cercle.hpp"

#include <sstream>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

Cercle::Cercle(double rayon) : rayon_(rayon) {}

double Cercle::area() const {
    return kPi * rayon_ * rayon_;
}

double Cercle::perimeter() const {
    return 2.0 * kPi * rayon_;
}

std::string Cercle::afficherInfo() const {
    std::ostringstream oss;
    oss << "Cercle(rayon=" << rayon_ << ")";
    oss << " aire=" << area();
    oss << " perimetre=" << perimeter();
    return oss.str();
}
