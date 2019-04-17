#include  "main.h"


void get_path(Graph graph,std::vector<Path*> chemin_possible)
{
    int i,j,y,nblien,verif1,verif2,verif3,verif4;

    Path try_it;
    std::vector<int> keep_trying;

    for(i=0;i=pow(2,graph.get_size_m_link());i++)
    {
        std::string chaine = (std::bitset<36>(i).to_string()).substr((char)35 - (char)graph.get_size_m_link(), 34);// pour chaque cas
        nblien=0;
            for (j=0;j<chaine.size();j++)
            {
                nblien+=chaine[j];
                std::cout<< nblien << std::endl;
            }
                if (j==(graph.get_size_m_point()-1))
            {
                    try_it.reset();
                    for (j=0;j<chaine.size();j++)
                    {
                        if(chaine[j]==1)
                        {
                                try_it.add_link(graph->m_links[j]);
                        }
                    }
                    /// Verif que tous les sommets sont présent dans le chemin try it a terminé
                    /// il faut en meme temps s'assurer qu'il n'y ait pas de boucle ce qui veut dire qu'il ne faut pas que les 2 id d'un lien soit déja présent dans le vecteur keep trying
                    ///pas manger depuis ce matin 4h donc je prend une pause
                    /// après avoir fait la vérif si tout est bon on ajoute le chemin a chemin_possible avec un pushback et est fini :!!!
//                    keep_trying.clear();
//                    verif1=0;
//                    verif2=0;
//                    verif3=0;
//                    verif4=0;
//                    for (y=0;y<try_it.get_trace_size();i++)
//                    {
//                            if(try_it.get_trace()[y].get_id_a==
//                    }

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


