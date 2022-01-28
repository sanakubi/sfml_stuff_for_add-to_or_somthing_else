#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(500, 500), "- - -");

    RectangleShape strelka(Vector2f(2, 225));
    CircleShape crc;
    Vector2f delta;

    crc.setPosition(400, 400);
    crc.setFillColor(Color(30, 144, 255, 255));
    crc.setRadius(10);

    strelka.setPosition(250, 250);
    strelka.setFillColor(Color(255, 0, 0));

    delta = strelka.getPosition() - crc.getPosition();
 
    float ratio = atan2(delta.y - 11, delta.x - 11); 
    
    std::cout << ratio << " " << ratio * (180.0 / 3.14) << std::endl;
    
    strelka.setRotation(90 + ratio * (180.0 / 3.14));
    


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(strelka);
        window.draw(crc);
        window.display();
        window.clear();
    }
    return 0;
}
