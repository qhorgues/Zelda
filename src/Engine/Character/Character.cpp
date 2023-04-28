#include <cassert>
#include "Character.hpp"
#include <tuple>

namespace Engine
{
    namespace __private
    {
        Character::Character(int x, int y) noexcept
            : m_coord(x, y)
        {
            assert(x >= 0 && y >= 0 && "x and y must be positive or zero");
        }

        Character::Character(Coord<int> coord) noexcept
            : m_coord{coord}
        {
            assert(coord.get_x() >= 0 && coord.get_y() >= 0 && "x and y must be positive or zero");
        }

        constexpr Coord<int> Character::get_position_coord() const noexcept
        {
            return m_coord;
        }

        std::tuple<int, int> Character::get_position_x_y() const
        {
            return std::make_tuple(m_coord.get_x(), m_coord.get_y());
        }
    }
}