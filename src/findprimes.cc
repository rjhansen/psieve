#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::ostream_iterator;
using std::stringstream;
using std::cout;
using std::cerr;
using std::copy;

typedef std::vector<unsigned int> UIvec;

UIvec psieve(const unsigned int N);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <upto>\n";
		return 0;
	}
	stringstream ss;
	ss << argv[1];
	unsigned int n;
	ss >> n;
	if (!ss) {
		cerr << argv[1] << " is not a valid parameter.\n";
		return -1;
	}
	UIvec primes = psieve(n);
	copy(primes.begin(), primes.end(), ostream_iterator<unsigned int>(cout, "\n"));
	return 0;
}
