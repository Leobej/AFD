#include "AFD.h"
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
void AFD::citire()
{
	std::ifstream file("fisier.txt");
	std::string curent;
	int contor;
	file >> contor;
	for (int index = 0; index < contor; index++)
	{
		std::string quri;
		file >> quri;
		Stari.push_back(quri);
	}
	file >> contor;
	for (int index = 0; index < contor; index++)
	{
		std::string alfabet;
		file >> alfabet;
		Sigma.push_back(alfabet);
	}
	file >> StareInit;
	file >> contor;
	for (int index = 0; index < contor; index++)
	{
		std::string finals;
		file >> finals;
		Finale.push_back(finals);
	}
	std::string elementtranzitie;
	std::string elementalfabet;
	std::string tranzitierezultate;
	while (file >> elementtranzitie >> elementalfabet >> tranzitierezultate)
	{
		std::pair<std::string, std::string>pairtemporar(elementtranzitie, elementalfabet);
		Delta.insert(std::pair<std::pair<std::string, std::string>, std::string>(pairtemporar, tranzitierezultate));
	}
}

void AFD::afisare()
{
	std::cout << "Q={";
	for (int index = 0; index < Stari.size(); index++)
	{
		std::cout << Stari[index] << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Sigma {";
	for (int index = 0; index < Sigma.size(); index++)
	{
		std::cout << Sigma[index] << " ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Starea initiala q este: " << StareInit << std::endl;
	std::cout << "Starile finale F sunt: ";
	for (int index = 0; index < Finale.size(); index++)
	{
		std::cout << Finale[index] << " ";
	}
	std::cout << std::endl;
	std::cout << "Functiile de tranzitii sunt: ";
	std::cout << std::endl;
	for (auto itr = Delta.begin(); itr != Delta.end(); ++itr)
	{
		std::cout << itr->first.first << " " << itr->first.second << " " << itr->second << std::endl;
	}
}

void AFD::minimizare()
{
	std::vector < std::string>Starineminimizate;
	std::vector<std::string>Stariminimizate;
	for (int index = 0; index < Stari.size(); index++)
	{
		int aux = 0;
		for (int index2 = 0; index2 < Finale.size(); index2++)
		{
			if (Stari[index] == Finale[index2])
			{
				aux = 1;
			}
		}
		if (aux == 0)
			Starineminimizate.push_back(Stari[index]);
	}
	for (int index = 0; index < Finale.size(); index++)
	{
		Stariminimizate.push_back(Finale[index]);
	}

	for (int index = 0; index < Starineminimizate.size(); index++)
	{
		for (int index2 = index++; index2 < Starineminimizate.size(); index2++)
		{
			for (auto itr = Delta.begin(); itr != Delta.end(); ++itr)
			{
				for (int index4 = 0; index4 < Sigma.size(); index4++)
				{
					if (itr->first.first == Starineminimizate[index] && itr->first.second == Sigma[index4]
						&&itr->second==Starineminimizate[index2])
					{
						std::string cuvanttemporar = itr->second;
						for (int index3 = 0; index3 < Starineminimizate.size(); index3++)
						{
							if (cuvanttemporar == Starineminimizate[index3])
							{
								
							}
						}
					}
				}
			}
		}
	}

}