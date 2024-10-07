#include "Matrix.hpp"
#include "../MatrixView/MatrixV.hpp"

Matrix::Matrix(const MatrixView &other)
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = other.firstRow, this->firstCol = other.firstCol;
    this->underlyingData = std::shared_ptr<double[]>(new double[other.colsNumber*other.rowsNumber]);
    
}

Matrix &Matrix::operator=( const MatrixView &other)
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = other.firstRow, this->firstCol = other.firstCol;
    this->underlyingData = std::shared_ptr<double[]>(new double[other.colsNumber*other.rowsNumber]);
    for (unsigned long i = 0; i < other.rowsNumber; i++)
    {
        for (unsigned long j = 0; j < other.colsNumber; j++)
            this->underlyingData[i] = other(i, j);
    }
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
    if (x >= this->rowsNumber || y >= this->colsNumber)
        throw std::overflow_error("Matrix Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * this->colsNumber + realY];
}
double &Matrix::operator()(unsigned long x, unsigned long y)
{
    if (x >= this->rowsNumber || y >= this->colsNumber)
        throw std::overflow_error("Matrix Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * this->colsNumber + realY];
}

unsigned long Matrix::rows() const
{
    return this->rowsNumber;
}
unsigned long Matrix::cols() const
{
    return this->colsNumber;
}