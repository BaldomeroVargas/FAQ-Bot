#include "levenshteinDistance.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	char one[] = "mars";
	char two[] = "mars planet";
	cout << levenshteinDistance(one, two);
	return 0;
}
