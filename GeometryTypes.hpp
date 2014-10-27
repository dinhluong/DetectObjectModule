//
//  GeometryTypes.h
//  5
//
//  Created by LTT on 10/17/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef _____GeometryTypes__
#define _____GeometryTypes__

#include <iostream>

struct Matrix44{
    
    union
    {
        float data[16];
        float mat[4][4];
    };
    
    Matrix44 getTransposed() const;
    Matrix44 getInvertedRT() const;
    static Matrix44 identity();
};


struct Matrix33{

    union
    {
        float data[9];
        float mat[3][3];
    };
    
    Matrix33 getTransposed() const;
    static Matrix33 identity();

};

struct Vector4
{
    float data[4];
};

struct Vector3
{
    float data[3];
    static Vector3 zero();
    Vector3 operator-() const;
};

struct Transformation
{

    Transformation();
    Transformation(const Matrix33& r, const Vector3& t);
    
    Matrix33& r();
    Vector3& t();
    
    const Matrix33& r() const;
    const Vector3& t() const;
    
    Matrix44 getMat44() const;
    
    Transformation getInverted() const;
    
private:
    Matrix33 m_rotation;
    Vector3 m_translation;
    
};
#endif /* defined(_____GeometryTypes__) */
