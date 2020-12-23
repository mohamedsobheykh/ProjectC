#include "AcademicYear.h"
#include "../GUI/GUI.h"

AcademicYear::AcademicYear()
{
	//TODO: make all necessary initializations
	
}


AcademicYear::~AcademicYear()
{
}

//Adds a course to this year in the spesified semester
bool AcademicYear::AddCourse(Course* pC, SEMESTER sem)
{
	
	//setting the y graphics info to be as the order of the course in the semester
	graphicsInfo course = pC->getGfxInfo();
	int courseOrder = YearCourses[sem].size() + 1;
	course.y = 150 + (courseOrder-1)*50;
	pC->setGfxInfo(course);
	/////////

	if (!pC)
	{
		return false;
	}

	YearCourses[sem].push_back(pC);
	
	

	TotalCredits += pC->getCredits();

	//TODO: acording to course type incremenet corrsponding toatl hours for that year


	return true;
}
// faeture#2Complete
//function to delete a course abedal
bool AcademicYear::DeleteCourse(int courseOrder, SEMESTER sem)
{
	int counter = 0;
	for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
	{
		if (counter == courseOrder)
		{
			YearCourses[sem].erase(it);
			return true;
		}
		counter++;
	}

	

	return false;
}
//

Course* AcademicYear::getCourse(SEMESTER sem, int courseIndex)
{
	if (courseIndex >= YearCourses[sem].size())
		return nullptr;

	auto it = YearCourses[sem].begin();
	advance(it, courseIndex);

	return *it;
	
}


void AcademicYear::DrawMe(GUI* pGUI) const
{
	pGUI->DrawAcademicYear(this);
	//Draw all semesters inside this year by iterating on each semester list
	//to get courses and draw each course
	
	for (int sem = FALL; sem < SEM_CNT; sem++)
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			(*it)->DrawMe(pGUI);	//call DrawMe for each course in this semester

		}
}

void AcademicYear::SaveMe(fstream* pFile , int yearNumber)
{
	string semesterNames[3] = { "Fall", "Spring", "Summer" };
	for (int sem = FALL; sem < SEM_CNT; sem++)
	{
		
		(*pFile) << "Year " << yearNumber << "," << semesterNames[sem] << ",";
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			(*it)->SaveMe(pFile);	//call SaveMe for each course in this semester
			(*pFile) << ",";
		}
		(*pFile) << endl;
	}
		
}



void AcademicYear::ImportMe(fstream* pFile, int yearNumber)
{
	string* line = new string;
	for (int sem = FALL; sem < SEM_CNT; sem++)
	{
		// getting one semester which represented by a line
		getline(*pFile, *line);

		// getting every course in the semester
		// first create the array which will get the course codes
		int NOFCounter = 0;
		for (char s : *line)
		{
			if (s == ',')
				NOFCounter++;
		}
		NOFCounter++;
		string* courseCode = new string[NOFCounter];

		// it loops on the line string and turn it into and array of course codes
		courseCode[0] = "";
		int Counter = 0;
		for (char s : *line)
		{
			if (s == ',')
			{
				Counter++;
				courseCode[Counter] = "";
			}
			else
			{
				courseCode[Counter] += s;
			}
		}

		// we take the array of the course codes and turn it into objects of courses in the academic semester
		// we start the loop from i=2 because the year name is in i=0 and the sem name is in i=1
		for (int i = 2; i < NOFCounter; i++)
		{
			// untill we impelement it we create dummy title and credit hours
			string Title = "Test101";
			int crd = 0;
			Course* pC = new Course(courseCode[i], Title, crd);
			//setting the x graphic info for the course 
			graphicsInfo courseCoordinates;
			courseCoordinates.x = (yearNumber-1) * 260 + sem*86;
			pC->setGfxInfo(courseCoordinates);
			// and finall add the course to the academic year
			this->AddCourse(pC, SEMESTER(sem));
		}

		delete[] courseCode;
	}
	delete line;
}

bool AcademicYear::checkCredits(Rules* pRules)
{
	int semCrCount = 0;
	bool issuesStatus = true;
	for (int sem = FALL; sem < SUMMER; sem++)
	{
		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			semCrCount += (*it)->getCredits();	//call DrawMe for each course in this semester

		}

		if (semCrCount < pRules->SemMinCredit)
		{
			Issue minCredit;
			minCredit.issueLabel = MODERATE;
			minCredit.issueInfo = "Semesters minimum credits are unvalid";
			pRules->Issues->planIssues.push_back(minCredit);

			issuesStatus = false;
		}

		if (semCrCount > pRules->SemMaxCredit)
		{
			Issue maxCredit;
			maxCredit.issueLabel = MODERATE;
			maxCredit.issueInfo = "Semester maximum credits unvalid";
			pRules->Issues->planIssues.push_back(maxCredit);

			issuesStatus = false;
		}
	}
		
	return issuesStatus;
}

