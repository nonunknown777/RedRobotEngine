#include "button.hpp"

namespace rre {

    Button::Button() {

        style_normal = new StyleBoxFlat();

        get_style<StyleBoxFlat>(style_normal)->bg_color = WHITE;

        style_hover = new StyleBoxFlat();

        get_style<StyleBoxFlat>(style_hover)->bg_color = BLACK;



        style_current = style_normal;
    }

    Button::~Button() {
        delete get_style<StyleBoxFlat>(style_current);
        delete get_style<StyleBoxFlat>(style_normal);

    }

    void Button::_draw() {
        Rectangle rect = Rectangle(position.x,position.y,size.x,size.y);
        style_current->draw(rect);
    }

    void Button::_input(const InputEvent& event) {

        if (event.type == InputType::MOUSE_MOVED) {
            if (CheckCollisionPointRec(Vector2(event.mouse_pos.x, event.mouse_pos.y),Rectangle(position.x,position.y,size.x,size.y))) {
                style_current = style_hover;
                //TODO: queue redraw
            } else {
                style_current = style_normal;
            }
            RenderingServer::get_singleton().update();

        }

    }


}