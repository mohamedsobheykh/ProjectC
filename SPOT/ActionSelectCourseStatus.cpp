#include"DisplayStudentLevel.h"
#include "ActionSelectCourseStatus.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

ActionSelectCourseStatus::ActionSelectCourseStatus(Registrar*P):Action(P)
{
}

bool ActionSelectCourseStatus::Execute()
{
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Select the course you want to choose its status (e.g. Done (Default), In Progress, Pending ..)");
	int yearWidth = 260;
	int semWidth = 86;
	//int semWidth = 80;
	//int courseHight = 50;

	// declaring a pointer to GUI Interface
	int x, y;
	Course* pC;
	if (actData.actType == DRAW_AREA)
	{
		x = actData.x;
		y = actData.y;

		int choicedYear = (x / yearWidth) + 1;
		SEMESTER  choicedSemester = SEMESTER(((x % yearWidth) / semWidth));
		int choicedCourse = (y - 150) / 50;

		StudyPlan* pSPlan = pReg->getStudyPlay();
		pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);
		Course* pC = pSPlan->getCourse(choicedYear, choicedSemester, choicedCourse);

		if (!pC)
		{
			return false;
		}
		pC->setSelected(true);
		pGUI->PrintMsg("Enter Course Status ( Done || In Progress || Pending )");

		string status = pGUI->GetSrting();
		string studentLevel = courseStatus(status, pC);
		actData = pGUI->GetUserAction("The student Level is " + studentLevel);

		return true;
	}
	
}

string ActionSelectCourseStatus::courseStatus(string Status,Course*pC)
{
	const char* courseStatus[3] = { "Done", "In Progress"," Pending" };
	int Credits = 0;
	static int sumOfCredits = 0;
	for (int i = 0; i < 3; i++)
	{
		if (Status == courseStatus[i])
			Credits = pC->getCredits();
		sumOfCredits += Credits;
		string S=studentLevel(sumOfCredits);
		return S;
	}


}

ActionSelectCourseStatus::~ActionSelectCourseStatus()
{
}
