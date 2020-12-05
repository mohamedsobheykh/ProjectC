#pragma once
#include "Action.h"
#include "..\\Rules.h"
#include <fstream>
using namespace std;
class ActionImportReq :
	public Action
{
	fstream majorrules;
	Rules* Rule1 = new Rules;
public:
	ActionImportReq(Registrar*);
	bool virtual Execute();
	virtual ~ActionImportReq();

};

