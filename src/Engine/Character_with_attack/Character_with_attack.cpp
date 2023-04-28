#include <cassert>
#include "Character_with_attack.hpp"

namespace Engine
{
    Character_with_attack::Character_with_attack(double hitpoint) noexcept
     : m_hitpoint(hitpoint)
    {
       assert(hitpoint >= 0 && "hitpoint cannot be negative");
    }
}