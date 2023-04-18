#include <cassert>
#include "Character_with_life.hpp"

namespace Engine
{
    Character_with_life::Character_with_life(int max_life)
        : m_max_life(max_life), m_life(max_life)
    {
        assert(max_life > 0 && "Life is necessarily positive");
    }

    void Character_with_life::full_regeneration(void) noexcept
    {
        m_life = m_max_life;
    }

    void Character_with_life::regeneration(int life_point) noexcept
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

    void Character_with_life::add_more_max_life(int more_max_life) noexcept
    {
        assert(more_max_life >= 0 && "\'more life\' is necessarily positive or zero");

        m_max_life += more_max_life;
    }

    int Character_with_life::get_life(void) noexcept
    {
        return m_life;
    }
}