#pragma once
#include <iostream>
#include <string>

//This file contains data sturctures required to store all registration RULES
#include <vector>
using namespace std;
#include "DEFs.h"


//Information for each course
//Title, code, credit hours, and pre-req list, type
struct CourseInfo
{
	string Title;
	Course_Code	Code;
	vector<Course_Code> PreReqList;	//Pre-requesite list of courses codes
	vector<Course_Code> CoReqList;	//Co-requesite list of courses codes
	int Credits;
	string type;	//Univ, track, major course
};

struct AcademicYearOfferings
{
	string Year; //academic year of the offerings e.g. 2019-2020


	//Each year has an array of of 3 vectors of courses CODE. 
	//Each vector cossrsponds to a semester
	//So Offerings[FALL] is a vector of courses offered in FALL in THAT year
	//So Offerings[SPRING] is a vector of courses offered in SPRING in THAT year
	//So Offerings[SUMMER] is a vector of courses offered in SUMMER in THAT year
	vector<Course_Code> Offerings[SEM_CNT];
};
 
struct Issues
{
	vector<Issue> planIssues;
};

struct Rules	//contains all objects for registrations rules
{
	//TODO: add more fields if needed

	vector<CourseInfo> CourseCatalog;	//List of ALL courses with full info
	vector<AcademicYearOfferings> OffringsList;	//all offerings for all acedmic years

	int SemMinCredit;		//min no. of credit hours per semester
	int SemMaxCredit;		//max no. of credit hours per semester

	int ReqUnivCredits;		 //total no. of credits req by Univ courses
	int Uni_compulsory_cr;   //credits req by Univ compulsory courses
	int Uni_elective_cr;     //credits req by Univ elective courses

	int Track_compulsory_cr; //credits req by track compulsory courses
	int Track_elective_cr;   //credits req by track elective courses
	int ReqTrackCredits;	 //total no. of credits req by Track courses

	int Major_compulsory_cr; //credits req by major compulsory courses
	int Major_elective_cr;   //credits req by major elective courses
	int ReqMajorCredits;	 //total no. of credits req by Major courses

	int no_concentration; // number of concentrations
	vector<int> no_cr_concentrations; //concentration1 com cr, concentration1 elective cr,....

	vector<Course_Code> UnivCompulsory;	//Univ Compulsory courses
	vector<Course_Code> UnivElective;	//Univ Elective courses

	vector<Course_Code> TrackCompulsory;//Track Compulsory courses
	vector<Course_Code> TrackElective;	//Track Elective courses (added for future)

	vector<Course_Code> MajorCompulsory;//Major Compulsory courses
	vector<Course_Code> MajorElective;	//Major Elective courses

	vector<Course_Code> consentration1_com;//consentration 1 courses comp
	vector<Course_Code> consentration1_ele;//consentration 1 courses  electives
	vector<Course_Code> consentration2_com;	//consentration 2 courses comp
	vector<Course_Code> consentration2_ele;	//consentration 2 courses electives
	vector<Course_Code> consentration3_com;//consentration 3 courses comp
	vector<Course_Code> consentration3_ele;//consentration 3 courses electives
	vector<Course_Code> consentration4_com;	//consentration 4 courses comp
	vector<Course_Code> consentration4_ele;	//consentration 4 courses electives

	
	Issues* Issues;
};

/* format of the txt file:
* 
total cr
uni com cr, uni elective cr
track com cr
major com cr, major electiv cr

no concentration
concentration1 com cr, concentration1 elective cr,....

uni com courses
uni elective courses
track com courses
major com courses
major elective courses

concentration1 com courses
concentration1 elective courses
concentration2 com courses
concentration2 elective courses
concentration3 com courses
concentration3 elective courses
concentration4 com courses
concentration4 elective courses
*/

