#pragma once

#include <cstddef> // std::size_t
#include <iosfwd>  // std::ostream fwd declaration
#include "point2d.hh"

// Fwd declarations


class box2d {

    public :
        bool has(const point2d& p) const;

        unsigned getRows() const
        {
            return this->rows;
        }

        unsigned getCols() const
        {
            return this->cols;
        }

        void setRowsandCols(unsigned prows, unsigned pcols)
        {
            this->rows = prows;
            this->cols = pcols;
        }

    private :
    unsigned rows;
    unsigned cols;
};
