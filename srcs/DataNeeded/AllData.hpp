#ifndef ALLDATA_HPP
#define ALLDATA_HPP

#include <memory>
#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include <iostream>
#include <cmath>

class AllData
{
    protected:
        unsigned long rowsNumber, colsNumber, firstRow, firstCol;
        std::shared_ptr<double[]> underlyingData;
        AllData(){}
    public:
        AllData(const AllData &other) : rowsNumber(other.rowsNumber), colsNumber(other.colsNumber),
        firstRow(other.firstRow), firstCol(other.firstCol),
        underlyingData(std::shared_ptr<double[]>(new double[rowsNumber * colsNumber]))
        {
            for (unsigned long i = 0; i < rowsNumber * colsNumber; i++)
                underlyingData[i] = other.underlyingData[i];
        }

        AllData(const AllData &&other): rowsNumber(other.rowsNumber), colsNumber(other.colsNumber),
        firstRow(other.firstRow), firstCol(other.firstCol),
        underlyingData(other.underlyingData){}

        AllData &operator=(const AllData &other)
        {
            this->rowsNumber = other.rowsNumber, this->colsNumber = other.colsNumber;
            this->firstRow = other.firstRow, this->firstCol = other.firstCol;
            this->underlyingData = std::shared_ptr<double[]>(new double[rowsNumber * colsNumber]);
            for (unsigned long i = 0; i < this->rowsNumber * this->colsNumber; i++)
                underlyingData[i] = other.underlyingData[i];
            return *this;
        }

        AllData &operator=(const AllData &&other)
        {
            this->rowsNumber = other.rowsNumber, this->colsNumber = other.cols();
            this->firstRow = other.firstRow, this->firstCol = other.firstCol;
            this->underlyingData = other.underlyingData;
            return *this;
        }

        virtual ~AllData(){}

        virtual const double &operator()(unsigned long x, unsigned long y) const = 0;

        virtual double &operator()(unsigned long x, unsigned long y) = 0;

        virtual unsigned long rows() const = 0;

        virtual unsigned long cols() const = 0;
};

#endif