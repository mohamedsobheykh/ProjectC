#include "AcademicYear.h"
#include "../GUI/GUI.h"
#include <string>
#include <iterator>

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
	//to get the x and y cordinates of that course 
	int courseOrder = YearCourses[sem].size() + 1;
	//course order is calculated by adding 1 to the size of the list of the courses so it checks
	//the size if the list then add anew course to it 
	course.y = 150 + (courseOrder-1)*50;
	//here 150 it the place which we begin to draw courses 
	// 50 is the height of the rectangle of the course
	//(courseOrder-1) after deduction by one it put the 1st item for example on y = 150 
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
	//counter here to enable us to move over all courses till we find the choiced course
	int counter = 0;
	//keyword auto to create an iterator of the same type  the list's elements
	for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
	{
		if (counter == courseOrder)
		{
			YearCourses[sem].erase(it);
			//removing the item which a specific order in the list of courses
			return true;
		}
		
		counter++;
		//increament to get the second item of the list 
	}

		

	return false;
}
//

//int AcademicYear::size(Course* pC, SEMESTER sem)
//{
//	int s = YearCourses[sem].size();
//	return s;
//}

Course* AcademicYear::getCourse(SEMESTER sem, int courseIndex)
{
	if (courseIndex >= YearCourses[sem].size())
		return nullptr;

	auto it = YearCourses[sem].begin();
	advance(it, courseIndex);

	return *it;
	
}

//progreq................................................................................................................
vector<Course*>  AcademicYear::getAllCourses() {
	vector<Course*>AllCourses;
	//Course* allCourses;
	/*for (int sem = FALL; sem < SEM_CNT; sem++) {
		for (int i = 0; i <= YearCourses[sem].size(); i++) {
			//Course* a = YearCourses[sem].begin();
			//AllCourses.erase(AllCourses.begin() + i);
			//for (auto allCourses = YearCourses[sem].begin(); allCourses == YearCourses[sem].end(); ++allCourses) {
			AllCourses.insert(AllCourses.begin() + i, 0);
		}
	}*/

	for (int sem = FALL; sem < SEM_CNT; sem++) {
		for (int i = 0; i < YearCourses[sem].size(); i++) {
		    list<Course*> ::iterator allCourses = YearCourses[sem].begin();
			advance(allCourses, i);
			//AllCourses.push_back(*(YearCourses[sem].begin()));
			//AllCourses.push_back(*allCourses);
			//for (auto allCourses  = YearCourses[sem].begin(); allCourses == YearCourses[sem].end(); ++allCourses) {
				AllCourses.push_back(*allCourses);
			//}
		}
	}
	return AllCourses;
	
}
//progreq................................................................................................................


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



void AcademicYear::ImportMe(fstream* pFile, int yearNumber )
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
	string semesterNames[3] = { "Fall", "Spring", "Summer" };
	
	bool issuesStatus = true;
	for (int sem = FALL; sem < SUMMER; sem++)
	{
		int semCrCount = 0;

		for (auto it = YearCourses[sem].begin(); it != YearCourses[sem].end(); ++it)
		{
			semCrCount += (*it)->getCredits();	//call DrawMe for each course in this semester

		}

		if (semCrCount < pRules->SemMinCredit)
		{
			Issue minCredit;
			minCredit.issueLabel = MODERATE;
			minCredit.issueInfo = semesterNames[sem] + " minimum credits have not been acheived";
			pRules->Issues->planIssues.push_back(minCredit);

			issuesStatus = false;
		}

		if (semCrCount > pRules->SemMaxCredit)
		{
			Issue maxCredit;
			maxCredit.issueLabel = MODERATE;
			maxCredit.issueInfo = semesterNames[sem] + " maximum credits have been exceeded";
			pRules->Issues->planIssues.push_back(maxCredit);

			issuesStatus = false;
		}
	}
		
	return issuesStatus;
}

