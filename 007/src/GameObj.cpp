#include "GameObj.h"

using namespace std;

GameObj::GameObj (std::string id) : _id (id) {}

string GameObj::id () const
{
	return _id;
}

ostream& operator << (ostream& strm, const GameObj& obj)
{
	obj.info (strm);
	return strm;
}

HP::HP (int n) : _points (n) {}

int HP::GetHP () const
{
	return _points;
}

Character::Character (HP hp, std::string name, std::string id) : GameObj (id), _points (hp), _name (name) {}

void Character::info (ostream& strm) const
{
	strm << _name << ", ma: [" << hp () << " HP]";
}

int Character::hp () const
{
	return _points.GetHP ();
}

Player::Player (HP hp, std::string name, std::string id) : GameObj (id), Character (hp, name, id) {}

void Player::info (std::ostream& strm) const
{
	strm << "Player: " << static_cast<Character> (*this);
}

Hurting::Hurting (HP dmg, std::string id) : GameObj (id), _points (dmg) {}

void Hurting::info (ostream& strm) const
{
	strm << "Jego uderzenie odbiera: [" << hp () << " HP]";
}

int Hurting::hp () const
{
	return _points.GetHP ();
}

Bomb::Bomb (HP hp, std::string id) : GameObj (id), Hurting (hp, id) {}

void Bomb::info (std::ostream& strm) const
{
	strm << static_cast <Hurting> (*this);
}

Boss::Boss (HP hp, std::string name, HP dmg, std::string id) : GameObj (id), Character (hp, name, id), Hurting (dmg, id) {}

void Boss::info (ostream& strm) const
{
	strm << "Bad guy: " << static_cast<Character> (*this) << endl;
	strm << static_cast<Hurting> (*this);
}