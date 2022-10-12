#include "Header.h"

using namespace std;

// -----------------------------------------------------------------------------
// -----------------------------accessor----------------------------------------
// -----------------------------------------------------------------------------

int System::get_N() const { return loop_link.get_strand_size(); }

void System::get_R(double *R, int size) const
{
  if (size != 3 * (loop_link.get_strand_size() + 1))
  {
    throw invalid_argument("invalid size in System::get_R");
  }
  // We construct an vector of the x,y,z coordinates to sort them according to x
  // for( auto& it : R_to_sort){for(auto& it2 : it){cout<<it2<<" ";}cout<<endl;}
  // fill the R array
  R[0] = 0.;
  R[1] = 0.;
  R[2] = 0.;
  int n(3);
  for (auto &it : loop_link.get_loops())
  {
    R[n] = it->get_Rright()->r()[0];
    R[n + 1] = it->get_Rright()->r()[1];
    R[n + 2] = it->get_Rright()->r()[2];
    n += 3;
  }
}

void System::get_ell_coordinates(double* ell_coordinate,int size)const 
{
  if(size != loop_link.get_strand_size()+1){throw invalid_argument("invalid size in System::get_R");}
int n(0);
  for(auto& loop : loop_link.get_loops()){
    ell_coordinate[n] = loop->get_ell_coordinate_0();
    n++;
  }
}

void System::get_ell(double *ells, int size) const
{
  if (size != loop_link.get_strand_size())
  {
    throw invalid_argument("invalid size in System::get_ell");
  }
  int n(0);
  for (auto &it : loop_link.get_loops())
  {
    ells[n] = it->get_ell();
    n++;
  }
}

void System::get_r(double *r, int size) const
{
  if (size != get_r_size())
  {
    throw invalid_argument("invalid size in System::get_r");
  }
  int n(0);
  for (auto &loop : loop_link.get_loops())
  {
    for (auto &link : loop->get_r())
    {
      r[3 * n] = link->r().at(0);
      r[3 * n + 1] = link->r().at(1);
      r[3 * n + 2] = link->r().at(2);
      n++;
    }
  }
}

int System::get_r_size() const
{
  int size(0);
  for (auto &it : loop_link.get_loops())
  {
    size += it->get_r().size();
  }
  return 3 * size;
}

double System::get_F() const
{
  double F(-get_N());
  for (auto &it : loop_link.get_loops())
  {
    F += -kBT * it->get_S();
  }
  return F;
}

void System::Print_Loop_positions() const
{
  for (auto &loop : loop_link.get_loops())
  {
    //cout << "theta Phi " << loop->get_theta() << " " << loop->get_phi() << endl;
    //cout << "xg,yg,zg " << loop->get_Rg()[0] << " " << loop->get_Rg()[1] << " " << loop->get_Rg()[2] << endl;
    cout << "volume " << loop->get_V() << endl;
    cout << "ell " << loop->get_ell() << endl;
    cout << "anchoring points. left :" << loop->get_Rleft()->r()[0] << " " << loop->get_Rleft()->r()[1] << " " << loop->get_Rleft()->r()[2] << " right : " << loop->get_Rright()->r()[0] << " " << loop->get_Rright()->r()[1] << " " << loop->get_Rright()->r()[2] << endl;
    cout << "number of crosslinkers of this loop :" << loop->get_r().size() << endl
         << endl;
  }
}

void System::check_loops_integrity()
{ 
}

void System::get_r_system(double *r, int size)const
{
  if (size != get_r_system_size())
  {
    throw invalid_argument("invalid size in System::get_r");
  }
  int n(0);
  for(auto& it : loop_link.get_linkers())
  {
    for(auto& it2 : it.second)
    {
      for(auto& it3 : it2.second)
      {
        r[3*n] = it3.second->r()[0];
        r[3*n+1] = it3.second->r()[1];
        r[3*n+2] = it3.second->r()[2];
        n++;
      }
    }
  }
}

int System::get_r_system_size() const
{
  return 3*loop_link.get_linker_size();
}

void System::print_random_stuff() const{
  //linkers.print();
  cout<<"loops linkers : "<<endl;
  for(auto& it : loop_link.get_loops()){for(auto& link : it->get_r()){
    cout<<link->r()[0]<< " " << link->r()[1] << " "<<link->r()[2]<<endl;
  }}
}