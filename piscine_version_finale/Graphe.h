
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
	void set_c(short _x, short _y)
	{
		m_x = _x;
		m_y = _y;
	}
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
        Link(unsigned int _id, float _cost1, float _cost2, unsigned int _a, unsigned int _b,Coord _mid_link,char _mode ); //ajout des param�tres de mode et de coord text

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
        void set_cost1(float a)
        {
            m_cost1=a;
        }



        ~Link();

    protected:

        char m_mode; //mode of the link : horizontal: 'h' / vertical : 'v' / diagonal up right : 'r' / diagonal up left : 'l' and 'n' as null
        Coord m_coord_text; //Coord for the text (weights)

        unsigned int m_id;
        unsigned int m_point_A;
        unsigned int m_point_B;
        float m_cost1;
        float m_cost2;
};

//------------------POINT------------------
class Point
{
public:
	Point(unsigned int _id, short _x, short _y);

	std::unordered_map<unsigned int,unsigned int> BFS_course() const;
	void addNeighboor( Link* _link, unsigned int _id);


	//-----------------------GETTER---------------------------
	unsigned int get_id() const
	{
		return m_id;
	}

	Coord get_coord() const
	{
		return m_Coord;
	}

	std::vector<Link*> get_neighboors() const
	{
		return m_neighboors;
	}

	unsigned int get_marked() const
	{
		return m_marked;
	}

	void set_marked(unsigned int new_mark)
	{
		m_marked = new_mark;
	}
	void reset_mark()
	{
		m_marked = m_id;
	}
	void set_pred(unsigned int _id)
	{
		m_pred_id = _id;
	}
	void set_weight(float _weight)
	{
		m_weight = _weight;
	}
	unsigned int get_pred()
	{
		return m_pred_id;
	}
	float get_weight()
	{
		return m_weight;
	}

	~Point();

protected:
	std::vector<Link*> m_neighboors;
	std::vector<unsigned int> m_neighboors_id;

	unsigned int m_id;
	unsigned int m_marked;
	unsigned int m_pred_id;
	float m_weight;

	Coord m_Coord;
};
//------------------GRAPH------------------

class Graph
{
public:
	Graph(){}
	Graph(std::string _FileName);
	void reload(std::string _FileName);
	Graph(Path& _copy_path, Graph& _base_graph);
	~Graph();

	std::vector<Path*> Djisktra_for_path(Graph& _graph,unsigned int _id);
	void Djisktra_for_weight(Graph& _graph);

	//---------------GETTER----------------------------
	std::vector<Point*> get_m_points()
	{
		return m_points;
	}
	std::vector<Link*> get_m_link()
	{
		return m_links;
	}
	std::string get_model_name()
	{
		return m_model_name;
	}


protected:
	std::vector<Point*> m_points;
	std::vector<Link*> m_links;
	std::string m_model_name;
};

void get_path(Graph& _graph, std::vector <Path*>& _possible_link);
void pareto_verif(std::vector <Path*>& chemin_possible, std::vector<Path*>& chemin_pareto);
#endif //LIB_THG

