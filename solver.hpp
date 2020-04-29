#include <iostream>
#include <complex>

using namespace std;
namespace solver
{
    class RealVariable{

            public:

		friend RealVariable operator+(RealVariable r, double n);
		friend RealVariable operator+(double n, RealVariable r);
		friend RealVariable operator+(RealVariable l, RealVariable r);

		friend RealVariable operator*(RealVariable r, double n);
		friend RealVariable operator*(double n, RealVariable r);
		friend RealVariable operator*(RealVariable l, RealVariable r);

		friend RealVariable operator-(RealVariable r, double n);
		friend RealVariable operator-(double n, RealVariable r);
		friend RealVariable operator-(RealVariable l, RealVariable r);

		friend RealVariable operator==(RealVariable r, double n);
		friend RealVariable operator==(double n, RealVariable r);
		friend RealVariable operator==(RealVariable l, RealVariable r);

		friend RealVariable operator^(RealVariable r, double n);
		friend RealVariable operator/(RealVariable r, double n);
	};

	class ComplexVariable
	{
	
	public:
		
		friend ComplexVariable operator+(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator+(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator+(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator*(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator*(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator*(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator-(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator-(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator-(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator==(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator==(complex<double> n, ComplexVariable r);
		friend ComplexVariable operator==(ComplexVariable l, ComplexVariable r);

		friend ComplexVariable operator^(ComplexVariable r, complex<double> n);
		friend ComplexVariable operator/(ComplexVariable r, complex<double> n);
	};


	double solve(RealVariable x);
	complex<double> solve(ComplexVariable x);  
};


