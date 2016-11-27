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

	//sample get singe entry from each cluster
	//in dbfunctions
	vector<Entry> db_cluster;
	db_cluster = sample_list(DataBase);

	for(int i = 0; i <db_cluster.size(); ++i){
		db_cluster.at(i).printEntry();
	}


	vector <Entry> tmp;
	for(int i = 0; i  < DataBase.size(); ++i){
		for(int j = 0; j < DataBase.at(i).size(); ++j){
			tmp.push_back(DataBase.at(i).at(j));
		}
	}
	sortDatabase(tmp);
	cluster(tmp);
	cout << "done" << endl;
	return 0;
}
