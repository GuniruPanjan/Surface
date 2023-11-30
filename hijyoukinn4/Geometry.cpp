#include "Geometry.h"
#include<cassert>
#include<cmath>

Vector2 Vector2::operator+(const Vector2& val) const
{
    return { x + val.x,y + val.y };
}

Vector2 Vector2::operator-(const Vector2& val) const
{
    return { x - val.x,y - val.y };
}

Vector2 Vector2::operator*(float scale) const
{
    return { x * scale,y * scale };
}

Vector2 Vector2::operator/(float div) const
{
    assert(div != 0.0f);
    return { x / div,y / div };
}

void Vector2::operator+=(const Vector2& val)
{
    x += val.x;
    y += val.y;
}

void Vector2::operator-=(const Vector2& val)
{
    x -= val.x;
    y -= val.y;
}

void Vector2::operator*(float scale)
{
    x *= scale;
    y *= scale;
}

void Vector2::operator/(float div)
{
    assert(div != 0.0f);
    x /= div;
    y /= div;
}

float Vector2::Length() const
{
    return std::hypotf(x, y);
}

float Vector2::SQLengtah() const
{
    return x * x + y * y;
}

void Vector2::Normalize()
{
    float len = Length();
    if (len == 0.0f)
    {
        return;
    }
    x /= len;
    y /= len;
}

Vector2 Vector2::Normalized() const
{
    float len = Length();
    if (len == 0.0f)
    {
        return{0.0f,0.0f};
    }

    return { x / len,y / len };
}

float Dot(const Vector2& lval, const Vector2& rval)
{
    //Ç©ÇØÇƒÅAë´ÇπÇŒÇ¢Ç¢
    return lval.x * rval.x + lval.y * rval.y;
}
