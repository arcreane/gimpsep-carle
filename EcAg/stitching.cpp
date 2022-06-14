#include "stitching.h";

Stitcher::Mode mode = Stitcher::PANORAMA;

vector<Mat> imgs;

int Stitching(string img1, string img2)
{
    Mat img_first = imread(img1);
    Mat img_second = imread(img2);

    if (img_first.empty())
    {
        cout << "Can't read image '" << img_first << "'\n";
        return -1;
    }
    if (img_second.empty())
    {
        cout << "Can't read image '" << img_second << "'\n";
        return -1;
    }
    imgs.push_back(img_first);
    imgs.push_back(img_second);



    Mat pano;

    Ptr<Stitcher> stitcher = Stitcher::create(mode, false);

    Stitcher::Status status = stitcher->stitch(imgs, pano);

    

    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images\n";
        return -1;
    }

    String windowName = "StitchingImages";
    namedWindow(windowName);

    imshow(windowName, pano);

    waitKey(0);
    destroyWindow(windowName);

    string save;
    cout << "Do you want to save your image ? (Yes or Not) " << endl;
    cin >> save;
    if (save == "Yes" || save == "yes") {
        string path;
        cout << "Please enter the path and the name of your wanted image ? " << endl;
        cin >> path;
        imwrite(path, pano);
    }

    return 0;
}