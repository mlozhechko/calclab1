#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "system_solver.h"
#include "matrix_utils.h"

namespace ub = boost::numeric::ublas;

template <class T>
int lab1Main(int argc, char** argv) {
  bool isMatrixSpecified = cmdOptionExists(argv, argv + argc, "-matrix");
  bool isVectorSpecified = cmdOptionExists(argv, argv + argc, "-vector");
  if (!isMatrixSpecified || !isVectorSpecified) {
    std::cerr << "source data is not specified" << std::endl;
    return -1;
  }

  if (cmdOptionExists(argv, argv + argc, "-debug")) {
    std::cout << "debug mode enabled" << std::endl;
    log::setEnabled(true);
    log::setPrecision(20);
  }

  if (!cmdOptionExists(argv, argv + argc, "-method")) {
    std::cerr << "solver method is not specified" << std::endl;
    return -2;
  }

  std::ifstream matrixStream(getCmdOption(argv, argv + argc, "-matrix"));
  std::ifstream vectorStream(getCmdOption(argv, argv + argc, "-vector"));

  ub::matrix<T> A, B;
  initMatrix(A, matrixStream);
  initVector(B, vectorStream);

  std::cout << "source A: " << A << std::endl;
  std::cout << "source B: " << B << std::endl;

  ub::matrix<T> X;
  std::string method(getCmdOption(argv, argv + argc, "-method"));

  if (method == "qr") {
    QRSolve(A, B, X);
  } else if (method == "gauss") {
    gaussSolve(A, B, X);
  } else {
    std::cerr << "solver method cannot be parsed" << std::endl;
    return -3;
  }
  std::cout << "X: " << X << std::endl;

  ub::matrix<T> Bm;
  matrixMult(A, X, Bm);

  ub::matrix<T> delta = Bm - B;
  std::cout << "residual Octa norm: " << normOcta(delta) << std::endl;
  std::cout << "residual Cubic norm: " << normCubic(delta) << std::endl;

  ub::matrix<T> AI;
  invertMatrix(A, AI);

  return 0;
}

int main(int argc, char** argv) {
  if (!cmdOptionExists(argv, argv + argc, "-precision")) {
    std::cerr << "precision is not specified" << std::endl;
    return -1;
  }

  std::string precision = getCmdOption(argv, argv + argc, "-precision");
  if (precision == "double") {
    return lab1Main<double>(argc, argv);
  } else if (precision == "float") {
    return lab1Main<float>(argc, argv);
  }

  std::cerr << "precision cannot be parsed correctly" << std::endl;
  return -2;
}
