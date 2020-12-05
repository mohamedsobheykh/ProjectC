#include "ActionReorderCourses.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"

#include <iostream>

ActionReorderCourses::ActionReorderCourses(Registrar* p) : Action (p)
{
}

bool ActionReorderCourses::Execute()
{
	GUI* pGUI = pReg->getGUI();
	

	return false;
}

ActionReorderCourses::~ActionReorderCourses()
{
}
