#pragma once
#include <string>

using namespace std;

class CoolObject
{
private:
	std::string p1, p2;
public:
	CoolObject(string p1, string p2) : p1{ p1 }, p2{ p2 }{}

	std::string getP1() const;
	std::string getP2() const;
};

