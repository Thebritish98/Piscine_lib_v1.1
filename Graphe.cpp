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

Coord::~Coord()
{

}

namespace thg
{

	//------------------GRAPH------------------
	Graph::Graph(std::string _FileName,Svgfile& _out):m_display{_out}
	{
		std::string value;
		std::ifstream file1{ _FileName + ".txt" };
		std::cout << "Quelle chiffre de fichier?";
		std::cin >> value;
		std::ifstream file2{ _FileName + "_weights_" + value +".txt" };
		if (!file1 || !file2)
			throw std::runtime_error("Impossible d'ouvrir en lecture " + _FileName +".txt ou "+ _FileName + "_weights_" + value + ".txt");
		if (file1.fail() || file2.fail())
			throw std::runtime_error("Probleme lecture ordre du graphe");

		//Lecture nombre de sommets//
		unsigned int NbPoints;
		short coord_1=0;
		short coord_2=0;
		std::string id;
		file1 >> NbPoints;


		//création des sommets avec Coords///
		for (unsigned int i = 0; i < NbPoints; i++)
		{
			file1 >> id; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
			file1 >> coord_1; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
			file1 >> coord_2; if (file1.fail()) throw std::runtime_error("Probleme de lecture des données");
			std::cout << coord_1 << " " << coord_2 << "--------------";
			m_points.insert({ id, new Point(id, coord_1,coord_2 ) });
			m_display.addCircle(coord_1, coord_2, 10, 2);
		}
		//Lecture nombre d'arrêtes//
		unsigned int NbLinks;
		unsigned int NbLinks2;
		float weight1;
		float weight2;
		std::string id_A;
		std::string id_B;
		file1 >> NbLinks;
		file2 >> NbLinks2;
		file2 >> id;
		if (NbLinks != NbLinks2)
			throw std::runtime_error("Nombre d'arrete différents dans les fichiers");
		for (unsigned int i = 0; i < NbLinks; i++)
		{
			file1 >> id; file2 >> id;//Trouver moyen de passer directement à la suite//
			file1 >> id_A;
			file1 >> id_B;
			file2 >> weight1;
			file2 >> weight2;
			m_links.insert({ id, new Link(id,weight1,weight2,id_A,id_B) });
		}
		//Ajout des extrémités des arrêtes//
		//Relecture du nombre d'arrêtes//
		//Lecture du nombre de poids à prendre en compte (premier test avec 2 non dynamique)//
		//Ajout pour id du nombre cost1 et cost2//
		file1.close();
		file2.close();
		
	}

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
	}*/

	//std::unordered_map<Point*, std::list<Point*>> Graph::smaller_travel(const Point& _DepartPoint, bool reverse = false) const
		/**
		This function do the Djisktra's algorithm in smallest or biggest travel distance, return an unordered map with The depart point and the list of all points to travel through
		**/
	//{
		//Declaration d'une unordered map avec id et unsigned int (valeur des arêtes)
	//}

	/*Graph Graph::Prim_algorithm(const Point& _DepartPoint) const
	{
		//return Graph();
	}



	int Graph::research_show_CC() const
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

	bool Graph::parity() const
	{
		int parite = 0;
		for (const auto& it : m_points)
			it.second->research_ps(parite);
		if (parite != 0)
			return true;
		else
			return false;
	}*/

	void Graph::show_svg() const
	{
		for (const auto& it : m_points)
		{
			

		}
	}

	Graph::~Graph()
	{
	}




	//------------------POINT------------------
	Point::Point(std::string _Name, short _x, short _y) :m_id{ _Name }, m_Coord {_x,_y}
	{
	}
	void Point::addNeighboor( Link* _link, std::string _id)
	{
		m_neighboors.insert({ _link,_id });
	}

	/*std::unordered_map<std::string, std::string> Point::BFS_course() const
	{
		std::unordered_map<std::string, std::string> l_pred;
		std::queue<const Point*> file;
		file.push(this);//on ajoute l'element actuel dans la file
		const Point* s;
		std::vector<Point*> list_point; /// A changer si mieux
		do {
			s = file.front();//on recupere le Point de tete
			file.pop();
			for (size_t i = 0; i < s->m_neighboors.size(); i++)
			{
				if (l_pred.find(s->m_neighboors[i].first->m_id) == (l_pred.end()) && (s->m_neighboors[i]->first != this))
				{
					file.push(s->m_neighboors[i]->first);
					l_pred.insert({ s->m_neighboors[i]->first->m_id,s->m_id });
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
			for (size_t i = 0; i < s->m_neighboors.size(); i++)
			{
				if (l_pred.find(s->m_neighboors[i].first->m_id) == (l_pred.end()) && (s->m_neighboors[i]->first != this))
				{
					pile.push(s->m_neighboors[i]->first);
					l_pred.insert({ s->m_neighboors[i]->first->m_id,s->m_id });
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
	Link::Link(std::string _id, float _cost1, float _cost2, std::string _a, std::string _b) : m_id{ _id }, m_cost1{ _cost1 }, m_cost2{ _cost2 }, m_point_A{_a}, m_point_B{_b}
	{
		std::cout << "Link constructor id:" << m_id + " " << m_cost1 << " " << m_cost2 << " " + m_point_A + " " + m_point_B << std::endl;
	}

	Link::~Link()
	{
	}


}



