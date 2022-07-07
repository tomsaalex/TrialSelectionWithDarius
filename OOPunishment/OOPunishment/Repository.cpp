#include "Repository.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Repository::readFromFile()
{
    ifstream fin(filePath);

    if (!fin.is_open())
    {
        throw exception();
    }

    storage.clear();
    string line;

    while (getline(fin, line))
    {
        if (line.length() == 0)
            continue;

        stringstream str(line);

        string P1; getline(str, P1, ',');
        string P2; getline(str, P2, ',');

        CoolObject obj{ P1, P2 };
        storage.push_back(obj);
    }
}

vector<CoolObject>& Repository::getAll()
{
    return storage;
}

int Repository::getSize()
{
    return 0;
}

void Repository::AddElement()
{
}
