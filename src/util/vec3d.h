#ifndef _VEC_H
#define _VEC_H

#include <cmath>
#include <limits>

class Vec3d
{
public:
	double x, y, z;
	
	Vec3d():x(0.0),y(0.0),z(0.0)
	{}
	Vec3d(double _x, double _y, double _z):x(_x),y(_y),z(_z)
	{}
	
	double length()
	{
		return sqrt(x*x + y*y + z*z);
	}
	
	Vec3d operator -(const Vec3d &b)
	{
		return Vec3d(x - b.x, y - b.y, z - b.z);
	}
	
	Vec3d operator +(const Vec3d &v)
	{
		return Vec3d(x + v.x, y + v.y, z + v.z);
	}
	
	Vec3d& operator +=(const Vec3d& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	
    friend Vec3d operator *(const double s, const Vec3d &v)
	{
		return Vec3d(v.x * s, v.y * s, v.z * s);
	}

    friend double operator *(const Vec3d &a, const Vec3d &b)
    {
        return (a.x * b.x + a.y * b.y + a.z * b.z);
    }

    Vec3d normalized()
    {
        double l = length();
        if (l <= std::numeric_limits<double>::epsilon())
            return Vec3d(0, 0, 0);
        return Vec3d(x / l, y / l, z / l);
    }

    Vec3d& normalize()
    {
        double l = length();
        if (l > std::numeric_limits<double>::epsilon())
            x /= l; y /= l; z /= l;
        return *this;
    }
};

#endif
