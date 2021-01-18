#pragma once
#include "Action.h"

#include "..\DEFs.h"

class ActionReport : public Action
{
	ActionData actData;
public:
	ActionReport(Registrar*);

	virtual bool Execute();
	virtual ~ActionReport();
};

