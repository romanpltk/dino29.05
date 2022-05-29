#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <string>

class Cactus {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	//static std::string barrier_file_names[];
	
public:
	Cactus(float x, float y) {
		std::string barrier_file_names[] = { "1.png", "2.png" ,"3.png" ,"4.png" };
		
		
			size_t num = rand() % CACTUS_TYPE_QTY;
			texture.loadFromFile(IMAGES_FOLDER + barrier_file_names[num]);
			sprite.setTexture(texture);
			sprite.setScale(0.35f, 0.43f);
			sprite.setPosition(x, y);
		
	}
	
	
	sf::FloatRect getHitBox() { 
		sf::FloatRect g_bounds = sprite.getGlobalBounds();

		sf::Vector2f hit = sf::Vector2f(g_bounds.width / 2, g_bounds.height / 2);
		//формирование нового прямоугольника
		
		
		return sprite.getGlobalBounds();
	}
	//sf::Sprite getSprite() { return sprite; }
	

	sf::Vector2f getPosition() { return sprite.getPosition(); }
	void update() {
		
		sf::Vector2f speed = sf::Vector2f(-8.f, 0.f);
		sprite.move(speed);
		if (sprite.getPosition().x <= 0 - getHitBox().width) {
			spawn();
			
		}
		
		
	}
	void spawn() {
		sf::FloatRect g_bound = sprite.getGlobalBounds();
	 int len = rand() % 151 + 100;
	 int new_x = WINDOW_WIDTH + g_bound.width+rand() % (static_cast<int>(
		 WINDOW_WIDTH - len));
			
			/*WINDOW_WIDTH + 2 *
			static_cast<size_t>(g_bound.width);*/
		float y = WINDOW_HEIGHT / 1.3 - g_bound.height;
		sprite.setPosition(new_x, y);
		
	}
	
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};
