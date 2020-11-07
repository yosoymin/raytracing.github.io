#ifndef INTERVAL_H
#define INTERVAL_H
//==============================================================================================
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==============================================================================================

class interval {
  public:
    double min, max;

    interval(double _min, double _max) : min(_min), max(_max) {}
    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    double fraction(double x) const {
        // Returns the fraction of the distance of x from min to max, where x=min yields 0, and
        // x=max yields 1. Values outside this range are extrapolated. The complement of lerp().
        return (x - min) / (max - min);
    }

    double lerp(double t) const {
        // Returns the linearly-interpolated value of x along the interval, where t=0 yields the
        // interval min value, and t=1 yields the interval max value. Values of t outside [0,1]
        // will yield extrapolated values. The complement of fraction().
        return min + t * (max - min);
    }
};

const static interval empty   (+infinity, -infinity);
const static interval universe(-infinity, +infinity);


#endif
