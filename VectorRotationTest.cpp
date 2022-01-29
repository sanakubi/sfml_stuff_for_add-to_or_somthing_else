#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;

void ratio_upd(CircleShape& crc, RectangleShape& strel) {
    Vector2f delta;

    delta = strel.getPosition() - crc.getPosition();
    float ratio = atan2(delta.y - 11, delta.x - 11);
    std::cout << ratio << " " << ratio * (180.0 / 3.14) << std::endl;
    strel.setRotation(90 + ratio * (180.0 / 3.14));
}

int main() {

    RenderWindow window(VideoMode(500, 500), "- - -");

    RectangleShape strelka(Vector2f(2, 225));
    CircleShape crc;
    Vector2f delta;

    crc.setPosition(1, 1);
    crc.setFillColor(Color(30, 144, 255, 255));
    crc.setRadius(10);

    strelka.setPosition(250, 250);
    strelka.setFillColor(Color(255, 0, 0));
    
    ratio_upd(crc, strelka);
    

    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseMoved)
            {
                std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
                std::cout << "new mouse y: " << event.mouseMove.y << std::endl;

                crc.setPosition(event.mouseMove.x, event.mouseMove.y);
                ratio_upd(crc, strelka);
            }
        }
        
        window.draw(strelka);
        window.draw(crc);
        window.display();
        window.clear();
    }
    return 0;
}
