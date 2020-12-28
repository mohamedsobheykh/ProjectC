#pragma once
#include <string>
using namespace std;


#include "..\DEFs.h"
#include "CMUgraphicsLib\CMUgraphics.h"

class Course;
class AcademicYear;
//user interface class
class GUI 
{

	enum MENU_ITEM //The items of the menu (you should add more items)
	{
		//Note: Items are ordered here as they appear in the menu
		//If you want to change the menu items order, just change the order here
		ITM_ADD,		//Add a new course

						//TODO: Add more items names here

		//TODO: Add more items names here
		ITM_Delete,			//Delete item 'abedal 	
		ITM_Notes,			//Add notes 'abedal
		ITM_DesplayNotes,
		ITM_Replace_CRS,
		ITM_Save,
		ITM_Load,
		ITM_Reorder,
		ITM_ProgRec,
		ITM_GPA,
		ITM_STATUS,
		ITM_EXIT,		//Exit item

		ITM_CNT			//no. of menu items ==> This should be the last line in this enum

	};

	//Some constants for GUI
	static const int	WindWidth = 1300, WindHeight = 700,	//Window width and height
		wx = 15, wy = 15,		//Window starting coordinates
		StatusBarHeight = 60,	//Status Bar Height
		MenuBarHeight = 80,		//Menu Bar Height (distance from top of window to bottom line of menu bar)
		MenuItemWidth = 70;		//Width of each item in the menu



	color DrawColor = BLACK;		//Drawing color
	color FillColor = YELLOW;		//Filling color (for courses)
	color HiColor = RED;			//Highlighting color
	color ConnColor = GREEN;		//Connector color
	color MsgColor = BLACK;			//Messages color
	color BkGrndColor = LIGHTGRAY;	//Background color
	color StatusBarColor = DARKGRAY;//statusbar color
	string WindTitle = "Study-Plan Organizational Tool (SPOT)";

	window* pWind;
	window* pWind2;
	

public:
	GUI();
	void setFillColor(const color);
	void CreateNewWindow();
	void CreateMenu() const;
	void ClearDrawingArea() const;
	void ClearStatusBar() const;	//Clears the status bar
	
	//output functions
	void PrintMsg(string msg) const;		//prints a message on status bar
	void PrintNotes(string msg) const;
	//Drawing functions
	void DrawCourse(const Course* );
	void DrawAcademicYear(const AcademicYear*);
	void UpdateInterface() const;
	
	//input functions
	ActionData GUI::GetUserAction(string msg = "") const;
	string GetSrting() const;

	void DrawCourseGrade(const Course* pCrs);

	
	
	

	~GUI();
};

