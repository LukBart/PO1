#pragma once

#include <iostream>
#include <string>
#include <vector>



class IVariable
{
public:
	IVariable () = default;
	IVariable (std::string name) :
	_name (name){};
	virtual ~IVariable () {};
	virtual void Print () const = 0;

protected:
	std::string _name;
};



template<typename T> class Variable : public IVariable
{
public:
	Variable (std::string name, T value):
	IVariable(name),
	_value (value){};
	~Variable (){};
	virtual void Print () const 
	{
		std::cout << _name << ": " << _value << std::endl;
	};
	void SetValue (T newValue)
	{
		_value = newValue;
	};
protected:
	T _value;
};
typedef Variable<double> VariableDouble;
typedef Variable<float> VariableFloat;
typedef Variable<int> VariableInt;
typedef Variable<char> VariableChar;
typedef Variable<bool> VariableBool;

class ArrayOfVariables 
{
public:
	ArrayOfVariables (const unsigned int MaxArraySize) : 
	_MaxArraySize(MaxArraySize){};
	~ArrayOfVariables () 
	{
		for (long unsigned i = 0; i < _variables.size(); i++)
		{
			delete _variables[i];
		}
	};
	template<typename T> Variable<T>* CreateAndAdd (std::string name, T value)
	{
		Variable<T> *var = new Variable<T> (name, value);
		_variables.push_back(var);
		return var;
	};
	void Print () const
	{
		for (long unsigned i = 0; i < _variables.size(); i++)
		{
			_variables[i]->Print();
		}
	};
	

private:
	const unsigned int _MaxArraySize;
	std::vector<IVariable*> _variables;

};

template<typename T> class VariableWithUnits : public Variable<T>
{
public:
	VariableWithUnits (std::string name, T value, std::string unit):
	Variable<T>(name, value),
	_unit(unit){};
	~VariableWithUnits () = default;
	void Print () const
	{
		std::cout << this->_name << ": " << this->_value << " [" << this->_unit << "]\n";
	};

private:
	std::string _unit;
};
