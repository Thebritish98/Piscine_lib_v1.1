#include "Display.h"


const std::string svgHeader =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" ";

const std::string svgEnding = "\n\n</svg>\n";


std::set<std::string> Svgfile::s_openfiles;

Svgfile::Svgfile(std::string _filename, int _width, int _height) :m_filename{ _filename }, m_width{ _width }, m_height{ _height }
{

	if (s_openfiles.count(m_filename))
		throw std::runtime_error("File " + m_filename + " already open !");

	m_ostrm.open(m_filename);
	s_openfiles.insert(m_filename);

	if (!m_ostrm)
	{
		std::cout << "Problem opening " << m_filename << std::endl;
		throw std::runtime_error("Could not open file " + m_filename);
	}

	//  std::cout << "OK" << std::endl;

	  // Writing the header into the SVG file
	m_ostrm << svgHeader;
	m_ostrm << "width=\"" << m_width << "\" height=\"" << m_height << "\">\n\n";
}

Svgfile::~Svgfile()
{
	// Writing the ending into the SVG file
	m_ostrm << svgEnding;

	// Removing this file from the list of open files
	s_openfiles.erase(m_filename);

	// No need to explicitly close the ofstream object (automatic upon destruction)
}

// Helper templated function
template<typename T>
std::string attrib(std::string name, T val)
{
	std::ostringstream oss;
	oss << name << "=\"" << val << "\" ";
	return oss.str();
}

void Svgfile::addCircle(double x, double y, double r, std::string color)
{
	m_ostrm << "<circle "
		<< attrib("cx", x)
		<< attrib("cy", y)
		<< attrib("r", r)
		<< attrib("fill", color)
		<< "/>\n";
}

void Svgfile::addLine(double x1, double y1, double x2, double y2, std::string color)
{
	m_ostrm << "<line "
		<< attrib("x1", x1)
		<< attrib("y1", y1)
		<< attrib("x2", x2)
		<< attrib("y2", y2)
		<< attrib("stroke", color)
		<< "/>\n";
}

void Svgfile::addText(double x, double y, std::string text, std::string color,std::string _font_size,std::string _font)
{
	/// <text x="180" y="60">Un texte</text>
	m_ostrm << "<text "
		<< attrib("x", x)
		<< attrib("y", y)
		<< attrib("font-family", _font)
		<< attrib("font-size", _font_size)
		<< attrib("fill", color)
		<< ">" << text << "</text>\n";
}

void Svgfile::addText(double x, double y, double val, std::string color)
{
	std::ostringstream oss;
	oss << val;
	addText(x, y, oss.str(), color);
}

std::string Svgfile::makeRGB(int r, int g, int b)
{
	std::ostringstream oss;
	oss << "rgb(" << r << "," << g << "," << b << ")";
	return oss.str();
}

void Svgfile::add_to_text(std::string _added_text)
{
	m_ostrm << _added_text;
}

void Svgfile::addGraph(std::vector<Coord>& _all_sol,std::vector<Coord>& _valid_sol,double _x, double _y,unsigned int _space)
{
	//moyen de faire en sorte de savoir ou placer les points
	std::string  color;
	float space_x,space_y;
	Coord coord_max(0, 0);
	this->addLine(_x,_y,_x,_y-387.5,"red");
	this->addLine(_x,_y,_x+540,_y,"red");
	for (const auto& it: _all_sol)
	{
		if (it.get_x()>coord_max.get_x())
		{
			coord_max.set_c(it.get_x(), coord_max.get_y());
		}
		if (it.get_y() > coord_max.get_y())
		{
			coord_max.set_c(coord_max.get_x(), it.get_y());
		}
	}
	space_x = (520 / coord_max.get_x());
	space_y = (360 / coord_max.get_y());
	for (unsigned int x = _space; _x + (space_x * x) < _x+520; x += _space)
	{
		this->addLine(_x + (space_x * x), _y+5, _x + (space_x * x), _y+10, "white");
	}
	for (unsigned int y = _space; _y - (space_y * y) > _y-387.5; y += _space)
	{
		this->addLine(_x-5 , _y- (space_y * y), _x-10, _y - (space_y * y), "white");
	}

	for (const auto& at : _all_sol)
	{
		this->addCircle(_x + (space_x * at.get_x()), _y - (space_y * at.get_y()), 4, "red");
	}
	for (const auto& at : _valid_sol)
	{
		this->addCircle(_x + (space_x * at.get_x()), _y - (space_y * at.get_y()), 4, "green");
	}
}

void Svgfile::addModel(Graph& _graph, double _x, double _y,std::string _color, bool _show_info, float _coef)
{
	Coord coord_min(_graph.get_m_points()[0]->get_coord().get_x(), _graph.get_m_points()[0]->get_coord().get_y());
	//calcul de rapport pour la taille des arr�tes
	//search smallest coord
	for (size_t i = 0; i < _graph.get_m_points().size(); i++)
	{
		if (_graph.get_m_points()[i]->get_coord().get_x()<coord_min.get_x())
		{
			coord_min.set_c(_graph.get_m_points()[i]->get_coord().get_x(),coord_min.get_y());
		}
		if (_graph.get_m_points()[i]->get_coord().get_y() < coord_min.get_y())
		{
			coord_min.set_c(coord_min.get_x(),_graph.get_m_points()[i]->get_coord().get_y());
		}
	}

	for (const auto& it : _graph.get_m_points())
	{
		this->addCircle(it->get_coord().get_x() - coord_min.get_x() + _x, it->get_coord().get_y() - coord_min.get_y() + _y, 5,_color);
		if(_show_info)
			this->addText(it->get_coord().get_x() - coord_min.get_x() + _x-5, it->get_coord().get_y() - coord_min.get_y() + _y+5,it->get_id(),"red");
	}
	for (const auto& at : _graph.get_m_link())
	{
		this->addLine(_graph.get_m_points()[at->get_id_a()]->get_coord().get_x() - coord_min.get_x() + _x, _graph.get_m_points()[at->get_id_a()]->get_coord().get_y() - coord_min.get_y() + _y, _graph.get_m_points()[at->get_id_b()]->get_coord().get_x() - coord_min.get_x() + _x, _graph.get_m_points()[at->get_id_b()]->get_coord().get_y() - coord_min.get_y() + _y,_color);
		if (_show_info)
		{
			switch (at->get_mode())
			{
			case 'v':
				at->mod_coord_mid(-25, 0);
				break;
			case 'h':
				at->mod_coord_mid(0  , -10 );
				break;
			case 'r':
				at->mod_coord_mid(-12 , -10 );
				break;
			case 'l':
				at->mod_coord_mid(5 , -10 );
				break;
			default:
				break;
			}
			at->mod_coord_mid(-coord_min.get_x() + _x, -coord_min.get_y() + _y);
			this->addText(at->get_coord_mid().get_x() , at->get_coord_mid().get_y() , at->weight_show(),_color );

		}
	}
}






		//-----------------Board Result--------------------
BoardResult::BoardResult():m_mode("retro_turbo")
{
	this->init_template();
}

void BoardResult::init_template()
{
	std::string tmp;
	m_pattern.erase();
	std::ifstream file("design_template/" + m_mode + ".txt");
	if (file.is_open())
	{
		while (getline(file, tmp))
		{
			m_pattern += tmp + "\n";
		}
	}
	else
	{
		std::cout << "\nImpossible d'ouvrir le fichier " << m_mode + ".txt" << std::endl;
	}
	file.close();
}
void BoardResult::set_template(Svgfile& _out)
{
	_out.add_to_text(m_pattern);
}
void BoardResult::give_results(Svgfile& _out, Graph& _graph,std::string _filename)
{
	std::string color;
	std::string font="sans-serif";
	this->init_template();
	if (m_mode == "high_tech")
	{
		color = "white";
		font = "Myriad-Pro";
	}
	else if (m_mode=="retro_turbo")
	{
		color = "#326775";
		//font = "";
	}
	else
		color = "red";
	this->set_template(_out);
	_out.addText(114, 77, _filename, color, "80px", font);
	_out.addText(112, 75, _filename, "url(#back1)", "80px", font);
	_out.addModel(_graph,140,110,color);
}

void BoardResult::set_mode()
{
}

BoardResult::~BoardResult()
{
}
