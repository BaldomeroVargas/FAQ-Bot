#include "entry.h"
#include "entry.cpp"
#include "dice.h"
#include "levenshtineDistance.h"
#include <vector>

void sortDatabase(vector<entry> db){
	vecotor<entry> temp;
	temp.push(db.at(1));
	db.erase(db.begin());
	while(db.size != 0){
		int max = 0;
		int next = 0;
		for(int i = 0; i < temp.size(); ++i){
			char* tmp = new char[DataBase.at(i).GetQuestion().length()];
			for(int k = 0; k < DataBase.at(i).GetQuestion().length(); ++k){
				tmp[k] = DataBase.at(i).GetQuestion().at(k);
			}
			for(int j = 0; j < db.size(); ++j){
				char* tmp2 = new char[DataBase.at(j).GetQuestion().length()];
				for(int k = 0; k < DataBase.at(j).GetQuestion().length(); ++k){
					tmp2[k] = DataBase.at(j).GetQuestion().at(k);
				}
				int curr = dice_match(tmp, tmp2);
				if(curr < max){
					max = curr;
					next = j;
				}
			}
		}
		temp.push(db.at(next));
		db.erase(db.begin() + next);
	}
	for(int i = 0; i < db.size(); ++i){
		cout << db.at(i).GetQuestion() << endl;
		cout << db.at(i).GetAnswer() << endl;
		cout << db.at(i).GetCluster() << endl;
	}
	return;
}
