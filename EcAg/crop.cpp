#include "crop.h"
using namespace std;
using namespace cv;

int Crop(string img_path, int xstart, int xend, int ystart, int yend)
{
	Mat source;
	source = imread(img_path);

	Mat crop = source(Range(xstart, xend), Range(ystart, yend));

	String windowName = "CroppedImage";

	namedWindow(windowName);
;

imshow(windowName, crop);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, crop);
	}

	return 0;
}
