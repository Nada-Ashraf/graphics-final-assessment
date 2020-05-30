#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED
#include <vector>
class Camera
{
private:
    std::vector<double> eye = {0, 0, 2};
    std::vector<double> center = {0, 0, -1};
    std::vector<double> up = {0, 1, 0};
    double speed = 3.1415 / 100;

    void normalize(std::vector<double> &a);
    void rotate(const std::vector<double> &dir, double theta, std::vector<double> &p);
    void cross_product(const std::vector<double> &a, const std::vector<double> &b, std::vector<double> &c);

public:
    void forward_backword(double speed);
    void initialize();
    void turn_up();
    void turn_down();
    void turn_right();
    void turn_left();
};

#endif