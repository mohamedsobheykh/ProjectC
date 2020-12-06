#pragma once
#include "Action.h"
//Class responsible for replace course action
class ActionreplaceCourse :
	public Action
{
public:
	ActionreplaceCourse(Registrar* p);
	bool virtual Execute();
	virtual ~ActionreplaceCourse();
};
