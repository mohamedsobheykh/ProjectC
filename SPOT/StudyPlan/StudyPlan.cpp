#include "StudyPlan.h"


StudyPlan::StudyPlan()
{
	//By default, the study plan starts with 5 years
	//More year can be added
	for (int i = 0; i < 5; i++)
		plan.push_back(new AcademicYear);
}

//adds a course to the study plan in certain year, semester
//year idetifies year number to add course to 1=first, 2 = 2nd,....
bool StudyPlan::AddCourse(Course* pC, int year, SEMESTER sem)
{
	//TODO: add all requried checks to add the course 
	//setting the x graphics info for the course
	graphicsInfo course = pC->getGfxInfo();
	//to get x and y cordinadtes for that course
	course.x = (year-1) *260 + int (sem) * 86;
	// the year width = 260 , 86 for each semester in each year
	pC->setGfxInfo(course); 
	////////////
	if (!plan[year - 1]->AddCourse(pC, sem))
	{
		//plan is a vector containing the years 
		//if it was not added
		return false;
	}
	
	return true;
}

bool StudyPlan::DeleteCourse(int courseOrder, int year, SEMESTER sem)
{


	plan[year-1]->DeleteCourse(courseOrder, sem);
	//useing the function delete to remove that course from the selcted year
	// -1 as it starts with 0 so 1st itemm its oreder is 0
	return true;
	

	if (plan[year - 1]->DeleteCourse(courseOrder, sem))
		//using the function to remove that course
	{
		return true;
	}
	return false;

}

void StudyPlan::DrawMe(GUI* pGUI) const
{
	//Plan draws all year inside it.
	for (int i = 0; i < plan.size(); i++)
		plan[i]->DrawMe(pGUI);
}

void StudyPlan::SaveMe(fstream* pFile)
{
	for (int i = 0; i < plan.size(); i++)
	{
		plan[i]->SaveMe(pFile,i+1);
	}
	
}

void StudyPlan::ImportMe(fstream* pFile)
{
	for (int i = 0; i < plan.size(); i++)
	{
		plan[i]->ImportMe(pFile , i + 1);
	}
	
}

Course* StudyPlan::getCourse(int year, SEMESTER sem, int courseIndex)
{
	Course* choicedCourse = plan[year - 1]->getCourse(sem, courseIndex);
	if (!choicedCourse)
	{
		return nullptr;
	}
	return choicedCourse;
}

bool StudyPlan::checkRules(Rules* pRules)
{
	bool issuesStatus = true;
	//Check Credits
	for (int i = 0; i < plan.size(); i++)
	{
		if (!plan[i]->checkCredits(pRules))
			issuesStatus = false;
	}
	///////////////

	return issuesStatus;
}

StudyPlan::~StudyPlan()
{
}
