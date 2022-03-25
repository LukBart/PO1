#pragma once

#include <iostream>

class GameObj
{
	friend std::ostream& operator << (std::ostream& strm, const GameObj& obj);
public:
	GameObj (std::string id);
	virtual ~GameObj () = default;
	std::string id () const;
	virtual void info (std::ostream& strm) const = 0;

protected:
	std::string _id;
};

class HP
{
public:
	HP (int n);
	int GetHP ()const ;
private:
	int _points;
};

class Character : public virtual GameObj
{
public:
	Character (HP hp, std::string name, std::string id);
	virtual void info (std::ostream& strm) const override;
	int hp () const;
protected:
	HP _points;
	std::string _name;
};

class Player : public Character
{
public:
	Player (HP hp, std::string name, std::string id);
	void info (std::ostream& strm) const override;
};

class Hurting : public virtual GameObj
{
public:
	Hurting (HP dmg, std::string id);
	virtual void info (std::ostream& strm) const override;
	int hp () const;

protected:
	HP _points;
};

class Bomb : public Hurting
{
public:
	Bomb (HP hp, std::string id);
	void info (std::ostream& strm) const override;

};

class Boss : public Character, public Hurting
{
public:
	Boss (HP hp, std::string name, HP dmg, std::string id);
	void info (std::ostream& strm) const override;
};