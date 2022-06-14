#define _CRT_SECURE_NO_WARNINGS
#include "canny.h";

int Canny_image(string img_path) {

	Mat image;
	image = imread(img_path);
	if (image.empty()) // Check for failure
	{
		printf("Could not open or find the image");
		system("pause"); //wait for any key press
		return -1;
	}

	double treshold1;
	double treshold2;
	int kernel;

	cout << "Please select your first treshold" << endl;
	scanf("%lf", &treshold1);
	cout << "Please select your second treshold" << endl;
	scanf("%lf", &treshold2);
	cout << "Please select your kernel" << endl;
	scanf("%d", &kernel);

	Mat canny_image;


	Canny(image, canny_image, treshold1, treshold2, kernel, false);

	String windowName = "Canny image";

	namedWindow(windowName);

	imshow(windowName, canny_image);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, canny_image);
	}

	return 0;

}