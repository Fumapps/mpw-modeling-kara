#include "SdlApplication.h"

#include <sdlgui/theme.h>
#include <utility>
#include <sstream>

#include "util/LightTheme.h"
#include "util/UiDimensions.h"

using namespace sdlgui;

namespace karasimulator {

static void throwExceptionWithSdlError(const std::string& message) {
    throw std::runtime_error(message + " SDL Error: " + SDL_GetError());
}

static void throwExceptionWithSdlTtfError(const std::string& message) {
    throw std::runtime_error(message + " TTF Error: " + TTF_GetError());
}

SdlApplication::SdlApplication(std::string title, SdlApplicationListener& listener)
        : title(std::move(title)), listener(listener) {
}

void SdlApplication::initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throwExceptionWithSdlError("SDL could not initialize!");
    } else {
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                  width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        SDL_SetWindowMinimumSize(window, MIN_WINDOW_WIDTH, MIN_WINDOW_HEIGHT);
        if (window == nullptr) {
            throwExceptionWithSdlError("Window could not be created!");
        } else {
            int imageFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imageFlags) & imageFlags)) {
                throwExceptionWithSdlError("SDL_image could not initialize!");
            } else if (TTF_Init() == -1) {
                throwExceptionWithSdlTtfError("SDL_ttf could not initialize!");
            } else {
                renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
                SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
                nanoGuiScreen = std::make_unique<Screen>(window, Vector2i{width, height}, title, true, true);
                nanoGuiScreen->setTheme(new LightTheme(renderer));

                if (renderer == nullptr) {
                    throwExceptionWithSdlError("Renderer could not be created!");
                } else {
                    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    listener.onInitialized(*this);
                }
            }
        }
    }

}


void SdlApplication::runApplication() {
    running = true;

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    int width = std::max(event.window.data1, MIN_WINDOW_WIDTH);
                    int height = std::max(event.window.data2, MIN_WINDOW_HEIGHT);
                    nanoGuiScreen->setSize(Vector2i{width, height});
                    nanoGuiScreen->performLayout(renderer);
                }
            }
            listener.onEvent(event);
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        listener.onRender(*renderer);
        nanoGuiScreen->drawAll();

        SDL_RenderPresent(renderer);
    }

    listener.onClose();

    dispose();
}

SDL_Texture& SdlApplication::loadTexture(const std::string& path) {
    SDL_Texture* newTexture = nullptr;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        throwExceptionWithSdlError("Unable to load image " + path);
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        SDL_FreeSurface(loadedSurface);
        if (newTexture == nullptr) {
            throwExceptionWithSdlError("Unable to texture from " + path);
        }
    }

    loadedTextures.push_back(newTexture);

    return *newTexture;
}

void SdlApplication::dispose() {
    if (disposed) {
        return;
    }

    for (auto texture : loadedTextures) {
        SDL_DestroyTexture(texture);
    }
    loadedTextures.clear();

    for (auto& fontEntry : loadedFontsPerSize) {
        TTF_CloseFont(fontEntry.second);
    }
    loadedFontsPerSize.clear();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    disposed = true;
}

SDL_Texture& SdlApplication::createTextureForText(const std::string& text, int size, const SDL_Color& color) {
    TTF_Font* font = loadFont(size);
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    loadedTextures.push_back(textTexture);
    SDL_FreeSurface(textSurface);
    return *textTexture;
}

TTF_Font* SdlApplication::loadFont(int size) {
    TTF_Font* font;
    auto fontIter = loadedFontsPerSize.find(size);
    if (fontIter != loadedFontsPerSize.end()) {
        font = (*fontIter).second;
    } else {
        font = TTF_OpenFont("resources/fonts/Roboto-Medium.ttf", size);
        loadedFontsPerSize[size] = font;
    }
    return font;
}

SDL_Window& SdlApplication::getWindow() const {
    return *window;
}

sdlgui::Screen& SdlApplication::getNanoguiScreen() const {
    return *nanoGuiScreen;
}

}
