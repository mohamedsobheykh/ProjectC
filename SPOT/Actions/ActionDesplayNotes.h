#pragma once
#include "Action.h"

class ActionDesplayNotes :
	public Action
{
public:
	ActionDesplayNotes(Registrar* p);
	bool virtual Execute();
	virtual ~ActionDesplayNotes();
};
