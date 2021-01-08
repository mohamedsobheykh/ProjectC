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
	
	
	//else //added
	//{
		//return false;
	//}
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

	//Check pre/co-requisities
	for (int year = 0; year < plan.size(); year++)
	{
		for (int sem = FALL; sem < SEM_CNT; sem++)
		{
			int counter = 0;
			Course* pC = plan[year]->getCourse((SEMESTER)sem, counter); //the course that we will check

			while (pC) {
				vector<Course_Code> PreReq = pC->getInfo()->PreReqList;
				//could be changed anytime for the right getter and the loop would remain the same
				
				for (Course_Code PreCode : PreReq) //loop each pre requisite for the course
				{
					cout << PreCode << "for" << pC->getCode() << endl;
					bool found = false;
					// check if the pre requisite course found
					for (int preYear = year; preYear >= 0 && !found; preYear--)
					{
						int preSem;

						if (preYear == year)
							preSem = sem - 1;

						else
							preSem = SUMMER;

						for (preSem; preSem >= 0 && !found; preSem--)
						{
							int preCounter = 0;
							Course* preC = plan[preYear]->getCourse((SEMESTER)preSem, preCounter);
							while (preC)
							{
								if (PreCode == preC->getCode())
								{
									found = true;
									break;
								}
								preCounter++;
								preC = plan[preYear]->getCourse((SEMESTER)preSem, preCounter);
							}

						}
					}

					if (!found)
					{
						Issue preReqIssue;
						preReqIssue.issueLabel = CRITICAL;
						preReqIssue.issueInfo = PreCode + " is a missing Pre-Requisite for " + pC->getCode();
						pRules->Issues->planIssues.push_back(preReqIssue);

						issuesStatus = false;
					}
				}

				vector<Course_Code> CoReq = pC->getInfo()->CoReqList;

				for (Course_Code CoReqCode : CoReq) //loop each pre requisite for the course
				{
					bool found = false;
					// check if the pre requisite course found
					int CoCounter = 0;
					Course* coC = plan[year]->getCourse((SEMESTER)sem, CoCounter);
					while (coC)
					{
						if (CoReqCode == coC->getCode())
						{
							found = true;
							break;
						}
						CoCounter++;
						coC = plan[year]->getCourse((SEMESTER)sem, CoCounter);
					}

					if (!found)
					{
						Issue CoReqIssue;
						CoReqIssue.issueLabel = CRITICAL;
						CoReqIssue.issueInfo = CoReqCode + " is a missing Co-Requisite for " + pC->getCode();
						pRules->Issues->planIssues.push_back(CoReqIssue);

						issuesStatus = false;
					}
				}

				counter++;
				pC = plan[year]->getCourse((SEMESTER)sem, counter);
			}
		}
	}
	///////////

	return issuesStatus;
}

StudyPlan::~StudyPlan()
{
}
