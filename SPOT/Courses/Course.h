#pragma once
#include <string>
#include <list>
using namespace std;
#include <fstream>
#include "..\DEFs.h"
#include "..\Rules.h"
#include "../GUI/Drawable.h"

//Base class for all types of courses
class Course : public Drawable
{
	const Course_Code code;	//course code: e.g. "CIE202". This is the course ID
	const string Title;		//course title: e.g. "Fundamentals of Computer Programming"
	int credits;	//no. of course credits
	string type;	//Univ, track, or major.....etc.
	bool Done;		//Done or not yet?
	list<Course_Code> PreReq;	//list of prerequisites
	list<Course_Code> CoReq;	//list of prerequisites

	CourseInfo* Info;
	IssueLabel issueState;
public:
	Course(Course_Code r_code,string r_title, int crd);
	string getTitle() const;
	string getCode() const;
	void settype( string );
	string gettype() const;
	int getCredits() const;
	CourseInfo* getInfo();
	void setIssueState(IssueLabel);
	IssueLabel getIssueState() const;
	void setInfo(CourseInfo* Info);
	void DrawMe(GUI*) const;
	void SaveMe(fstream*);
	virtual ~Course();

};
