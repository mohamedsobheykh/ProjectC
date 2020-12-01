#pragma once
#include "Action.h"
#include <string>
#include <fstream>
//Class responsible for saving the current study plan action
class ActionSavePlan :
	public Action
{
	string name;
	fstream* pFile;
	string directory;
public:
	ActionSavePlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionSavePlan();
};
