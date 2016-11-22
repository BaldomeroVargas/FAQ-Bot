#include "dbfunctions.h"

using namespace std;

int main(int argc, char** argv){

	//arguement count error check
	if(argc != 2){
		cout << "Error: Please use [exectuable] [database] format to run program.\n";
		return -1;
	}

	//importing data base
	vector <Entry> DataBase;
	importDataBase(DataBase, argv[1]);

	/*string input;
	//test output

	for(int i = 0; i < DataBase.size(); ++i){
		cout << DataBase.at(i).GetQuestion() << endl;
		cout << DataBase.at(i).GetAnswer() << endl;
		cout << DataBase.at(i).GetCluster () << endl;
		cout << endl;
	}*/
	sortDatabase(DataBase);
	cout << "Ask me a question." << endl;
	/*
	while(true){
		getline(cin, input);
		// should be changed to something that chackes the distance to every cluster and then
		// if it is in the same cluster it outputs the most similar response. if not it asks if you want to move topics.
		//if yes it will output the most similar response from that clustor and update current cluster.
		cout << input << endl;
	}*/

	for(int i = 0; i < DataBase.size(); ++i){
		char* tmp = new char[DataBase.at(i).GetQuestion().length()];
		for(int k = 0; k < DataBase.at(i).GetQuestion().length(); ++k){
			tmp[k] = DataBase.at(i).GetQuestion().at(k);
		}
		tmp[DataBase.at(i).GetQuestion().length()] = '\0';
		for(int j = i; j < DataBase.size(); ++j){
			char* tmp2 = new char[DataBase.at(j).GetQuestion().length()];
			for(int k = 0; k < DataBase.at(j).GetQuestion().length(); ++k){
				tmp2[k] = DataBase.at(j).GetQuestion().at(k);
			}
			tmp2[DataBase.at(j).GetQuestion().length()] = '\0';
			cout << DataBase.at(i).GetQuestion() << endl;
			cout << DataBase.at(j).GetQuestion() << endl;
			cout << "Distance: " << dice_match(tmp, tmp2) << endl << endl;
			delete tmp2;
		}
		delete tmp;
	}
	return 0;

}
