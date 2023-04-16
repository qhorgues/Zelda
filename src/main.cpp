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

namespace 
{
    constexpr int WIDTH_LINK_SPRITE {24};
    constexpr int HEIGHT_LINK_SPRITE {27};
};

int main()
{
    try
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
    }
    
}
