#include "videoRead.h"


int VideoRead(string vid_path) {

    // Create a VideoCapture object and open the input file
    // If the input is the web camera, pass 0 instead of the video file name VideoCapture cap(0);
    VideoCapture cap(vid_path);

    // Check if camera opened successfully
    if (!cap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }

    while (1) {

        Mat frame;
        // Capture frame-by-frame
        cap >> frame;

        // If the frame is empty, break immediately
        if (frame.empty())
        {
            break;
        }

        
        // Display the resulting frame
        String windowName = "frame";
        namedWindow(windowName);
        imshow(windowName, frame);

        // Press  ESC on keyboard to exit
        char c = (char)waitKey(25);
        if (c == 27)
            break;
    }

    // When everything done, release the video capture object
    cap.release();

    // Closes all the frames
    destroyAllWindows();

    return 0;
}
