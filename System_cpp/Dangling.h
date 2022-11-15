#ifndef Dangling_h
#define Dangling_h
class Dangling : public Strand
{
  /*
  Dangling is the extremity of the polymer. The polymer is always bound at its
  left and free at its right. This class is very similar to Loop, except that
  linkers are in a sphere.
  */
public:
  Dangling();
  Dangling(Linker* R0,
          LoopLinkWrap& loop_link,
          double ell_0,  // ell_0 is the coordinate
          double ell_in, // this is the remaining length
          double rho,
          bool rho_adjust);
  Dangling(const Dangling& dangling,LoopLinkWrap &loop_link);
  Dangling(const Dangling& dangling,
            Linker* new_left_linker,
            LoopLinkWrap &loop_link);
  double get_S()const override; // entropy of the polymer.
  void get_volume_limit(double& key_0_min,double& key_0_max,
                        double& key_1_min,double& key_1_max,
                        double& key_2_min,double& key_2_max) const override;
  Linker* get_Rright() const;

private:
  double radius;
  // returns a random position in a sphere
  std::array<double,3> random_in_volume() override;
  // number of configuration of a polymer bound in r1 and length ell
  double Omega(double ell) const;
  // use random_in_sphere to generate  a number of linkers
   // build le vector p_linkers from the overall map of the system:
  double compute_rate(double li, Linker* rlinker) override;
};
#endif