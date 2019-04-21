//#include "main.h"
//
/////sort
//bool tri_cout1(const Link* &p,const Link* &d){return p->m_cost1<d->m_cost1;}
//
//void kruskal(std::vector<Link*> m_links, Path* & apm,std::vector<Point*> m_points)                                     /// on est d'accord que je modifie que virtuellement graph ?
//{
//   /// tri du vecteur graph
//   int i,y,z;
//   unsigned int verif1,verif2,verif3,intermediaire;
//   float intercos;
///// tester avec me tri.
//        /// tri
//                for (i=0;i<(m_links.size()-1)*(m_links.size()-1);i++)
//                {
//                    if (m_links[i]->get_cos1()<m_links[i+1]->get_cos1())
//                    {
//                        intercos=m_links[i+1]->get_cos1();
//                        m_links[i+1]->set_cost1(m_links[i]->get_cos1());
//                        m_links[i]->set_cost1(intercos);
//
//                    }
//                }
//
//   //     std::sort(*m_links.begin(),*m_links.end(), tri_cout1);
//verif3=0;
//verif2=1;
//                for(i=0;i<m_links.size()&&verif2!=0;i++) /// pour chaque lien dans l'ordre croissant si le tri juste au dessus marche
//                {
//                    verif1=0;
//                    verif2=0;
//                  if (m_points[m_links[i]->get_id_a()]->get_marked()<m_points[m_links[i]->get_id_b()]->get_marked())/// si point marka<markb toutes les markb de chaque point <a
//                  {
//                      verif1=1;
//                       intermediaire=m_points[m_links[i]->get_id_b()]->get_marked();
//                                 for(z=0;z<m_points.size();z++)
//                                 {
//                                     if (intermediaire==m_points[z]->get_marked())
//                                     m_points[z]->set_marked(m_points[m_links[i]->get_id_a()]->get_marked());
//                                 }
//                  }
//                  else if (m_points[m_links[i]->get_id_a()]->get_marked()>m_points[m_links[i]->get_id_b()]->get_marked())
//                  {
//                      verif1=1;
//                       intermediaire=m_points[m_links[i]->get_id_a()]->get_marked();
//                                 for(z=0;z<m_points.size();z++)
//                                 {
//                                     if (intermediaire==m_points[z]->get_marked())
//                                     m_points[z]->set_marked(m_points[m_links[i]->get_id_b()]->get_marked());
//                                 }
//                  }
//
//                 if (verif1==1)  /// si l'ordi est passé par une des deux condition en haut -> qu les deux points n'était pas relié et que verif =1 donc on ajoute le lien
//                    apm->add_link(m_links[i]);
//
//                  for(z=0;z<m_points.size()&&verif2!=1;z++)
//                  {
//                             if (verif3!=m_points[z]->get_marked())
//                             {
//                                verif2=1;                                        /// tant que tous les points n'ont pas 0 comme marque la verif est caduc
//                             }
//
//                  }
//                }
//
//                /// reset les points pour être sur que quoi que l'on demande après tout aille bien
//            for(z=0;z<m_points.size();z++)
//                         {
//                            m_points[z]->reset_mark();
//                         }
//
//}
//
//
//
//
//
////
////                             for (y=0;y<m_links.size();y++)
////                         {
////                                if (graph.get_m_points()[m_links.get_trace()[y]->get_id_a()]->get_marked()<graph.get_m_points()[m_links.get_trace()[y]->get_id_b()]->get_marked()) // si la marque de a est inferieur a la marque de b
////                             {
////
////                                 intermediaire=graph.get_m_points()[m_links.get_trace()[y]->get_id_b()]->get_marked();
////                                 for(z=0;z<graph.get_m_points().size();z++)
////                                 {
////                                     if (intermediaire==graph.get_m_points()[z]->get_marked())
////                                     graph.get_m_points()[z]->set_marked(graph.get_m_points()[m_links.get_trace()[y]->get_id_a()]->get_marked());
////                                 }
////                                }
////                             else if (graph.get_m_points()[m_links.get_trace()[y]->get_id_a()]->get_marked()>graph.get_m_points()[m_links.get_trace()[y]->get_id_b()]->get_marked())
////                             {
////                                 intermediaire=graph.get_m_points()[m_links.get_trace()[y]->get_id_a()]->get_marked();;
////                                 for(z=0;z<graph.get_m_points().size();z++)
////                                 {
////                                     if (intermediaire==graph.get_m_points()[z]->get_marked())
////                                     graph.get_m_points()[z]->set_marked(graph.get_m_points()[m_links.get_trace()[y]->get_id_b()]->get_marked());
////                                 }
////                             }
////                         }
////                         for(z=0;z<graph.get_m_points().size()&&verif2!=1;z++)
////                         {
////                             if (verif1!=graph.get_m_points()[z]->get_marked())
////                             {
////                                verif2=1;
////                             }
////                         }
////                         if (verif2==0)
////                         {
////                            chemin_possible.push_back(new Path(m_links));
////                         }
////
////
////
////
////}
