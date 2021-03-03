#include <cmath>

#ifndef __Vec2_H__
#define __Vec2_H__

class Vec2 {

    public:
        // Properties
        float x, y;

        // Constructors
        inline Vec2() :x(0), y(0) {};
        inline Vec2(float x, float y) : x(x), y(y) {};
        inline Vec2(const Vec2& v) : x(v.x), y(v.y) {};

        // Getter
        float length() const;
        Vec2 ortho() const;
        float dist(Vec2 v) const;

        // Setters
        void set(float x, float y);

        // Actions
        Vec2& operator=(const Vec2& v) ;
        Vec2 operator+(Vec2& v);
        Vec2 operator-(Vec2& v);
        Vec2 operator*(Vec2& v);
        Vec2 operator/(Vec2& v);
        Vec2& operator+=(Vec2& v);
        Vec2& operator-=(Vec2& v);
        Vec2& operator*=(Vec2& v);
        Vec2& operator/=(Vec2& v);
        Vec2 operator+(double s);
        Vec2 operator-(double s);
        Vec2 operator*(double s);
        Vec2 operator/(double s);
        Vec2& operator+=(double s);
        Vec2& operator-=(double s);
        Vec2& operator*=(double s);
        Vec2& operator/=(double s);
        void rotate(double deg);
        Vec2& normalize();
        void truncate(double length);
        //static float dot(Vec2 v1, Vec2 v2);
        //static float cross(Vec2 v1, Vec2 v2);
    };

// Type
//typedef Vec2<float> Vec2f;
//typedef Vec2<double> Vec2d;


#endif