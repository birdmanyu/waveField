template <typename T>
class BoundsMatrix
{
        std::vector<T> inner_;
        unsigned int dimx_, dimy_;

public:
        BoundsMatrix (unsigned int dimx, unsigned int dimy)
                : dimx_ (dimx), dimy_ (dimy)
        {
                inner_.resize (dimx_*dimy_);
        }

        T& operator()(unsigned int x, unsigned int y)
        {
                if (x >= dimx_ || y>= dimy_)
                        throw std::out_of_range("matrix indices out of range"); // ouch
                return inner_[dimx_*y + x];
        }
};
