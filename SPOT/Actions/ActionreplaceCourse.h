#pragma once
#include "Action.h"
using namespace std;
//Class responsible for replace course action
class ActionreplaceCourse :
	public Action
{
	
public:
	//, ActionData
	ActionreplaceCourse(Registrar* p);
	bool virtual Execute();
	virtual ~ActionreplaceCourse();
};
