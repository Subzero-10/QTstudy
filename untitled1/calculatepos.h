#ifndef CALCULATEPOS_H
#define CALCULATEPOS_H
#include<math.h>

class calculatePos
{
public:
    calculatePos();
    struct point_t {
        double x, y;
    };

    struct circle_t {
        struct point_t center;
        double r;
    };
    int double_equals(double const a, double const b) ;
    double distance_sqr(struct point_t const* a, struct point_t const* b) ;
    double distance(struct point_t const* a, struct point_t const* b) ;
    int insect(struct circle_t circles[], struct point_t points[]) ;
    void calculate(int pos1,int pos2, unsigned long disten1,unsigned long disten2,double *x,double *y);
};

#endif // CALCULATEPOS_H
