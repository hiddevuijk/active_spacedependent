
#include "configFile.h"
#include "vec3.h"
#include "system.h"


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

  double totalTime = config.read<double>("totalTime");

  int ntime = config.read<int>("ntime");
  double sampleDt = config.read<double>("sampleDt");

  double omega = 4 * acos(0.0) * omegaI / L;

  System system(dt, vs, alpha, omega, D, Dr, seed);


  double time = 0;
  while( time < totalTime) {


	system.integrate(sampleDt);

	
	time += sampleDt;
  }


  return 0;
}

