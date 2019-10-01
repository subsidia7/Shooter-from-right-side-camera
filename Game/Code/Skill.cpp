#include "pch.h"
#include "Skill.h"
#include "Game.h"
extern HANDLE hConsole;

Skill::Skill(){};
Skill::Skill(int mana, int HEALTH, int damage, int cost_)
{
	mana_add = mana;
	HEALTH_add = HEALTH;
	damage_add = damage;
	cost = cost_;
	skill_is_already = false;
}

void Skill::ShowSkillBox(int x, int y)
{
	SetConsoleTextAttribute(hConsole, 12);
	goTo(x, y);
	cout << "Добавка маны     : " << (*this).mana_add;
	goTo(x, ++y);
	cout << "Добавка здоровья : " << (*this).HEALTH_add;
	goTo(x, ++y);
	cout << "Добавка урона    : " << (*this).damage_add;
	goTo(x, ++y);
	cout << "Стоимость        : " << (*this).cost;
	goTo(x, ++y);
	if((*this).skill_is_already)
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
	else
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE );
	cout << "       Купить      ";
	SetConsoleTextAttribute(hConsole, 15);
}


Skill::~Skill()
{
}
