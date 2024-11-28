#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <iostream>

class Sprite {
public:
  sf::Texture texture;
  sf::Sprite sprite;

  // Since sf::Sprite does not have default constructor, we need to
  // use member initialization
  Sprite(std::string path): sprite(texture) {
    // Load texture
    if(!texture.loadFromFile(path))
      std::cout << "File not found" << std::endl;
    // Set Sprite  
    sprite.setTexture(texture);
  } 
  
private:
};

#endif
