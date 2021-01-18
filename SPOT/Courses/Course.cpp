#include "Course.h"
#include "../GUI/GUI.h"

Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	credits = crd;
	Info = new CourseInfo;
	issueState = CLEAN;
}

Course::~Course()
{
}

Course_Code Course::getCode() const
{
	return code;
}

string Course::getTitle() const
{
	return Title;
}
string Course::gettype() const
{
	return type;
}
void Course::settype(string w)
{
	type = w;
 }

//return course credits
int Course::getCredits() const
{
	return credits;
}

CourseInfo* Course::getInfo()
{
	CourseInfo* pInfo = Info;
	return pInfo;
}

void Course::setIssueState(IssueLabel issueState)
{
	this->issueState = issueState;
}

IssueLabel Course::getIssueState() const
{
	return issueState;
}

void Course::setInfo(CourseInfo* Info)
{
	this -> Info = Info;
}


void Course::DrawMe(GUI* pG) const
{
	pG->DrawCourse(this);
}

void Course::SaveMe(fstream* pFile)
{
	(*pFile) << this->code;
}
