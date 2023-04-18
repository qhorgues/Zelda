#ifndef MOVABLE_CHARACTER_HPP
#define MOVABLE_CHARACTER_HPP

#include <tuple>
#include "../../Coord.hpp"

namespace Engine
{
    class Movable_Character
    {
    public:
        Movable_Character() = delete;
        Movable_Character(int x, int y, double velocity) noexcept;
        Movable_Character(Coord coord, double velocity) noexcept;

        Movable_Character(Movable_Character const &) = delete;
        Movable_Character &operator=(Movable_Character const &) = delete;

        Movable_Character(Movable_Character &&) = delete;
        Movable_Character &operator=(Movable_Character &&) = delete;

        enum class Direction
        {
            NORTH,
            SOUTH,
            EST,
            WEST,
            NONE
        };

        void move(Direction direction, double delta_time = 1.) noexcept;
        std::tuple<int, int> get_position();

        ~Movable_Character() = default;

    private:
        double m_velocity;
        Coord m_coord;
    };
};

#endif