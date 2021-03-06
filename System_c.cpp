#include "Header.h"
extern "C"
{
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  void* create_system(double ell_tot,double distance_anchor,double rho0,double temperature,int seed,bool adjust)
  {
    return new System(ell_tot, distance_anchor, rho0, temperature,seed,adjust);
  }
  void get_R(void* ptr, double* R, int size){
    System* system = reinterpret_cast<System*>(ptr);
    system->get_R(R,size);
  }
  void get_ell(void* ptr, double* ell, int size){
    System* system = reinterpret_cast<System*>(ptr);
    system->get_ell(ell,size);
  }
  int get_N(void* ptr){
    System* system = reinterpret_cast<System*>(ptr);
    return system->get_N();
  }
  double evolve(void* ptr, bool* bind)
  {
    System* system = reinterpret_cast<System*>(ptr);
    return system->evolve(bind);
  }
  int get_r_size(void* ptr){
    System* system = reinterpret_cast<System*>(ptr);
    return system->get_r_size();
  }
  void get_r(void* ptr, double* r, int size){
    System* system = reinterpret_cast<System*>(ptr);
    system->get_r(r,size);
  }
  void Print_Loop_positions(void* ptr){
    System* system = reinterpret_cast<System*>(ptr);
    system->Print_Loop_positions();
  }
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------

}
