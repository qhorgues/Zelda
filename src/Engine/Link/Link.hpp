#ifndef LINK_HPP
#define LINK_HPP

#include "../Movable_Character/Movable_Character.hpp"

namespace Engine
{
    class Link final : public Movable_Character
    {
    public:
        Link() = default;
            
        Link(Link const&) = delete;
        Link& operator=(Link const&) = delete;

        Link(Link &&) = delete;
        Link& operator=(Link &&) = delete;

        ~Link() = default;
    private:
    };
}

#endif