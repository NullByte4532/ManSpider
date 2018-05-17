#include <SFML/Graphics.hpp>
#include "player.h"	
#include "view.h"	
#include <iostream>

#define FramesNum 4
#define StrangeConst1 500000
#define StrangeConst2 50 // velocity scale
#define sqrt2 1.4142135

using namespace std;
using namespace sf;

void movePlayerAndCamera(Player& player, float dx, float dy) {
	player.sprite.move(dx, dy);
	player.setPlayerX(player.sprite.getPosition().x);
	player.setPlayerY(player.sprite.getPosition().y);
	getCoordinatesForView(player.getPlayerX(), player.getPlayerY());
};

void Moving (Player& player, int speed, float time) {
	double CurrentFrame = 0;
	int dx = 0, dy = 0;

	if (Keyboard::isKeyPressed(Keyboard::A))
		dx -= 1;

	if (Keyboard::isKeyPressed(Keyboard::D))
		dx += 1;

	if (Keyboard::isKeyPressed(Keyboard::W))
		dy -= 1;

	if (Keyboard::isKeyPressed(Keyboard::S))
		dy += 1;


	

	if (dx == 1) {
		if (dy == 1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 600, 120, 120));
			movePlayerAndCamera(player, time * speed * StrangeConst2 / sqrt2, time * speed * StrangeConst2 / sqrt2);
		}
		if (dy == 0) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 240, 120, 120));
			movePlayerAndCamera(player, time * speed * StrangeConst2, 0);
			//cout << player.getPlayerX();
		}
		if (dy == -1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 720, 120, 120));
			movePlayerAndCamera(player, time * speed * StrangeConst2, -time * speed * StrangeConst2 / sqrt2);
		}
		cout << "(" << player.getPlayerX() << " " << player.getPlayerY() << ")";
	}
	if (dx == 0) {
		if (dy == 1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 0, 120, 120));
			movePlayerAndCamera(player, 0, time * speed * StrangeConst2);
		}
		if (dy == 0) {
			//��������� ��� ����
		}
		if (dy == -1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 360, 120, 120));
			movePlayerAndCamera(player, 0, -time * speed * StrangeConst2);
		}
	}
	if (dx == -1) {
		if (dy == 1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 480, 120, 120));
			movePlayerAndCamera(player, -time * speed * StrangeConst2, time * speed * StrangeConst2 / sqrt2);
		}
		if (dy == 0) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 120, 120, 120));
			movePlayerAndCamera(player, -time * speed * StrangeConst2, 0);
		}
		if (dy == -1) {
			CurrentFrame += StrangeConst1 * time;
			player.sprite.setTextureRect(IntRect(120 * ((int)CurrentFrame % 4), 840, 120, 120));
			movePlayerAndCamera(player, -time * speed * StrangeConst2, -time * speed * StrangeConst2 / sqrt2);
		}
		cout << "(" << player.getPlayerX() << " " << player.getPlayerY() << ")";
	}
};