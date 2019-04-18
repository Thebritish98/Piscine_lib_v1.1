#include "Graphe.h"


Coord::Coord(short x, short y): m_x{x}, m_y {y}
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

namespace thg
{

//------------------GRAPH------------------
Graph::Graph(std::string _FileName)
{
    std::string value;
    std::ifstream file1{ _FileName + ".txt" };		//Ouvre le fichier .txt demandé
    std::cout << "Quelle chiffre de fichier?";
    std::cin >> value;								//On choisit ici quel fichier d epoids on veut ouvrir avec
    std::ifstream file2{ _FileName + "_weights_" + value +".txt" };	//Ouverture du fichier cité au dessus
    if (!file1 || !file2)
        throw std::runtime_error("Impossible d'ouvrir en lecture " + _FileName +".txt ou "+ _FileName + "_weights_" + value + ".txt");	//lance une erreur si le fichier ne peux pas s'ouvrir car n'existe pas
    if (file1.fail() || file2.fail())
        throw std::runtime_error("Probleme lecture ordre du graphe");

    //Création des variables necessaire à la récupération des coordonnées
    unsigned int NbPoints;
    short x=0;
    short y=0;
    unsigned int id;
    file1 >> NbPoints;


    //création des sommets avec Coords///
    for (unsigned int i = 0; i < NbPoints; i++) //Tant que tous les points ne sont pas ajoutés
    {
        file1 >> id;
        if (file1.fail())
            throw std::runtime_error("Probleme de lecture des données");
        file1 >> x;
        if (file1.fail())
            throw std::runtime_error("Probleme de lecture des données");
        file1 >> y;
        if (file1.fail())
            throw std::runtime_error("Probleme de lecture des données");
        m_points.push_back(new Point(id, x,y ) );
    }
    //Déclaration des variables nécessaire à la création des arrêtes//
    unsigned int NbLinks;
    unsigned int NbLinks2;
    float weight1;
    float weight2;
    short mid_x_link=0;
    short mid_y_link=0;
    short Point_A_x;
    short Point_A_y;
    short Point_B_x;
    short Point_B_y;
    unsigned int id_A;
    unsigned int id_B;
    char mode;

    file1 >> NbLinks;
    if (file1.fail())
        throw std::runtime_error("Probleme de lecture des données");
    file2 >> NbLinks2;
    if (file2.fail())
        throw std::runtime_error("Probleme de lecture des données");
    file2 >> id;
    if (file2.fail())
        throw std::runtime_error("Probleme de lecture des données");

    if (NbLinks != NbLinks2)//Si le nombre d'arrête du fichier 1 et 2 sont différentes alors on lance une erreur
        throw std::runtime_error("Nombre d'arrete différents dans les fichiers");
    for (unsigned int i = 0; i < NbLinks; i++)
    {
        file1 >> id;
        file2 >> id;//Trouver moyen de passer directement à la suite//
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

        if (Point_A_x==Point_B_x)
        {
            mode = 'v';
        }
        else if (Point_A_y == Point_B_y)
        {
            mode = 'h';
        }
        else
        {
            if ((Point_A_x<Point_B_x && Point_A_y < Point_B_y)||(Point_B_x < Point_A_x && Point_B_y < Point_A_y))
            {
                mode = 'l';
            }
            else
            {
                mode = 'r';
            }
        }


        Link* ptLink = new Link(id, weight1, weight2, id_A, id_B, {mid_x_link,mid_y_link}, mode);
        m_links.push_back(ptLink  ); //On aoute toutes les valeurs récupérer sur l'arrête dans la map comprise dans le graphe

        //Ajout des voisins dans les données des points
        m_points[id_A]->addNeighboor(ptLink, id_B);//Ajout de la liaison entre A et B
        m_points[id_B]->addNeighboor(ptLink, id_A);//Ajout de la liaison entre B et A
    }
    file1.close();
    file2.close();

}


//A REMETTRE
/*void Graph::BFS_show(std::string _StartingEdge) const
{
	Point* s0 = (m_points.find(_StartingEdge))->second;
	std::unordered_map<std::string, std::string> l_pred;
	std::cout << "BFS_course a partir de " << _StartingEdge << " :" << std::endl;
	l_pred = s0->BFS_course();
	for (auto s : l_pred) {
		std::cout << s.first << " <--- ";
		std::pair<std::string, std::string> pred = s;
		while (pred.second != _StartingEdge) {
			pred = *l_pred.find(pred.second);
			std::cout << pred.first << " <--- ";
		}
		std::cout << _StartingEdge << std::endl;
	}
}

void Graph::DFS_show(std::string _StartingEdge) const
{
	Point* s0 = (m_points.find(_StartingEdge))->second;
	std::unordered_map<std::string, std::string> l_pred;
	std::cout << "DFS_course a partir de " << _StartingEdge << " :" << std::endl;
	l_pred = s0->DFS_course();
	for (auto s : l_pred) {
		std::cout << s.first << " <--- ";
		std::pair<std::string, std::string> pred = s;
		while (pred.second != _StartingEdge) {
			pred = *l_pred.find(pred.second);
			std::cout << pred.first << " <--- ";
		}
		std::cout << _StartingEdge << std::endl;
	}
}

void Graph::BFS_course(std::string _StartingEdge) const
{
	Point* s0 = (m_points.find(_StartingEdge))->second;
	std::unordered_map<std::string, std::string> l_pred;
	l_pred = s0->BFS_course();
}

void Graph::DFS_course(std::string _StartingEdge) const
{
	Point* s0 = (m_points.find(_StartingEdge))->second;
	std::unordered_map<std::string, std::string> l_pred;
	l_pred = s0->DFS_course();
}

//std::unordered_map<Point*, std::list<Point*>> Graph::smaller_travel(const Point& _DepartPoint, bool reverse = false) const
	/**
	This function do the Djisktra's algorithm in smallest or biggest travel distance, return an unordered map with The depart point and the list of all points to travel through
	**/
//{
//Declaration d'une unordered map avec id et unsigned int (valeur des arêtes)
//}

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



/*int Graph::research_show_CC() const
{
	int i = 0;
	std::unordered_set<std::string> comp_co;
	std::cout << std::endl;
	for (const auto& it : m_points)                                    //pointeur auto qui va prendre tous les Points
	{

		if (comp_co.count(it.second->get_id()) == 0)               //condition de verification pour voir si le Point est dans la liste
		{
			++i;
			std::cout << "cc" << i << ":" << std::endl;
			it.second->researchCC(comp_co);                       //va rechercher les composantes connexes du Point sélectionner
			std::cout << std::endl;

		}
	}
	return i;
}
*/
void Graph::show_svg(Svgfile& _out,bool _show_info)
{
    /**
    Affiche le svg du graphe, update necessaire: ajouter un moyen de donner le point de référence depuis lequel tracer le graphe / Donner les coûts des arrêtes
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




/*					PARTIE A REMETTRE SANS BUG

std::unordered_map<std::string, std::string> Point::BFS_course() const
{
	std::unordered_map<std::string, std::string> l_pred;
	std::queue<const Point*> file;
	file.push(this);//on ajoute l'element actuel dans la file
	const Point* s;
	std::vector<Point*> list_point; /// A changer si mieux
	do {
		s = file.front();//on recupere le Point de tete
		file.pop();
		for (const auto& it : s->get_neighboors)
		{
			if (l_pred.find(it.first.m_id)==(l_pred.end()) && (it.first != this))
			{
				file.push(it.first);
				l_pred.insert({ it.first.m_id,it.m_id });
			}
		}

	} while (!file.empty());//on entre dans la boucle tant que la file n'est pas vide

	return l_pred;
}
std::unordered_map<std::string, std::string> Point::DFS_course() const
{
	std::unordered_map<std::string, std::string> l_pred;
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
}

void Point::researchCC(std::unordered_set<std::string> & _cc) const
{
	_cc.insert(m_id);
	std::cout << m_id << "   ";
	for (const auto& it : m_neighboors)
	{
		if (_cc.count(it.first->m_id) == 0)
			std::cout << it.second.get_weight();
		it.first->researchCC(_cc);/// on recherche tous les voisins par reconnaissance de parité
	}
}

void Point::research_ps(int& _parity) const
{
	if (m_neighboors.size() % 2 != 0)
		_parity = 1;
}*/

Point::~Point()
{
}


//------------------LINK------------------
Link::Link(unsigned int _id, float _cost1, float _cost2, unsigned int _a, unsigned int _b, Coord _mid_link, char _mode) : m_id{ _id }, m_cost1{ _cost1 }, m_cost2{ _cost2 }, m_point_A{ _a }, m_point_B{ _b }, m_mode{ _mode }, m_coord_text{_mid_link}
{
    //std::cout << "Link constructor id:" << m_id + " " << m_cost1 << " " << m_cost2 << " " << m_point_A << " " << m_point_B << std::endl;
}

Link::~Link()
{
}


}
