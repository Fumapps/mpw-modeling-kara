#ifndef KARASIMULATOR_CPP_SDLAPPLICATION_H
#define KARASIMULATOR_CPP_SDLAPPLICATION_H

#include <SDL.h>

#undef main // fixes compile error on Windows

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sdlgui/screen.h>

#include <string>
#include <vector>
#include <unordered_map>
#include "SdlApplicationListener.h"

namespace karasimulator {

/// \brief Convenience wrapper of a SDL application
class SdlApplication {
public:

    SdlApplication(std::string title, SdlApplicationListener& listener);

    void initialize(int width, int height);

    void runApplication();

    SDL_Texture& loadTexture(const std::string& path);
    SDL_Texture& createTextureForText(const std::string& text, int size, const SDL_Color& color);

    void dispose();

    SDL_Window& getWindow() const;
    sdlgui::Screen& getNanoguiScreen() const;

private:

    std::string fontColorWithSizeToKey(int size, const SDL_Color& color);
    TTF_Font* loadFont(int size);

    const std::string title;
    SdlApplicationListener& listener;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    std::unique_ptr<sdlgui::Screen> nanoGuiScreen;

    std::vector<SDL_Texture*> loadedTextures;
    std::unordered_map<int, TTF_Font*> loadedFontsPerSize;

    bool running = false;
    bool disposed = false;

};

}

#endif //KARASIMULATOR_CPP_SDLAPPLICATION_H
