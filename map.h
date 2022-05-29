#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Map {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed{ MAP_SPEED_X, 0.f };
public:
	Map(float x, float y) {
		texture.loadFromFile(IMAGES_FOLDER + MAP_NAME);
		sprite.setTexture(texture);
		sprite.setScale(1.6667f, 1.6667f);
		sprite.setPosition(x, y);
	}

	sf::Sprite getSprite() { return sprite; }
	void update() {
		sprite.move(speed);
		if (sprite.getPosition().x <= -WINDOW_WIDTH) {
			sprite.setPosition(+WINDOW_WIDTH, 0.f);
		}
	}
};