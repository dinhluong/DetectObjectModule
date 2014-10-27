//
//  TinySP.h
//  5
//
//  Created by LTT on 10/21/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef _____TinySP__
#define _____TinySP__

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

float perimeter(const std::vector<cv::Point2f> &a);

bool isInto(cv::Mat &contour, std::vector<cv::Point2f> &b);

#endif /* defined(_____TinySP__) */
