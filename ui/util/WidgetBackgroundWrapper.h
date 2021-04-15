#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WIDGETBACKGROUNDWRAPPER_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WIDGETBACKGROUNDWRAPPER_H

#include <sdlgui/widget.h>

namespace karasimulator {

/**
 * Simple sdlgui wrapper which allows to set a background
 */
class WidgetBackgroundWrapper : public sdlgui::Widget {
public:

    explicit WidgetBackgroundWrapper(sdlgui::Widget* parent, const SDL_Color& color);

    void setColor(const SDL_Color& color) { this->color = color; }
    const SDL_Color& getColor() const { return color; }

    void draw(SDL_Renderer* renderer) override;

    void performLayout(SDL_Renderer* ctx) override;

private:

    SDL_Color color;

};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_WIDGETBACKGROUNDWRAPPER_H
