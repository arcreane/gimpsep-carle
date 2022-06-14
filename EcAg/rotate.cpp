#include "rotate.h"

int Rotate(string img_path, int angle)
{
	Mat source, M, result;

	source = imread(img_path);
	if (source.empty())
	{
		printf("Could not open or find the image");
		system("pause");
		return -1;
	}

	Point2f center(source.cols / 2, source.rows / 2);
	double scale = 1;

	// Getting the matrix which will define the rotation
	M = getRotationMatrix2D(center, angle, scale);

	// Rotating the source and storing in result
	warpAffine(source, result, M, result.size());

	// Create windows for display
	String windowName = "RotatedImage";


	// Display images
	namedWindow(windowName);

	imshow(windowName, result);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, result);
	}

	return 0;
}
