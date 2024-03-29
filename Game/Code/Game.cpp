#include "pch.h"
#include "Person.h"
#include "Game.h"
#include "Skill.h"

COORD position;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void goTo(int x, int y)
{
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(hConsole, position);
}

void Setup(Person hero, Person enemy)
{
	hero.Draw(51);
	enemy.Draw(85);
	hero.showIndicators(34);
	enemy.showIndicators(68);
}

void ShowSkills(Skill *&skills, const int length)
{
	int x0 = 0, x = x0;
	int y = 11;
	for (int i = 0; i < length; i++)
	{
		if (i == 3 || i == 6)
		{
			x = x0;
			y += 5;
		}
		goTo(x, y);
		skills[i].ShowSkillBox(x,y);
		x += 23;
	}
}

void CreateSkills(Skill*&skills)
{
	int Skills_count = 9;
	Skill strengs1(0, 3, 1, 1);
	Skill strengs2(0, 15, 0, 2);
	Skill strengs3(0, 20, 3, 3);
	Skill agility1(0, 2, 1, 1);
	Skill agility2(0, 4, 1, 2);
	Skill agility3(0, 10, 4, 5);
	Skill intellect1(3, 0, 0, 1);
	Skill intellect2(7, 0, 2, 2);
	Skill intellect3(10, 0, 1, 3);
	Skill Skills[] = {
			  strengs1, strengs2, strengs3,
			  agility1, agility2, agility3,
			  intellect1, intellect2, intellect3
			 };
	skills = new Skill[Skills_count];
	for (int i = 0; i < Skills_count; i++)
	{
		skills[i] = Skills[i];
	}
}

void ChooseSkill(Skill *skills, Person &hero)
{
	bool chosen = false;
	goTo(9, 15);
	while (!chosen)
	{
		switch (_getch())
		{
		case 77:
		{// нажата клавиша вправо
			if (position.X < 55)
			{
				goTo(position.X += 23, position.Y);
				SetConsoleCursorPosition(hConsole, position);
			}
			break;
		}
		case 75:
		{// нажата клавиша влево
			if (position.X > 1)
			{
				goTo(position.X -= 23, position.Y);
				SetConsoleCursorPosition(hConsole, position);
			}
			break;
		}
		case 80:
		{// нажата клавиша вниз
			if (position.Y < 22)
			{
				position.Y += 5;
				goTo(position.X, position.Y);
				SetConsoleCursorPosition(hConsole, position);
			}
			break;
		}
		case 72:
		{// нажата клавиша вверх
			if (position.Y > 15)
			{
				position.Y -= 5;
				goTo(position.X, position.Y);
				SetConsoleCursorPosition(hConsole, position);
			}
			break;
		}
		case 13:
		{// нажат enter
			int i = (position.X - 9) / 23 + 3*(position.Y / 5 - 3);
			if (skills[i].cost <= hero.skill_points)
			{
			//cout << position.Y << " " << position.X;
				hero.skill_points -= skills[i].cost;
				skills[i].skill_is_already = true;
				ShowSkills(skills, 9);
				goTo(0, 7);
				SetConsoleTextAttribute(hConsole, 11);
				cout << "Очки навыков: " << hero.skill_points;
				SetConsoleTextAttribute(hConsole, 15);
				hero.HEALTH += skills[i].HEALTH_add;
				hero.health = hero.HEALTH;
				hero.MANA += skills[i].mana_add;
				hero.mana = hero.MANA;
				hero.dmg += skills[i].damage_add;
				chosen = true;
			}
			break;
		}
		case 27:
		{//esc
			chosen = true;
			break;
		}
		default:
			break;
		}
	}
}

void Rofl(Person &enemy, Person &hero, bool &EXIT, Skill* skills)
{
	if (!enemy.Lose())
	{
		enemy.AttackLeft(hero.x0, hero.y0, 58);
		hero.health -= enemy.dmg;
		hero.showIndicators(34);

		if (hero.Lose())
		{
			Sleep(500);
			EXIT = true;
		}

	}
	else
	{
		hero.skill_points++;
		hero.HEALTH++;
		hero.health = hero.HEALTH;
		enemy.HEALTH += 4;
		enemy.health = enemy.HEALTH;
		enemy.dmg+=1;
		hero.mana = hero.MANA;
		Sleep(500);
		goTo(0, 7);
		SetConsoleTextAttribute(hConsole, 11);
		cout << "Очки навыков: " << hero.skill_points;
		SetConsoleTextAttribute(hConsole, 15);
		ChooseSkill(skills, hero);
		Setup(hero, enemy);

	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Person hero("  ", 10, 5, 0, 0, 1);
	Person enemy("  ", 10, 0, 60, 0, 1);
	/*for (int i = 0; i < 120; i++)
	{
		SetConsoleTextAttribute(hConsole, i);
		cout << i << "\n";
	}*/
	Skill* skills;
	CreateSkills(skills);
	Setup(hero, enemy);
	ShowSkills(skills, 9);
	bool EXIT = false;
	goTo(0, 7);
	SetConsoleTextAttribute(hConsole, 11);
	cout << "Очки навыков: " << hero.skill_points;
	SetConsoleTextAttribute(hConsole, 15);
	while (!EXIT)
	{	
		switch (_getch())
		{
		case 'f':
		{
			hero.AttackRight(enemy.x0, enemy.y0, 4);
			enemy.health-=hero.dmg;
			enemy.showIndicators(68);
			Rofl(enemy, hero, EXIT, skills);
			break;
		}
		case 'k': 
		{
			if (hero.mana > 1)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				hero.AttackRight(enemy.x0, enemy.y0, 4);
				SetConsoleTextAttribute(hConsole, 15);
				enemy.health -= hero.dmg*2;
				enemy.showIndicators(68);
				hero.mana -= 2;
				hero.showIndicators(34);
				Rofl(enemy, hero, EXIT, skills);
			}
			break;
		}
		default:
			break;
		}		
	}
	system("pause");
	return 0;
}
