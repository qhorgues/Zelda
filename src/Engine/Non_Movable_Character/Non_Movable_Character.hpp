#ifndef NON_MOVABLE_CHARACTER_HPP
#define NON_MOVABLE_CHARACTER_HPP

#include "../Character/Character.hpp"

namespace Engine
{
    class Non_Movable_Character : public __private::Character
    {
    public:
        using __private::Character::Character;
        Non_Movable_Character() = delete;
        constexpr virtual ~Non_Movable_Character() = default;

        Non_Movable_Character(Non_Movable_Character const &) = delete;
        Non_Movable_Character &operator=(Non_Movable_Character const &) = delete;

        Non_Movable_Character(Non_Movable_Character &&) = delete;
        Non_Movable_Character &operator=(Non_Movable_Character &&) = delete;
    };
}

#endif
