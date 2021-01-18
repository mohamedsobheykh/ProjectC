#pragma once	
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"


//The maestro class for the application
class Registrar
{
	GUI* pGUI;	//pointer to GUI 
	Rules* pRules;	//Registration rules
	StudyPlan* pSPlan;
	Rules RegRules;
	Rules RegRulesDoubleMajor;
	//Rules* pRulesOfDoubleMajor;
public:
	Registrar();
	GUI* getGUI() const;
	Action* CreateRequiredAction();
	bool ExecuteAction(Action*);
	void UpdateInterface();
	StudyPlan* getStudyPlay() const;
	CourseInfo* GetCourseInfo(Course_Code code);
	Course* NewCourse(Course_Code code);
	Rules* getRules() const;
	//Rules* getRulesOfDoubleMajor()const;
	void checkRules();
	// added recently to import the catalog 
	void ImportCourseCat();
	void ImportCourseOfferings();   //added recently to import the offerings 
	void Run();

	~Registrar();
};

