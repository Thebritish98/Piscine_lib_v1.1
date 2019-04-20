#include "main.h"

int main()
{
    unsigned int i;
	Svgfile svgout;
	std::string Name_File;
	std::cout << "Nom du modele:";
	std::cin >> Name_File;
	Graph test(Name_File);
	svgout.addModel(test,100,100);
    //std::cout << "traque "<<pourquoi.get_tot1()<<std::endl;
	std::vector<Path*> chemin;
	std::vector<Path*> chemin_pareto;
	get_path(test,chemin);
//	std::cout << "total chemin possible i 1 "<<chemin[0]->get_tot1(); /// ici me semble bizarre
	//std::cout<<"taille entre get_path et verif   "<<chemin.size()<<std::endl;
//	for(i=0;i<chemin.size();i++)
//    {
//  //      std::cout <<" Chemin "<<i<<std::endl;
//        chemin[i]->afficher_path();
//    }
	pareto_verif(chemin,chemin_pareto);///peut être bug ici
//	std::cout<<chemin.size()<<std::endl;
//std::cout<< " a paprtir d'ici"<<std::endl;
	for( i=0;i<chemin_pareto.size();i++)
    {

        chemin_pareto[i]->afficher_path();
        std::cout<<"cout 1        "<<chemin_pareto[i]->get_tot1()<< "et     "<<chemin_pareto[i]->get_tot2()<<std::endl;
    }

	util::exec("output.svg");
	return 0;
}

namespace util
{
	void exec(LPCSTR FileName)
	{
		ShellExecute(NULL, "open", FileName, NULL, NULL, SW_SHOWNORMAL); //à l'aide https://docs.microsoft.com/en-us/windows/desktop/api/shellapi/nf-shellapi-shellexecutea
	}

}

