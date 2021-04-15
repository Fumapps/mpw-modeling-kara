#include "SdlGameInputInterface.h"

#include <mutex>

using namespace sdlgui;

namespace karasimulator {

SdlGameInputInterface::SdlGameInputInterface(Screen& screen)
        : screen(screen), semaphore(0) {
}

void SdlGameInputInterface::onRender(SDL_Renderer& renderer) {
    screen.drawAll();
}

void SdlGameInputInterface::onEvent(SDL_Event& event) {
    screen.onEvent(event);
}

bool SdlGameInputInterface::isActive() const {
    return active;
}

int SdlGameInputInterface::readInteger(std::string message) {
    showMessageForTextInput(message, sdlgui::MessageDialog::Type::Information);
    inputDialog->setNumeric(true);
    wait();

    try {
        return std::stoi(inputDialog->getInputText());
    } catch (std::exception& e) {
        return 0;
    }
}

void SdlGameInputInterface::wait() {
    active = true;
    semaphore.lock();
    active = false;
}

std::string SdlGameInputInterface::readString(std::string message) {
    showMessageForTextInput(message, sdlgui::MessageDialog::Type::Information);
    wait();
    return inputDialog->getInputText();
}

void SdlGameInputInterface::confirmAlert(const std::exception& t) {
    showMessage(t.what(), sdlgui::MessageDialog::Type::Warning);
    wait();
}

void SdlGameInputInterface::showMessageForTextInput(const std::string& message, InputDialogWindow::Type type) {
    showMessage(message, type);
    inputDialog->setInputFieldVisible(true);
}

void SdlGameInputInterface::showMessage(const std::string& message, InputDialogWindow::Type type) {
    inputDialog = &screen.wdg<InputDialogWindow>(MessageDialog::Type::Information, "Message box", message);
    inputDialog->setCallback([&] {
        semaphore.release();
    });
    inputDialog->setInputFieldVisible(false);
}

void SdlGameInputInterface::abort() {
    semaphore.release();
}

}
