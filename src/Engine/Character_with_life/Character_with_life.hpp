#ifndef CHARACTER_WITH_LIFE
#define CHARACTER_WITH_LIFE

namespace Engine
{
    class Character_with_attack;

    class Character_with_life
    {
    public:
        Character_with_life() = delete;
        explicit Character_with_life(double max_life) noexcept;

        Character_with_life(Character_with_life const &) = delete;
        Character_with_life &operator=(Character_with_life const &) = delete;

        Character_with_life(Character_with_life &&) = delete;
        Character_with_life &operator=(Character_with_life &&) = delete;

        constexpr void full_regeneration(void) noexcept;
        void regeneration(double life_point) noexcept;
        void add_more_max_life(double more_max_life) noexcept;
        double get_life(void) const noexcept;

        constexpr virtual ~Character_with_life() = default;

        friend Character_with_attack;
        
    private:
        void degat(double attack_value) noexcept;
        double m_max_life;
        double m_life;
    };
}

#endif