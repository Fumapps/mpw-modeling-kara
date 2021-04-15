#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_INPUTDIALOGWINDOW_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_INPUTDIALOGWINDOW_H

#include <sdlgui/window.h>
#include <sdlgui/messagedialog.h>

namespace karasimulator {

class InputDialogWindow : public sdlgui::Window {
public:

    using Type = sdlgui::MessageDialog::Type;

    explicit InputDialogWindow(Widget* parent, Type type, const std::string& title, const std::string& message);

    void setNumeric(bool numeric);

    void setInputFieldVisible(bool visible);

    void setCallback(std::function<void()> callback) {
        mCallback = callback;
    }

    const std::string& getInputText() const;

private:
    std::function<void()> mCallback;
    sdlgui::TextBox* textBox;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_KARASIMULATOR_CPP_INPUTDIALOGWINDOW_H
