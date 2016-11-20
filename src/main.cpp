#include "dbfunctions.h"

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
