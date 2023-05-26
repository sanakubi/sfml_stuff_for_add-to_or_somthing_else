#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;


void ratio_upd(CircleShape& crc, RectangleShape& strel) {
    Vector2f delta;
    delta = strel.getPosition() - crc.getPosition();
    float ratio = atan2(delta.y - 11, delta.x - 11);
    strel.setRotation(90 + ratio * (180.0 / 3.14));
}

void strelkpos(Event& event, RectangleShape& strel) {
    uint8_t speed = 3;
    if (event.key.shift) speed = 10;
    if (event.key.code == Keyboard::Up) strel.move(0, -1 * speed);
    if (event.key.code == Keyboard::Down) strel.move(0, speed);
    if (event.key.code == Keyboard::Right) strel.move(speed, 0);
    if (event.key.code == Keyboard::Left) strel.move(-1 * speed, 0);

}

int main() {

    RenderWindow window(VideoMode(500, 500), "- arrows -");
    RectangleShape strelka(Vector2f(2, 75));

    std::vector<RectangleShape> ars;
    for (int i = 0; i < 50; i++) ars.push_back(RectangleShape(Vector2f(2, 75)));

    for (int i = 0; i < 50; i++) {
        ars[i].setPosition(i * 10, i * 10);
        ars[i].setFillColor(Color(255, 0, 0));
    }

    CircleShape crc;
    VertexArray point(Points, 50);
    int x = 0;

    crc.setPosition(1, 1);
    crc.setFillColor(Color(30, 144, 255, 255));
    crc.setRadius(10);

    strelka.setPosition(250, 250);
    strelka.setFillColor(Color(255, 0, 0));

    ratio_upd(crc, strelka);

    int grad, dly;
    grad = dly = 0;

    Event event;
    
    while (window.isOpen()) {

        if (!(dly % 9)) {

            for (int i = 0; i < 50; i++) {
                Vector2f tmp_axy = ars[i].getPosition();

                int x_ = 250 + round(200 * cos((i * 10 + grad) * 3.14 / 180));
                int y_ = 250 + round(200 * sin((i * 10 + grad) * 3.14 / 180));

                ars[i].setPosition(x_, y_);
            }
            grad++;
        }
        dly++;

        while (window.pollEvent(event)) {

            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseMoved) {

                crc.setPosition(event.mouseMove.x - 11, event.mouseMove.y - 11);
                ratio_upd(crc, strelka);

                point[x].position = Vector2f(event.mouseMove.x, event.mouseMove.y);
                point[x].color = Color(255, 0, 200);
                if (x >= 49) x = 0;
                x++;
            }

            if (event.type == Event::KeyPressed) {
                strelkpos(event, strelka);
                ratio_upd(crc, strelka);
            }

        }

                for (int i = 0; i < 50; i++) {
                    ratio_upd(crc, ars[i]);
                    Vector2f tmp_arxy = ars[i].getPosition();

                    int x, y; x = y = 0;
                    x = event.mouseMove.x - tmp_arxy.x;
                    y = event.mouseMove.y - tmp_arxy.y;

                    int longn = sqrt(pow(x, 2) + pow(y, 2));

                    ars[i].setSize(Vector2f(2, longn - 40));
                }

        window.clear();

        for (int i = 0; i < 50; i++) {
            window.draw(ars[i]);
        }

        //window.draw(point);
        //window.draw(strelka);
        window.draw(crc);
        window.setMouseCursorVisible(false);
        window.display();
    }

    return 0;
}
