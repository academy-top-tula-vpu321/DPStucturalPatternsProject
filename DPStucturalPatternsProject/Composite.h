#pragma once
#include <iostream>
#include <string>
#include <vector>

class Unit
{
	std::string name;
	int attack;

public:
	std::string& Name() { return name; }

	Unit(std::string name, int attack = 0) 
		: name{ name }, attack{ attack } {}

	virtual std::string ToString()
	{
		return "Unit: " + name 
			+ " attack: " + std::to_string(Attack());
	}

	virtual int Attack() { return attack; }
	virtual ~Unit() {}
};

class IFactory
{
public:
	virtual Unit* Create() = 0;
	virtual ~IFactory() {}
};

class InfantryUnit : public Unit
{
public:
	InfantryUnit() : Unit("infantry", 2) {}
};

class InfantryFactory : public IFactory
{
public:
	Unit* Create() override
	{
		return new InfantryUnit();
	}
};

class ArcherUnit : public Unit
{
public:
	ArcherUnit() : Unit("archer", 4) {}
};

class ArcherFactory : public IFactory
{
public:
	Unit* Create() override
	{
		return new ArcherUnit();
	}
};

class HorsemanUnit : public Unit
{
public:
	HorsemanUnit() : Unit("horseman", 7) {}
};

class HorsemanFactory : public IFactory
{
public:
	Unit* Create() override
	{
		return new HorsemanUnit();
	}
};


class GroupUnit : public Unit
{
	std::vector<Unit*> group;
public:
	GroupUnit(std::string name) : Unit(name) {};

	int Attack() override
	{
		int attack{};
		for (Unit* unit : group)
			attack += unit->Attack();
		return attack;
	}
	
	std::string ToString() override
	{
		std::string str = Unit::ToString() + "\n";
		for (Unit* unit : group)
			str += "\t" + unit->ToString() + "\n";
		return str;
	}

	void Add(Unit* unit)
	{
		group.push_back(unit);
	}
};
