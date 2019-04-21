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

	//------------------GRAPH------------------

Graph::Graph(Path& _copy_path, Graph& _base_graph) :m_points{ _base_graph.get_m_points() }, m_links{_copy_path.get_trace()}
{
}

Graph::Graph(std::string _FileName)
{
	m_model_name = _FileName;
	_FileName = "ressource/" + _FileName; //add files name in directory path to ensure finding the files
	std::string value;
	std::ifstream file1{ _FileName + ".txt" };		//Ouvre le fichier .txt demandÃ©
	std::cout << "Quelle chiffre de fichier?\n";
	std::cin >> value;								//On choisit ici quel fichier de poids on veut ouvrir avec
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


			file1 >> id; file2 >> id;//Trouver moyen de passer directement à la suite//
			file1 >> id_A;//On récupère l'id du point de départ
			file1 >> id_B;//On récupère l'id du point de destination
			file2 >> weight1;//On récupère dans le deuxième fichier le premier poids
			file2 >> weight2;//puis le deuxième

			Point_A_x = m_points[id_A]->get_coord().get_x();
			Point_A_y = m_points[id_A]->get_coord().get_y();
			Point_B_x = m_points[id_B]->get_coord().get_x();
			Point_B_y = m_points[id_B]->get_coord().get_y();

			//Calcul avec la différence des coord id_A et id_B lpour avoir coord_text
			mid_x_link = (Point_A_x + Point_B_x) / 2;
			mid_y_link = (Point_A_y + Point_B_y) / 2;
			//Recherche du mode de l'arrête:

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
			m_links.push_back(ptLink); //On aoute toutes les valeurs récupérer sur l'arrête dans la map comprise dans le graphe

			//Ajout des voisins dans les données des points
			m_points[id_A]->addNeighboor(ptLink, id_B);//Ajout de la liaison entre A et B
			m_points[id_B]->addNeighboor(ptLink, id_A);//Ajout de la liaison entre B et A
	}
	file1.close();
	file2.close();

}
void Graph::reload(std::string _FileName)
{
	m_model_name = _FileName;
	for (size_t i = 0; i < m_points.size(); i++)
	{
		m_points.pop_back();
	}
	for (size_t i = 0; i < m_links.size(); i++)
	{
		m_links.pop_back();
	}
	_FileName = "ressource/" + _FileName; //add files name in directory path to ensure finding the files
	std::string value;
	std::ifstream file1{ _FileName + ".txt" };		//Ouvre le fichier .txt demandé
	std::cout << "Quelle chiffre de fichier?";
	std::cin >> value;								//On choisit ici quel fichier de poids on veut ouvrir avec
	std::ifstream file2{ _FileName + "_weights_" + value + ".txt" };	//Ouverture du fichier cité au dessus
	if (!file1 || !file2)
		throw std::runtime_error("Impossible d'ouvrir en lecture " + _FileName + ".txt ou " + _FileName + "_weights_" + value + ".txt");	//lance une erreur si le fichier ne peux pas s'ouvrir car n'existe pas
	if (file1.fail() || file2.fail())
		throw std::runtime_error("Probleme lecture ordre du graphe");

	//Création des variables necessaire à la récupération des coordonnées
	unsigned int NbPoints;
	short x = 0;
	short y = 0;
	unsigned int id;
	file1 >> NbPoints;


	//création des sommets avec Coords///
	for (unsigned int i = 0; i < NbPoints; i++) //Tant que tous les points ne sont pas ajoutés
	{
		file1 >> id; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
		file1 >> x; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
		file1 >> y; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
		m_points.push_back(new Point(id, x, y));
	}
	//Déclaration des variables nécessaire à la création des arrêtes//
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

	file1 >> NbLinks; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
	file2 >> NbLinks2; if (file2.fail()) throw std::runtime_error("Probleme de lecture des données");
	file2 >> id; if (file2.fail()) throw std::runtime_error("Probleme de lecture des données");

	if (NbLinks != NbLinks2)//Si le nombre d'arrête du fichier 1 et 2 sont différentes alors on lance une erreur
		throw std::runtime_error("Nombre d'arrete différents dans les fichiers");
	for (unsigned int i = 0; i < NbLinks; i++)
	{


			file1 >> id; file2 >> id;//Trouver moyen de passer directement � la suite//
			file1 >> id_A;//On r�cup�re l'id du point de d�part
			file1 >> id_B;//On r�cup�re l'id du point de destination
			file2 >> weight1;//On r�cup�re dans le deuxi�me fichier le premier poids
			file2 >> weight2;//puis le deuxi�me

			Point_A_x = m_points[id_A]->get_coord().get_x();
			Point_A_y = m_points[id_A]->get_coord().get_y();
			Point_B_x = m_points[id_B]->get_coord().get_x();
			Point_B_y = m_points[id_B]->get_coord().get_y();

			//Calcul avec la diff�rence des coord id_A et id_B lpour avoir coord_text
			mid_x_link = (Point_A_x + Point_B_x) / 2;
			mid_y_link = (Point_A_y + Point_B_y) / 2;
			//Recherche du mode de l'arr�te:

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
			m_links.push_back(ptLink); //On aoute toutes les valeurs r�cup�rer sur l'arr�te dans la map comprise dans le graphe

			//Ajout des voisins dans les donn�es des points
			m_points[id_A]->addNeighboor(ptLink,id_B);//Ajout de la liaison entre A et B
			m_points[id_B]->addNeighboor(ptLink, id_A);//Ajout de la liaison entre B et A
		}
		file1.close();
		file2.close();

	}

	Graph::~Graph()
	{
	}


	std::vector<Path*> Graph::Djisktra_for_path(Graph& _graph,unsigned int _id)
{
		/*Le programme qui l'appelle le fait pour chaque sommet*/
		std::vector<Path*> test;
	return test;
}

void Graph::Djisktra_for_weight(Graph& _graph)
{
}
bool Graph::bfsTestConnexite(int nombreTotalSommets)
{
	std::vector<bool> discovered;
	discovered.resize(nombreTotalSommets);
	std::queue<const Point*> file;
	int nbSommetsDansLaCC = 1;

	file.push(m_points[0]);
	discovered[0] = true;

	while (!(file.empty()))
	{

		for (auto s : file.front()->get_neighboors())
		{
			if (!discovered[get_m_points()[(s)->get_id_b()]->get_id()] )
			{
				file.push(m_points[get_m_points()[(s)->get_id_b()]->get_id()]);
				discovered[get_m_points()[(s)->get_id_b()]->get_id()] = true;
			}
		}
		file.pop();
		nbSommetsDansLaCC++;
	}

	return (nbSommetsDansLaCC ==  nombreTotalSommets);
}


//------------------POINT------------------
Point::Point(unsigned int _id, short _x, short _y) :m_id{ _id }, m_Coord {_x,_y},m_marked{_id}
{
}
void Point::addNeighboor( Link* _link, unsigned int _id)
	/**
	Ajout de voisin dans la liste
	**/
{
	m_neighboors.push_back( _link);
	m_neighboors_id.push_back( _id);
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



