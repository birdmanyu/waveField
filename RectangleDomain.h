#ifndef RECTANGLE_DOMAIN_H
#define RECTANGLE_DOMAIN_H

template<typename T>
class RectangleDomain: public Domain<T>{
private:
    std::vector<T> x;
    std::vector<T> y;
    int nx;
    int ny;
    T Lx;
    T Ly;

public:
    RectangleDomain(int nx_in, int ny_in, T Lx_in, T Ly_in);
    void setXY();
    auto getX(){return x;}
    auto getY(){return y;}
};

template<typename T>
RectangleDomain<T>::RectangleDomain(int nx_in, int ny_in, T Lx_in, T Ly_in){
    nx = nx_in;
    ny = ny_in;
    Lx = Lx_in;
    Ly = Ly_in;
    this->setXY();
}

template<typename T>
void RectangleDomain<T>::setXY(){

    // Set the x-coordinate
    x = linspace<T>((T)-Lx/2, Lx/2, nx);
    std::vector<T> v_temp;
    for (int i = 0; i < ny-1; i++){
        v_temp = linspace<T>((T)-Lx/2, Lx/2, nx);
        x.insert(x.end(), v_temp.begin(), v_temp.end());
    }

    // Set the y-coordinate
    y = linspace<T>((T)-Ly/2, Ly/2, ny);



}


#endif
