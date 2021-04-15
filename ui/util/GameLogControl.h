#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMELOGCONTROL_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMELOGCONTROL_H

#include <sdlgui/screen.h>
#include <sdlgui/window.h>
#include <sdlgui/vscrollpanel.h>
#include <unordered_map>

#include "KaraView.h"

namespace karasimulator {

class GameLogControl : public sdlgui::Window {
private:

    sdlgui::Screen& screen;
    sdlgui::Widget* listPanel;
    sdlgui::VScrollPanel* scrollPanel;

    std::unordered_map<const viewmodel::ViewModelLogEntry*, sdlgui::Widget*> logEntryWidgets;

public:

    explicit GameLogControl(sdlgui::Screen& screen);

    void bindToGameLog(const viewmodel::GameViewModel& viewModel);

    void draw(SDL_Renderer* surface) override;

    void performLayout(SDL_Renderer* ctx) override;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_GAMELOGCONTROL_H
