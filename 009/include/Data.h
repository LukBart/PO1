#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>


class Data
{
public:
	Data (std::string day, std::vector<double> values);
	void print () const;
	std::vector<double> GetValues () const;

private:
	std::string _day;
	std::vector<double> _values;
};