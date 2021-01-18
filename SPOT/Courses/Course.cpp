#include "Course.h"
#include "../GUI/GUI.h"

Course::Course()
{
	show = true;
}

void Course::setShowCourse(bool show)
{
	this->show = show;
}

bool Course::getShowCourse() const
{
	return show;
}

Course::Course(Course_Code r_code, string r_title, int crd):code(r_code),Title(r_title)
{
	show = true;
	credits = crd;
	Info = new CourseInfo;
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
