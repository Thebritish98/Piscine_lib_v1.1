#include "main.h"




bool tri_cout1(const Link* &p,const Link* &d){return p->m_cost1<d->m_cost1;}

void kruskal(std::vector<Link*> m_links, Path* & apm,std::vector<Point*> m_points)                                     /// on est d'accord que je modifie que virtuellement graph ?
{
   /// tri du vecteur graph
   int i,y=0,z;
   unsigned int verif1,verif2,verif3,intermediaire;
   float intercos;
   Path inter;
   Link* interlien;
/// tester avec me tri.
        /// tri

                for (i=0;i<(m_links.size()-1)*(m_links.size()-1);i++)
                {
                    if (y==m_links.size()-1)
                        y=0;

                    if (m_links[y]->get_cos1()>m_links[y+1]->get_cos1())
                    {
                        interlien=m_links[y+1];
                        m_links[y+1]=m_links[y];
                        m_links[y]=interlien;

                    }
                    y++;
                }
                for (i=0;i<m_links.size();i++)
                {
                    std::cout << "résultat du tri " << i<< "   "<< m_links[i]->get_cos1()<<std::endl;
                }

   //     std::sort(*m_links.begin(),*m_links.end(), tri_cout1);
verif3=0;
verif2=1;

               // std::cout<< "tout va bien ici2"<<std::endl;
                for(i=0;i<m_links.size()&&verif2!=0;i++) /// pour chaque lien dans l'ordre croissant si le tri juste au dessus marche
                {
                    verif1=0;
                    verif2=0;
                  if (m_points[m_links[i]->get_id_a()]->get_marked()<m_points[m_links[i]->get_id_b()]->get_marked())/// si point marka<markb toutes les markb de chaque point <a
                  {
                      verif1=1;
                       intermediaire=m_points[m_links[i]->get_id_b()]->get_marked();
                                 for(z=0;z<m_points.size();z++)
                                 {
                                     if (intermediaire==m_points[z]->get_marked())
                                     m_points[z]->set_marked(m_points[m_links[i]->get_id_a()]->get_marked());
                                 }
                  }
                  else if (m_points[m_links[i]->get_id_a()]->get_marked()>m_points[m_links[i]->get_id_b()]->get_marked())
                  {
                      verif1=1;
                       intermediaire=m_points[m_links[i]->get_id_a()]->get_marked();
                                 for(z=0;z<m_points.size();z++)
                                 {
                                     if (intermediaire==m_points[z]->get_marked())
                                     m_points[z]->set_marked(m_points[m_links[i]->get_id_b()]->get_marked());
                                 }
                  }
        std::cout<< "j'ai trouve mon copain le bug"<<std::endl;
                 if (verif1==1)  /// si l'ordi est passé par une des deux condition en haut -> qu les deux points n'était pas relié et que verif =1 donc on ajoute le lien
                    inter.add_link(m_links[i]);
                                std::cout<< "tout va bien ici"<<std::endl;
                  for(z=0;z<m_points.size()&&verif2!=1;z++)
                  {
                             if (verif3!=m_points[z]->get_marked())
                             {
                                verif2=1;                                        /// tant que tous les points n'ont pas 0 comme marque la verif est caduc
                             }

                  }
                }

                /// reset les points pour être sur que quoi que l'on demande après tout aille bien
            for(z=0;z<m_points.size();z++)
                         {
                            m_points[z]->reset_mark();
                         }
            std::cout << "voici kruskal Anais je t'aime" <<std::endl;
            apm=new Path(inter);
            apm->afficher_path();
}





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
	Path* apm;
//	std::cout<<chemin.size()<<std::endl;
//std::cout<< " a paprtir d'ici"<<std::endl;
	for( i=0;i<chemin_pareto.size();i++)
    {

        chemin_pareto[i]->afficher_path();
        std::cout<<"cout 1        "<<chemin_pareto[i]->get_tot1()<< "et     "<<chemin_pareto[i]->get_tot2()<<std::endl;
    }
    kruskal(test.get_m_link(),apm,test.get_m_points());
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

