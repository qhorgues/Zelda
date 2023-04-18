#include <cassert>
#include <tuple>
#include "Movable_Character.hpp"

namespace Engine
{
    Movable_Character::Movable_Character(int x, int y, double velocity) noexcept
        : m_velocity(velocity), m_coord{x, y}
    {
        assert(velocity >= 0 && "Velocity cannot be negative");
    }

    Movable_Character::Movable_Character(Coord coord, double velocity) noexcept
        : m_velocity(velocity), m_coord{coord}
    {
        assert(velocity >= 0 && "Velocity cannot be negative");
    }

    void Movable_Character::move(Direction direction, double delta_time) noexcept
    {
        switch (direction)
        {
        case Direction::NORTH:
            m_coord.y -= static_cast<int>(m_velocity * delta_time);
            break;

        case Direction::SOUTH:
            m_coord.y += static_cast<int>(m_velocity * delta_time);
            break;

        case Direction::WEST:
            m_coord.x -= static_cast<int>(m_velocity * delta_time);
            break;

        case Direction::EST:
            m_coord.x += static_cast<int>(m_velocity * delta_time);
            break;

        case Direction::NONE:
        default:
            break;
        }
    }

    std::tuple<int, int> Movable_Character::get_position()
    {
        return std::make_tuple(m_coord.x, m_coord.y);
    }
} // namespace Engine
