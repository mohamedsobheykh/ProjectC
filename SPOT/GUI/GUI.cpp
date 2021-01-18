#include "GUI.h"
//#include "..\Rules.h"
#include "../Courses/Course.h"
#include "../StudyPlan/AcademicYear.h"
#include <sstream>
#include <iostream>
//#include "../Registrar.h"

GUI::GUI()
{ 
	pWind = new window(WindWidth, WindHeight,wx,wy);
	pWind->ChangeTitle(WindTitle);
	ClearDrawingArea();
	ClearStatusBar();
	CreateMenu();
}
/*
void GUI::PrintIssueReport(Issues* planIssues)
{
	int Xi = 600;
	int Yi = 100;
	int width = 600;
	int hight = 600;
	window* pWind2;
	pWind2 = new window(width, hight, Xi, Yi);
	pWind2->ChangeTitle("StudyPlan Validity Report - ESC to close");
	//clear drawing area
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;
	
	// Flush out the input queues before beginning
	pWind2->FlushMouseQueue();
	pWind2->FlushKeyQueue();
	while (true)
	{
		int x, y;
		//ctInput = pWind2->GetMouseClick(x, y);//Get the coordinates of the user click
		ktInput = pWind2->GetKeyPress(cKeyData);
		if (ktInput == ESCAPE)
			break;  

		//pWind2->UpdateBuffer();
		//Redraw everything
		pWind2->SetBrush(BkGrndColor);
		pWind2->SetPen(BkGrndColor);
		pWind2->DrawRectangle(Xi, Yi, Xi + width, Yi + hight);


		pWind2->SetFont(20, BOLD, BY_NAME, "Arial");
		pWind2->SetPen(MsgColor);
		pWind2->DrawString(Xi + 50, Yi + 50,"comeon jalksj;sf ljadsljf ");
		cout << "reachedhere";

		

	}
	 
	delete pWind2;
}
*/
void GUI::PrintIssueReport(Issues* planIssues)
{
	window* temp = pWind;
	pWind = new window(WindWidth, WindHeight, wx, wy);
	pWind->ChangeTitle("StudyPlan Validity Report - ESC to close");
	ClearDrawingArea();
	//ClearStatusBar();
	//CreateMenu();
	pWind->SetFont(30, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLUE);
	pWind->DrawString(wx, wy, "The Issues list: ");

	while (true)
	{
		pWind->SetBuffering(true);
		//Redraw everything
		//CreateMenu();
		//ClearStatusBar();
		ClearDrawingArea();
		pWind->UpdateBuffer();
		pWind->SetBuffering(false);
		// start writing
		int lineCount = 0;
		int colCount = 0;
		pWind->SetFont(30, BOLD, BY_NAME, "Arial");
		pWind->SetPen(BLUE);
		pWind->DrawString(wx, wy, "The Issues list: ");

		pWind->SetFont(15, BOLD, BY_NAME, "Arial");
		pWind->SetPen(MsgColor);
		for (int i = 0; i < planIssues->planIssues.size(); i++)
		{
			ostringstream msg;
			msg << i +1 << "- " << planIssues->planIssues[i].issueInfo;
			pWind->DrawString(wx + colCount*(WindWidth/3), wy + 70 + 20 * lineCount++, msg.str());

			if (lineCount == 28)
			{
				lineCount = 0;
				colCount++;
			}
		}

		if (this->GetUserAction().actType == CANCEL)
			break;
	}
	delete pWind;
	pWind = temp;
}


void GUI::CreateNewWindow()
{
	pWind2 = new window(400, 300, 50, 50);
	pWind2->DrawCircle(20, 20, 20);
	ClearDrawingArea();
}

void GUI::setFillColor(const color newFillColor)
{
	FillColor = newFillColor;
}




//Clears the status bar
void GUI::ClearDrawingArea() const
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor);
	pWind->DrawRectangle(0, MenuBarHeight, WindWidth, WindHeight -StatusBarHeight);

}

void GUI::ClearStatusBar() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, WindHeight - StatusBarHeight, WindWidth, WindHeight);
}

void GUI::CreateMenu() const
{
	pWind->SetBrush(StatusBarColor);
	pWind->SetPen(StatusBarColor);
	pWind->DrawRectangle(0, 0, WindWidth, MenuBarHeight);

	//You can draw the menu icons any way you want.

	//First prepare List of images paths for menu item
	string MenuItemImages[ITM_CNT];
	MenuItemImages[ITM_ADD] = "GUI\\Images\\Menu\\Menu_add_course.jpg";
    MenuItemImages[ITM_EXIT] = "GUI\\Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_Delete] = "GUI\\Images\\Menu\\Menu_Delete.jpg"; //'abedal
	MenuItemImages[ITM_Notes] = "GUI\\Images\\Menu\\Menu_Add_Notes.jpg";
	MenuItemImages[ITM_DesplayNotes] = "GUI\\Images\\Menu\\Menu_Desplay_Notes.jpg";
	MenuItemImages[ITM_Replace_CRS] = "GUI\\Images\\Menu\\Menu_Replace.jpg";
	MenuItemImages[ITM_Save] = "GUI\\Images\\Menu\\Menu_Save.jpg";
	MenuItemImages[ITM_Load] = "GUI\\Images\\Menu\\Menu_Load.jpg";
	MenuItemImages[ITM_ProgRec] = "GUI\\Images\\Menu\\Menu_ProgRec.jpg"; ////////////////////
	MenuItemImages[ITM_Reorder] = "GUI\\Images\\Menu\\Menu_Reorder.jpg";
	MenuItemImages[ITM_GPA] = "GUI\\Images\\Menu\\Menu_GPA.jpg";
	MenuItemImages[ITM_STATUS] = "GUI\\Images\\Menu\\Menu_CourseStatus.jpg";
	MenuItemImages[ITM_DoubleConcentration] = "GUI\\Images\\Menu\\Menu_DoubleCocentration.jpg";
	MenuItemImages[ITM_Minor] = "GUI\\Images\\Menu\\Menu_Minor.jpg";
	MenuItemImages[ITM_Report] = "GUI\\Images\\Menu\\Menu_Report.jpg";
	MenuItemImages[ITM_DoubleMajor] = "GUI\\Images\\Menu\\Menu_double_major.jpg";
	MenuItemImages[ITM_Filter] = "GUI\\Images\\Menu\\Menu_filter.jpg";

	//TODO: Prepare image for each menu item and add it to the list done

	//Draw menu items one image at a time
	for (int i = 0; i<ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*MenuItemWidth, 0, MenuItemWidth, MenuBarHeight);
}

////////////////////////    Output functions    ///////////////////

//Prints a message on the status bar
void GUI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX, WindHeight - MsgY, msg);
}

void GUI::PrintNotes(string msg) const
{
	//ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 980;
	int MsgY = 50;

	// printting the note
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->SetPen(MsgColor);
	pWind->DrawString(MsgX,MsgY, msg);

	
}

void GUI::PrintIssue(int Moderate, int Critical)
{
	if (Critical > -1)
	{
		int MsgX = 1000;
		int MsgY = 10;
		
		pWind->SetFont(20, BOLD, BY_NAME, "Arial");
		pWind->SetPen(StatusBarColor);
		pWind->SetBrush(RED);
		pWind->DrawRectangle(MsgX, MsgY, MsgX + 200, MsgY + 20 ,FILLED);
		pWind->SetPen(WHITE);

		ostringstream msg;
		msg << Critical << " CRITICAL ISSUE";
		pWind->DrawString(MsgX+10, MsgY, msg.str());
	}
	if (Moderate > 0)
	{
		int MsgX = 1000;
		int MsgY = 30;
		
		pWind->SetFont(20, BOLD, BY_NAME, "Arial");
		pWind->SetPen(StatusBarColor);
		pWind->SetBrush(ORANGE);
		pWind->DrawRectangle(MsgX, MsgY, MsgX + 200, MsgY + 20);
		pWind->SetPen(WHITE);

		ostringstream msg;
		msg << Moderate << " MODERATE ISSUE";
		pWind->DrawString(MsgX + 10, MsgY, msg.str());
	}
	
}



//////////////////////////////////////////////////////////////////////////
void GUI::UpdateInterface() const
{
	
	pWind->SetBuffering(true);
	//Redraw everything
	CreateMenu();
	ClearStatusBar();
	ClearDrawingArea();
	pWind->UpdateBuffer();
	pWind->SetBuffering(false);

}


//int typenum = coursetypeindecate(Rules * pRules, const Course * pCrs);

////////////////////////    Drawing functions    ///////////////////
void GUI::DrawCourse(const Course* pCrs)
{
	if (pCrs->isSelected())
		pWind->SetPen(HiColor, 2);
	else if (pCrs->getIssueState() != CLEAN)
	{
		pCrs->getIssueState() == CRITICAL ? pWind->SetPen(RED, 2) : pWind->SetPen(ORANGE, 2);
	}
	else  {
		//pWind->SetPen(DrawColor, 2);
		//pWind->SetBrush(FillColor);
		if (pCrs->gettype() == "UnivCompulsory" ) {
			pWind->SetPen(VIOLET, 2);
			pWind->SetBrush(FillColor);
		}
		 else if (pCrs->gettype() == "TrackCompulsory") {
			pWind->SetPen(GREEN, 2);
			pWind->SetBrush(FillColor);
		}
		 else if (pCrs->gettype() == "MajorCompulsory") {
			pWind->SetPen(YELLOW, 2);
			pWind->SetBrush(FillColor);
		}
		 else if (pCrs->gettype() == "Tconsentration_com") {
			pWind->SetPen(PINK, 2);
			pWind->SetBrush(FillColor);
		}
		 else {
			pWind->SetPen(BLACK, 2);
			pWind->SetBrush(FillColor);
		
		}

		
		
	}

	pWind->SetBrush(FillColor);
	graphicsInfo gInfo = pCrs->getGfxInfo();
	
	//abedal
	if (gInfo.y < 150) // to be in the drawing part away from the menu and words years and semesters
	{
	}
	else
	{
		 // to order courses below each other 
		// determining whuch semester and year the user click
		//gInfo.x is the x cordinate of the click
		
		
		if (gInfo.x < 80)
		{
			
			gInfo.x = 0;
		}
		else if ((gInfo.x > 86.7)& (gInfo.x < 166))
		{
			


			gInfo.x = 86.7;
		}
		else if ((gInfo.x > 166)& (gInfo.x < 253))
		{
			
			
			gInfo.x = 177;
		}


		//FOR THE SECIND YEAR
		else if ((gInfo.x > 260.2)& (gInfo.x < 340.2))// 0.2 TO PASS THE PORDERS
		{
			
			
			gInfo.x = 260.2;
		}
		else if ((gInfo.x > 346.8)& (gInfo.x < 420.6))
		{
			
			
			gInfo.x = 346.8;
		}
		else if ((gInfo.x > 427.2)& (gInfo.x < 507.2))
		{
			
			
			gInfo.x = 435;
		}
		//FOR THE THIRD YEAR
		else if ((gInfo.x > 507.2)& (gInfo.x < 593.8)) // 0.2 TO PASS THE PORDERS
		{
			
			
			gInfo.x = 520;
		}
		else if ((gInfo.x > 600.4)& (gInfo.x < 680.4))
		{
			
			
			gInfo.x = 610;
		}
		else if ((gInfo.x > 687)& (gInfo.x < 767))
		{
			
			
			gInfo.x = 695;
		}

		//FOR THE 4TH YAER
		else if ((gInfo.x > 773.6)& (gInfo.x < 853.6)) // 0.2 TO PASS THE PORDERS
		{
			
			
			gInfo.x = 782;
		}
		else if ((gInfo.x > 860.2)& (gInfo.x < 940.2))
		{
			
			
			gInfo.x = 871;
		}
		else if ((gInfo.x > 946.8)& (gInfo.x < 1026.8))
		{
			
			
			gInfo.x = 955;
		}

		//FOR THE 5TH YEAR
		else if ((gInfo.x > 1033.4)& (gInfo.x < 1113.4)) // 0.2 TO PASS THE PORDERS
		{
			
			
			gInfo.x = 1042;
		}
		else if ((gInfo.x > 1120) & (gInfo.x < 1200))
		{
		    
			
			gInfo.x = 1130;
		}
		
		else if ((gInfo.x > 1206.6)& (gInfo.x < 1286.6))
		{
		
			
			gInfo.x = 1215;
		}
		
		
		
		//abedal
		if ((pCrs->gettype() == "UnivElective") || (pCrs->gettype() == "TrackElective") ||
			(pCrs->gettype() == "MajorElective") || (pCrs->gettype() == "Tconsentration_ele")) {
			pWind->DrawEllipse(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
		}
		else {
			pWind->DrawRectangle(gInfo.x, gInfo.y, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT);
		}
		pWind->DrawLine(gInfo.x, gInfo.y + CRS_HEIGHT / 2, gInfo.x + CRS_WIDTH, gInfo.y + CRS_HEIGHT / 2);
	    
		//Write the course code and credit hours.
		int Code_x = gInfo.x + CRS_WIDTH * 0.15;
		int Code_y = gInfo.y + CRS_HEIGHT * 0.05;
		pWind->SetFont(CRS_HEIGHT * 0.4, BOLD , BY_NAME, "Gramound");
		pWind->SetPen(MsgColor);

		ostringstream crd;
		crd<< "crd:" << pCrs->getCredits();
		pWind->DrawString(Code_x, Code_y, pCrs->getCode());
		pWind->DrawString(Code_x, Code_y + CRS_HEIGHT/2, crd.str());
		}
	 
}

void GUI::DrawAcademicYear(const AcademicYear* pY) 
{
	graphicsInfo gInfo = pY->getGfxInfo();

	static int addd = 0;
	static int num = 0;
	pWind->SetPen(DrawColor, 2);

	pWind->DrawRectangle(0 + addd, 80, 260 + addd, 640, FRAME);

	pWind->SetBrush(LIGHTGRAY);
	pWind->DrawRectangle(0 + addd, 80, 260 + addd, 130);

	int YearX = 80 + addd;
	int YearY = 95;

	int Sem1X = 30 + addd;
	int Sem1Y = 130;
	int Sem2X = 110 + addd;
	int Sem2Y = 130;
	int Sem3X = 190 + addd;
	int Sem3Y = 130;


	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->SetPen(BLACK);

	pWind->DrawString(YearX, YearY, " Year no. ");
	pWind->DrawInteger(YearX + 70, YearY, 1 + num);

	pWind->SetPen(DrawColor, 1);
	pWind->DrawLine(86.6 + addd, 130, 86.6 + addd, 640);
	pWind->DrawLine(173.3 + addd, 130, 173.3 + addd, 640);

	pWind->DrawLine(20 + addd, 150, 250 + addd, 150);


	pWind->SetFont(15, BOLD, BY_NAME, "Arial");
	pWind->DrawString(Sem1X, Sem1Y, " Fall ");
	pWind->DrawString(Sem2X, Sem2Y, " Spring ");
	pWind->DrawString(Sem3X, Sem3Y, " Summer ");

	addd = addd + 260;
	num = num + 1;
	if (num > 4) {
		num = 0;
	}
	if (addd > 1040) {
		addd = 0;

	}
	
}


////////////////////////    Input functions    ///////////////////
//This function reads the position where the user clicks to determine the desired action
//If action is done by mouse, actData will be the filled by mouse position
ActionData GUI::GetUserAction(string msg) const
{
	keytype ktInput;
	clicktype ctInput;
	char cKeyData;

	
	// Flush out the input queues before beginning
	pWind->FlushMouseQueue();
	pWind->FlushKeyQueue();
	
	PrintMsg(msg);

	while (true)
	{
		int x, y;
		ctInput = pWind->GetMouseClick(x, y);	//Get the coordinates of the user click
		ktInput = pWind->GetKeyPress(cKeyData);

		if (ktInput == ESCAPE)	//if ESC is pressed,return CANCEL action
		{
			return ActionData{ CANCEL };
		}

		
		if (ctInput == LEFT_CLICK)	//mouse left click
		{
			//[1] If user clicks on the Menu bar
			if (y >= 0 && y < MenuBarHeight)
			{
				//Check whick Menu item was clicked
				//==> This assumes that menu items are lined up horizontally <==
				int ClickedItemOrder = (x / MenuItemWidth);
				//Divide x coord of the point clicked by the menu item width (int division)
				//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

				switch (ClickedItemOrder)
				{
				case ITM_ADD: return ActionData{ ADD_CRS };	//Add course
				case ITM_EXIT: return ActionData{ EXIT };		//Exit
				case ITM_Delete: return ActionData{ DEL_CRS };   //abedal delete a course
				case ITM_Notes: return ActionData{ ADD_Notes };  //abedal delete a course
				case ITM_DesplayNotes: return ActionData{ Display_Notes };
									 
				case ITM_Replace_CRS: return ActionData{ Replace_CRS };//abedal delete a course
				case ITM_Save: return ActionData { SAVE }; // save course sobhey
				case ITM_Load: return ActionData{ LOAD }; // Load course sobhey
				case ITM_ProgRec: return ActionData{ ImportReq }; // import program req
				case ITM_Reorder: return ActionData{ REORDER };
				case ITM_GPA:return ActionData{ CalculateGPA };
				case ITM_STATUS:return ActionData{ CourseStatus };
				case ITM_DoubleConcentration:return ActionData{ DoubleConcentration };
				case ITM_Minor:return ActionData{ Minor };
				case ITM_Report: return ActionData{ Report };
				case ITM_DoubleMajor: return { DoubleMajor };
				case ITM_Filter: return { Filter };
				default: return ActionData{ MENU_BAR };	//A click on empty place in menu bar
				}
			}

			//[2] User clicks on the drawing area
			if (y >= MenuBarHeight && y < WindHeight - StatusBarHeight)
			{
				
				return ActionData{ DRAW_AREA,x,y };	//user want clicks inside drawing area
			}

			//[3] User clicks on the status bar
			return ActionData{ STATUS_BAR };
		}
	}//end while

}

string GUI::GetSrting() const
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar

	

	string userInput;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);

		switch (Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input

		case 13:		//ENTER key is pressed
			return userInput;

		case 8:		//BackSpace is pressed
			if (userInput.size() > 0)
				userInput.resize(userInput.size() - 1);
			break;

		default:
			userInput += Key;
		};

		PrintMsg(userInput);
	}

}








GUI::~GUI()
{
	delete pWind;
}
