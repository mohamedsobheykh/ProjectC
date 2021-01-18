#include "ActionReport.h"
#include "..\Registrar.h"
#include "../Courses/UnivCourse.h"
using namespace std;
#include <iostream>

ActionReport::ActionReport(Registrar* p) : Action(p)
{
}

bool ActionReport::Execute()
{
	//pReg->checkRules();
	Issues* planIssues = pReg->getRules()->Issues;

	GUI* pGUI = pReg->getGUI();
	pGUI->PrintIssueReport(planIssues);

	fstream* pFile = new fstream("Issues.txt", ios::out);

	for (int i = 0; i < planIssues->planIssues.size(); i++)
	{
		(*pFile) << planIssues->planIssues[i].issueInfo << endl;
	}


	if (!(*pFile)) // checks that the file is opened successfully
	{
		return false;
	}

	return true;
}

ActionReport::~ActionReport()
{
}
