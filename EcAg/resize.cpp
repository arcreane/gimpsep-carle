#include "resize.h"

int Resize(string img_path, double scaleX, double scaleY)
{
	Mat source, dst;
	source = imread(img_path);

	// Scaling down the image 0.6 times
	resize(source, dst, Size(round(scaleX * source.cols), round(scaleY * source.rows)), INTER_LINEAR);

	String windowName = "ResizedImage";

	namedWindow(windowName);
	imshow(windowName, dst);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, dst);
	}

	return 0;
}
