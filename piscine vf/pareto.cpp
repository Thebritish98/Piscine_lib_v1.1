#include  "main.h"



// bool Point::ordre_sommet();


/// test original garder pour montrer qu'on a chercher
//int  test (Path test,Graph &graph)
//{
//    int i,y,verif=0, verif2=0 ,verif3 =0;
//  for (i=0;i<test.get_trace_size();i++)
//  {
//  // std::cout << "yolo " <<graph.get_m_points()[test.get_trace()[y]->get_id_b()]->get_marked() <<" et  " <<graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked() << std::endl;
//        if (graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked()==350&&graph.get_m_points()[test.get_trace()[i]->get_id_b()]->get_marked()==350)
//            verif3=1;
//      if(graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked()==0)
//        verif=1;
//      if(graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked()!=0&&graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked()!=350)
//            {
//                verif2+=graph.get_m_points()[test.get_trace()[i]->get_id_a()]->get_marked();
//                graph.get_m_points()[test.get_trace()[i]->get_id_a()]->set_marked(350);
//            }
//      if(graph.get_m_points()[test.get_trace()[i]->get_id_b()]->get_marked()==0)
//          verif=1;
//      if (graph.get_m_points()[test.get_trace()[i]->get_id_b()]->get_marked()!=0&&graph.get_m_points()[test.get_trace()[i]->get_id_b()]->get_marked()!=350)
//      {
//          verif2+=graph.get_m_points()[test.get_trace()[i]->get_id_b()]->get_marked();
//          graph.get_m_points()[test.get_trace()[i]->get_id_b()]->set_marked(350);
//      }
//
//  }
//  if (verif==1&& verif3==0)
//      return verif2;
//  else return 0;
//}

/// test approximation bfs montrer qu'on a chercher
//int bfs(Path test,Graph graph )
//{
//    int i,y,z;
//    std::vector<Point> bfs;
//    std::vector<unsigned int > voisin;
//    bfs.push_back(*graph.get_m_points()[0]);
//    bfs[0].set_marked(0);
//      voisin=bfs[0].get_neigh_id();
//std::cout << "ici ok "<<std::endl;
// for(z=0;z<graph.get_m_points().size();z++)
//   {
//    for(i=0;i<voisin.size();i++)
//    {
//      //  std::cout << "ici ok2 "<<std::endl;
//        bfs.push_back(*graph.get_m_points()[voisin[i]]);
//    }
//    for(i=0;i<bfs.size();i++)
//    {
//        if(bfs[i].get_marked()!=0)
//        {//std::cout << "ici ok3 "<<std::endl;
//            for(y=0;y<bfs[i].get_neigh_id().size();y++)
//            voisin.push_back(bfs[i].get_neigh_id()[y]);
//
//            bfs[i].set_marked(0);
//        }
//    }
//   }
//   //std::cout << "ici ok4 "<<std::endl;
//   if (bfs.size()==graph.get_m_points().size())
//    return 1;
//   else
//    return 0;
//}


void get_path(Graph &graph,std::vector<Path*> &chemin_possible)
{
  unsigned  int i,j,y,z=0,nblien,verif1,verif2,verif3,nbtour=0,nb2tour=0,nbtour3=0,valueon, intermediaire;
    int nbmark=0, nbmark2;
std::cout<<"dans le code"<< std::endl;
    Path try_it;

    for(i=0;i<graph.get_m_points().size();i++)
        nbmark+=graph.get_m_points()[i]->get_marked();

    for(i=0;i<pow(2,graph.get_m_link().size());i++)
    {

               nblien=std::bitset<32>(i).count();

                if (nblien==(graph.get_m_points().size()-1)) /// si le chemin a arrete == ordre n-1
            {
                 std::string chaine = (std::bitset<32>(i).to_string()).substr((char)32 - (char)graph.get_m_link().size(), 31);
                    try_it.reset();
                    for (j=0;j<chaine.size();j++)/// Creer le path en arrette et non en booléen
                    {
                        if(chaine[j]=='1')
                        {
                                    try_it.add_link(graph.get_m_link()[j]);
                        }
                    }
                            Graph to_test{try_it,graph};
                        verif1=0;
                        verif2=0;
                        ///test connexe a refaire
                           ///test connexe a refaire
                        /// La mon Ptitlu il faudrais qu'on fasse le tableau de connexité pour s'assurer que le graphe est connexe
                        /// vu que chez moi ici ça compile pas je te l'écrit en francais
                        /// pour chque lien //
                        ///le point a et le point b  du lien selectionne on regarde lequel est le plus bas ici a pour l'exemple
                            ///alors la mark de b et tous les points dont la mark = la mark de b prennent la mark de a .
                        /// si tous les points on la même marque le graph est entiérement connecter.
                        /// ce qui suit est LA CONDITION A AVOIR
                        /// il est cependant interdit d'avoir un lien dont le point A et B ont la même ID
                        /// si les conditoin sont validé il faut activé la ligne 53
                        /// bisous

                        /// Ps je t'ai fait des zolies get et set pour te donner du courage
                        verif3=0;
//                        for(y=0;y<try_it.get_trace_size();y++)
//                        {
//
//                        }


//
//                         for (y=0;y<try_it.get_trace_size();y++)
//                         {
//
//                             if (graph.get_m_points()[try_it.get_trace()[y]->get_id_a()]->get_marked()<graph.get_m_points()[try_it.get_trace()[y]->get_id_b()]->get_marked()) // si la marque de a est inferieur a la marque de b
//                             {
//
//                                 intermediaire=graph.get_m_points()[try_it.get_trace()[y]->get_id_b()]->get_marked();// inter = mark b
//
//                                 for(z=0;z<graph.get_m_points().size();z++)// pour tous les points de get_m point
//                                 {
//
//                                     if (intermediaire==graph.get_m_points()[z]->get_marked())    // si leur mark = a la mark d'intermediaire et donc de b
//                                     graph.get_m_points()[z]->set_marked(graph.get_m_points()[try_it.get_trace()[y]->get_id_a()]->get_marked());// elles prennent la valeur de la mark de a
//                                 }
//                             }
//                             else if (graph.get_m_points()[try_it.get_trace()[y]->get_id_a()]->get_marked()>graph.get_m_points()[try_it.get_trace()[y]->get_id_b()]->get_marked())
//                             {
//                                 intermediaire=graph.get_m_points()[try_it.get_trace()[y]->get_id_a()]->get_marked();
//
//                                 for(z=0;z<graph.get_m_points().size();z++)
//                                 {
//                                                   if (intermediaire==graph.get_m_points()[z]->get_marked())
//                                     graph.get_m_points()[z]->set_marked(graph.get_m_points()[try_it.get_trace()[y]->get_id_b()]->get_marked());
//                                 }
//                             }
//                         }
//                         for(z=0;z<graph.get_m_points().size()&&verif2!=1;z++)
//                         {
//                            // std::cout << "bernard ici tout va bien " <<std::endl;
//                             if (verif1!=graph.get_m_points()[z]->get_marked())
//                             {
//                                verif2=1;
//                              //  std::cout <<"verif 2 =1 ici" <<std::endl;
//                             }
//                              //  std::cout <<"  graph get m point size" << graph.get_m_points().size() <<std::endl;
//                        }
//std::cout <<"cherche bug" <<nbmark <<"et  " << nbmark2 << std::endl;

                         if (to_test.bfsTestConnexite(graph.get_m_points().size())==true)
                         {
                            chemin_possible.push_back(new Path(try_it));
                           // std::cout << "Iri ici tout va bien " <<std::endl;
                         }

                         for(z=0;z<graph.get_m_points().size();z++)
                         {
                             graph.get_m_points()[z]->reset_mark();
                         }









//                        for (y=0;y<try_it.get_trace_size();y++) /// test si il est connexe
//                        {
//                            for (z=0;z<graph.get_m_points().size();z++)
//                            {
//                                    if(try_it.get_trace()[y]->get_id_a()==graph.get_m_points()[z]->get_id())
//                                 {
//                                     if(selection_point[z]==0)
//                                        selection_point[z]=1;
//                                     else
//                                        verif1=1;
//                                 }
//                                 if(try_it.get_trace()[y]->get_id_b()==graph.get_m_points()[z]->get_id())
//                                 {
//                                 if(selection_point[z]==0)
//                                    selection_point[z]=1;
//                                 else
//                                    verif2=1;
//                             }
//
//                        }
                    }
//                     if (verif1!=1||verif2!=1)
//                             {
///** Tu ajoutes try it la valeur de try it qui est une variable déclaré dans la fonction mais qui disparais après alors ton chemin pointe juste sur une adresse mémoire**/
//                                 chemin_possible.push_back(new Path(try_it));  /// si il ne l'est pas l'ajoute aux chemin possible pour pareto
//                                 //chemin_possible.push_back(&try_it);  /// si il ne l'est pas l'ajoute aux chemin possible pour pareto
//
//                             }
            }
//               	for(i=0;i<chemin_possible.size();i++)
//    {
//                    //     std::cout <<" Chemin qui devrait etre bon "<<i<<std::endl;
//                     //    chemin_possible[i]->afficher_path();
//
//
//    }
std::cout <<    " nb chemin a redefinir " <<chemin_possible.size() <<std::endl;
std::cout <<"nbtour" <<nbtour <<std::endl;
    }
   // std::cout<< "test1 ok "<< nbtour<<std::endl;
    // std::cout<< "testzrafvg ok "<< nb2tour<<std::endl;
//     std::cout<<"ajout_try_it"<<nbtour3<<std::endl;
  //  std::cout<<" nombre d'input a la verif d'après"<<chemin_possible.size()<<std::endl;
   // std::cout<<"tot 1 ici" << chemin_possible[0]->get_tot1()<<std::endl; /// ici est toujours bon
//}

  void pareto_verif( std::vector <Path*> &chemin_possible, std::vector<Path*> &chemin_pareto ) // Algo qui efface tous les chemins qui ne sont pas pareto optimo
{

    unsigned int  i,y,nbtour=0,nbtour2=0,verif=0;
   //std::cout<<"  lol est chaud " <<chemin_possible.size()<<std::endl;
    for(i=0;i<chemin_possible.size();i++)
        {
            verif=0;

        for(y=0;y<chemin_possible.size()&&verif!=1;y++)
        {

            if(y!=i)
           {

                 if(chemin_possible[i]->get_tot1()>chemin_possible[y]->get_tot1()&&chemin_possible[i]->get_tot2()>= chemin_possible[y]->get_tot2())
                 {
                          verif=1;
                 }
                 else if(chemin_possible[i]->get_tot1()>=chemin_possible[y]->get_tot1()&&chemin_possible[i]->get_tot2()> chemin_possible[y]->get_tot2())
                 {
                          verif=1;
                 }
//                 else if (chemin_possible[i]->get_tot1()==chemin_possible[y]->get_tot1()&&chemin_possible[i]->get_tot2(
           }
        }
       // std::cout <<std::endl<<" verif " <<verif <<std::endl;
        if(verif==0)
        {
            chemin_pareto.push_back(chemin_possible[i]);
          //  chemin_possible[i]->afficher_path();
        }

    }
  //  std::cout<<"nb de truc efface  " <<nbtour<<std::endl;
  std::cout<< "taille de chemin pareto  "<<chemin_pareto.size()<<std::endl;
   // std::cout<< "nombre de truc pouvant etre efface"<<nbtour2<<std::endl;
}



//    float dijk_on_point(Graph graph,Path chemin )
//    {
//        int i=0,y,verif=0;
//        int mark=graph.get_m_points()+1;
//        Graph sous_graph(chemin,graph);
//        Link* lien;
//        lien nul;
//         while(verif!=0)///tant que je le veux
//        {
//            for(y=0; y<sous_graphe.get_m_points()[i].get_neighboors().size();y++)///on ajoute les lien voisin du points
//                lien->push_back(sous_graphe.get_m_points()[i].get_neighboors()[y]);///
//            get_m_points()[i]->set_marked(mark);
//            fot((y=0;y<lien.size();y++)
//                {
//                    if
//                }
//            i++
//        }
//    }








    void pareto_verif_points(std::vector <float> &cost1,std::vector<float> &cost2,std::vector<Path*> &pareto,std::vector<Path*> &maybe, std::vector<float> &pareto_cost1,std::vector<float> &pareto_cost2)
{
                int i,y,verif=0;
                for(i=0;i<cost1.size();i++)
                {
                    verif=0;
                        for (y=0;y<cost1.size();y++)
                    {
                                if(i!=y)
                        {
                                    if (cost1[i]>cost1[y]&&cost2[i]>=cost2[y])
                                            verif=1;

                                else if (cost1[i]>=cost1[y]&&cost2[i]>cost2[y])
                                            verif=1;

                        }
                    }
                    if ( verif==0)
                            {
                                pareto_cost1.push_back(cost1[i]);
                                pareto_cost2.push_back(cost2[i]);
                                pareto.push_back(maybe[i]);
                            }
                }

}





float Djisktra_for_weight(Path& _path,Graph& _graph,unsigned int _Starting_point)
{
    ///INITIALISATOPO?
    bool nend=false;
    Graph test(_path, _graph);
    float returned_value=0;//va contenir total cout1 et total cout2
    Point* pt_points;
    std::vector<Point*> list_unvisited_point;
    for (size_t i = 0; i < test.get_m_points().size(); i++)
    {
        if(test.get_m_points()[i] !=test.get_m_points()[_Starting_point])
            list_unvisited_point.push_back(test.get_m_points()[i]);
    }
    float weight=0;
    Point* smallest_weight_point;
    pt_points = test.get_m_points()[_Starting_point];
    /// PROCESS
    while (!nend)//liste non vide
    {
      //  std::cout << "tant que pas fini " <<std::endl;
        pt_points->set_marked(test.get_m_points().size());///NOUS MARQUONS LE POINT ACTUEL
        weight = pt_points->get_weight();/// POID = POID DU POINT ??????????       ???????????                              on récupère le poids du sommet sur lequel on est actuellement !!
        returned_value += weight; ///solution de départ += distance/poid                             //on ajoute son poids au total cout2 que l'on va renvoyer
        //actualise les valeurs si plus petites
        for (const auto& at : pt_points->get_neighboors())///pour tous les liens relié au points
        {
            int idb = ((at->get_id_b()==pt_points->get_id())?at->get_id_a():at->get_id_b());

            if ((at->get_cos2()+ weight <= test.get_m_points()[idb]->get_weight()||test.get_m_points()[idb]->get_weight()==0) && test.get_m_points()[idb]->get_marked()!= test.get_m_points().size())//si le poids depuis ce chemin est inférieur à celui trouver précédemment
            {
             //   std::cout << "Poid mis a jour " <<std::endl;
                test.get_m_points()[idb]->set_pred(pt_points->get_id());//on dit que le précédent est ce point (pt_points)
                test.get_m_points()[idb]->set_weight(at->get_cos2() + weight);//on update le poids du points
            }
        }
        //pointe sur la plus petite valeur
        if (list_unvisited_point.empty())
        {
            nend = true;
        }
        else
        {
            for (const auto& it : list_unvisited_point)//trouve le poids le plus petit
            {

                if (it->get_weight() <= smallest_weight_point->get_weight())
                {
                    // std::cout<<  "somme selectione" <<smallest_weight_point->get_id() <<std::endl;
                    smallest_weight_point = it;
                }
            }
            pt_points = smallest_weight_point;
          //  list_unvisited_point.pop_back(std::find(list_unvisited_point.begin(), list_unvisited_point.end(), pt_points));
          if(std::find(list_unvisited_point.begin(), list_unvisited_point.end(), pt_points)!=list_unvisited_point.end()))
            list_unvisited_point.erase(std::find(list_unvisited_point.begin(), list_unvisited_point.end(), pt_points));//efface de la liste le point selectionné pour la prochaine boucle
        }

    }
    //reset side
    for (const auto& it : test.get_m_points())
    {
                       // std::cout <<" stuck? " <<std::endl;
        it->reset_mark();
        it->set_weight(0);
        it->set_pred(test.get_m_points().size());
    }
    return returned_value;
}

float Total_cout2(Path& _path, Graph& _graph)
{
    float returned_value=0;
    for (unsigned int i = 0; i < _graph.get_m_points().size(); i++)
    {
        returned_value += Djisktra_for_weight(_path, _graph, i);
    }
    return returned_value;
}





void dijkstra
(Graph graph, std::vector<Path*> &chemin_pareto_dijkstra, std::vector<float> & cost1_pareto ,std::vector<float> & cost2_pareto,std::vector<Path*> &chemin_dijkstra,std::vector<float> &cos1temp,std::vector<float> &cos2temp)
{
    Path try_it;
    int nblien;
    int j,i,y,z;


            for(i=0;i<pow(2,graph.get_m_link().size());i++)
    {

               nblien=std::bitset<32>(i).count();

                if (nblien>=(graph.get_m_points().size()-1)) /// si le chemin a arrete == ordre n-1
            {
             //   std::cout << "a";
                 std::string chaine = (std::bitset<32>(i).to_string()).substr((char)32 - (char)graph.get_m_link().size(), 31);
                    try_it.reset();
                    for (j=0;j<chaine.size();j++)/// Creer le path en arrette et non en booléen
                    {

                        if(chaine[j]=='1')
                        {

                                    try_it.add_link(graph.get_m_link()[j]);
                        }
                    }  //   std::cout <<"avant algo dijkstra n fois " <<std::endl;
                            for (y=0;y<try_it.get_trace_size();y++)  /// on constitue des vecteurs.
                            {


                                cos2temp.push_back (Total_cout2(try_it,graph));
                                cos1temp.push_back(try_it.get_tot1());
                                chemin_dijkstra.push_back(new Path(try_it));

                            }
                                //    std::cout<< "ici";
                          //  std::cout <<"avant tri/pareto verif" <<std::endl;
                            pareto_verif_points(cos1temp,cos2temp,chemin_pareto_dijkstra,chemin_dijkstra,cost1_pareto,cost2_pareto);
            }

    }

//    for (z=0;z<cos2temp.size();z++)
                       // std::cout <<"  point après vérif " <<cos2temp[z] <<std::endl;

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



