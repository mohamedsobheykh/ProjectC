#pragma once
#include "Action.h"
#include "..\DEFs.h"

class ActionDisplayInfo : public Action
{
	ActionData actData;
public:
	ActionDisplayInfo(Registrar* , ActionData);

	virtual bool Execute();
	virtual ~ActionDisplayInfo();
};
