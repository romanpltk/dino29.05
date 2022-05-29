#include "player.h"
#include "settings.h"
#include "game.h"
std::string Player::player_anim_files[]{
	"Run (1).png","Run (2).png","Run (3).png","Run (4).png","Run (5).png","Run (6).png","Run (7).png",
	"Run (8).png"
};
std::string Player::player_jump_files[]{
	"Jump (1).png","Jump (2).png","Jump (3).png","Jump (4).png","Jump (5).png",
	"Jump (6).png","Jump (7).png","Jump (8).png",
	"Jump (9).png","Jump (10).png","Jump (11).png","Jump (12).png"
};
Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + player_anim_files[0]);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.28f);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 13, WINDOW_HEIGHT / 1.3 - g_bounds.height);
}
void Player::update() {
	sf::Time now = clock.getElapsedTime();
	if (now.asMilliseconds() > frame_delay) {
		if (frames < 7) {
			frames++;
			clock.restart();
			texture.loadFromFile(IMAGES_FOLDER + player_anim_files[frames]);
			sprite.setTexture(texture);
		}
		else {
			frames = 0;
		}
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		
		if (!isJump) {
			sf::Time now = clock.getElapsedTime();
			if (now.asMilliseconds() > frame_delay && frame < 11) {
				frame++;
				clock.restart();
				texture.loadFromFile(IMAGES_FOLDER + player_jump_files[frame]);
				sprite.setTexture(texture);
			}
			isJump = true;
			speed = -14.f;

		}
	}
	if (isJump) {
		speed += 0.5f;
		if (speed > 13.5f) {
			isJump = false;
			speed = 0;
		}
	}
	sprite.move(0, speed);
}
void Player::draw(sf::RenderWindow & window) { window.draw(sprite); }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
void Player::decreaseHp(size_t dmg) { hp -= dmg; }
int Player::getHP() { return hp; }