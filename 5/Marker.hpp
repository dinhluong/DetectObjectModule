//
//  Marker.h
//  5
//
//  Created by LTT on 10/20/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef _____Marker__
#define _____Marker__
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "GeometryTypes.hpp"
#include <opencv2/
class Marker
{
public:
    Marker();
    
    friend bool operator<(const Marker &M1, const Marker &M2);
    friend std::ostream & operator<<(std::ostream &str, const Marker &M);
    
    static cv::Mat rotate(cv::Mat in);
    static int hammDistMarker(cv::Mat bits);
    static int mat2id(const cv::Mat &bit);
    static int getMarkerId(cv::Mat &in, int &nRotation);
    
public:
    
    // Id of Marker.
    
    int id;
    // Marker transformation with regards to the camera.
    
    std::vector<cv::Point2f> points;
    
    Transformation transformation;
    //Helper function to draw the marker contour over the image.
    
    void drawContour(cv::Mat& image, cv::Scalar color = (0,250,0)) const;
};

#endif /* defined(_____Marker__) */
