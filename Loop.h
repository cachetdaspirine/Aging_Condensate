#ifndef Loop_h
#define Loop_h
class Loop{
public:
  Loop(double ell_loop,double rho,int seed);
  Loop(std::array<double,3> R0,std::array<double,3> R1, double ell_loop, double rho,int seed);
  ~Loop();

  void select_link_length(double& length, std::array<double,3>& r_selected,double& time);

  std::array<double,3> get_Rright() const;
  std::array<double,3> get_Rleft() const;
  std::vector<std::array<double,3>> get_r() const;
  double get_ell() const;
  double get_total_binding_rates() const;
  double get_theta()const; // angle with x axis
  double get_phi() const; // angle with z axis
  std::array<double,3> get_Rg() const;
  double get_V()const;
private:
  std::array<double,3> Rright,Rleft;
  std::vector<std::array<double,3>> r;
  std::vector<std::vector<double>> rates;
  double ell,V;
  double a,b;
  double rho0;
  double total_rates;
  std::mt19937 generator;

  std::array<double,3> random_in_ellipse(double a,double b,double c,double xg,double yg,double zg);
  double Omega(std::array<double,3> r1,std::array<double,3> r2,double ell);
  double compute_binding_rate(int r_index, double ell);
  void generate_binding_sites();

};
#endif
