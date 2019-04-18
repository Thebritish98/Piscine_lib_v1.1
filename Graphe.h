#ifndef LIB_THG
#define LIB_THG

#include "main.h"
class Path;
class Svgfile;




class Coord
{
public:
	Coord() :m_x{ 0 }, m_y{ 0 } 
	{}
	Coord(short x, short y);
	short get_x() const;//accesseur de m_x
	short get_y() const;//accesseur de m_y
	void mod_c(short _x_add,short _y_add); //add value to x and y
	~Coord();

protected:
	short m_x;
	short m_y;
};


//------------------LINK------------------
class Link
{
public:
	Link(){}
	Link(Link& _link_cop);
	Link(unsigned int _id, float _cost1, float _cost2, unsigned int _a, unsigned int _b,Coord _mid_link,char _mode ); //ajout des paramètres de mode et de coord text

	//----------------GETTER-----------------------
	float get_cos1()
	{
		return m_cost1;//weight 1  of the link
	}
	float get_cos2()
	{
		return m_cost2;//weight 2  of the link
	}
	unsigned int get_id_a()
	{
		return m_point_A;
	}
	unsigned int get_id_b()
	{
		return m_point_B;
	}
	unsigned int get_id()
	{
		return m_id;
	}
	Coord get_coord_mid()
	{
		return m_coord_text;
	}
	char get_mode()
	{
		return m_mode;
	}
	void mod_coord_mid(short _x_add, short _y_add)
	{
		m_coord_text.mod_c(_x_add, _y_add);
	}
	std::string weight_show()const
	{
		std::stringstream oss;
		oss << m_cost1;
		oss << ";";
		oss << m_cost2;
		return oss.str();
	}
	~Link();

protected:
	float m_cost1;
	float m_cost2;
	char m_mode; //mode of the link : horizontal: 'h' / vertical : 'v' / diagonal up right : 'r' / diagonal up left : 'l' and 'n' as null
	Coord m_coord_text; //Coord for the text (weights)

	unsigned int m_id;
	unsigned int m_point_A;
	unsigned int m_point_B;
};

//------------------POINT------------------
class Point
{
public:
	Point(unsigned int _id,short _x , short _y);
	void addNeighboor( Link* _link, unsigned int _id);

				/*A REMETTRE

	std::unordered_map<unsigned int, unsigned int> BFS_course() const;
	std::unordered_map<unsigned int, unsigned int> DFS_course() const;*/

	//-----------------------GETTER---------------------------
	unsigned int get_id() const
	{
		return m_id;
	}

	Coord get_coord() const
	{
		return m_Coord;
	}

	std::unordered_map<Link*, unsigned int> get_neighboors() const
	{
		return m_neighboors;
	}




	~Point();

protected:
	std::unordered_map<Link* , unsigned int> m_neighboors;

	unsigned int m_id;

	Coord m_Coord;
};

//------------------GRAPH------------------

class Graph
{
public:
	Graph(std::string _FileName);

	void show_svg(Svgfile& _out, bool _show_info=true);
	~Graph();
	/*			A VOIR SI REMETTRE
	void BFS_show(unsigned int _StartingEdge) const;
	void DFS_show(unsigned int _StartingEdge) const;
	void BFS_course(unsigned int _StartingEdge) const;
	void DFS_course(unsigned int _StartingEdge) const;*/

	///-----------------------------A CODER----------------
	std::unordered_map<Point*, std::list<Point*>> smaller_travel(const Point& _DepartPoint, bool reverse) const;//Djisktra algorithm to find the smallest distance between all points and show it. Reverse mode make choose the longest one


	Graph Prim_algorithm(const Point& _DepartPoint) const;	//Return a partial Graph with all smallest connexion

	//---------------GETTER----------------------------
	std::vector<Point*> get_m_points()
	{
		return m_points;
	}
	std::vector<Link*> get_m_link()
	{
		return m_links;
	}


protected:
	std::vector<Point*> m_points;
	std::vector<Link*> m_links;
};



/*
void get_path(Graph& _graph, std::vector <Path*>& _possible_link);
void pareto_verif(std::vector <Path*>& _possible_link);*/
#endif //LIB_THG

