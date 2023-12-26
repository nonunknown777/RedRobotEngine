#include "popup.hpp"

Popup::Popup(std::string name = "Popup") : Window(name) {
    panel = new StyleBoxFlat();
}

Popup::~Popup() {
}
