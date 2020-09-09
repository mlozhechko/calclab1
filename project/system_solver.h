#pragma once

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ub = boost::numeric::ublas;

template <class T>
int gaussSolve(const ub::matrix<T>& sourceMatrix, const ub::matrix<T>& sourceVector, ub::matrix<T>& solution);

template <class T>
int QRSolve(const ub::matrix<T>& sourceMatrix, const ub::matrix<T>& sourceVector, ub::matrix<T>& solution);