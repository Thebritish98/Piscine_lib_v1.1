#include "Path.h"
#include <iterator>

Path::Path()
{

}

Path::~Path()
{

}

void Path::add_link(Link* _link)
{
	unsigned int i;
	m_path.push_back(_link);
	Link* pt_link=m_path.front();
	m_sumW1 = 0;
	m_sumW2 = 0;
	for (i = 0; i < m_path.size(); i++)
	{
		//pt_link = std::next(m_path.begin(), i);  comment faire que ça marche?
		m_sumW1 += pt_link->get_cos1();
		m_sumW2 += pt_link->get_cos2();
	}
}