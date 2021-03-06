//
//  CameraCalibration.h
//  5
//
//  Created by LTT on 10/20/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef _____CameraCalibration__
#define _____CameraCalibration__

#include <iostream>
#include "GeometryTypes.hpp"


class CameraCalibration
{
public:
    CameraCalibration();
    CameraCalibration(float fx, float fy, float cx, float cy);
    CameraCalibration(float fx, float fy, float cx, float cy, float distorsionCoeff[4]);
    
    void getMatrix34(float cparam[3][4]) const;
    
    const Matrix33& getIntrinsic() const;
    const Vector4&  getDistorsion() const;
    
private:
    Matrix33 m_intrinsic;
    Vector4  m_distorsion;
};
#endif /* defined(_____CameraCalibration__) */
