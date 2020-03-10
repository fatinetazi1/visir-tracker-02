#include "types.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/video.hpp"
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;

// Function Headers
vector<Point2f> featureExtraction(Mat frame);

// Global variables

// Runner
int main(int argc, const char** argv) {
    VideoCapture camera; // Camera
    Mat img; // Image
    int frames = 0; // Frames counter
    
    // Problem 2.1
    
    // Reading the video stream
    if (!camera.open(0)) {
        cout << "Error opening video camera" << endl;
        return 1;
    }
    
    vector<Point2f> corners; // Features
    
    // Loop 1
    for(;;) {
        camera >> img;
        
        // Detect features every 300-th frame
        if (frames%300 == 0) {
            corners = featureExtraction(img); // Apply Shi-Tomasi corner detector
        }
        
        // Visualize corners detected
        for(int i = 0; i < corners.size(); i++) {
            circle(img, corners[i], 4, Scalar( 255, 0, 0 ), 4);
        }
        
        //Show result
        imshow("Camera - Feature Extraction", img);
        
        int key = waitKey(5);
        if (key == 27 || key == 'q') break;
        
        frames++;
    }
    
    camera.release();
    
    // Problem 2.2
    
    // Reading the video stream
    if (!camera.open(0)) {
        cout << "Error opening video camera" << endl;
        return 1;
    }
    
    // Reset frames counter
    frames = 0;
    
    // Random colors
    vector<Scalar> colors;
    RNG rng;
    for(int i = 0; i < 100; i++) {
        int r = rng.uniform(0, 256);
        int g = rng.uniform(0, 256);
        int b = rng.uniform(0, 256);
        colors.push_back(Scalar(r,g,b));
    }
    
    Mat old, old_gray;
    Mat recent, recent_gray;
    vector<Point2f> old_corners, recent_corners, good_recent_corners; // Features
    
    //First frame
    camera >> old;
    cvtColor(old, old_gray, COLOR_BGR2GRAY);
    
    // Find corners of first frame
    old_corners = featureExtraction(img);
    
    // Create a mask image for drawing purposes
    Mat mask = Mat::zeros(img.size(), img.type());
    
    // Loop 2
    for(;;) {
        if (frames%2 == 0) {
            camera >> recent;
            cvtColor(recent, recent_gray, COLOR_BGR2GRAY);
            
            // calcOpticalFlowPyrLK arguments
            vector<uchar> status;
            vector<float> err;
            TermCriteria criteria = TermCriteria((TermCriteria::COUNT) + (TermCriteria::EPS), 10, 0.03);
            
            // Calculate optical flow
            calcOpticalFlowPyrLK(old_gray, recent_gray, old_corners, recent_corners, status, err, Size(15,15), 2, criteria);
            
            for(int i = 0; i < old_corners.size(); i++) {
                // Select good points
                if(status[i] == 1) {
                    good_recent_corners.push_back(recent_corners[i]);
                    
                    // Problem 2.3 Optical Flow Visualization
                    line(mask, recent_corners[i], old_corners[i], colors[i], 2);
                    circle(recent, recent_corners[i], 5, colors[i], -1);
                }
            }
            
            // Show results
            add(recent, mask, recent);
            imshow("Camera - Sparse Optical Flow Estimation", recent);
            
            int keyboard = waitKey(30);
            if (keyboard == 'q' || keyboard == 27)
                break;
            
            old_gray = recent_gray.clone(); // Update the previous frame
            old_corners = good_recent_corners; // Update previous corners
        }
        frames++;
    }
    
    return 0;
}


// Feature Extraction
vector<Point2f> featureExtraction(Mat frame) {
    Mat frame_gray;
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY); // Convert to grayscale
    vector<Point2f> corners;

    // Apply corner detection
    goodFeaturesToTrack(frame_gray, corners, 200, 0.01, 10,
                        Mat(), 3, false, 0.04);
    
    // Return features
    return corners;
}
