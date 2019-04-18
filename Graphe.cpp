
#include "Graphe.h"


Coord::Coord(short x, short y): m_x{x} , m_y {y}
{
	//std::cout << "(" + x << ";" << y + ")" << std::endl;
}

short Coord::get_x() const
{
	return m_x;
}

short Coord::get_y() const
{
	return m_y;
}

void Coord::mod_c(short _x_add,short _y_add)
{
	m_x += _x_add;
	m_y += _y_add;
}

Coord::~Coord()
{

}

//void pareto_verif(std::vector <Path*>& _possible_link) // Algo qui efface tous les chemins qui ne sont pas pareto optimo
//{
//	unsigned int  i, y;
//	for (i = 0; i < _possible_link.size(); i++)
//	{
//		for (y = 0; y < _possible_link.size(); y++)
//		{
//			if (y != i)
//			{
//				if ((_possible_link[i]->get_sum_w_1() < _possible_link[y]->get_sum_w_1() && _possible_link[i]->get_sum_w_2() <= _possible_link[y]->get_sum_w_2())||(_possible_link[i]->get_sum_w_1() <= _possible_link[y]->get_sum_w_1() && _possible_link[i]->get_sum_w_2() < _possible_link[y]->get_sum_w_2()))
//					_possible_link.erase(_possible_link.begin() + i);
//			}
//		}
//
//	}
//}

//void get_path(Graph& _graph, std::vector <Path*>& _possible_link)
//{
//	unsigned int i, j, y, nblien, verif1, verif2, verif3, verif4;
//
//
//	Path try_it;
//	std::vector<int> keep_trying;
//
//
//	for (i = 0; i <= pow(2, _graph.get_m_link().size()); i++)
//	{
//		std::string chaine = (std::bitset<36>(i).to_string()).substr((char)35 - (char)_graph.get_m_link().size(), 34);// pour chaque cas
//		nblien = 0;
//		for (j = 0; j < chaine.size(); j++)
//		{
//			nblien += chaine[j];
//			std::cout << nblien << std::endl;
//		}
//		if (j == (_graph.get_m_points().size() - 1))
//		{
//			try_it.reset();
//			for (j = 0; j < chaine.size(); j++)
//			{
//				if (chaine[j] == 1)
//				{
//					try_it.add_link(_graph.get_m_link()[j]);
//				}
//			}
//			/// Verif que tous les sommets sont prÃ©sent dans le chemin try it a terminÃ©
//			/// il faut en meme temps s'assurer qu'il n'y ait pas de boucle ce qui veut dire qu'il ne faut pas que les 2 id d'un lien soit dÃ©ja prÃ©sent dans le vecteur keep trying
//			///pas manger depuis ce matin 4h donc je prend une pause
//			/// aprÃ¨s avoir fait la vÃ©rif si tout est bon on ajoute le chemin a _possible_link avec un pushback et est fini :!!!
////                    keep_trying.clear();
////                    verif1=0;
////                    verif2=0;
////                    verif3=0;
////                    verif4=0;
////                    for (y=0;y<try_it.get_trace_size();i++)
////                    {
////                            if(try_it.get_trace()[y].get_id_a==
////                    }
//
//
//		}
//
//
//	}
//}
	//------------------GRAPH------------------
Graph::Graph(std::string _FileName)
{
	_FileName = "ressource/" + _FileName; //add files name in directory path to ensure finding the files
	std::string value;
	std::ifstream file1{ _FileName + ".txt" };		//Ouvre le fichier .txt demandÃ©
	std::cout << "Quelle chiffre de fichier?";
	std::cin >> value;								//On choisit ici quel fichier d epoids on veut ouvrir avec
	std::ifstream file2{ _FileName + "_weights_" + value + ".txt" };	//Ouverture du fichier citÃ© au dessus
	if (!file1 || !file2)
		throw std::runtime_error("Impossible d'ouvrir en lecture " + _FileName + ".txt ou " + _FileName + "_weights_" + value + ".txt");	//lance une erreur si le fichier ne peux pas s'ouvrir car n'existe pas
	if (file1.fail() || file2.fail())
		throw std::runtime_error("Probleme lecture ordre du graphe");

	//CrÃ©ation des variables necessaire Ã  la rÃ©cupÃ©ration des coordonnÃ©es
	unsigned int NbPoints;
	short x = 0;
	short y = 0;
	unsigned int id;
	file1 >> NbPoints;


	//crÃ©ation des sommets avec Coords///
	for (unsigned int i = 0; i < NbPoints; i++) //Tant que tous les points ne sont pas ajoutÃ©s
	{
		file1 >> id; if (file1.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");
		file1 >> x; if (file1.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");
		file1 >> y; if (file1.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");
		m_points.push_back(new Point(id, x, y));
	}
	//DÃ©claration des variables nÃ©cessaire Ã  la crÃ©ation des arrÃªtes//
	unsigned int NbLinks;
	unsigned int NbLinks2;
	float weight1;
	float weight2;
	short mid_x_link = 0;
	short mid_y_link = 0;
	short Point_A_x;
	short Point_A_y;
	short Point_B_x;
	short Point_B_y;
	unsigned int id_A;
	unsigned int id_B;
	char mode;

	file1 >> NbLinks; if (file1.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");
	file2 >> NbLinks2; if (file2.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");
	file2 >> id; if (file2.fail()) throw std::runtime_error("Probleme de lecture des donnÃ©es");

	if (NbLinks != NbLinks2)//Si le nombre d'arrÃªte du fichier 1 et 2 sont diffÃ©rentes alors on lance une erreur
		throw std::runtime_error("Nombre d'arrete diffÃ©rents dans les fichiers");
	for (unsigned int i = 0; i < NbLinks; i++)
	{
		file1 >> id; file2 >> id;//Trouver moyen de passer directement Ã  la suite//
		file1 >> id_A;//On rÃ©cupÃ¨re l'id du point de dÃ©part
		file1 >> id_B;//On rÃ©cupÃ¨re l'id du point de destination
		file2 >> weight1;//On rÃ©cupÃ¨re dans le deuxiÃ¨me fichier le premier poids
		file2 >> weight2;//puis le deuxiÃ¨me

		Point_A_x = m_points[id_A]->get_coord().get_x();
		Point_A_y = m_points[id_A]->get_coord().get_y();
		Point_B_x = m_points[id_B]->get_coord().get_x();
		Point_B_y = m_points[id_B]->get_coord().get_y();
		//Calcul avec la diffÃ©rence des coord id_A et id_B lpour avoir coord_text
		mid_x_link = (Point_A_x + Point_B_x) / 2;
		mid_y_link = (Point_A_y + Point_B_y) / 2;
		//Recherche du mode de l'arrÃªte:

		if (Point_A_x == Point_B_x)
		{
			mode = 'v';
		}
		else if (Point_A_y == Point_B_y)
		{
			mode = 'h';
		}
		else
		{
			if ((Point_A_x < Point_B_x && Point_A_y < Point_B_y) || (Point_B_x < Point_A_x && Point_B_y < Point_A_y))
			{
				mode = 'l';
			}
			else
			{
				mode = 'r';
			}
		}
		Link* ptLink = new Link(id, weight1, weight2, id_A, id_B, { mid_x_link,mid_y_link }, mode);
		m_links.push_back(ptLink); //On aoute toutes les valeurs rÃ©cupÃ©rer sur l'arrÃªte dans la map comprise dans le graphe

		//Ajout des voisins dans les donnÃ©es des points
		m_points[id_A]->addNeighboor(ptLink, id_B);//Ajout de la liaison entre A et B
		m_points[id_B]->addNeighboor(ptLink, id_A);//Ajout de la liaison entre B et A
	}
	file1.close();
	file2.close();
}
Graph Graph::Prim_algorithm(const Point& _DepartPoint) const
{
    Point* sommet = (m_points.find(_DepartPoint))->second;
    //std::unordered_map<std::string, std::string> l_pred;;
    //l_pred = sommet->get_neighboors();
    std::list<std::string> liste;
    std::vector<bool> marquer;

    /*std::unordered_map <Point*> marquer;
    marquer.insert(sommet);*/

    int i,y;
    Link arete;

    for(i=0; i< m_points ; i++) //on marque tous les sommets comme non marquer
        marquer[i] = false;

    marquer[sommet] = true; //on marque le plus sommet en marquer

    //toutes les aretes = m_link
    //tous les sommets =  m_points
    for ( auto s : sommet->get_neighboors() ) //on regarde pour tous les sommets
    {
        if( marquer[s] == false) //si le sommet n'est pas marqué
        {
            while( m_links.size() != m_points.size()-1 )  //on regarde toutes les aretes
            {

                for (auto a : m_links)
                {
          /* ??? */ if ( s.arete.get_cos1()->first < s.arete.get_cos1()->second ) //on prend l'arete qui a le cout minimum
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
    //return Graph();
}
	void Graph::show_svg(Svgfile& _out,bool _show_info)
	{
		/**
		Affiche le svg du graphe, update necessaire: ajouter un moyen de donner le point de rÃ©fÃ©rence depuis lequel tracer le graphe / Donner les coÃ»ts des arrÃªtes
		**/
		for (const auto& it : m_points)
		{
			_out.addCircle(it->get_coord().get_x(), it->get_coord().get_y(), 6);
		}
		for (const auto& at : m_links)
		{
			_out.addLine((m_points[at->get_id_a()])->get_coord().get_x(), (m_points[at->get_id_a()])->get_coord().get_y(), (m_points[at->get_id_b()])->get_coord().get_x(), (m_points[at->get_id_b()])->get_coord().get_y());
			if (_show_info)
			{
				switch (at->get_mode())
				{
				case 'v':
					at->mod_coord_mid(-25, 0);
					break;
				case 'h':
					at->mod_coord_mid(0, -10);
					break;
				case 'r':
					at->mod_coord_mid(-10, -10);
					break;
				case 'l':
					at->mod_coord_mid(5, -10);
					break;
				default:
					break;
				}
				_out.addText(at->get_coord_mid().get_x(), at->get_coord_mid().get_y(), at->weight_show());

			}
		}
	}

	Graph::~Graph()
	{
	}




	//------------------POINT------------------
	Point::Point(unsigned int _id, short _x, short _y) :m_id{ _id }, m_Coord {_x,_y}
	{
	}
	void Point::addNeighboor( Link* _link, unsigned int _id)
		/**
		Ajout de voisin dans la liste
		**/
	{
		m_neighboors.insert({ _link,_id });
	}



	Point::~Point()
	{
	}



	//------------------LINK------------------
	Link::Link(unsigned int _id, float _cost1, float _cost2, unsigned int _a, unsigned int _b, Coord _mid_link , char _mode) : m_id{ _id }, m_cost1{ _cost1 }, m_cost2{ _cost2 }, m_point_A{ _a }, m_point_B{ _b }, m_mode{ _mode }, m_coord_text{_mid_link}
	{
		//std::cout << "Link constructor id:" << m_id + " " << m_cost1 << " " << m_cost2 << " " << m_point_A << " " << m_point_B << std::endl;
	}
	Link::Link(Link& _link_cop)
	{
		m_id = _link_cop.m_id;
		m_cost1 = _link_cop.m_cost1;
		m_cost2 = _link_cop.m_cost2;
		m_point_A = _link_cop.m_point_A;
		m_point_B = _link_cop.m_point_B;
		m_mode = _link_cop.m_mode;
		m_coord_text = _link_cop.m_coord_text;
	}

	Link::~Link()
	{
	}





/*---------------------------------------------------------------------------------

std::unordered_map<unsigned int, unsigned int> Point::BFS_course() const
{
	std::unordered_map<unsigned int, unsigned int> l_pred;
	std::queue<const Point*> file;
	file.push(this);//on ajoute l'element actuel dans la file
	const Point* s;
	std::vector<Point*> list_point; /// A changer si mieux
	do {
		s = file.front();//on recupere le Point de tete
		file.pop();
		for ( const auto& it : s->get_neighboors())
		{
			if (l_pred.find(it.first.get_id())==(l_pred.end()) && (it.first != this))
			{
				file.push(it.first);
				l_pred.insert({ it.first.m_id,it.m_id });
			}
		}

	} while (!file.empty());//on entre dans la boucle tant que la file n'est pas vide

	return l_pred;
}

std::unordered_map<unsigned int, unsigned int> Point::DFS_course() const
{
	std::unordered_map<unsigned int, unsigned int> l_pred;
	std::stack<const Point*> pile;
	const Point* s;
	pile.push(this);
	while (!pile.empty())
	{
		s = pile.top();//on recupere le Point de tete
		pile.pop();
		for (const auto& it : s->get_neighboors)
		{
			if (l_pred.find(it.first.m_id)==(l_pred.end()) && (it.first != this))
			{
				pile.push(it.first);
				l_pred.insert({ it.first.m_id,it.m_id });
			}
		}
	}


	return l_pred;

	std::unordered_map<Point*, std::list<Point*>> Graph::smaller_travel(const Point& _DepartPoint, bool reverse = false) const*/
		/**
		This function do the Djisktra's algorithm in smallest or biggest travel distance, return an unordered map with The depart point and the list of all points to travel through
		**/
		//{
			//Declaration d'une unordered map avec id et unsigned int (valeur des arÃªtes)
		//}

/*

	void Graph::BFS_show(unsigned int _StartingEdge) const
	{
		Point* s0 = m_points[_StartingEdge];
		std::unordered_map<unsigned int, unsigned int> l_pred;
		std::cout << "BFS_course a partir de " << _StartingEdge << " :" << std::endl;
		l_pred = s0->BFS_course();
		for (auto s : l_pred) {
			std::cout << s.first << " <--- ";
			std::pair<unsigned int, unsigned int> pred = s;
			while (pred.second != _StartingEdge) {
				pred = *l_pred.find(pred.second);
				std::cout << pred.first << " <--- ";
			}
			std::cout << _StartingEdge << std::endl;
		}
	}

	void Graph::DFS_show(unsigned int _StartingEdge) const
	{
		Point* s0 =m_points[_StartingEdge];
		std::unordered_map<unsigned int, unsigned int> l_pred;
		std::cout << "DFS_course a partir de " << _StartingEdge << " :" << std::endl;
		l_pred = s0->DFS_course();
		for (auto s : l_pred) {
			std::cout << s.first << " <--- ";
			std::pair<unsigned int, unsigned int> pred = s;
			while (pred.second != _StartingEdge) {
				pred = *l_pred.find(pred.second);
				std::cout << pred.first << " <--- ";
			}
			std::cout << _StartingEdge << std::endl;
		}
	}

	void Graph::BFS_course(unsigned int _StartingEdge) const
	{
		Point* s0 = m_points[_StartingEdge];
		std::unordered_map<unsigned int, unsigned int> l_pred;
		l_pred = s0->BFS_course();
	}

	void Graph::DFS_course(unsigned int _StartingEdge) const
	{
		Point* s0 = m_points[_StartingEdge];
		std::unordered_map<unsigned int, unsigned int> l_pred;
		l_pred = s0->DFS_course();
	}

}*/

