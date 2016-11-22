#include "dbfunctions.h"

using namespace std;

int main(int argc, char** argv){

	//arguement count error check
	if(argc != 2){
		cout << "Error: Please use [exectuable] [database] format to run program.\n";
		return -1;
	}

	//importing data base in clusters
	vector < vector<Entry> > DataBase;
	importDataBase(DataBase, argv[1]);
	vector <Entry> tmp;
	for(int i = 0; i  < DataBase.size(); ++i){
		for(int j = 0; j < DataBase.at(i).size(); ++j){
			tmp.push_back(DataBase.at(i).at(j));
		}
	}
	sortDatabase(tmp);
	return 0;
}
