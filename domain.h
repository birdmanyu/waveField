#ifndef DOMAIN_H
#define DOMAIN_H

template<typename T>
class Domain{
private:
    std::vector<T> x;
    std::vector<T> y;
    int nx;
    int ny;

public:
    virtual void setXY() = 0;
};


#endif
