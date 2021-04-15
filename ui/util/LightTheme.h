#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_LIGHTTHEME_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_LIGHTTHEME_H

#include <sdlgui/theme.h>

namespace karasimulator {

class LightTheme : public sdlgui::Theme {
public:

    explicit LightTheme(SDL_Renderer* context) : Theme(context) {
        using sdlgui::Color;
        mDropShadow = Color(32, 32, 32, 255);
        mTransparent = Color(0, 0);
        mBorderDark = Color(255 - 29, 255);
        mBorderLight = Color(255 - 92, 255);
        mBorderMedium = Color(255 - 35, 255);
        mTextColor = Color(255 - 255, 160);
        mDisabledTextColor = Color(255 - 255, 80);
        mTextColorShadow = Color(0, 160);
        mIconColor = mTextColor;

        mButtonGradientTopFocused = Color(255 - 64, 255);
        mButtonGradientBotFocused = Color(255 - 48, 255);
        mButtonGradientTopUnfocused = Color(255 - 74, 255);
        mButtonGradientBotUnfocused = Color(255 - 58, 255);
        mButtonGradientTopPushed = Color(255 - 41, 255);
        mButtonGradientBotPushed = Color(255 - 29, 255);

        /* Window-related */
        mWindowFillUnfocused = Color(255 - 43, 255);
        mWindowFillFocused = Color(255 - 45, 255);
        mWindowTitleUnfocused = Color(255 - 220, 160);
        mWindowTitleFocused = Color(255 - 255, 190);

        /* Slider */
        mSliderKnobOuter = Color(255 - 92, 255);
        mSliderKnobInner = Color(255 - 220, 255);

        mWindowHeaderGradientTop = mButtonGradientTopUnfocused;
        mWindowHeaderGradientBot = mButtonGradientBotUnfocused;
        mWindowHeaderSepTop = mBorderLight;
        mWindowHeaderSepBot = mBorderDark;

        mWindowPopup = Color(255 - 50, 255);
        mWindowPopupTransparent = Color(255 - 50, 0);
    }
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_LIGHTTHEME_H
