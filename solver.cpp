#include <iostream>
#include <complex>
#include <exception>
#include "solver.hpp"


using namespace std;
using namespace solver;

double solver::solve (RealVariable x)
{
	if (x.a==0 && x.b==0 && x.c!=0) 
	{ 
		throw runtime_error("Error");
	}
	if ((x.a!=1 && x.b==0 && x.c==0) || (x.a==0 && x.b!=0 && x.c==0))
	return 0;
	else if (x.a!=0 && x.b!=0 && x.c==0)
	{
		return ((x.a / x.b) * (-1));
	}
	else if ((x.a==0 && x.b!=0 && x.c!=0) || (x.a!=0 && x.b==0 && x.c!=0) || (x.a!=0 && x.b!=0 && x.c!=0))
	{
		double dis = (x.b *x.b) + (-4 * x.a * x.c);
		if (dis<0)
		throw runtime_error("Error, the discriminant is negative");
		return (-x.b + sqrt(dis))/(x.a * 2);
	}
}

complex<double> solver::solve (ComplexVariable x)
{
	if (x.a==0.0 && x.b==0.0 && x.c!=0.0) 
	{ 
		throw runtime_error("Error");
	}
	if ((x.a!=1.0 && x.b==0.0 && x.c==0.0) || (x.a==0.0 && x.b!=0.0 && x.c==0.0))
	return 0;
	else if (x.a!=0.0 && x.b!=0.0 && x.c==0.0)
	{
		return ((x.a / x.b) * (-1.0));
	}
	else if ((x.a==0.0 && x.b!=0.0 && x.c!=0.0) || (x.a!=0.0 && x.b==0.0 && x.c!=0.0) || (x.a!=0.0 && x.b!=0.0 && x.c!=0.0))
	{
		complex<double> dis = (x.b *x.b) + ((-4.0) * x.a * x.c);
		return (-x.b + sqrt(dis))/(x.a * 2.0);
	}
}

RealVariable solver::operator+(const double x, RealVariable y)
{
	return RealVariable(y.a, y.b, y.c +x);
}
RealVariable solver::operator+(RealVariable y, const double x)
{
    return RealVariable(y.a, y.b, y.c +x);
}
RealVariable solver::operator+(RealVariable y, RealVariable  x)
{
    return RealVariable(y.a + x.a, y.b + x.b, y.c + x.c);
}

RealVariable solver::operator-(const double x, RealVariable y)
{
return RealVariable(-y.a, -y.b, x - y.c);
}
RealVariable solver::operator-(RealVariable y, const double x)
{
    return RealVariable(y.a, y.b, y.c - x);
}
RealVariable solver::operator-(RealVariable y, RealVariable  x)
{
    return RealVariable(y.a -x.a, y.b - x.b, y.c - x.c);
}

RealVariable solver::operator*(const double x, RealVariable y)
{
return RealVariable(y.a * x, y.b * x, y.c * x);
}
RealVariable solver::operator*(RealVariable y, const double x)
{
return RealVariable(y.a * x, y.b * x, y.c * x);
}

RealVariable solver::operator/(const double x, RealVariable y)
{
	RealVariable z(y.a, y.b, y.c);
	if (y.a!=0)
	z.a = x/z.a;
	if (y.b!=0)
	z.b = x/z.b;
	if (y.c!=0)
	z.c = x/z.c;
	return z;
}
RealVariable solver::operator/(RealVariable y, const double x)
{
	if (x!=0)
	{
		return RealVariable(y.a/x, y.b/x, y.c/x);
	}
	else throw runtime_error("can't divide by 0");
}
RealVariable solver::operator/(RealVariable x, RealVariable  y)
{
	RealVariable z(y.a, y.b, y.c);
	if (y.a!=0)
	z.a = x.a/z.a;
	if (y.b!=0)
	z.b = x.b/z.b;
	if (y.c!=0)
	z.c = x.c/z.c;
	return z;
}

RealVariable solver::operator==(const double x, RealVariable y)
{
return RealVariable(y.a, y.b, y.c+((-1)*x));
}
RealVariable solver::operator==(RealVariable y, const double x)
{
return RealVariable(y.a, y.b, y.c+((-1)*x));
}
RealVariable solver::operator==(RealVariable x, RealVariable  y)
{
	RealVariable z(x.a, x.b, x.c);
	if (y.a!=0) 
	z.a = x.a+((-1)*y.a);
	if (y.b!=0) 
	z.b = x.b+((-1)*y.b);
	if (y.c!=0) 
	z.c = x.c+((-1)*y.c);
	return z;
}
RealVariable solver::operator^(RealVariable y, const int x)
{
	if (x==0)
	return RealVariable(0, 0, 1);
	if (x==1)
	return y;
	if (x==2)
	return RealVariable(y.a*y.a, 2* y.a* y.b, y.c* y.c);
	else
	throw runtime_error("Error");
}


ComplexVariable solver::operator+(ComplexVariable x, complex<double> y)
{
return ComplexVariable(x.a, x.b, x.c+y);
}
ComplexVariable solver::operator+(complex<double> y, ComplexVariable x)
{
    return ComplexVariable(x.a, x.b, x.c+y);
}
ComplexVariable solver::operator+(ComplexVariable x, ComplexVariable  y)
{
    return ComplexVariable(x.a+y.a, x.b+y.b, x.c+y.c);
}

ComplexVariable solver::operator-(complex<double> y, ComplexVariable x)
{
return ComplexVariable(x.a, x.b, y-x.c);
}
ComplexVariable solver::operator-(ComplexVariable x, complex<double> y)
{
    return ComplexVariable(x.a, x.b, x.c-y);
}
ComplexVariable solver::operator-(ComplexVariable x, ComplexVariable y)
{
    return ComplexVariable(x.a-y.a, x.b-y.b, x.c-y.c);
}
ComplexVariable solver::operator*(complex<double> y, ComplexVariable x)
{
return ComplexVariable(x.a * y, x.b * y, x.c *y);
}
ComplexVariable solver::operator*(ComplexVariable x, complex<double> y)
{
    return ComplexVariable(x.a * y, x.b * y, x.c *y);
}

ComplexVariable solver::operator/(complex<double> y, ComplexVariable x)
{
	ComplexVariable z(x.a, x.b, x.c);
	if (x.a!=0.0)
	z.a = y/z.a;
	if (x.b!=0.0)
	z.b = y/z.b;
	if (x.c!=0.0)
	z.c = y/z.c;
	return z;
}
ComplexVariable solver::operator/(ComplexVariable x, complex<double> y)
{
	if (y!=0.0)
    return ComplexVariable(x.a/y, x.b/y, x.c/y);
	else throw runtime_error("can't divide by 0");
}
ComplexVariable solver::operator/(ComplexVariable x, ComplexVariable  y)
{
	ComplexVariable z(y.a, y.b, y.c);
	if (y.a!=0.0)
	z.a = x.a/z.a;
	if (y.b!=0.0)
	z.b = x.b/z.b;
	if (y.c!=0.0)
	z.c = x.c/z.c;
	return z;
}
ComplexVariable solver::operator==(complex<double> y, ComplexVariable x)
{
return ComplexVariable(x.a, x.b, x.c+(std::complex<double>(-1)*y));
}
ComplexVariable solver::operator==(ComplexVariable x, complex<double> y)
{
    return ComplexVariable(x.a, x.b, x.c+(std::complex<double>(-1)*y));
}
ComplexVariable solver::operator==(ComplexVariable x, ComplexVariable  y)
{
	ComplexVariable z(x.a, x.b, x.c);
	if (y.a!=0.0) 
	z.a = x.a+(std::complex<double>(-1)*y.a);
	if (y.b!=0.0) 
	z.b = x.b+(std::complex<double>(-1)*y.b);
	if (y.c!=0.0) 
	z.c = x.c+(std::complex<double>(-1)*y.c);
	return z;
}
ComplexVariable solver::operator^(ComplexVariable x, int y)
{
	if (y==0)
	return ComplexVariable(0, 0, 1);
	if (y==1)
	return x;
	if (y==2)
	return ComplexVariable(x.a*x.a, 2.0* x.a* x.b, x.c* x.c);
	else
	throw runtime_error("Error");
}
