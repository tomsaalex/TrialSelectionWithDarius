#pragma once
#include "CoolObject.h"
#include <vector>
#include <string>

using namespace std;

class Repository
{
private:
	vector<CoolObject> storage;
	string filePath;

	void readFromFile();
	void writeFromFile();

public:
	Repository(string fileName) :filePath{ fileName } { readFromFile(); }
	Repository(const Repository&) = delete;

	vector<CoolObject>& getAll();
	int getSize();
	void AddElement();

};
