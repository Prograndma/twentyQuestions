#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class question {
public:
	string SetQuestion(string name);
	void AskQuestion();
	string SetName();
	string GetName();
	string theQuestion;
	string objName;

private:
	question*  yesPointer;
	question* noPointer;
	

};

