#pragma once
#include "Action.h"
#include <string>
#include <fstream>
//Class responsible for import study plan action
class ActionImportPlan :
	public Action
{
	string name;
	fstream* pFile;
	string directory;
public:
	ActionImportPlan(Registrar*);
	bool virtual Execute();
	virtual ~ActionImportPlan();
};
