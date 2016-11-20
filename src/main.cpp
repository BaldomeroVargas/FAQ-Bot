#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "entry.h"

//subject to being moved to another file
//just here rn for testing purposes

//function to import the database to be used from the txr file
void importDataBase(vector<Entry> & db, const char* db_name){
	
	ifstream input;
	input.open(db_name);
	//error check with file opening
	if(!(input.is_open())){
		cout << "Error opening file.\n";
		exit(-1);
	}

	Entry current;			//temp object to push to vector
	string element = "";		//temp element string to push elements to vector
	int itt = 0;
	while(getline(input,element)){
		//if empty line ignore
		if(element == ""){
			continue;
		}
		//switch statement to choose which element to update
		switch(itt){
			//updating question
			case 0:
				current.SetQuestion(element);
				itt++;
				break;
			//updating answer
			case 1:
				current.SetAnswer(element);
				itt++;
				break;
			//updating cluster
			case 2:
				//string -> int
				int numb;
				istringstream(element) >> numb;
				current.SetCluster(numb);
				itt = 0;
				db.push_back(current);
				break;
			//should not get here	
			default:
				cout << "Error: Should not be here\n";
				exit(0);
		}
	}
	input.close();
}

//outputs database into file
void export_DataBase(const vector<Entry> &  db, const char* db_name){

	ofstream output;
	output.open(db_name);

	//error check with file opening
	if(!(output.is_open())){
		cout << "Error opening file.\n";
		exit(-1);
	}

	//outputing database to file
	for(int i = 0; i < db.size(); ++i){
		output << db.at(i).GetQuestion() << endl;
		output << db.at(i).GetAnswer() << endl;
		output << db.at(i).GetCluster() << endl;
		output << endl;
	}

	output.close();
}

int main(int argc, char** argv){

	//arguement count error check
	if(argc != 2){
		cout << "Error: Please use [exectuable] [database] format to run program.\n";
		return -1;
	}

	//importing data base
	vector <Entry> DataBase;
	importDataBase(DataBase, argv[1]);

	//test output
	for(int i = 0; i < DataBase.size(); ++i){
		cout << DataBase.at(i).GetQuestion() << endl;
		cout << DataBase.at(i).GetAnswer() << endl;
		cout << DataBase.at(i).GetCluster () << endl;
		cout << endl;
	}
	return 0;

}
