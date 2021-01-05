#pragma once
#include <iostream>
#include<string>
#include<string.h>
using namespace std;
#include"Registrar.h"
#include"Courses/UnivCourse.h"
string studentLevel(static int totalCredits);



string studentLevel(static int totalCredits)
{
	if (totalCredits <= 32)
		return"Foundation";
	else if (totalCredits <= 67)
		return"Sophomore";
	else if (totalCredits <= 101)
		return"Junior";
	else if (totalCredits <= 135)
		return"Senior I";
	else if (totalCredits <= 162)
		return"Senior II";

}