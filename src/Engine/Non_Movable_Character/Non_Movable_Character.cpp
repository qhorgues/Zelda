#include <cassert>
#include "Non_Movable_Character.hpp"
#include <tuple>

namespace Engine
{
    Non_Movable_Character::Non_Movable_Character(int x, int y) noexcept
        : m_coord{x, y}
    {
        assert(x >= 0 && y >= 0 && "x and y must be positive or zero");
    }

    Non_Movable_Character::Non_Movable_Character(Coord coord) noexcept
        : m_coord{coord}
    {
        assert(coord.x >= 0 && coord.y >= 0 && "x and y must be positive or zero");
    }

    std::tuple<int, int> Non_Movable_Character::get_position()
    {
        return std::make_tuple(m_coord.x, m_coord.y);
    }
}