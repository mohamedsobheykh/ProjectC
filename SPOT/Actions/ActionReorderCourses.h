#pragma once
#include "Action.h"

class ActionReorderCourses : public Action
{
public:
	ActionReorderCourses(Registrar*);
	bool virtual Execute();
	virtual ~ActionReorderCourses();
};