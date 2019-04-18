#include "Path.h"
#include <iterator>

Path::Path()
{
}

Path::Path(Path& _path_copy) :trace{ _path_copy.get_trace() }, cout_tot1{ _path_copy.get_tot1() }, cout_tot2{ _path_copy.get_tot2() }
{

}

Path::~Path()
{

}

void  Path::add_link(Link* lien)
{
	int i;
	trace.push_back (lien);
	cout_tot1=0;
	cout_tot2=0;
	for(i=0;i<trace.size();i++)
	{
		cout_tot1+=trace[i]->get_cos1();
		cout_tot2+=trace[i]->get_cos2();
	}

}

void Path::afficher_path()
{
	int i, a, b;
	for (i = 0; i < trace.size(); i++)
	{
		std::cout << "si c'est pas 7 yolo" << trace.size() << std::endl;
		a = trace[i]->get_id_a();
		b = trace[i]->get_id_b();
		std::cout << "premier point" << a << "deuxiemepoint" << b << std::endl;
	}
}