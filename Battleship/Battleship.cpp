// Battleship.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include <sstream>

using namespace std;

class ship {

public:
	vector<string> position;
	vector<int> flag;
};

void battle(int N, string &S, string &T) {
	vector<string> vect;
	string LN;
	vector<ship> Ships;
	size_t n = std::count(S.begin(), S.end(), ',');
	for (int i = 0; i<n + 1; i++) {
		stringstream ss(S);
		getline(ss, LN, ',');
		getline(ss, S);
		//cout<<LN<<"+";
		vect.push_back(LN);
	}

	for (int i = 0; i< vect.size(); i++)
		std::cout <<i<<"- "<< vect.at(i)<<std::endl;
	//ShipPos(Ships, vect);
}




int main()
{
	string S = "1A 2B,3A 4B, 6A 7B";
	string T = "1A 2B";
	battle(4,S,T);

	
	return 0;
}

