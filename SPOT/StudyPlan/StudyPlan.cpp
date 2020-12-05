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

	plan[year - 1]->AddCourse(pC, sem);
	
	return true;
}

bool StudyPlan::DeleteCourse(int courseOrder, int year, SEMESTER sem)
{

	plan[year-1]->DeleteCourse(courseOrder, sem);
	return true;
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
	return choicedCourse;
}

StudyPlan::~StudyPlan()
{
}
