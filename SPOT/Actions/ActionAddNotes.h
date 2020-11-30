#pragma once
#include "Action.h"
//Class responsible for adding course action
class ActionAddNotes :
	public Action
{
public:
	ActionAddNotes(Registrar* p);
	bool virtual Execute();
	virtual ~ActionAddNotes();
};
