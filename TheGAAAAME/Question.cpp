#include "Question.h"
string question::SetQuestion(string name) {
	string aQuestion;
	cout << "What is a question that is yes for " << objName << " and no for " << name << "?";
	getline(cin, aQuestion);
	cout << endl;
	return aQuestion;
}

void question::AskQuestion() {

}

string question::SetName() {
	string aName;
	cout << "What is it?";
	getline(cin, aName);
	return aName;	
}

string question::GetName() {
	return objName;
}