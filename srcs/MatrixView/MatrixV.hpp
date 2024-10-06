#ifndef MATRIXVIEW_HPP
# define MATRIXVIEW_HPP

#include "../DataNeeded/AllData.hpp"
#include "../Matrix/Matrix.hpp"

class MatrixView: public AllData
{
    private:
        unsigned long realCOLS, realROWS;
    public:
        MatrixView(Matrix &m, unsigned long x, unsigned long y, unsigned long rowsNb, unsigned long colsNb);
        MatrixView(const AllData &other);
        MatrixView(const AllData &&other);
        MatrixView &operator=(const MatrixView &other);
        const double &operator()(unsigned long x, unsigned long y) const;
        double &operator()(unsigned long x, unsigned long y);
        unsigned long rows() const;
        unsigned long cols() const;
        unsigned long rowStart() const;
        unsigned long colStart() const;
};
#endif