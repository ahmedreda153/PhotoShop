
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char secondImage[SIZE][SIZE];
unsigned char newImage[SIZE][SIZE];

void displayMenu();
void loadImage ();
void saveImage ();
void blackWhite();
void invert();
void mergeImages();
void loadAnother();
void flip(char choice);
void rotateImage(int angle);



int main()
{
	char choice;
		displayMenu();
		cin >> choice;

		switch (choice) {
		case '0':
			cout << "Thanks For Using The App" << endl;
			break;

		case '1':
		    cout << "You're Now Using The Black and White Filter"<<endl;
		    loadImage ();
		    blackWhite();
            saveImage ();
            break;


		case'2':
            cout << "You're Now Using The Invert Filter"<<endl;
            loadImage();
            invert();
            saveImage();
            break;

		case'3':
		    cout << "You're Now Using The Merge Filter"<<endl;
		    loadImage();
		    loadAnother();
		    mergeImages();
		    saveImage();
		    break;

		case'4':
		    char flipChoice;
		    cout << "You're Now Using The Flip Filter"<<endl;
		    loadImage();
		    cout <<"Do you want to Flip (h)orizontally or (v)ertically ? ";
		    cin >>  flipChoice;
		    flip(flipChoice);
		    saveImage();
		    break;

//		case'5':


		case'6':
		    int angle;
		    cout << "You're Now Using The Rotate Filter"<<endl;
		    loadImage();
		    cout <<"Please Choose the angle (90 - 180 - 270):  ";
		    cin >> angle;
		    rotateImage(angle);
		    saveImage();
		    break;
/*		case'7':

		case'8':

		case'9':

		case'a':

		case'b':

		case'c':

		case's':

*/
		}

}

void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}


void loadAnother(){

char secondImageName[100];
cout << "Enter the image file name you want to merge with: ";
cin >> secondImageName;

strcat (secondImageName, ".bmp");
readGSBMP(secondImageName, secondImage);

}


void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter The Name You Want To Save The Image With: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

void displayMenu() {
		cout << "Please select a filter to apply or 0 to exit the program" << endl;
		cout << "1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-Rotate Image\n7-Detect Image Edges\n8-Enlarge Image" << endl;
		cout << "9-Shrink Image\na-Miror 1/2 Image\nb-Shuffle Image\nc-Blur Image\nd-Save The Image to a File\n0-Exit" << endl;


}

void blackWhite(){

long avg = 0;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {

    avg += image[i][j];

    }
  }

  avg /= (SIZE*SIZE);

cout <<"The Average is: " <<avg << endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

    if (image[i][j] > avg){

        image[i][j] = 255;
    }
    else{

        image[i][j] = 0;
    }
    }
  }
}

void invert(){

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j] = 255 - image[i][j];

        }
    }
}

void mergeImages(){
    int avg;
        for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        avg = 0;
        avg = image[i][j] + secondImage[i][j];
        avg /= 2;
        image[i][j] = avg;
        }
    }


}

void flip(char choice){


if (choice == 'v'){

for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

        newImage[255-i][j] = image[i][j];

        }
}
}

else if (choice == 'h'){

for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

        newImage[i][255-j] = image[i][j];

        }
}

}
for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

         image[i][j] = newImage[i][j] ;

        }
}
}

void rotateImage(int angle){
if (angle == 90){
    for (int i = 0; i < SIZE ; i++) {
        for (int j = i; j< SIZE; j++) {
                int temp = image[i][j];
                image[i][j] = image[j][i];
                image[j][i] = temp;
        }
    }
flip('v');
}
if (angle == 180){

    rotateImage(90);
    rotateImage(90);

}
if (angle == 270){
        rotateImage(90);
        rotateImage(90);
        rotateImage(90);
}
}

