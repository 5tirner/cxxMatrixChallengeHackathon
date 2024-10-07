#include "Matrix.hpp"
#include "../MatrixView/MatrixV.hpp"

Matrix::Matrix(const MatrixView &other)
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = 0, this->firstCol = 0;
    this->underlyingData = std::shared_ptr<double[]>(new double[other.colsNumber*other.rowsNumber]);
    // std::cout << "Rows Number: " << other.rowsNumber << ", Cols Number: " << other.colsNumber << std::endl
    // << "First Row: " << other.firstRow << ", First Col: " << other.firstCol << std::endl
    // << "Real rows Number: " << other.realROWS << ", Real Cols Number: " << other.realCOLS << std::endl;
    // for (unsigned long i = 0; i < other.realCOLS * other.realROWS; i++)
    // {
    //     if (i != 0 &&i % other.realCOLS == 0)
    //         std::cout << std::endl;
    //     else
    //         std::cout << other.underlyingData[i] << ' ';
    // }
    // std::cout << "\nSubOne" << std::endl;
    unsigned long k = 0;
    for (unsigned long i = 0; i < other.rowsNumber; i++)
    {
        unsigned long StartFrom = other.realCOLS * (other.firstRow + i) + other.firstCol;
        // std::cout << "start from: " << StartFrom << std::endl;
        for (unsigned long j = 0; j < other.colsNumber; j++, StartFrom++, k++)
        {
            // std::cout << other.underlyingData[StartFrom] << ' ';
            this->underlyingData[k] = other.underlyingData[StartFrom];
        }
        // std::cout << std::endl;
    }
    // std::cout << "\n-----------------------------\n";
}

Matrix &Matrix::operator=( const MatrixView &other)
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = 0, this->firstCol = 0;
    this->underlyingData = std::shared_ptr<double[]>(new double[other.colsNumber*other.rowsNumber]);
    unsigned long k = 0;
    for (unsigned long i = 0; i < other.rowsNumber; i++)
    {
        unsigned long StartFrom = other.realCOLS * (other.firstRow + i) + other.firstCol;
        for (unsigned long j = 0; j < other.colsNumber; j++, StartFrom++, k++)
            this->underlyingData[k] = other.underlyingData[StartFrom];
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