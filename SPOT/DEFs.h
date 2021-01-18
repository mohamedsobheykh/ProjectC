#pragma once

//This header file contains some defenitions to be used all over the application
#include <string>
using namespace std;
typedef string Course_Code;


//Semesters
enum SEMESTER
{
	FALL,
	SPRING,
	SUMMER,
	SEM_CNT	//number of semesters 
};


//All possible actions
enum ActionType
{
	ADD_CRS,	//Add a course to study plan
	DEL_CRS,	//Delete a course from study plan


	SAVE,		//Save a study plan to file
	LOAD,		//Load a study plan from a file
	ADD_Notes,   //Add notes 
	Display_Notes,
	Replace_CRS,  //replace a course
	REORDER, //reorder the course to another sem or year

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	ImportReq, //import prog req
	EXIT,		//Exit the application

	STATUS_BAR,	//A click on the status bar
	MENU_BAR,	//A click on an empty place in the menu bar
	DRAW_AREA,	//A click in the drawing area
	CalculateGPA, // enter the letter grade to each course and calculate the weighted gpa
	CourseStatus,// choose the course status ( done / pending / in progress )
	DoubleMajor,// choose the second major
	Filter,//display filter
	CANCEL,		//ESC key is pressed

	//TODO: Add more action types

};

//to sotre data related to the last action
struct ActionData
{
	ActionType actType;
	int x, y;
	
};

enum IssueLabel
{
	CRITICAL,
	MODERATE
};
struct Issue
{
	IssueLabel issueLabel;
	string issueInfo;
};


