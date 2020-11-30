
#pragma once
#include "Action.h"
//Class responsible for adding course action
class ActionExit :
	public Action
{
public:
	ActionExit(Registrar*);
	bool virtual Execute();
	virtual ~ActionExit();
};