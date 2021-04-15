#include "InputDialogWindow.h"

#include <sdlgui/layout.h>
#include <sdlgui/label.h>
#include <sdlgui/button.h>
#include <sdlgui/entypo.h>
#include <sdlgui/textbox.h>

#include <array>

using namespace sdlgui;

namespace karasimulator {

InputDialogWindow::InputDialogWindow(Widget* parent, Type type, const std::string& title, const std::string& message)
        : Window(parent, title) {
    setLayout(new BoxLayout(Orientation::Vertical,
                            Alignment::Middle, 10, 10));
    setModal(true);

    Widget* panel1 = new Widget(this);
    panel1->setLayout(new BoxLayout(Orientation::Horizontal,
                                    Alignment::Middle, 10, 15));
    int icon = 0;
    switch (type) {
        case Type::Information:
            icon = ENTYPO_ICON_CIRCLED_INFO;
            break;
        case Type::Question:
            icon = ENTYPO_ICON_CIRCLED_HELP;
            break;
        case Type::Warning:
            icon = ENTYPO_ICON_WARNING;
            break;
    }
    Label* iconLabel = new Label(panel1, std::string(utf8(icon).data()), "icons");
    iconLabel->setFontSize(50);
    Label* mMessageLabel = new Label(panel1, message);
    Widget* panel2 = new Widget(this);
    panel2->setLayout(new BoxLayout(Orientation::Vertical,
                                    Alignment::Middle, 0, 15));

    textBox = new TextBox(panel2, "");
    textBox->setEditable(true);
    textBox->setAlignment(TextBox::Alignment::Left);
    textBox->setFixedSize(Vector2i(100, 20));
    textBox->setFontSize(16);

    Button* button = new Button(panel2, "OK");
    button->setCallback([&] {
        if (mCallback) mCallback();
        dispose();
    });
    center();
    requestFocus();
}

void InputDialogWindow::setInputFieldVisible(bool visible) {
    textBox->setVisible(visible);
}

const std::string& InputDialogWindow::getInputText() const {
    return textBox->value();
}

void InputDialogWindow::setNumeric(bool numeric) {
    if (numeric) {
        textBox->setFormat("[-]?[0-9]*\\.?[0-9]+");
        textBox->setDefaultValue("0");
    } else {
        textBox->setFormat("");
        textBox->setDefaultValue("");
    }
    textBox->setValue(textBox->defaultValue());
}


}
