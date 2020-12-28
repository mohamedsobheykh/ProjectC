#include"Registrar.h"
#include"Actions/Action.h"
#include<string>
class ActionCalculateGPA: 
	public Action
{
public:
	//ActionCalculateGPA(Regi)
	ActionCalculateGPA(Registrar*p);
	bool virtual Execute();
	double calculateGPA(string letter, Course* pC);

	virtual ~ActionCalculateGPA();
private:
	string GPA;
	string letterGrade;
	Course* pC;
	ActionData actionData;
};


