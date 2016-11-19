#include "entry.h"

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

//destructor definition
Entry::~Entry(){
	//what to do here??
}

//accessors definitions
const string Entry::GetQuestion(){
	return question;
}

const string Entry::GetAnswer(){
	return answer;
}

const int Entry::GetCluster(){
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

