#define _CRT_SECURE_NO_WARNINGS
#include "brightness.h"

int Brightness(string img_path)
{
	Mat image;
	image = imread(img_path);
	if (image.empty()) // Check for failure
	{
		printf("Could not open or find the image");
		system("pause"); //wait for any key press
		return -1;
	}

	int brightness_factor;
	cout << "Please select your birghtness factor" << endl;
	scanf("%d", &brightness_factor);

	Mat lighten_image;
	image.convertTo(lighten_image, -1, 1, brightness_factor);

	String windowName = "BrightnessImage";

	namedWindow(windowName);	

	imshow(windowName, lighten_image);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, lighten_image);
	}

	return 0;
}
