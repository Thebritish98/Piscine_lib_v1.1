#include "main.h"

int main()
{
	bool end = false;
	std::cout << "\t\t\tPROJET ING2 S2\n--------------------------------------------------------\n--------------------------------------------------------\n";
	while (!end)
	{
		/*MAIN PROCESS*/
		Svgfile svgout;
		Coord A(20, 15);
		Coord B(15, 15);
		Coord C(10, 15);
		Coord D(5, 15);
		Coord E(20, 5);
		std::vector<Coord> ZA;
		std::vector<Coord> ZB;
		ZA.push_back(A);
		ZA.push_back(B);
		ZA.push_back(C);
		ZA.push_back(D);
		ZA.push_back(E);
		ZB.push_back(A);
		ZB.push_back(D);
		ZB.push_back(E);
		BoardResult testboard;
		std::string Name_File;
		std::cout << "Nom du modele:";
		std::cin >> Name_File;

		Graph test(Name_File);
		testboard.give_results(svgout, test,Name_File);
		svgout.addGraph(ZA, ZB, 840, 500); 

		/*std::vector<Path*> chemin_vec;
		get_path(test, chemin_vec);
		std::cout << "total chemin possible i 1 " << chemin_vec[0]->get_tot1(); /// ici me semble bizarre
		pareto_verif(chemin_vec);*/


		/*for (size_t i = 0; i < chemin_vec.size(); i++)
			chemin_vec[i]->afficher_path();*/



		end = true;
		/*std::vector<Graph*> graph_vec;
		for (size_t i = 0; i < chemin_vec.size(); i++)
		{
			graph_vec.push_back(new Graph(*chemin_vec[i],test));
			svgout.addModel(*graph_vec[i],i*200+100,100,"white");
		}*/
		util::exec("output.svg");


		//end of program
		//end = util::stay();
	}
	return 0;
}

namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}

}

