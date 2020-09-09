#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ub = boost::numeric::ublas;

int main(int argc, char** argv) {
    ub::matrix<double> A(10, 10);
    std::cout << A << std::endl;

    return 0;
}
