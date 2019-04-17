#ifndef PATHHPP
#define PATHHPP

#include "main.h"
    class Path
     {
         public:
        Path();
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

         private:
        std::vector<Link*> trace;
        float cout_tot1;
        float cout_tot2;



     };

#endif
