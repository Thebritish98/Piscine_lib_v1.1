#include  "main.h"


void get_path(Graph &graph,std::vector<Path*> &chemin_possible)
{
  unsigned  int i,j,y,z,nblien,verif1,verif2;

    Path try_it;
   // std::vector<int> keep_trying;
    std::vector<unsigned int> selection_point;
    std::vector<unsigned int> reset_selec_point;
    for(i=0;i<graph.get_m_points().size();i++)
        selection_point.push_back(0);
    for(i=0;i<graph.get_m_points().size();i++)
        reset_selec_point.push_back(0);
    for(i=0;i<pow(2,graph.get_m_link().size());i++)
    {
               std::string chaine = (std::bitset<36>(i).to_string()).substr((char)35 - (char)graph.get_m_link().size(), 34);// pour chaque cas
               nblien=0;


            for (j=0;j<chaine.size();j++)
            {
                nblien+=chaine[j];
                std::cout<< nblien << std::endl;
            }
                if (j==(graph.get_m_points().size()-1)) /// si le chemin a arretet = ordre n-1
            {
                    try_it.reset();
                    selection_point=reset_selec_point;
                    for (j=0;j<chaine.size();j++)/// Creer le path en arrette et non en booléen
                    {
                        if(chaine[j]==1)
                        {
                                try_it.add_link(graph.get_m_link()[j]);
                        }
                    }
//                    / Verif que tous les sommets sont présent dans le chemin try it a terminé
//                    / il faut en meme temps s'assurer qu'il n'y ait pas de boucle ce qui veut dire qu'il ne faut pas que les 2 id d'un lien soit déja présent dans le vecteur keep trying
//                    /pas manger depuis ce matin 4h donc je prend une pause
//                    / après avoir fait la vérif si tout est bon on ajoute le chemin a chemin_possible avec un pushback et est fini :!!!
                //    keep_trying.clear();
                    verif1=0;
                    verif2=0;
                    for (y=0;y<try_it.get_trace_size();y++) /// test si il est connexe
                    {
                        for (z=0;z<graph.get_m_points().size();z++)
                        {
                             if(try_it.get_trace()[y]->get_id_a()==graph.get_m_points()[z]->get_id())
                             {
                                 if(selection_point[z]==0)
                                    selection_point[z]=1;
                                 else
                                    verif1=1;
                             }
                             if(try_it.get_trace()[y]->get_id_b()==graph.get_m_points()[z]->get_id())
                             {
                                 if(selection_point[z]==0)
                                    selection_point[z]=1;
                                 else
                                    verif2=1;
                             }
                             if (verif1!=1||verif2!=1)
                                chemin_possible.push_back(&try_it);  /// si il ne l'est pas l'ajoute aux chemin possible pour pareto
                        }
                    }

            }


    }
}

  void pareto_verif( std::vector <Path*> chemin_possible ) // Algo qui efface tous les chemins qui ne sont pas pareto optimo
{
    unsigned int  i,y;
    for(i=0;i<chemin_possible.size();i++)
    {
        for(y=0;y<chemin_possible.size();y++)
        {
            if(y!=i)
           {
               if(chemin_possible[i]->get_tot1()<chemin_possible[y]->get_tot1()&&chemin_possible[i]->get_tot2()<=chemin_possible[y]->get_tot2())
                   chemin_possible.erase(chemin_possible.begin()+i);
               else if (chemin_possible[i]->get_tot1()<=chemin_possible[y]->get_tot1()&&chemin_possible[i]->get_tot2()<chemin_possible[y]->get_tot2())
                          chemin_possible.erase(chemin_possible.begin()+i);
           }
        }

    }
}



//  void pareto_verif( vector< Path* > chemin_possible ) // Algo qui efface tous les chemins qui ne sont pas pareto optimo
//{
//    int i,y;
//    for(i=0;i<chemin_possible.size;i++)
//    {
//        for(y=0;y<chemin_possible;y++)
//        {
//            if(y!=i)
//           {
//
//               if(chemin_possible[i]->cout_tot1<chemin_possible[y]->cout_tot1&&chemin_possible[i]->cout_tot2<=chemin_possible[y]->cout_tot2)
//                    chemin_possible[i].erase;
//               else if (chemin_possible[i]->cout_tot1<=chemin_possible[y]->cout_tot1&&chemin_possible[i]->cout_tot2<chemin_possible[y]->cout_tot2)
//                          chemin_possible[i].erase;
//           }
//        }
//
//    }
//}


