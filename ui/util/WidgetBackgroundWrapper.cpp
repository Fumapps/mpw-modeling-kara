#include "WidgetBackgroundWrapper.h"

#include <sdlgui/layout.h>
#include <SDL.h>
#include <algorithm>

namespace karasimulator {

WidgetBackgroundWrapper::WidgetBackgroundWrapper(sdlgui::Widget* parent, const SDL_Color& color)
        : Widget(parent), color(color) {
}

void WidgetBackgroundWrapper::draw(SDL_Renderer* renderer) {
    SDL_Rect rect{absolutePosition().x, absolutePosition().y, mSize.x, mSize.y};
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    Widget::draw(renderer);
}

void WidgetBackgroundWrapper::performLayout(SDL_Renderer* ctx) {
    Widget::performLayout(ctx);
    Widget* child = childAt(0);
    setWidth(std::max(child->width(), width()));
    setHeight(std::max(child->height(), height()));
}


}
