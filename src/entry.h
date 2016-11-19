#ifndef ENTRY_H
#define ENTRY_H

#include <string>
using namespace std;

//object that takes in the database entries 
class Entry{
	
	private:
		//Q and A strings
		string question;
		string answer;

		//clustering number???
		int cluster;

	public:
		//member function declarations
		//contructors
		Entry();
		Entry(const string Q, const string A, const int C);

		//destructor
		~Entry();

		//accessors
		const string GetQuestion();
		const string GetAnswer();
		const int GetCluster();
		
		//modifiers
		void SetQuestion(const string Q);
		void SetAnswer(const string A);
		void SetCluster(const int C);

		//other
		void printEntry();
};
#endif
