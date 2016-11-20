#include "levenshteinDistance.h"
#include "dice.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	char one[] = "Is Jupiter a planet?";
	char two[] = "What is Jupiter?";
	string String1;
	string String2;
	//cout << "Enter String 1: ";
	//getline(cin, one);
	//cout << "Enter String 2: ";
	//getline(cin, two);
	String1 = one;
	String2 = two;
	cout << levenshteinDistance(one, two) << endl;
	cout << dice_match(one, two) << endl;
	return 0;
}
