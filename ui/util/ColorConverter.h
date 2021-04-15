#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_COLORCONVERTER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_COLORCONVERTER_H

#include <SDL.h>
#include "sdlgui/common.h"
#include "Color.h"

namespace karasimulator {

class ColorConverter {
public:

    ColorConverter() = delete;

    static sdlgui::Color toNanoguiColor(viewmodel::Color color) {
        SDL_Color sdlColor = toSdlColor(color);
        return {sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a};
    }

    static sdlgui::Color toDarkerColor(viewmodel::Color color, float factor) {
        sdlgui::Color nanoguiColor = toNanoguiColor(color);
        sdlgui::Color resultColor = nanoguiColor * factor;
        return resultColor.withAlpha(nanoguiColor.a()); // retain alpha
    }

    static SDL_Color toSdlColor(viewmodel::Color color) {
        switch (color) {
            case viewmodel::Color::BLACK:
                return {0, 0, 0, 255};
            case viewmodel::Color::BLUE:
                return {0, 0, 255, 255};
            case viewmodel::Color::GREEN:
                return {0, 255, 0, 255};
            case viewmodel::Color::YELLOW:
                return {255, 255, 0, 255};
            case viewmodel::Color::PINK:
                return {255, 175, 175, 255};
            case viewmodel::Color::MAGENTA:
                return {255, 0, 255, 255};
            case viewmodel::Color::RED:
                return {255, 0, 0, 255};
        }
        return {0, 0, 0, 255};
    }


};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_COLORCONVERTER_H
