//
//  MarkerDetector.h
//  5
//
//  Created by LTT on 10/20/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#ifndef _____MarkerDetector__
#define _____MarkerDetector__

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

#include "BGRAVideoFrame.h"
#include "CameraCalibration.hpp"

class Marker;


class MarkerDetector
{
public:
    
    typedef std::vector<cv::Point>    PointsVector;
    typedef std::vector<PointsVector> ContoursVector;

    MarkerDetector(CameraCalibration calibration);
    
    //! Searches for markes and fills the list of transformation for found markers
    void processFrame(const BGRAVideoFrame& frame);
    
    const std::vector<Transformation>& getTransformations() const;

protected:
    
    //! Main marker detection routine
    bool findMarkers(const BGRAVideoFrame& frame, std::vector<Marker>& detectedMarkers);
    
    //! Converts image to grayscale
    void prepareImage(const cv::Mat& bgraMat, cv::Mat& grayscale) const;
    
    //! Performs binary threshold
    void performThreshold(const cv::Mat& grayscale, cv::Mat& thresholdImg) const;
    
    //! Detects appropriate contours
    void findContours(cv::Mat& thresholdImg, ContoursVector& contours, int minContourPointsAllowed) const;
    
    //! Finds marker candidates among all contours
    void findCandidates(const ContoursVector& contours, std::vector<Marker>& detectedMarkers);
    
    //! Tries to recognize markers by detecting marker code
    void recognizeMarkers(const cv::Mat& grayscale, std::vector<Marker>& detectedMarkers);
    
    //! Calculates marker poses in 3D
    void estimatePosition(std::vector<Marker>& detectedMarkers);
    
private:
    float m_minContourLengthAllowed;
    
    cv::Size markerSize;
    cv::Mat camMatrix;
    cv::Mat distCoeff;
    std::vector<Transformation> m_transformations;
    
    cv::Mat m_grayscaleImage;
    cv::Mat m_thresholdImg;
    cv::Mat canonicalMarkerImage;
    
    ContoursVector           m_contours;
    std::vector<cv::Point3f> m_markerCorners3d;
    std::vector<cv::Point2f> m_markerCorners2d;
};

#endif /* defined(_____MarkerDetector__) */
