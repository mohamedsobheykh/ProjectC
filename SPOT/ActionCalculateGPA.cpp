#include<iostream>
using namespace std;
#include"ActionCalculateGPA.h"
#include"Registrar.h"
#include"Courses/UnivCourse.h"
#include<vector>
#include<string>

ActionCalculateGPA::ActionCalculateGPA(Registrar* P):Action(P)
{
	//actionData = actData;

}

bool ActionCalculateGPA::Execute()
{
	GUI* pGUI = pReg->getGUI();
	ActionData actData = pGUI->GetUserAction("Select the course ..");


	int yearWidth = 260;
	int semWidth = 86;
	//int semWidth = 80;
	//int courseHight = 50;

	// declaring a pointer to GUI Interface
	int x, y;
	Course* pC;
	if (actData.actType==DRAW_AREA)
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
		pGUI->PrintMsg("Enter the predict or acquired grade in letters (e.g. A)");
		 string letterGrade = pGUI->GetSrting();
		 double GPA = calculateGPA(letterGrade, pC);
		 string s = to_string(GPA);
		// pGUI->PrintMsg(s);
		 actData = pGUI->GetUserAction("The Weighted GPA is:"+s);
		return true;
	} 
}
double ActionCalculateGPA::calculateGPA(string letter, Course* pC)
{
	static double totalGPA = 0;
	  int Credits = 0;
	double Score = 0;
	static int sumOfCredits = 0;
	if (letter == "A" || letter == "a")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 4;
		totalGPA += Score;
	}
	else if (letter == "A-" || letter == "a-")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 3.67;
		totalGPA += Score;
	}
	else if (letter == "B+" || letter == "b+")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 3.33;
		totalGPA += Score;
	}
	else if (letter == "B" || letter == "b")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 3.0;
		totalGPA += Score;
	}
	else if (letter == "B-" || letter == "b-")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 2.67;
		totalGPA += Score;

	}
	else if (letter == "C+" || letter == "c+")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 2.33;
		totalGPA += Score;

	}
	else if (letter == "C" || letter == "c")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 2.0;
		totalGPA += Score;
	}
	else if (letter == "C-" || letter == "c-")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 1.67;
		totalGPA += Score;
	}
	else if (letter == "F" || letter == "f")
	{
		Credits = pC->getCredits();
		sumOfCredits += Credits;
		Score = Credits * 0;
		totalGPA += Score;
	}
	
	return totalGPA / sumOfCredits;
	
}






ActionCalculateGPA::~ActionCalculateGPA()
{
}
