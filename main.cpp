#include "main.h"

int main()
{
	bool end = false;
	Svgfile svgout;
	BoardResult Board;
	std::string str_tmp;
	std::cout << "Quelle modele voulez vous?" << std::endl;
	std::cin >> str_tmp;
	Graph test(str_tmp);
	std::cout << "\t\tPROJET ING2 S2\n";
	/*MAIN PROCESS*/
	while (!end)
	{
		util::Line();
		switch (util::menu<unsigned int>("\nQue voulez vous faire?", { {0,"lancer Kruskal/Pareto"},{1,"Lancer Djisktra/Pareto"} ,{2,"Modifier le theme"} ,{3,"Quitter"} }))
		{
		case 0:
			/*
			On lance kruskal pareto et affichage avec graphe de base sur 1 ecran
			*/
			std::cout << "On lance kruskal" << std::endl;
			break;
		case 1:
			/*
			On lance pareto affichage avec graphe de base et djikstra sur fiche a coté
			*/
			std::cout << "On lance djisktra" << std::endl;
			break;
		case 2:
			util::setting(test,Board);
			break;
		case 3:
			end = true;
			break;
		}
	}
	Board.init_template();
	util::show(test, Board, svgout);
	util::exec("output.svg");
	return 0;
}


namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}
	void Line()
	{
		std::cout << "-----------------------------------------\n";
	}

	void refresh(Graph& _graph,BoardResult& _board,std::string _filename)
	{
		if(_filename != "none")
			_graph.reload(_filename);
		_board.init_template();
	}

	void setting(Graph& _graph, BoardResult& _board)
	{
		bool end = false;
		std::string str_tmp;
		while (!end)
		{
			switch (util::menu<unsigned int>("Que voulez vous modifier?", { {1,"Modifier le theme"},{2,"Quitter les options"} }))
			{
			case  1:
				_board.set_mode();
				util::refresh(_graph, _board, "none");
				break;
			case  2:
				end = true;
				break;
			}
		}
	}

	void show(Graph& _graph, BoardResult _board, Svgfile& _out)
	{
		_board.set_template(_out);
		_board.give_results(_out, _graph, _graph.get_model_name());
	}


}