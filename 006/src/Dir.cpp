#include "Dir.h"


Dir::~Dir ()
{
	std::cout << "Deleting Dir: " << _name << std::endl;
	for (long unsigned i = 0; i < _content.size(); i++){
		std::cout << "About to delete " << _content[i]->getName() << std::endl;
		delete _content[i];
	}
}

Dir& Dir::operator += (SystemElement* other)
{
	_content.push_back (other);
	return *this;
}

Dir* Dir::findDir (std::string name)
{
	for (long unsigned i = 0; i < _content.size(); i++)
	{
		Dir* dir;
		if ((dir = static_cast<Dir*>(_content[i])))
		{
			if (dir->getName() == name)
			{
				return dir;
			}
			Dir* e = dir->findDir(name);
			if (e != nullptr)
				return e;
		}
	}
	return nullptr;
}

void Dir::add (SystemElement* other)
{
	_content.push_back (other);
}

SystemElement* Dir::get (std::string name)
{
	for (long unsigned i = 0; i < _content.size();i++)
	{
		// std::cout << _content[i]->getName();
		if (_content[i]->getName() == name)
		{
			return _content[i];
		}
		Dir* dir;
		if ((dir = dynamic_cast<Dir*>(_content[i])))
		{
			SystemElement* e = dir->get(name);
			if (e != nullptr)
			{
				return e;
			}
		}
	}
	return nullptr;
}

void Dir::StreamOfElements (std::ostream& strm, int counter) const
{
	for (int i = 0; i < counter; i++)
	{
		strm << "  ";
	}
	strm << _name << " (DIR)" << std::endl;
	for (long unsigned i = 0; i < _content.size (); i++)
	{
		_content[i]->StreamOfElements (strm, counter + 1);
	}
}
