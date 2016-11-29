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
	vector<Entry> sample = sample_list(DataBase);

	string input;
	/*test output

	for(int i = 0; i < DataBase.size(); ++i){
		cout << DataBase.at(i).GetQuestion() << endl;
		cout << DataBase.at(i).GetAnswer() << endl;
		cout << DataBase.at(i).GetCluster () << endl;
		cout << endl;
	}*/

	cout << "Ask me a question." << endl;
	while(true){
		getline(cin, input);
		// should be changed to something that chackes the distance to every cluster and then
		// if it is in the same cluster it outputs the most similar response. if not it asks if you want to move topics.
		//if yes it will output the most similar response from that clustor and update current cluster.
		int cluster =  find_cluster(sample, input);
		cout << find_entry(DataBase.at(cluster), input) << endl;
	}
	return 0;
}
