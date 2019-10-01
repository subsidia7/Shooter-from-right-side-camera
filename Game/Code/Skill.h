#pragma once
class Skill
{
public:
	int mana_add;
	int HEALTH_add;
	int damage_add;
	int cost;
	Skill();
	bool skill_is_already = false;
	Skill(int mana, int HEALTH, int damage, int cost_);
	void ShowSkillBox(int x, int y);
	~Skill();
private:
};

