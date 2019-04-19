#include "main.h"

int main()
{
	bool end = false;
	std::cout << "\t\t\tPROJET ING2 S2\n--------------------------------------------------------\n--------------------------------------------------------\n";
	while (!end)
	{
		/*MAIN PROCESS*/
		Svgfile svgout;
		BoardResult testboard;
		std::string Name_File;
		std::cout << "Nom du modele:";
		std::cin >> Name_File;
		Graph test(Name_File);
		testboard.give_results(svgout, test,Name_File);

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

/*
Ajouter menu avec le choix en option du type de tableau de résultat que l'on veut (ouvrrira un fichier .txt)
*/

namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}

	bool stay()
	{
		bool end;
		unsigned int choice=2;
		std::cout << "Voulez vous rester?\n0-Oui\n1-Non\n";
		while (choice != 0 && choice != 1)
		{
			std::cin >> choice;
			if (choice == 0)
			{
				end = false;
			}
			else if (choice == 1)
			{
				end = true;
			}
			else if(choice!=0||choice!=1)
			{
				std::cout << "Choix non valide\n";
			}
		}
		return end;
	}

}

