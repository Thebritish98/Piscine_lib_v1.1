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
