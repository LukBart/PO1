#include "Animals.h"

using namespace std;

Sheep::Sheep (const std::string &name) : Animal (name), _sheared (false)
{

}

Sheep::~Sheep ()
{
	cout << "- Owca " << name();
	if (_sheared == false)
		cout << " nieostrzyzona";
	else
		cout << " ostrzyzona";
	cout << " wraca do zagrody" << endl;
}


void Sheep::print () const
{
	cout << "- Owca " << name();
	if (_sheared == false)
		cout << " nieostrzyzona" << endl;
	else
		cout << " ostrzyzona" << endl;
}

void Sheep::shear () 
{
	_sheared = true;
}

Cow::Cow (const std::string &name) : Animal (name)
{

}

Cow::~Cow () 
{
	cout << "- Krowa " << name() << " wraca do obory" << endl;
}

void Cow::print () const
{
	cout << "- Krowa " << name () << endl;
}

Horse::Horse (const std::string &name) : Animal (name)
{

}

Horse::~Horse ()
{
	cout << "- Kon " << name() << " wraca do stajni" << endl;
}

void Horse::print () const
{
	cout << "- Kon " << name () << endl;
}