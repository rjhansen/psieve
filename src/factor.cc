#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>

using std::ostream_iterator;
using std::stringstream;
using std::cout;
using std::cerr;
using std::setw;
using std::copy;

typedef std::vector<unsigned int> UIvec;
typedef std::vector<unsigned int>::iterator UIveciter;

#define SQRT(x) static_cast<double>(sqrt(static_cast<double>(x)))

UIvec psieve(const unsigned int N);

UIvec factorize(unsigned int n)
{
	static UIvec primes = psieve(10000000);
	UIvec factors;
	UIveciter iter = primes.begin();
	unsigned int stopAt = SQRT(n) + 1;
	
	while (iter != primes.end() && *iter <= stopAt) {
		if (*iter == n)
			break;
		if ((n % *iter) == 0) {
			n = n / *iter;
			factors.push_back(*iter);
			stopAt = SQRT(n) + 1;
			iter = primes.begin();
			continue;
		}
		++iter;
	}
	factors.push_back(n);
	return factors;
}

int main(int argc, char* argv[])
{
	for (int i = 1 ; i < argc ; i += 1) {
		stringstream ss;
		ss << argv[i];
		unsigned int n;
		ss >> n;
		if (!ss || n <= 2) {
			cerr << argv[i] << " is an invalid parameter.\n";
			continue;
		}
		UIvec factors = factorize(n);
		cout << setw(12) << n << ": ";
		copy(factors.begin(), factors.end(), ostream_iterator<unsigned int>(cout, " "));
		cout << "\n";
	}
	return 0;
}
