#ifndef LIB_THG
#define LIB_THG

#include "main.h"

class Coord
{
public:
	Coord(short x, short y);
	short get_x() const;//accesseur de m_x
	short get_y() const;//accesseur de m_y
	~Coord();

protected:
	short m_x;
	short m_y;
};

namespace thg
{

	//------------------LINK------------------
	class Link
	{
	public:
		Link(std::string _id, float _cost1, float _cost2,std::string _a, std::string _b);
		float get_cos1()
		{
			return m_cost1;
		}
		float get_cos2()
		{
			return m_cost2;
		}
		std::string get_id_a()
		{
			return m_point_A;
		}
		std::string get_id_b()
		{
			return m_point_B;
		}
		std::string get_id()
		{
			return m_id;
		}
		~Link();

	protected:
		float m_cost1;
		float m_cost2;

		std::string m_id;
		std::string m_point_A;
		std::string m_point_B;
	};

	//------------------POINT------------------
	class Point
	{
	public:
		Point(std::string _Name,short _x , short _y);
		void addNeighboor( Link* _link,std::string _id);
		/*void showNeighboors() const;

		std::unordered_map<std::string, std::string> BFS_course() const;
		std::unordered_map<std::string, std::string> DFS_course() const;

		void researchCC(std::unordered_set<std::string>& _cc) const;*/


		std::string get_id() const
		{
			return m_id;
		}

		Coord get_coord() const
		{
			return m_Coord;
		}

		std::unordered_map<Link*, std::string> get_neighboors() const
		{
			return m_neighboors;
		}


		//void research_ps(int& _parity) const;


		~Point();

	protected:
		std::unordered_map<Link* , std::string> m_neighboors;

		std::string m_id;

		Coord m_Coord;
	};

	//------------------GRAPH------------------

	class Graph
	{
	public:
		Graph(std::string _FileName, Svgfile& _out);
		void BFS_show(std::string _StartingEdge) const;
		void DFS_show(std::string _StartingEdge) const;

		void BFS_course(std::string _StartingEdge) const;
		void DFS_course(std::string _StartingEdge) const;
		///-----------------------------Sans doute mettre un string au lieu de reference sur un point?----------------
		std::unordered_map<Point*, std::list<Point*>> smaller_travel(const Point& _DepartPoint, bool reverse) const;//Djisktra algorithm to find the smallest distance between all points and show it. Reverse mode make choose the longest one

		Graph Prim_algorithm(const Point& _DepartPoint) const;	//Return a partial Graph with all smallest connexion

		int research_show_CC() const;

		bool parity()const;

		void show_svg()const;

		~Graph();

	protected:
		std::unordered_map<std::string, Point*> m_points;
		std::unordered_map<std::string, Link*> m_links;
		Svgfile& m_display;
	};


}
#endif //LIB_THG

