#pragma once
#include "Action.h"
//Class responsible for adding course action
class ActionMinor :
	public Action

{
public:
	ActionMinor(Registrar*);
	bool virtual Execute();
	virtual ~ActionMinor();
};

