#include "MatrixV.hpp"

MatrixView::MatrixView(Matrix &m, unsigned long x, unsigned long y, unsigned long rowsNb, unsigned long colsNb)
{
    this->rowsNumber = rowsNb, this->colsNumber = colsNb, this->firstRow = x, this->firstCol = y;
    this->realROWS = m.rows(), this->realCOLS = m.cols();
    this->underlyingData = m.underlyingData;
}

MatrixView::MatrixView(const MatrixView &other): AllData()
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = other.firstRow, this->firstCol = other.firstCol;
    this->realROWS = other.realROWS, this->realCOLS = other.realCOLS;
    this->underlyingData = other.underlyingData;
}

MatrixView &MatrixView::operator=(const MatrixView &other)
{
    this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
    this->firstRow = other.firstRow, this->firstCol = other.firstCol;
    this->realROWS = other.realROWS, this->realCOLS = other.realCOLS;
    this->underlyingData = other.underlyingData;
    return *this;
}

const double &MatrixView::operator()(unsigned long x, unsigned long y) const
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("MatrixView Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * this->realCOLS + realY];
}
double &MatrixView::operator()(unsigned long x, unsigned long y)
{
    if (x >= this->rows() || y >= this->cols())
        throw std::overflow_error("MatrixView Exception: Invalid Memory Access");
    unsigned long realX = this->firstRow + x, realY = this->firstCol + y;
    return this->underlyingData[realX * this->realCOLS + realY];
}

unsigned long MatrixView::rows() const
{
    return this->rowsNumber;
}
unsigned long MatrixView::cols() const
{
    return this->colsNumber;
}