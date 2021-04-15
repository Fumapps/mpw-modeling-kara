#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_CONTROLWINDOWTHEME_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_CONTROLWINDOWTHEME_H

#include "LightTheme.h"

namespace karasimulator {

/**
 * A simple theme which is used for windows, which represent controls and hence
 * shall not be rendered as a window.
 */
class ControlWindowTheme : public LightTheme {
public:

    explicit ControlWindowTheme(SDL_Renderer* context) : LightTheme(context) {
        mWindowHeaderHeight = 0;
        mWindowDropShadowSize = 0;
        mWindowFillFocused = {255, 255};
        mWindowFillUnfocused = {255, 255};
    }
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_CONTROLWINDOWTHEME_H
