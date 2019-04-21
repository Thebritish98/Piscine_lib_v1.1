#include "main.h"


void get_path(Graph& graph, std::vector<Path*>& chemin_possible);
void pareto_verif(std::vector <Path*>& chemin_possible, std::vector<Path*>& chemin_pareto);
void dijkstra(Graph graph, std::vector<Path*> &chemin_pareto_dijkstra, std::vector<float> & cost1_pareto ,std::vector<float> & cost2_pareto,std::vector<Path*> &chemin_dijkstra,std::vector<float> &cos1temp,std::vector<float> &cos2temp);

