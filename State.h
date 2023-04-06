#pragma once
#include <string>

using namespace std;

class FState
{
public:
	FState();
	FState(int NewID, string NewName);

	int ID;
	string Name;
};

