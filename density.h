#ifndef GUARD_DENSITY_H
#define GUARD_DENSITY_H

// density of the system projected on the xy plane

#include <iostream>


#include <fstream>
#include <string> 

class Density {
public:
	Density( unsigned int nbin, double L);	

	void sample(double x);

	// write to out stream
	void write(std::ostream &out);
	// write to file named outname
	void write(const char* outname);

private:

	unsigned int nbin_;	// number of bins
	double L_; // systemsize	
	double bs_;	// bin size


	std::vector<double> rho_;
	std::vector<double> bins_;

	unsigned int Nsample_;
};

Density::Density(unsigned int nbin, double L)
  : nbin_(nbin), L_(L), bs_(L/nbin),
	rho_(nbin, 0.0), bins_(nbin), Nsample_(0)
{

	for(unsigned int i = 0; i < nbin; ++i) {
		bins_[i] = (i+0.5)*bs_;
	}
}	



void Density::sample(double x)
{
	++Nsample_;

	// PBC
	x = x - L_ * floor(x/L_);
	rho_[ std::floor(x/bs_) ] += 1.;
}




void Density::write(std::ostream &out)
{

	double norm = 1./(bs_*Nsample_);

	for (unsigned int i = 0; i < nbin_; ++i) {
		out << bins_[i];
		if (i < nbin_ - 1) out << "\t";
	}
	out << "\n";
	for (unsigned int i = 0; i < nbin_; ++i) {
		out << rho_[i] * norm;
		if (i < nbin_ - 1) out << "\t";
	}
}

void Density::write(const char* outname)
{
	std::ofstream out;
	out.open(outname);

    write(out);	
	out.close();
}


#endif
