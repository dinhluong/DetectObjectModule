//
//  PDLViewController.m
//  5
//
//  Created by LTT on 10/16/14.
//  Copyright (c) 2014 PDL. All rights reserved.
//

#import "PDLViewController.h"
#import "VideoSource.h"
#import "MarkerDetector.hpp"
#import "SimpleVisualizationController.h"

@interface PDLViewController() <VideoSourceDelegate>

@property (strong, nonatomic) VideoSource * videoSource;
@property (nonatomic) MarkerDetector * markerDetector;
@property (strong, nonatomic) SimpleVisualizationController * visualizationController;

@end

@implementation PDLViewController
@synthesize glview, videoSource, markerDetector, visualizationController;

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
	// Do any additional setup after loading the view, typically from a nib.
    self.videoSource = [[VideoSource alloc] init];
    self.videoSource.delegate = self;
    
    self.markerDetector = new MarkerDetector([self.videoSource getCalibration]);
    [self.videoSource startWithDevicePosition:AVCaptureDevicePositionBack];
}

- (void)viewDidUnload
{
    // Release any retained subviews of the main view.
    [self setGlview:nil];
    [super viewDidUnload];
}

- (void)viewWillAppear:(BOOL)animated
{
    [self.glview initContext];
    
    CGSize frameSize = [self.videoSource getFrameSize];
    CameraCalibration camCalib = [self.videoSource getCalibration];
    
    self.visualizationController = [[SimpleVisualizationController alloc] initWithGLView:self.glview
                                                                             calibration:camCalib
                                                                               frameSize:frameSize];
    
    [super viewWillAppear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Important notice:
    // Since the logical interface orientation differs from coordinate system of video frame
    // We force the interface orientation to landscape right for simplicity.
    // This orientation has one-to-one coordinates mapping from frame buffer to view.
    // So we don't have to worry about inconsistent AR.
    return interfaceOrientation == UIInterfaceOrientationLandscapeRight;
}

- (void) dealloc
{
    delete self.markerDetector;
}


#pragma mark - VideoSourceDelegate
-(void)frameReady:(BGRAVideoFrame) frame
{
    // Start upload new frame to video memory in main thread
    dispatch_sync( dispatch_get_main_queue(), ^{
        [self.visualizationController updateBackground:frame];
    });
    
    // And perform processing in current thread
    self.markerDetector->processFrame(frame);
    
    // When it's done we query rendering from main thread
    dispatch_async( dispatch_get_main_queue(), ^{
        [self.visualizationController setTransformationList:(self.markerDetector->getTransformations)()];
        [self.visualizationController drawFrame];
    });
}

@end