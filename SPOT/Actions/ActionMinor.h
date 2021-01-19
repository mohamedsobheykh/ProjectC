#pragma once
#include "Action.h"
#include "..\Registrar.h"
#include "..\Rules.h"
//Class responsible for adding course action
class ActionMinor :
	public Action

{
	Rules* R2;
public:
	ActionMinor(Registrar*);
	bool virtual Execute();
	virtual ~ActionMinor();
};

