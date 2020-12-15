#pragma once
#include "Action.h"

#include "../Courses/Course.h"
#include "../StudyPlan/AcademicYear.h"
class ActionDesplayNotes :
	public Action
{
public:
	ActionDesplayNotes(Registrar* p);
	bool virtual Execute();
	virtual ~ActionDesplayNotes();
};
