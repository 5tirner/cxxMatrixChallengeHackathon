#include "Matrix.hpp"
#include "../MatrixView/MatrixV.hpp"

Matrix::Matrix(const MatrixView &other): AllData(std::move(other)) {}

Matrix &Matrix::operator=( const MatrixView &other)
{
    this->rowsNumber = other.rows(), this->colsNumber = other.cols();
    this->firstRow = other.rowStart(), this->firstCol = other.colStart();
    this->underlyingData = other.AllMatrix();
    return *this;
}

Matrix::Matrix(unsigned long x, unsigned long y)
{
    this->rowsNumber = x, this->colsNumber = y;
    this->firstCol = 0, this->firstRow = 0;
    this->underlyingData = std::shared_ptr<double []>(new double[x * y]);
}

Matrix::Matrix(unsigned long x, unsigned long y, double val)
{
    this->rowsNumber = x, this->colsNumber = y;
    this->firstCol = 0, this->firstRow = 0;
    this->underlyingData = std::shared_ptr<double []>(new double[x * y]);
    for (unsigned long i = 0; i < x * y; i++)
        this->underlyingData[i] = val;
}

Matrix::Matrix(const AllData &other): AllData(other){}

Matrix::Matrix(const AllData &&other): AllData(std::move(other)){}


const double &Matrix::operator()(unsigned long x, unsigned long y) const
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("Matrix Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * realY + realY];
}
double &Matrix::operator()(unsigned long x, unsigned long y)
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("Matrix Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * realY + realY];
}

unsigned long Matrix::rows() const
{
    return this->rowsNumber;
}
unsigned long Matrix::cols() const
{
    return this->colsNumber;
}
unsigned long Matrix::rowStart() const
{
    return this->firstRow;
}
unsigned long Matrix::colStart() const
{
    return this->firstCol;
}

float frobenius_norm(const Matrix &m)
{
    float total = 0;
    for (unsigned long i = m.rowStart(); i < m.rows(); i++)
    {
        for (unsigned long j = m.colStart(); j < m.cols(); j++)
            total += std::pow(m(i, j), 2);
    }
    return std::sqrt(total);
}