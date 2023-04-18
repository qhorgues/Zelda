#include <iostream>
#include <exception>

#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDLImage.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/Surface.hh>
#include <SDL2pp/Texture.hh>
#include <SDL2pp/Exception.hh>

#include "Engine/Movable_Character/Movable_Character.hpp" 
#include "Engine/Character_with_life/Character_with_life.hpp"

namespace 
{
    constexpr int WIDTH_LINK_SPRITE {24};
    constexpr int HEIGHT_LINK_SPRITE {27};
};

class A final : public Engine::Movable_Character, public Engine::Character_with_life
{
public:
    A(int x, int y, double velocity, int max_life) : Engine::Movable_Character(x, y, velocity), Engine::Character_with_life(max_life)
    {
    }
};

int main()
{
    /* try
    {
        SDL2pp::SDL sdl {SDL_INIT_VIDEO};
        SDL2pp::SDLImage sdl_image {IMG_INIT_PNG};

        SDL2pp::Window window {"Zelda", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 400, SDL_WINDOW_SHOWN};
        SDL2pp::Renderer renderer {window, -1, SDL_RENDERER_ACCELERATED};

        SDL2pp::Surface link {"assets/link.png"};
        SDL2pp::Texture link_tex {renderer, link}; 

        renderer.Copy(link_tex, SDL2pp::Rect(0, 0, WIDTH_LINK_SPRITE, HEIGHT_LINK_SPRITE), SDL2pp::Rect(0, 0, WIDTH_LINK_SPRITE*10, HEIGHT_LINK_SPRITE*10));
        renderer.Present();
        SDL_Delay(5000);

    }
    catch (SDL2pp::Exception const& e)
    {
        std::cout << "Error : " << e.GetSDLFunction() 
                  << " -> " << e.GetSDLError() << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "Error : " << e.what() << std::endl;
    } */
    
    A link {12, 15, 2, 60};
    link.add_more_max_life(2);
    link.regeneration(3);
    link.move(Engine::Movable_Character::Direction::WEST, 0.5);

    return 0;
}
