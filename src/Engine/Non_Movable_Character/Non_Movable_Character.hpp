#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../../Coord.hpp"
#include <tuple>

namespace Engine
{
    class Non_Movable_Character
    {
    public:
        Non_Movable_Character() = delete;
        Non_Movable_Character(int x, int y) noexcept;
        Non_Movable_Character(Coord coord) noexcept;

        Non_Movable_Character(Non_Movable_Character const &) = delete;
        Non_Movable_Character &operator=(Non_Movable_Character const &) = delete;

        Non_Movable_Character(Non_Movable_Character &&) = delete;
        Non_Movable_Character &operator=(Non_Movable_Character &&) = delete;

        ~Non_Movable_Character() = default;

        std::tuple<int, int> get_position();

    private:
        Coord m_coord;
    };
}

#endif