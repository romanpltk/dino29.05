#include "game.h"
#include "settings.h"
#include <iostream>

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE,
		sf::Style::Titlebar | sf::Style::Close), map1(WINDOW_WIDTH, 0.f),
	map2(0.f, 0.f), game_over_screen(IMAGES_FOLDER + GAME_OVER_FILE_NAME, 1.634f, 0.98f),text("res/kenvector_future.ttf", 24, 10, 5, sf::Color::Yellow)
{
	window.setVerticalSyncEnabled(true);
	for (size_t i = 0; i < CACTUS_QTY; i++) {
		Cactus* cactus = new Cactus(WINDOW_WIDTH 
			, WINDOW_HEIGHT / 1.3 - 100);
		cactuses.push_back(cactus);
	}
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		update();
		check_collisions();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		
	}
}
void Game::update() {
	switch (game_state) {
	case INTRO:
		break;
	case PLAY:
		map1.update();
		map2.update();
		text.update(std::to_string(player.getHP()));
		player.update();
		for (size_t i = 0; i < CACTUS_QTY; i++) {
			cactuses[i]->update();
		}
		if (player.getHP() <= 0) game_state = GAME_OVER;
		break;
	case GAME_OVER:
		break;
	}
}
void Game::draw() {
	window.clear(sf::Color(204, 255, 255));
	switch (game_state) {
	case INTRO:
		break;
	case PLAY:
		window.draw(map1.getSprite());
		window.draw(map2.getSprite());
		window.draw(text.getText());
		player.draw(window);
		for (size_t i = 0; i < CACTUS_QTY; i++) {
			cactuses[i]->draw(window);
		}
		break;
	case GAME_OVER:
		window.draw(game_over_screen.getSprite());
		break;
	}
	window.display();
}
void Game::check_collisions() {
	for (auto iter = cactuses.begin(); iter != cactuses.end(); iter++) {
		if (player.getHitBox().intersects((*iter)->getHitBox())) {
			size_t notdamage = 500;
			sf::Time now = clock.getElapsedTime();
			if (now.asMilliseconds() > notdamage) {
				clock.restart();
				player.decreaseHp(static_cast<size_t>(
					(*iter)->getHitBox().width / 3));
			}
		}
	}
}
