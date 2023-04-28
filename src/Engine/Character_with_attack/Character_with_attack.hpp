#ifndef CHARACTER_WITH_ATTACK
#define CHARACTER_WITH_ATTACK

#include <concepts>
#include "../Character_with_life/Character_with_life.hpp"

namespace Engine
{
    class Character_with_attack
    {
        public:
            Character_with_attack() = delete;
            explicit Character_with_attack(double hitpoint) noexcept;

            Character_with_attack(Character_with_attack const &) = delete;
            Character_with_attack &operator=(Character_with_attack const &) = delete;

            Character_with_attack(Character_with_attack &&) = delete;
            Character_with_attack &operator=(Character_with_attack &&) = delete;

            template <std::derived_from<Engine::Character_with_life> T>
            void attack(T& target) const noexcept
            {
                target.degat(m_hitpoint);
            }

            constexpr virtual ~Character_with_attack() = default;
        private:
            double m_hitpoint;
    };
}

#endif