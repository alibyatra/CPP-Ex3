#include <iostream>
#include <complex>

using namespace std;
namespace solver
{
    class RealVariable{
            public:
			double a, b, c;
			RealVariable()
			:a(0), b(1), c(0){};
			RealVariable(double	a, double b, double c)
			: a(a), b(b), c(c){};

		friend RealVariable operator+(const double x, RealVariable y);
		friend RealVariable operator+(RealVariable y, const double x);
		friend RealVariable operator+(RealVariable y, RealVariable x);

		friend RealVariable operator-(const double x, RealVariable y);
		friend RealVariable operator-(RealVariable y, const double x);
		friend RealVariable operator-(RealVariable y, RealVariable  x);

		friend RealVariable operator*(const double x, RealVariable y);
		friend RealVariable operator*(RealVariable y, const double x);

		friend RealVariable operator/(const double x, RealVariable y);
		friend RealVariable operator/(RealVariable y, const double x);
		friend RealVariable operator/(RealVariable x, RealVariable  y);
		
		friend RealVariable operator==(const double x, RealVariable y);
		friend RealVariable operator==(RealVariable y, const double x);
		friend RealVariable operator==(RealVariable x, RealVariable  y);
		
		friend RealVariable operator^(RealVariable y, const int x);
	};

	class ComplexVariable
	{
	public:
	complex<double> a, b, c;
	ComplexVariable():a(0), b(1), c(0){};
	ComplexVariable(complex<double> a, complex<double> b, complex<double> c): a(a), b(b), c(c){};

		friend ComplexVariable operator+(ComplexVariable x, complex<double> y);
		friend ComplexVariable operator+(complex<double> y, ComplexVariable x);
		friend ComplexVariable operator+(ComplexVariable x, ComplexVariable y);

		friend ComplexVariable operator-(complex<double> y, ComplexVariable x);
		friend ComplexVariable operator-(ComplexVariable x, complex<double> y);
		friend ComplexVariable operator-(ComplexVariable x, ComplexVariable y);

		friend ComplexVariable operator*(complex<double> y, ComplexVariable x);
		friend ComplexVariable operator*(ComplexVariable x, complex<double> y);

		friend ComplexVariable operator/(complex<double> y, ComplexVariable x);
		friend ComplexVariable operator/(ComplexVariable x, complex<double> y);
		friend ComplexVariable operator/(ComplexVariable x, ComplexVariable  y);

		friend ComplexVariable operator==(complex<double> y, ComplexVariable x);
		friend ComplexVariable operator==(ComplexVariable x, complex<double> y);
		friend ComplexVariable operator==(ComplexVariable x, ComplexVariable  y);
		
		friend ComplexVariable operator^(ComplexVariable x, int y);
	};
	
	double solve(RealVariable x);
	complex<double> solve(ComplexVariable x);  
};


