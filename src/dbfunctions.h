#ifndef DBFUNCTIONS_H
#define DBFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "entry.h"
#include "dice.h"

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

void sortDatabase(vector<Entry>& db){
	vector<Entry> temp;
	temp.push_back(db.at(0));
	db.erase(db.begin());
	while(db.size() != 0){
		int max = 0;
		int next = 0;
		for(int i = 0; i < temp.size(); ++i){
			char* tmp = new char[temp.at(i).GetQuestion().length()];
			for(int k = 0; k < temp.at(i).GetQuestion().length(); ++k){
				tmp[k] = temp.at(i).GetQuestion().at(k);
			}
			for(int j = 0; j < db.size(); ++j){
				char* tmp2 = new char[db.at(j).GetQuestion().length()];
				for(int k = 0; k < db.at(j).GetQuestion().length(); ++k){
					tmp2[k] = db.at(j).GetQuestion().at(k);
				}
				int curr = dice_match(tmp, tmp2);
				if(curr > max){
					max = curr;
					next = j;
				}
			}
		}
		temp.push_back(db.at(next));
		db.erase(db.begin() + next);
	}
	db = temp;
	export_DataBase(db, "database.txt");
	for(int i = 0; i < temp.size(); ++i){
		cout << temp.at(i).GetQuestion() << endl;
		cout << temp.at(i).GetAnswer() << endl;
		cout << temp.at(i).GetCluster() << endl;
	}
	return;
}

#endif
