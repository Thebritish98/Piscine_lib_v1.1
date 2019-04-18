
Graph Graph::Prim_algorithm(const Point& _DepartPoint) const
{
	Point* sommet = (m_points.find(_DepartPoint))->second;
	//std::unordered_map<std::string, std::string> l_pred;;
	//l_pred = sommet->get_neighboors();
	std::list<std::string> liste;
	std::vector<bool> marquer;

	/*std::unordered_map <Point*> marquer;
	marquer.insert(sommet);*/

	int i, y;
	Link arete;

	for (i = 0; i < m_points; i++) //on marque tous les sommets comme non marquer
		marquer[i] = false;

	marquer[sommet] = true; //on marque le plus sommet en marquer

	//toutes les aretes = m_link
	//tous les sommets =  m_points
	for (auto s : sommet->get_neighboors()) //on regarde pour tous les sommets
	{
		if (marquer[s] == false) //si le sommet n'est pas marqué
		{
			while (m_links.size() != m_points.size() - 1)  //on regarde toutes les aretes
			{

				for (auto a : m_links)
				{
					/* ??? */ if (s.arete.get_cos1()->first < s.arete.get_cos1()->second) //on prend l'arete qui a le cout minimum
					{
						//if( /*(s.arete->first->marquer != 0)*/ ) //verfie qu'on a pas prit deux fois la meme a
						//{
						liste.push_back(s.arete);//on ajoute l'arete dans la liste de lien
						marquer[s] = true;
						//}
					}

				}

			}
		}

	}
	return liste;
}