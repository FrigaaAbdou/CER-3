#include <iostream>
#include <memory>
#include <vector>

#include "Carre.hpp"
#include "Cercle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

int main() {
    std::vector<std::unique_ptr<Forme>> formes;
    formes.push_back(std::make_unique<Cercle>(5.0));
    formes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    formes.push_back(std::make_unique<Carre>(3.0));
    formes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));

    for (const auto &forme : formes) {
        std::cout << forme->afficherInfo() << '\n';
    }
    return 0;
}
