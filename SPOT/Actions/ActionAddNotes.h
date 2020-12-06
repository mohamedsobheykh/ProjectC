#pragma once
#include "Action.h"

class ActionAddNotes :
	public Action
{
public:
	ActionAddNotes(Registrar* p);
	bool virtual Execute();
	virtual ~ActionAddNotes();
};
