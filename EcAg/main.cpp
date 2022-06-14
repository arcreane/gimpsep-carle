#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

int main(void) {

	map<int, String> features = { {1, "1 - Crop image ",},
								{2, "2 - Resize image ",},
								{3, "3 - Rotate image ",},
								{4, "4 - Put image in grey ",},
								{5, "5 - Dilate image",},
								{6, "6 - Erode image",},
								{7, "7 - Change birghness of image",},
								{8, "8 - Canny image",},
								{9, "9 - Stitching images",},
								{10, "10 - Play Video"},
								{0, "0 - Exit",} };
	int selected_feature;
	char path[100];
	char path2[100];
	int xstart;
	int ystart;
	int xend;
	int yend;
	double scaleX;
	double scaleY;
	int angle;
	bool loopContinue = true;
	
	//Accueil de l'utilisateur
	printf("Hello there, i'm GIMP-like image editor.\n");

	//Lancement de la boucle de l'application
	while (loopContinue) {

		//Exposition des features disponibles
		printf("Please enter the number of what do you want to do :\n");
		for (auto it = features.cbegin(); it != features.cend(); ++it) {
			cout << it->second << endl;
		}

		//Choix de la feature par l'utilisateur
		scanf("%d", &selected_feature);


		//Execution des choix de l'utilisateur
		switch (selected_feature) {

			//Crop Image
			case 1:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				cout << "Enter the X Start of your image : " << endl;
				scanf("%d", &xstart);
				cout << "Enter the X End of your image : " << endl;
				scanf("%d", &xend);
				cout << "Enter the Y Start of your image : " << endl;
				scanf("%d", &ystart);
				cout << "Enter the Y End of your image : " << endl;
				scanf("%d", &yend);
				Crop(path, xstart, xend, ystart, yend);
				break;
			

			//Resize Image
			case 2:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				cout << "Enter the X scale of your image : " << endl;
				scanf("%lf", &scaleX);
				cout << "Enter the Y scale of your image : " << endl;
				scanf("%lf", &scaleY);
				Resize(path, scaleX, scaleY);
				break;

			//Rotate Image
			case 3:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				cout << "Select angle of rotation :" << endl;
				scanf("%d", &angle);
				Rotate(path, angle);
				break;
			
			//Put image in grey
			case 4:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				SaveGrey(path);
				break;
			//Dilate image
			case 5:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				Dilatation(path);
				break;
			//Erode image
			case 6:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				Erode(path);
				break;
			//Brightness
			case 7:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				Brightness(path);
				break;
			//Brightness
			case 8:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your image : " << endl;
				cin >> path;
				Canny_image(path);
				break;
			//Stitching
			case 9:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your first image : " << endl;
				cin >> path;
				cout << "Enter the path of your second image : " << endl;
				cin >> path2;
				Stitching(path, path2);
				break;
			//Read Video
			case 10:
				cout << "You've selected : " << features.find(selected_feature)->second << endl;
				cout << "Enter the path of your video : " << endl;
				cin >> path;
				VideoRead(path);
				break;
			//Exit App
			case 0:
				loopContinue = false;
				break;
			default:
				cout << "Your selected feature doesn't exist, please retry :" << endl;
		}
	}
	return 0;

}
