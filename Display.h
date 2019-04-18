#ifndef DISPLAYHPP
#define DISPLAYHPP

#include "main.h"
class Graph;
class Coord;
constexpr char defcol[] = "black";

class Svgfile
{
public:
	Svgfile(std::string _filename = "output.svg", int _width = 1000, int _height = 800);
	~Svgfile();

	void addCircle(double x, double y, double r, std::string color = defcol);
	void addLine(double x1, double y1, double x2, double y2, std::string color = defcol);

	void addText(double x, double y, std::string text, std::string color = defcol);
	void addText(double x, double y, double val, std::string color = defcol);

	void addGraph(std::unordered_map<Coord*,bool> _data, double _x, double _y); // Ajoute le graphe affichant le résultat
	void addModel(Graph& _graph, double _x, double _y ,bool _show_info=true,float _coef=1.0); //Graphe d'entrée ou de sortie, le but étant de choisir la dimension max et le ppoint de départ du graphe

	static std::string makeRGB(int r, int g, int b);

	void add_to_text(std::string _added_text);

	/// Type non copiable
	Svgfile(const Svgfile&) = delete;
	Svgfile& operator=(const Svgfile&) = delete;

private:
	std::string m_filename;
	std::ofstream m_ostrm;
	int m_width;
	int m_height;

	// Pour éviter les ouvertures multiples
	static std::set<std::string> s_openfiles;
};

		//---------------------Board Result------------------------
class BoardResult
{
public:
	BoardResult();
	void init_template();
	void set_template(Svgfile& _out);
	void give_results(Svgfile& _out,Graph& _graph)const; // show the results on the svg file with the template choosen
	//-------------SETTER-------------
	void set_mode(); //permet de modifier le mode pour ne pas avoir le mmode par défaut, on demande a l'intérieur quelle mode ils veulent


	~BoardResult();

protected:
	std::string m_mode;
	std::string m_pattern; //pattern from hight tech or synthwave universe. (en faire un saucisson?)


};

#endif // !DISPLAYHPP
