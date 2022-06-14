#ifndef CROP_H    
#define CROP_H

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int Crop(string img_path, int xstart, int xend, int ystart, int yend);

#endif
