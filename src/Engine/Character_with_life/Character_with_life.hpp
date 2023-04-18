#ifndef CHARACTER_WITH_LIFE
#define CHARACTER_WITH_LIFE

namespace Engine
{
    class Character_with_life
    {
    public:
        Character_with_life() = delete;
        Character_with_life(int max_life);

        Character_with_life(Character_with_life const &) = delete;
        Character_with_life &operator=(Character_with_life const &) = delete;

        Character_with_life(Character_with_life &&) = delete;
        Character_with_life &operator=(Character_with_life &&) = delete;

        void full_regeneration(void) noexcept;
        void regeneration(int life_point) noexcept;
        void add_more_max_life(int more_max_life) noexcept;
        int get_life(void) noexcept;

        ~Character_with_life() = default;

    private:
        int m_max_life;
        int m_life;
    };
}

#endif