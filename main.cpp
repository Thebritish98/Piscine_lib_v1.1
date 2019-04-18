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
	testboard.init_template();
	std::string Name_File;
	std::cout << "Nom du modele:";
	std::cin >> Name_File;
	Graph test(Name_File);
	testboard.set_template(svgout);
	test.show_svg(svgout);
	end = true;
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

