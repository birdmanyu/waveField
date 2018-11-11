#ifndef DOMAIN_H
#define DOMAIN_H

template<typename T>
class RectangleDomain: public Domain<T>{
private:
    std::vector<T> x;
    std::vector<T> y;
    int nx;
    int ny;

public:
    RectangleDomain(int nx_in, ny_in);
    void setXY();
};



#endif
