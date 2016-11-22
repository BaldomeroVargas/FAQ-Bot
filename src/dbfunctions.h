#ifndef DBFUNCTIONS_H
#define DBFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "entry.h"
#include "dice.h"
#include "levenshteinDistance.h"

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
	string copy;
	while(db.size() != 0){
		int max = 0;
		int next = 0;
		for(int i = 0; i < temp.size(); ++i){
			copy = remove(temp.at(i).GetQuestion());
			char* tmp = new char[copy..length()];
			for(int k = 0; k < copy.length(); ++k){
				tmp[k] = copy.at(k);
			}
			for(int j = 0; j < db.size(); ++j){
				copy = db.at(j).GetQuestion().length();
				char* tmp2 = new char[copy.length()];
				for(int k = 0; k < copy.length(); ++k){
					tmp2[k] = copy.at(k);
				}
				int curr = distance(tmp, tmp2);
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

int distance(char* one, char* two){
	return dice_match(one, two);
}

string remove(string parse){
	int tmp;
	for(int i = 0; i < BOW.size(); ++i){
		while(parse.find(BOW.at(i)) != string::npos){
			pasre.erase(parse.find(BOW.at(i)i), BOW.at(i).size()); 
		}
	}
	cout << parse << endl;
	return parse;
}

#endif
