#include "Carre.hpp"

#include <sstream>

Carre::Carre(double cote) : cote_(cote) {}

double Carre::area() const {
    return cote_ * cote_;
}

double Carre::perimeter() const {
    return 4.0 * cote_;
}

std::string Carre::afficherInfo() const {
    std::ostringstream oss;
    oss << "Carre(cote=" << cote_ << ")";
    oss << " aire=" << area();
    oss << " perimetre=" << perimeter();
    return oss.str();
}
