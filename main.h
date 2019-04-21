#ifndef MAINHPP
#define MAINHPP

#include <bitset> //bits/stdc++.h?
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
#include <Windows.h>
#include  <algorithm>
#include "Display.h"
#include "Graphe.h"

class BoardResult;
namespace util
{

	void exec(LPCSTR FileName);

	template <typename T>
	T menu(std::string _title, std::map<T, std::string> _mapname)
	{
		/**
		send a std::vector test with all options
		**/
		T choice;
//		util::Line();
		std::cout << _title << std::endl;
		//util::Line();
		for (const auto& elem : _mapname)
		{
                std::cout << elem.first << "/ " << elem.second << std::endl;
		}
		while (_mapname.find(choice) == _mapname.end())
		{
			std::cin >> choice;
			if (_mapname.find(choice) == _mapname.end())
			{
				std::cout << "Choix non Valide" << std::endl;
			}
		}
		return choice;
	}
	void Line();
	void refresh(Graph& _graph, BoardResult& _board, std::string _filename);
	void setting(Graph& _graph, BoardResult& _board);
	void show(Graph& _graph, BoardResult _board, Svgfile& _out);
}
#endif // !MAINHPP
