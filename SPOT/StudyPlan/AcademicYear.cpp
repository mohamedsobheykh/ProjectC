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
	//TODO:
	//This function still needs many checks to be compelete
	YearCourses[sem].push_back(pC);
	TotalCredits += pC->getCredits();

	//TODO: acording to course type incremenet corrsponding toatl hours for that year


	return true;
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
			// and finall add the course to the academic year
			this->AddCourse(pC, SEMESTER(sem));
		}

		delete[] courseCode;
	}
	delete line;
}
