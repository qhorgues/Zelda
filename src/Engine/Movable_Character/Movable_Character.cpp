#include <cassert>
#include <tuple>
#include "Movable_Character.hpp"

namespace Engine
{
    Movable_Character::Movable_Character(int x, int y, double velocity) noexcept
        : __private::Character(x, y), m_velocity(velocity)
    {
        assert(velocity >= 0 && "Velocity cannot be negative");
    }

    Movable_Character::Movable_Character(Coord<int> coord, double velocity) noexcept
        : __private::Character(coord), m_velocity(velocity)
    {
        assert(velocity >= 0 && "Velocity cannot be negative");
    }

    void Movable_Character::move(Direction direction, double delta_time) noexcept
    {
        auto const [x, y] = get_position_x_y();
        switch (direction)
        {
        case Direction::NORTH:
            m_coord.set_y(y - static_cast<int>(m_velocity * delta_time));
            break;

        case Direction::SOUTH:
            m_coord.set_y(y + static_cast<int>(m_velocity * delta_time));
            break;

        case Direction::WEST:
            m_coord.set_x(x - static_cast<int>(m_velocity * delta_time));
            break;

        case Direction::EST:            
            m_coord.set_x(x + static_cast<int>(m_velocity * delta_time));
            break;

        case Direction::NONE:
        default:
            break;
        }
    }

} // namespace Engine
