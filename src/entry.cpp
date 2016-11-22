#include "entry.h"
#include <iostream>

//comstructor definitions
Entry::Entry(){
	question = "";
	answer = "";
	cluster = 0;
}

Entry::Entry(const string Q, const string A, const int C){
	question = Q;
	answer = A;
	cluster = C;
}

//accessors definitions
string Entry::GetQuestion() const{
	return question;
}

string Entry::GetAnswer() const{
	return answer;
}

int Entry::GetCluster() const{ 
	return cluster;
}

//modifiers defintions
void Entry::SetQuestion(const string Q){
	question = Q;
}

void Entry::SetAnswer(const string A){
	answer = A;
}

void Entry::SetCluster(const int C){
	cluster = C;
}

void Entry::printEntry(){
	cout << question << endl;
	cout << answer << endl;
	cout << cluster << endl;
}
