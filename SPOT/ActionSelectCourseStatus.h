#pragma once
#include"Actions/Action.h"
#include"Registrar.h"
#include<iostream>
#include<string>
using namespace std;
class ActionSelectCourseStatus : public Action
{

public:
	ActionSelectCourseStatus(Registrar*P);
	bool virtual Execute();
	string courseStatus(string Status,Course *pC);



	virtual ~ActionSelectCourseStatus();
private:
	Course* pC;
	ActionData actionData;

	

};


