#include "Triangle.hpp"

#include <cmath>
#include <sstream>

Triangle::Triangle(double a, double b, double c)
    : coteA_(a), coteB_(b), coteC_(c) {}

double Triangle::area() const {
    const double s = perimeter() / 2.0;
    return std::sqrt(s * (s - coteA_) * (s - coteB_) * (s - coteC_));
}

double Triangle::perimeter() const {
    return coteA_ + coteB_ + coteC_;
}

std::string Triangle::afficherInfo() const {
    std::ostringstream oss;
    oss << "Triangle(a=" << coteA_ << ", b=" << coteB_ << ", c=" << coteC_ << ")";
    oss << " aire=" << area();
    oss << " perimetre=" << perimeter();
    return oss.str();
}
