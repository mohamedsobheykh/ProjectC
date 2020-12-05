#pragma once
#include "Action.h"

class ActionDisplayInfo : public Action
{
public:
	ActionDisplayInfo(Registrar*);
	virtual bool Execute();
	virtual ~ActionDisplayInfo();
};
