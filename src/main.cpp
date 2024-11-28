#include <SFML/Graphics.hpp>
#include "../include/sprite.hpp"


int main() {
  auto window =
      sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
  window.setFramerateLimit(144);

  // sf::Texture texture;

  // if (!texture.loadFromFile("images/charmander.png")) {
  //   std::cout << "File not found" << std::endl;
  // }

  // sf::Sprite sprite(texture);

  Sprite sprite("images/charmander.png");
  
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    window.draw(sprite.sprite);
    window.display();
  }
}
