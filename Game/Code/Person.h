#pragma once
#include "pch.h"

class Person
{
public:
	int health, mana;
	int HEALTH, MANA;
	int x0, y0;
	int dmg, skill_points = 0;
	string appearence;

	Person(string app, int heal, int man, int x, int y, int damage);

	bool Lose();
	void AttackRight(int enemyX, int enemyY, int x);
	void AttackLeft(int enemyX, int enemyY, int x);
	void Draw(int color);
	void showIndicators(int color);

};

