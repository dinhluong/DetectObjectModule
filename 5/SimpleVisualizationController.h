//
//  SimpleVisualizationController.h
//  5
//
//  Created by LTT on 10/21/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "EAGLView.h"
#import "CameraCalibration.hpp"
#import "BGRAVideoFrame.h"
#import "GeometryTypes.hpp"
#import <vector>
@interface SimpleVisualizationController : NSObject
{
    EAGLView * m_glview;
    GLuint m_backgroundTextureId;
    std::vector<Transformation> m_transformations;
    CameraCalibration m_calibration;
    CGSize m_frameSize;
}

-(id) initWithGLView:(EAGLView*)view calibration:(CameraCalibration) calibration frameSize:(CGSize) size;

-(void) drawFrame;
-(void) updateBackground:(BGRAVideoFrame) frame;
-(void) setTransformationList:(const std::vector<Transformation>&) transformations;

@end
