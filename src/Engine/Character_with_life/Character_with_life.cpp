#include <cassert>
#include "Character_with_life.hpp"

namespace Engine
{
    Character_with_life::Character_with_life(double max_life) noexcept
        : m_max_life(max_life), m_life(max_life)
    {
        assert(max_life > 0 && "Life is necessarily positive");
    }

    constexpr void Character_with_life::full_regeneration(void) noexcept
    {
        m_life = m_max_life;
    }

    void Character_with_life::regeneration(double life_point) noexcept
    {
        assert(life_point >= 0 && "Life point is necessarily positive or zero");

        if (life_point >= (m_max_life - m_life))
        {
            full_regeneration();
        }
        else
        {
            m_life += life_point;
        }
    }

    void Character_with_life::add_more_max_life(double more_max_life) noexcept
    {
        assert(more_max_life >= 0 && "\'more life\' is necessarily positive or zero");

        m_max_life += more_max_life;
    }

    double Character_with_life::get_life(void) const noexcept
    {
        return m_life;
    }

    void Character_with_life::degat(double attack_value) noexcept
    {
        if (attack_value >= m_life)
        {
            m_life = 0;
        }
        else
        {
            m_life -= attack_value;
        }
    }
}