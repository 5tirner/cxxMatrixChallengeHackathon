#ifndef MATRIX_HPP
# define MATRIX_HPP

#include "../DataNeeded/AllData.hpp"

class MatrixView;
class Matrix: public AllData
{
    friend class MatrixView;
    public:
        Matrix(const MatrixView &other);
        Matrix &operator=( const MatrixView &other);
        Matrix(unsigned long x, unsigned long y);
        Matrix(unsigned long x, unsigned long y, double val);
        Matrix(const AllData &other);
        Matrix(const AllData &&other);
        ~Matrix(){}
        const double &operator()(unsigned long x, unsigned long y) const;
        double &operator()(unsigned long x, unsigned long y);
        unsigned long rows() const;
        unsigned long cols() const;
};

// float frobenius_norm(const Matrix &m);
#endif