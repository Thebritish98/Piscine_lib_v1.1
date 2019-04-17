#ifndef PATHHPP
#define PATHHPP

#include "main.h"
class Link;

class Path
{
public:
	Path();
	void add_link(Link* _link);

	void reset()
	{
		m_path.clear();
	}
	std::list<Link*>& get_path_()
	{
		return m_path;
	}

	//--------------GETTER--------------
	float get_sum_w_1()
	{
		return m_sumW1;
	}
	float get_sum_w_2()
	{
		return m_sumW2;
	}
	~Path();

protected:
	std::list<Link*> m_path;
	float m_sumW1;
	float m_sumW2;


};
#endif