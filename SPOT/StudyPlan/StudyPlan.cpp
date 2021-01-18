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

//progreq...........................................
vector<Course*> StudyPlan::getAllCourses() {
	vector<Course*> ALLcourses;
	for (int i = 0; i < plan.size(); i++)
	{

		vector<Course*>AllCourses = plan[i]->getAllCourses();
		for (int i = 0; i < AllCourses.size(); i++)
		{
			ALLcourses.push_back(*(AllCourses.begin()+i));
		}
	}
	return ALLcourses;
}



bool StudyPlan::checkRules(Rules* pRules , GUI* pGUI)

{
	bool issuesStatus = true;

	// check for total cr of the studyplan
	vector<Course*> ALL = getAllCourses();
	int TOTALCR = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		//int TOTALCR = 0;
		TOTALCR = (*(ALL.begin()+i))->getCredits() + TOTALCR;
		
	}
	int r = pRules->ReqUnivCredits;
	if (TOTALCR >= r) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue total_cr;
		total_cr.issueLabel = CRITICAL;
		total_cr.issueInfo = "there are a missing courses of the total cr of the studyplan ";
		pRules->Issues->planIssues.push_back(total_cr);

	}
	//..................................................................................................
	//check for UnivCompulsory 
	int cUnivCompulsory = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->UnivCompulsory.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->UnivCompulsory.at(j);
			if (a == b ) {
				cUnivCompulsory++;
			}
		}
	}
	if (cUnivCompulsory == pRules->UnivCompulsory.size()) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue UnivCompulsoryy;
		UnivCompulsoryy.issueLabel = CRITICAL;
		UnivCompulsoryy.issueInfo = "there are a missing courses of the Univ Compulsory courses ";
		pRules->Issues->planIssues.push_back(UnivCompulsoryy);
	
	}
	//..................................................................................................
	//check for UnivElective cr
	int cUnivElective = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->UnivElective.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->UnivElective[j];
			if (a == b) {
				cUnivElective = (*(ALL.begin() + i))->getCredits() + cUnivElective;
				
			}
		}
	}
	if (cUnivElective >= pRules->Uni_elective_cr) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue UnivElectivee;
		UnivElectivee.issueLabel = CRITICAL;
		UnivElectivee.issueInfo = "there are a missing courses of the Univ Electivee courses ";
		pRules->Issues->planIssues.push_back(UnivElectivee);
	
	}
	//..................................................................................................
	//check TrackCompulsory
	int cTrackCompulsory = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->TrackCompulsory.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->TrackCompulsory[j];
			if (a == b) {
				cTrackCompulsory++;
			}
		}
	}
	if (cTrackCompulsory == pRules->TrackCompulsory.size()) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue TrackCompulsoryy;
		TrackCompulsoryy.issueLabel = CRITICAL;
		TrackCompulsoryy.issueInfo = "there are a missing courses of the Track Compulsory courses ";
		pRules->Issues->planIssues.push_back(TrackCompulsoryy);
	
		
	}
	//..................................................................................................
	//check MajorCompulsory
	int cMajorCompulsory = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->MajorCompulsory.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->MajorCompulsory[j];
			if (a == b) {
				cMajorCompulsory++;
			}
		}
	}
	if (cMajorCompulsory == pRules->MajorCompulsory.size()) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue MajorCompulsoryy;
		MajorCompulsoryy.issueLabel = CRITICAL;
		MajorCompulsoryy.issueInfo = "there are a missing courses of the Major Compulsory courses ";
		pRules->Issues->planIssues.push_back(MajorCompulsoryy);
	}
	//..................................................................................................
	//check for MajorElective cr
	int cMajorElective = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->MajorElective.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->MajorElective[j];
			if (a == b) {
				cMajorElective = (*(ALL.begin() + i))->getCredits() + cMajorElective;

			}
		}
	}
	if (cMajorElective >= pRules->Major_elective_cr) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue MajorElectivee;
		MajorElectivee.issueLabel = CRITICAL;
		MajorElectivee.issueInfo = "there are a missing courses of the Major Electives " ;
		pRules->Issues->planIssues.push_back(MajorElectivee);
	}
	//..................................................................................................
	//check for consentration Compulsory cr
	int cconCompulsory = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->Tconsentration_com.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->Tconsentration_com[j];
			if (a == b) {
				cconCompulsory++;
			}
		}
	}
	if (cconCompulsory == pRules->Tconsentration_com.size()) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue cconCompulsoryy;
		cconCompulsoryy.issueLabel = CRITICAL;
		cconCompulsoryy.issueInfo = "there are a missing courses of the Major Compulsory courses ";
		pRules->Issues->planIssues.push_back(cconCompulsoryy);
	}
	//..................................................................................................
	//check for consentration Elective cr
	int cconElective = 0;
	for (int i = 0; i < ALL.size(); i++)
	{
		for (int j = 0; j < pRules->Tconsentration_ele.size(); j++) {
			string a = (*(ALL.begin() + i))->getCode();
			string b = pRules->Tconsentration_ele[j];
			if (a == b) {
				cconElective = (*(ALL.begin() + i))->getCredits() + cconElective;

			}
		}
	}
	if (cconElective >= pRules->Tcon_ele) {
		issuesStatus = true;
	}
	else {
		issuesStatus = false;
		Issue conElectivee;
		conElectivee.issueLabel = CRITICAL;
		conElectivee.issueInfo = "there are a missing courses of the Major Electives ";
		pRules->Issues->planIssues.push_back(conElectivee);
	}





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
					if (PreCode == " ")
						continue;
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
						//show the borderline for critical issue
						pC->setIssueState(CRITICAL);
						pC->DrawMe(pGUI);
						pC->setIssueState(CLEAN);

						issuesStatus = false;
					}
				}

				vector<Course_Code> CoReq = pC->getInfo()->CoReqList;

				for (Course_Code CoReqCode : CoReq) //loop each pre requisite for the course
				{
					if (CoReqCode == " ")
						continue;
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
						//show the borderline for critical issue
						pC->setIssueState(CRITICAL);
						pC->DrawMe(pGUI);
						pC->setIssueState(CLEAN);

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
