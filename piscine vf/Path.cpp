#include "Path.h"
#include <iterator>

Path::Path()
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
    int i,a,b;
    for(i=0;i<trace.size();i++)
    {
        //std::cout<<"si c'est pas 7 yolo"<<trace.size()<<std::endl;
        a=trace[i]->get_id_a();
        b=trace[i]->get_id_b();
        std::cout<<"point     "<<a<<" et "<<b<<std::endl;
    }
    std::cout <<"cout1 " <<cout_tot1 <<"cout2 " <<cout_tot2<<std::endl;
}
