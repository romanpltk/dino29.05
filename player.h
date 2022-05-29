#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
#include <string>
class Player {
private:
	sf::Texture texture;
	
	sf::Sprite sprite;
	sf::Clock clock;
	float speed = 0.f;
	static std::string player_anim_files[];
	static std::string player_jump_files[];
	size_t frame = 0;
	size_t frames = 0;
	size_t frame_delay = 55;
	bool isJump = false;
	int hp = PLAYER_HP;
	
public:
	Player();
	void update();
	void draw(sf::RenderWindow& window);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void decreaseHp(size_t);
	int getHP();

};