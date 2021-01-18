#pragma once
#include"Registrar.h"
#include"Actions/Action.h"
#include<vector>
#include"Courses/Course.h"
class ActionDisplayFilter : public Action
{
public:
	ActionDisplayFilter(Registrar* P);
	bool virtual Execute();
	virtual ~ActionDisplayFilter();



private:
	
	Course* pC;


};

