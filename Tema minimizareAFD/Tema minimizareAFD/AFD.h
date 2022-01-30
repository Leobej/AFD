#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
class AFD
{
private:
	std::vector<std::string>Stari;
	std::vector<std::string>Sigma;
	std::map<std::pair<std::string, std::string>, std::string>Delta;
	std::string StareInit;
	std::vector<std::string>Finale;
public:
	void citire();
	void afisare();
	void minimizare();
};

