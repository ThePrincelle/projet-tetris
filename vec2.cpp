#include "vec2.h"

// Getters
float Vec2::length() const
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::ortho() const
{
    return Vec2(y, -x);
}


float Vec2::dist(Vec2  v) const
{
    Vec2 d(v.x - x, v.y - y);
    return d.length();
}

// Setters

void Vec2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

// Actions

Vec2& Vec2::operator=(const Vec2& v) {
    x = v.x;
    y = v.y;
    return *this;
}


Vec2 Vec2::operator+(Vec2& v)
{
    return Vec2(x + v.x, y + v.y);
}


Vec2 Vec2::operator-(Vec2& v)
{
    return Vec2(x - v.x, y - v.y);
}


Vec2 Vec2::operator*(Vec2& v)
{
    return Vec2(x * v.x, y * v.y);
}


Vec2 Vec2::operator/(Vec2& v)
{
    return Vec2(x / v.x, y / v.y);
}


Vec2& Vec2::operator+=(Vec2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}


Vec2& Vec2::operator*=(Vec2& v)
{
    x *= v.x;
    y *= v.y;
    return *this;
}


Vec2& Vec2::operator-=(Vec2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}


Vec2& Vec2::operator/=(Vec2& v)
{
    x /= v.x;
    y /= v.y;
    return *this;
}


Vec2 Vec2::operator+(double s)
{
    return Vec2(x + s, y + s);
}


Vec2 Vec2::operator-(double s)
{
    return Vec2(x - s, y - s);
}


Vec2 Vec2::operator*(double s)
{
    return Vec2(x * s, y * s);
}


Vec2 Vec2::operator/(double s)
{
    return Vec2(x / s, y / s);
}


Vec2& Vec2::operator+=(double s)
{
    x += s;
    y += s;
    return *this;
}


Vec2& Vec2::operator-=(double s)
{
    x -= s;
    y -= s;
    return *this;
}


Vec2& Vec2::operator*=(double s)
{
    x *= s;
    y *= s;
    return *this;
}


Vec2& Vec2::operator/=(double s)
{
    x /= s;
    y /= s;
    return *this;
}


void Vec2::rotate(double deg)
{
    double theta = deg / 180.0 * M_PI;
    double c = cos(theta);
    double s = sin(theta);
    double tx = x * c - y * s;
    double ty = x * s + y * c;
    x = tx;
    y = ty;
}


Vec2& Vec2::normalize()
{
    if (length() == 0) return *this;
    *this *= (1.0 / length());
    return *this;
}


void Vec2::truncate(double length)
{
    double angle = atan2f(y, x);
    x = length * cos(angle);
    y = length * sin(angle);
}

/*
static float Vec2::dot(Vec2 v1, Vec2 v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}


static float Vec2::cross(Vec2 v1, Vec2 v2)
{
    return (v1.x * v2.y) - (v1.y * v2.x);
}*/