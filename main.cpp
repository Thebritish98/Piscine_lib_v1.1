#include "main.h"

int main()
{
    unsigned int i;
	Svgfile svgout;
	std::string Name_File;
	std::cout << "Nom du modele:";
	std::cin >> Name_File;
	Graph test(Name_File);
	test.show_svg(svgout);
	//util::exec("output.svg");
	Path pourquoi;
	pourquoi.add_link(test.get_m_link()[1]);
	pourquoi.add_link(test.get_m_link()[0]);
	pourquoi.add_link(test.get_m_link()[2]);
    //std::cout << "traque "<<pourquoi.get_tot1()<<std::endl;
	std::vector<Path*> chemin;
	get_path(test,chemin);
	std::cout << "total chemin possible i 1 "<<chemin[0]->get_tot1(); /// ici me semble bizarre
	//std::cout<<chemin.size()<<std::endl;
	pareto_verif(chemin);///peut être bug ici
//	std::cout<<chemin.size()<<std::endl;
	for( i=0;i<chemin.size();i++)
        chemin[i]->afficher_path();
// il erase tous je vais regardé pkok je vais pipi
	return 0;
}

namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}

}

