#include <iostream>
#include <exception>
#include "Engine/Character_with_life/Character_with_life.hpp"
#include "Engine/Movable_Character/Movable_Character.hpp"
#include "Engine/Non_Movable_Character/Non_Movable_Character.hpp"

namespace 
{
    constexpr int WIDTH_LINK_SPRITE {24};
    constexpr int HEIGHT_LINK_SPRITE {27};
};

class A : public Engine::Character_with_life, public Engine::Movable_Character
{
public:
    A(int x, int y, double velocity, int max_life) : Character_with_life(max_life), Movable_Character(x, y, velocity)
    {}

};

int main()
{
    A a {12, 15, 0.5, 50};

    std::cout << a.get_life() << std::endl;
    a.add_more_max_life(20);
    a.regeneration(40);
    std::cout << a.get_life() << std::endl;

    a.move(Engine::Movable_Character::Direction::EST, 2.);

    auto[x, y] = a.get_position();

    std::cout << x << " / " << y << std::endl;
}
