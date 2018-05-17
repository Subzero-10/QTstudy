#include "calculatepos.h"
#include<math.h>
calculatePos::calculatePos()
{

}
void calculatePos::calculate(int pos1,int pos2, unsigned long disten1,unsigned long disten2,double *x,double *y)
{
    struct circle_t circles[2];
    struct point_t points[2];
    circles[0].center.x = pos1-620;
    circles[0].center.y = 0;
    circles[0].r = disten1;
    circles[1].center.x = pos2-620;
    circles[1].center.y = 0;
    circles[1].r = disten2;
    insect(circles, points);
    switch (insect(circles, points)) {
                case -1:
                    *x = 0;
                    *y = 0;
                    break;
                case 0:
                    *x = 0;
                    *y = 0;
                    break;
                case 1:
                    *x = points[0].x;
                    *y = points[0].y;
                    break;
                case 2:
                    *x = points[0].x;
                    *y = points[0].y;
    }

}

int calculatePos::double_equals(double const a, double const b)
{
    static const double ZERO = 1e-9;
    return fabs(a - b) < ZERO;
}

double calculatePos::distance_sqr(struct point_t const* a, struct point_t const* b)
{
    return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
}

double calculatePos::distance(struct point_t const* a, struct point_t const* b)
{
    return sqrt(distance_sqr(a, b));
}

int calculatePos::insect(struct circle_t circles[], struct point_t points[])
{
    double d, a, b, c, p, q, r;
    double cos_value[2], sin_value[2];
    if (double_equals(circles[0].center.x, circles[1].center.x)
        && double_equals(circles[0].center.y, circles[1].center.y)
        && double_equals(circles[0].r, circles[1].r)) {
        return -1;
    }

    d = distance(&circles[0].center, &circles[1].center);
    if (d > circles[0].r + circles[1].r
        || d < fabs(circles[0].r - circles[1].r)) {
        return 0;
    }

    a = 2.0 * circles[0].r * (circles[0].center.x - circles[1].center.x);
    b = 2.0 * circles[0].r * (circles[0].center.y - circles[1].center.y);
    c = circles[1].r * circles[1].r - circles[0].r * circles[0].r
        - distance_sqr(&circles[0].center, &circles[1].center);
    p = a * a + b * b;
    q = -2.0 * a * c;
    if (double_equals(d, circles[0].r + circles[1].r)
        || double_equals(d, fabs(circles[0].r - circles[1].r))) {
        cos_value[0] = -q / p / 2.0;
        sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);

        points[0].x = circles[0].r * cos_value[0] + circles[0].center.x;
        points[0].y = circles[0].r * sin_value[0] + circles[0].center.y;

        if (!double_equals(distance_sqr(&points[0], &circles[1].center),
                           circles[1].r * circles[1].r)) {
            points[0].y = circles[0].center.y - circles[0].r * sin_value[0];
        }
        return 1;
    }

    r = c * c - b * b;
    cos_value[0] = (sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
    cos_value[1] = (-sqrt(q * q - 4.0 * p * r) - q) / p / 2.0;
    sin_value[0] = sqrt(1 - cos_value[0] * cos_value[0]);
    sin_value[1] = sqrt(1 - cos_value[1] * cos_value[1]);

    points[0].x = circles[0].r * cos_value[0] + circles[0].center.x;
    points[1].x = circles[0].r * cos_value[1] + circles[0].center.x;
    points[0].y = circles[0].r * sin_value[0] + circles[0].center.y;
    points[1].y = circles[0].r * sin_value[1] + circles[0].center.y;

    if (!double_equals(distance_sqr(&points[0], &circles[1].center),
                       circles[1].r * circles[1].r)) {
        points[0].y = circles[0].center.y - circles[0].r * sin_value[0];
    }
    if (!double_equals(distance_sqr(&points[1], &circles[1].center),
                       circles[1].r * circles[1].r)) {
        points[1].y = circles[0].center.y - circles[0].r * sin_value[1];
    }
    if (double_equals(points[0].y, points[1].y)
        && double_equals(points[0].x, points[1].x)) {
        if (points[0].y > 0) {
            points[1].y = -points[1].y;
        } else {
            points[0].y = -points[0].y;
        }
    }
    return 2;
}
