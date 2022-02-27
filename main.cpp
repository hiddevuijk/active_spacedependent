
#include "configFile.h"
#include "vec3.h"
#include "system.h"
#include "density.h"


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ConfigFile config("input.txt");
  double dt     = config.read<double>("dt");
  double vs     = config.read<double>("vs");
  double alpha  = config.read<double>("alpha");
  double omegaI = config.read<double>("omegaI");
  double D      = config.read<double>("D");
  double Dr     = config.read<double>("Dr");
  double L      = config.read<double>("L");
  long int seed = config.read<long int>("seed");

  double totalTime    = config.read<double>("totalTime");
  double tEquilibrate = config.read<double>("tEquilibrate");

  double sampleDt = config.read<double>("sampleDt");

  unsigned int nbin = config.read<unsigned int>("nbin");

  double omega = 4 * acos(0.0) * omegaI / L;

  System system(dt, vs, alpha, omega, D, Dr, seed);

  Density density(nbin, L);

  system.integrate(tEquilibrate);
  double time = 0;
  while( time < totalTime) {


	system.integrate(sampleDt);
	density.sample( system.getPositionX() );
	
	time += sampleDt;
  }

  density.write("rho.dat");
  


  return 0;
}

