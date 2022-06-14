#define _CRT_SECURE_NO_WARNINGS
#include "erode.h";

int Erode(string img_path) {

	Mat image;
	image = imread(img_path);
	if (image.empty()) // Check for failure
	{
		printf("Could not open or find the image");
		system("pause"); //wait for any key press
		return -1;
	}

	int erode_size;

	cout << "Please select your dilatation size" << endl;
	scanf("%d", &erode_size);

	Mat eroded_image;
	Mat element = getStructuringElement(
		MORPH_RECT, Size(2 * erode_size + 1,
			2 * erode_size + 1),
		Point(erode_size, erode_size));
	erode(image, eroded_image, element, Point(-1, -1), 1);

	String windowName = "Dilated image";

	namedWindow(windowName);

	imshow(windowName, eroded_image);

	waitKey(0);

	destroyWindow(windowName);

	string save;
	cout << "Do you want to save your image ? (Yes or Not) " << endl;
	cin >> save;
	if (save == "Yes" || save == "yes") {
		string path;
		cout << "Please enter the path and the name of your wanted image ? " << endl;
		cin >> path;
		imwrite(path, eroded_image);
	}

	return 0;

}