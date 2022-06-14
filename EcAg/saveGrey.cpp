#include "saveGrey.h"

int SaveGrey(string img_path)
{
	Mat image;
	image = imread(img_path);
	if (image.empty()) // Check for failure
	{
		printf("Could not open or find the image");
		system("pause"); //wait for any key press
		return -1;
	}
	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	//imwrite("C:/Users/cogne/OneDrive/Images/HappyFish2.jpg", gray_image);

	String windowName = "GreyImage";

	namedWindow(windowName);

	imshow(windowName, gray_image);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, gray_image);
	}

	return 0;
}
