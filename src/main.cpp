#include <iostream>
#include <exception>
#include "Engine/Engine.hpp"

namespace 
{
    constexpr int WIDTH_LINK_SPRITE {24};
    constexpr int HEIGHT_LINK_SPRITE {27};
};

class A : public Engine::Character_with_life, public Engine::Movable_Character, public Engine::Character_with_attack
{
public:
    A(int x, int y, double velocity, double max_life, double hitpoint) noexcept
     : Character_with_life(max_life), Movable_Character(x, y, velocity), Character_with_attack(hitpoint)
    {}

};

int main()
{
    A a {12, 15, 0.5, 50., 6.};
    Engine::Character_with_attack b {9};

    std::cout << a.get_life() << std::endl;
    a.add_more_max_life(20.);
    a.regeneration(40);
    std::cout << a.get_life() << std::endl;

    b.attack(a);

    std::cout << a.get_life() << std::endl;


    a.move(Engine::Movable_Character::Direction::EST, 2.);

    auto[x, y] = a.get_position_x_y();

    std::cout << x << " / " << y << std::endl;
}
