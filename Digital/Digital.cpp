#include <iostream>

struct mdecimal {

	mdecimal() : d(0), m(8) {}
	
	template <typename T>
	mdecimal(const T lp, const unsigned char m1 = 8) {
		m = m1;
		if (m1 > 19) m = 19;
		d = lp * pow(10, m) + 0.5; // 0.5 - окгругление
	}

	mdecimal operator +(mdecimal& v) {
		mdecimal res;

		// приведение к одинаковой точности
		if (m < v.m) {
			
			res.d = d + long long (v.d * pow(10, m - v.m) + 0.5);
			res.m = m;
		}
		else {
			res.d = long long (d * pow(10, v.m - m) + 0.5) + v.d;
			res.m = v.m;
		}

		return res;
	}
	
	mdecimal operator -(mdecimal& v) {
		mdecimal res=v;
		res.d = -res.d;
		return *this + res;
	}

	friend std::ostream& operator<<(std::ostream& os, const mdecimal & md) {
		long long lp = md.d / pow(10, md.m);
		std::cout << lp << "." << md.d - lp * pow(10, md.m);
		return os;
	}

private:
	long long d; // число
	unsigned char m; // точность /10^m
};


template<typename T>
int CountBit(T b)
{
	T p = 0;
	int c = 0;

	do
	{
		p = b;
		b |= 1;
		b = (b << 1);
		c += 1;
	}
	while (p < b);

	return c;
}


int main()
{
	double t=0;
	
	std::cout << CountBit(unsigned long long(0)) << std::endl;
	std::cout << sizeof(unsigned long long) * 8 << std::endl;

	mdecimal d1(5.3,3), d2(2.0009,3), r(0,5);

	r = d1 - d2;

	std::cout << r << std::endl;

	return 0;
}