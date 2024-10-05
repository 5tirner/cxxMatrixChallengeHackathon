#include "MatrixV.hpp"


MatrixView::MatrixView(Matrix &m, unsigned long x, unsigned long y, unsigned long rowsNb, unsigned long colsNb)
{
    this->rowsNumber = rowsNb, this->colsNumber = colsNb, this->firstRow = x, this->firstCol = y;
    this->underlyingData = m.AllMatrix();
    // std::cout << this->underlyingData << ", " << m.AllMatrix() << std::endl;
}

MatrixView::MatrixView(const AllData &other): AllData(std::move(other)){}

MatrixView::MatrixView(const AllData &&other): AllData(std::move(other)){}


const double &MatrixView::operator()(unsigned long x, unsigned long y) const
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("MatrixView Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * realY + realY];
}
double &MatrixView::operator()(unsigned long x, unsigned long y)
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("MatrixView Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * realY + realY];
}

unsigned long MatrixView::rows() const
{
    return this->rowsNumber;
}
unsigned long MatrixView::cols() const
{
    return this->colsNumber;
}
unsigned long MatrixView::rowStart() const
{
    return this->firstRow;
}
unsigned long MatrixView::colStart() const
{
    return this->firstCol;
}