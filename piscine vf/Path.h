#ifndef PATHHPP
#define PATHHPP

#include "main.h"
class Link;


    class Path
     {
         public:
        Path();
        Path(Path& _path_copy):trace{_path_copy.get_trace()},cout_tot1{_path_copy.get_tot1()},cout_tot2{_path_copy.get_tot2()}
        {
        }
        ~Path();
        void add_link(Link* lien);
        float get_tot1() const
        {
            return cout_tot1;
        }
        float get_tot2() const
        {
            return cout_tot2;
        }
        void reset()
        {
            trace.clear();
        }
        int get_trace_size()
        {
           return  trace.size();
        }
         std::vector<Link*> get_trace()
        {
             return trace;
        }
        void afficher_path();

         private:
        std::vector<Link*> trace;
        float cout_tot1;
        float cout_tot2;



     };
#endif
