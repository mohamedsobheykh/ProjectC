#pragma once
#include "Action.h"
#include "..\\Rules.h"
#include <fstream>
#include <iostream>
using namespace std;
//Class responsible for adding course action
class ActionDoubleConcentration :
	public Action
{
	fstream openFile;
	Rules* Rule1;
public:
	ActionDoubleConcentration(Registrar*);
	bool virtual Execute();
	virtual ~ActionDoubleConcentration();
};

