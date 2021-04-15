#include "SpeedSliderControl.h"

#include "ControlWindowTheme.h"
#include "util/UiDimensions.h"

using namespace sdlgui;

namespace karasimulator {

const double MIN_SPEED = 1.0;
const double MAX_SPEED = 10.0;

SpeedSliderControl::SpeedSliderControl(sdlgui::Screen& screen)
        : Window(&screen, "") {

    setTheme(new ControlWindowTheme(screen.sdlRenderer()));
    setPosition(SLIDER_X, SLIDER_HEIGHT);

    sliderControl = &slider();
    sliderControl->withFixedWidth(SLIDER_WIDTH);
    withFixedWidth(SLIDER_WIDTH);
}

void SpeedSliderControl::bindToSpeed(const viewmodel::GameViewModel& viewModel,
                                     viewmodel::GameViewInput& viewInput) {
    sliderControl->setValue(speedToSliderValue(viewModel.getSpeed()));

    sliderControl->setCallback([&viewInput](float value) {
        viewInput.speedChanged(sliderValueToSpeed(value));
    });

}

float SpeedSliderControl::speedToSliderValue(double speed) {
    return static_cast<float>((speed - MIN_SPEED) / (MAX_SPEED - MIN_SPEED));
}

double SpeedSliderControl::sliderValueToSpeed(float value) {
    return MIN_SPEED + (MAX_SPEED-MIN_SPEED)*value;
}

}
