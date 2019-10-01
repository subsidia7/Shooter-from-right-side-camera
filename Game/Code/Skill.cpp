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
	cout << "������� ����     : " << (*this).mana_add;
	goTo(x, ++y);
	cout << "������� �������� : " << (*this).HEALTH_add;
	goTo(x, ++y);
	cout << "������� �����    : " << (*this).damage_add;
	goTo(x, ++y);
	cout << "���������        : " << (*this).cost;
	goTo(x, ++y);
	if((*this).skill_is_already)
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN);
	else
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE );
	cout << "       ������      ";
	SetConsoleTextAttribute(hConsole, 15);
}


Skill::~Skill()
{
}
