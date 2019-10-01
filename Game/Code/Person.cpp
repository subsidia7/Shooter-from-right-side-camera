#include "pch.h"
#include "Person.h"
#include "Game.h"

extern HANDLE hConsole;

Person::Person(string app, int heal, int man, int x, int y, int damage)
{
	HEALTH = heal;
	MANA = man;
	appearence = app;
	health = heal;
	mana = man;
	dmg = damage;
	x0 = x;
	y0 = y;
}

bool Person::Lose()
{
	if ((*this).health <= 0) return 1;
	return 0;
}
void Person::Draw(int color)
{
	int x = (*this).x0;
	int y = (*this).y0;
	goTo(x, y);
	SetConsoleTextAttribute(hConsole, color);
	cout << (*this).appearence;

	SetConsoleTextAttribute(hConsole, 15);
}
void Person::showIndicators(int color)
{
	int x, y;
	x = (*this).x0;
	y = (*this).y0;
	SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
	y += 2;
	goTo(x, y);
	for (int i = 0; i < (*this).HEALTH; i++)
	{
		cout << " ";
	}
	y += 2;
	goTo(x, y);
	for (int i = 0; i < (*this).MANA; i++)
	{
		cout << " ";
	}

	x = (*this).x0;
	y = (*this).y0;
	SetConsoleTextAttribute(hConsole, color);
	y += 2;
	goTo(x, y);
	for (int i = 0; i < (*this).health; i++)
	{
		cout << " ";
	}
	y += 2;
	goTo(x, y);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);

	for (int i = 0; i < (*this).mana; i++)
	{
		cout << " ";
	}
	SetConsoleTextAttribute(hConsole, 15);
}

void Person::AttackRight(int enemyX, int enemyY, int x)
{
	enemyX--;
	for (; x < enemyX; x++)
	{
		goTo(x, enemyY);
		Sleep(15);
		cout << "-";
		goTo(x - 1, enemyY);
		cout << " ";
	}
	goTo(x - 1, enemyY);
	cout << " ";
}

void Person::AttackLeft(int enemyX, int enemyY, int x)
{
	enemyX++;
	for (; x > enemyX; x--)
	{
		goTo(x, enemyY);
		Sleep(15);
		cout << "-";
		goTo(x + 1, enemyY);
		cout << " ";
	}
	goTo(x + 1, enemyY);
	cout << " ";
}