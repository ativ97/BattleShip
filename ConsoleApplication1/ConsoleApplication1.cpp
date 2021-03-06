// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class ship {

public:
	vector<string> position;
	vector<int> flag;
	int hit;
	int sunk;
};

void ShipPos(vector<ship> &Ships, vector<string> pos) {

	for (int i = 0; i < pos.size(); i++)
	{
		string line = pos.at(i);
		//cout << line;
		int length = line.length();
		int space = line.find(' ');
		int TL, BR;
		try {
			TL = stoi(line.substr(0, space));
		}
		catch (std::invalid_argument&e) {

		}
		char TopL = line[space - 1];
		try {
			BR = stoi(line.substr(space + 1, length - (space + 2)));
		}
		catch (std::invalid_argument&e) {

		}
		char BotR = line[length - 1];
		ship temp;
		for (int i = TL; i <= BR; i++)
			for (int j = (int)TopL - 64; j <= (int)BotR - 64; j++) {
				//cout << "[" << i << "]" << "[" << j << "]" << endl;
				string SP = to_string(i);
				SP += j + 64;
				int flag = 0;
				//cout << SP;
				temp.position.push_back(SP);
				temp.flag.push_back(flag);
				temp.hit = 0;
				temp.sunk = 0;
			}
		Ships.push_back(temp);
		//cout << "'" << TL << "'" << TopL << endl;
		//cout << "'" << BR << "'" << BotR << endl;
	}
}

void attack(vector<ship> &Ships, string T) {

	istringstream iss(T);
	vector<string> tokens{ istream_iterator<string>{iss},
		istream_iterator<string>{} };

	for (int i = 0; i < tokens.size(); i++) {
		string P = tokens.at(i);
		for (auto &A : Ships) {

			auto it = std::find(A.position.begin(), A.position.end(), P);
			if (it == A.position.end())
			{
				// name not in vector
			}
			else
			{
				auto index = std::distance(A.position.begin(), it);
				A.flag[index] = 1;
			}
			int sum = std::accumulate(A.flag.begin(), A.flag.end(), 0);
			if (sum > 0)
			{
				if (sum == A.flag.size())
					A.sunk = 1;
				else
					A.hit = 1;
			}
		}
	}

}

string solution(int N, string &S, string &T) {
	vector<string> vect;
	string LN;
	vector<ship> Ships;
	int n = count(S.begin(), S.end(), ',');
	for (int i = 0; i < n + 1; i++) {
		stringstream ss(S);
		getline(ss, LN, ',');
		getline(ss, S);
		//cout<<LN<<"+";
		vect.push_back(LN);
	}

	//	for (int i = 0; i< vect.size(); i++)
	//		std::cout << i << "- |" << vect.at(i)<<"|" << std::endl;
	ShipPos(Ships, vect);
	int ShipsHit = 0, ShipsSunk = 0;
	attack(Ships, T);
	for (auto &A : Ships)
	{
		if (A.sunk == 1)
		{
			ShipsSunk += 1;
		}
		else if (A.hit == 1)
		{
			ShipsHit += 1;
		}
	}
	string answer = to_string(ShipsSunk) + "," + to_string(ShipsHit);
	//cout<<answer;
	return answer;
}