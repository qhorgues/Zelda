#ifndef COORD_HPP
#define COORD_HPP

#include <utility>
#include <concepts>

template <typename T = int> requires std::is_arithmetic<T>::value
class Coord final
{
public:
    constexpr Coord() = default;
    constexpr Coord(T x, T y) noexcept
     : m_coord(x, y)
    {
    }
    constexpr ~Coord() = default;

    constexpr Coord(Coord const&) = default;
    constexpr Coord& operator=(Coord const&) = default;

    constexpr Coord(Coord &&) = default;
    constexpr Coord& operator=(Coord &&) = default;

    constexpr T get_x(void) const noexcept
    {
        return m_coord.first;
    }

    constexpr T get_y(void) const noexcept
    {
        return  m_coord.second;
    }

    constexpr void set_x(T x) noexcept
    {
        m_coord.first = x;
    }

    constexpr void set_y(T y) noexcept
    {
        m_coord.second = y;
    }

private:
    std::pair<int, int> m_coord;
};

#endif