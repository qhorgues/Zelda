#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../../Coord.hpp"

namespace Engine
{
    class Movable_Character;
    namespace __private
    {
        class Character
        {
        public:
            Character() = delete;
            explicit Character(int x, int y) noexcept;
            explicit Character(Coord<int> coord) noexcept;

            Character(Character const &) = delete;
            Character &operator=(Character const &) = delete;

            Character(Character &&) = delete;
            Character &operator=(Character &&) = delete;


            constexpr Coord<int> get_position_coord() const noexcept;
            std::tuple<int, int> get_position_x_y() const;

            friend Movable_Character;

        protected:
            constexpr ~Character() = default;
        private: 
            Coord<int> m_coord;
        };
    }
    
}

#endif