#include "TitleBar.hpp"
#include "Button.hpp"
#include "../Window.hpp"

namespace psychicui {

    TitleBar::TitleBar() :
        Div() {
        setTag("TitleBar");
        _defaultStyle->set(direction, "row");

        add<Button>(
            "Close", [this]() {
                window()->close();
            }
        )->addClassName("close");

        add<Button>(
            "Minimize", [this]() {
                window()->toggleMinimized();
            }
        )->addClassName("minimize");

        add<Button>(
            "Maximize", [this]() {
                window()->toggleFullscreen();
            }
        )->addClassName("maximize");

        _label = add<Label>();
        _label->addClassName("title");
    };

    void TitleBar::addedToRender() {
        Div::addedToRender();
        // TODO: Allow updates to title
        _label->setText(window()->title());
    }

    void TitleBar::onMouseDownEvent(int mouseX, int mouseY, int button, int modifiers) {
        Div::onMouseDownEvent(mouseX, mouseY, button, modifiers);
        window()->startDrag();
    }

    void TitleBar::onMouseUpEvent(int mouseX, int mouseY, int button, int modifiers) {
        Div::onMouseUpEvent(mouseX, mouseY, button, modifiers);
        window()->stopDrag();
    }
}