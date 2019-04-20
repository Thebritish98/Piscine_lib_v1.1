#ifndef PATHHPP
#define PATHHPP

#include "main.h"
class Link;

	class Path
	 {
		 public:
		Path();
		Path(Path& _path_copy);
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
