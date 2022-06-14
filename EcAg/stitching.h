#ifndef STITCHING_H    
#define STITCHING_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>

using namespace std;
using namespace cv;

int Stitching(string img1, string img2);

#endif