#ifndef POINT_H_
#define POINT_H_

namespace spic {

    /**
     * @brief Struct representing both a 2D point and a 2D vector.
     * @spicapi
     */
    struct Point {
        double x;
        double y;

        double Length() const;

        void Normalize();

        void Truncate(double max);

        Point friend operator-(const Point& left, const Point& right);

        Point friend operator+(const Point& left, const Point& right);

        Point operator*(double scalar) const;

        Point operator/(double scalar) const;

        void operator*=(double scalar);
    };

}

#endif // POINT_H_
