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
void loadImage();
void saveImage();
void blackWhite();
void invert();
void mergeImages();
void loadAnother();
void flip(char choice);
void Darken_Lighten();
void rotateImage(int angle);
void Detect_Image_Edges();
void Shrink_Image();
void rotateimage2();
void mirrorImage();
void blur();

int main()
{
    char choice;
    displayMenu();
    cin >> choice;

    switch (choice)
    {
    case '0':
        cout << "Thanks For Using The App" << endl;
        break;

    case '1':
        cout << "You're Now Using The Black and White Filter" << endl;
        loadImage();
        blackWhite();
        saveImage();
        break;

    case '2':
        cout << "You're Now Using The Invert Filter" << endl;
        loadImage();
        invert();
        saveImage();
        break;

    case '3':
        cout << "You're Now Using The Merge Filter" << endl;
        loadImage();
        mergeImages();
        saveImage();
        break;

    case '4':
        char flipChoice;
        cout << "You're Now Using The Flip Filter" << endl;
        loadImage();
        cout << "Do you want to Flip (h)orizontally or (v)ertically ? ";
        cin >> flipChoice;
        flip(flipChoice);
        saveImage();
        break;

    case '5':
        int temp;
        cout << "You're Now Using The Darken and Lighten Filter" << endl;
        loadImage();
        cout << "1-Darken" << endl;
        cout << "2-Lighten" << endl;
        cout << "choose :";
        cin >> temp;
        Darken_Lighten();
        saveImage();
        break;

    case '6':
        int angle;
        cout << "You're Now Using The rotate Filter" << endl;
        loadImage();
        cout << "Please Choose the angle (90 - 180 - 270):  ";
        cin >> angle;
        rotateImage(angle);
        // rotateimage2();
        saveImage();
        break;

    case '7':
        cout << "You're Now Using The Detect Image Edges Filter" << endl;
        loadImage();
        Detect_Image_Edges();
        saveImage();
        break;

        // case'8':

    case '9':
        int temp1;
        cout << "You're Now Using The Shrink Filter" << endl;
        loadImage();
        cout << "1-Shrink to (1/2)" << endl;
        cout << "2-Shrink to (1/3)" << endl;
        cout << "3-Shrink to (1/4)" << endl;
        cout << "choose: ";
        cin >> temp1;
        Shrink_Image();
        saveImage();
        break;

    case 'a':
        int num;
        cout << "You're Now Using The Mirror Filter" << endl;
        loadImage();
        cout << "do you want to mirror the \n1.Right half\n2.Left half\n3.Upper half\n4.Lowe half" << endl;
        cin>>num;
        mirrorImage();
        saveImage();
        break;



        // case'b':

        case'c':
        cout << "You're Now Using The Blur Filter" << endl;
        loadImage();
        blur();
        saveImage();



        // case's':
    }
}

void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void mirrorImage(){
    int num;
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<SIZE; j++){
            if (j<128){
                if(num==1){
                    image[i][255-j]=image[i][j];
                }
                else if(num==2){
                    image[i][j]=image[i][255-j];
                }
                else if (num==3){
                    image[255-i][255-j]=0;
                }
            }
        }
    }
}

void rotateimage2(){
    for (int i = 0; i < SIZE; i++){
        for (int j=0; j<SIZE; j++){
            image[i][j]=image[j][255-i];
            // image[j][255-i]=image[255-i][255-j];
            // image[i][j]=image[i][255-j];
            // image[i][255-j]=image[255-i][255-j];
            // image[255-i][255-j]=image[255-i][j];
        }
    }
    // for (int i=0; i<SIZE; i++){
    //     for (int j=0; j<SIZE; j++){
    //         if (i<128){
    //             image[j][i]=image[j][255-i];
    //         }
    //     }
    // }
}

// void loadAnother(){

// char secondImageName[100];
// cout << "Enter the image file name you want to merge with: ";
// cin >> secondImageName;

// strcat (secondImageName, ".bmp");
// readGSBMP(secondImageName, secondImage);
// }

void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter The Name You Want To Save The Image With: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void displayMenu()
{
    cout << "Please select a filter to apply or 0 to exit the program" << endl;
    cout << "1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-rotate Image\n7-Detect Image Edges\n8-Enlarge Image" << endl;
    cout << "9-Shrink Image\na-Miror 1/2 Image\nb-Shuffle Image\nc-Blur Image\nd-Save The Image to a File\n0-Exit" << endl;
}

void blackWhite()
{

    long avg = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            avg += image[i][j];
        }
    }

    avg /= (SIZE * SIZE);

    cout << "The Average is: " << avg << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (image[i][j] > avg)
            {

                image[i][j] = 255;
            }
            else
            {

                image[i][j] = 0;
            }
        }
    }
}

void invert()
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            image[i][j] = 255 - image[i][j];
        }
    }
}

void mergeImages()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            secondImage[i][j] = image[i][j];
        }
    }
    cout << "Enter the name of the second photo without (.bmp) ";
    loadImage();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = (secondImage[i][j] + image[i][j]) / 2;
        }
    }
}

void flip(char choice)
{

    if (choice == 'v')
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                newImage[255 - i][j] = image[i][j];
            }
        }
    }

    else if (choice == 'h')
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                newImage[i][255 - j] = image[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            image[i][j] = newImage[i][j];
        }
    }
}

void Darken_Lighten()
{
    int temp;
    if (temp == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][j] / 2;
            }
        }
    }
    else if (temp == 2)
    {
        int num = 0;
        int i, j;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if ((image[i][j] + (image[i][j] / 2)) > 255)
                {
                    image[i][j] = 255;
                }
                else
                {
                    image[i][j] = image[i][j] + (image[i][j] / 2);
                }
            }
        }
    }
    else
        cout << "ERROR INVALID CHOOSE";
}

// void rotateImage(int angle)
// {
//     if (angle == 90)
//     {
//         for (int i = 0; i < SIZE; i++)
//         {
//             for (int j = i; j < SIZE; j++)
//             {
//                 int temp = image[i][j];
//                 image[i][j] = image[j][i];
//                 image[j][i] = temp;
//             }
//         }
//         flip('v');
//     }
//     if (angle == 180)
//     {

//         secondImageateImage(90);
//         secondImageateImage(90);
//     }
//     if (angle == 270)
//     {
//         secondImageateImage(90);
//         secondImageateImage(90);
//         secondImageateImage(90);
//     }
// }

void rotateImage(int angle)
{
    if (angle == 90)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                secondImage[255 - j][i] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image[i][j] = secondImage[i][j];
            }
        }
    }
    if (angle == 180)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                secondImage[255 - i][255 - j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image[i][j] = secondImage[i][j];
            }
        }
    }
    if (angle == 270)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                secondImage[255 - j][i] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image[i][j] = secondImage[i][j];
            }
        }
    }
}

void Detect_Image_Edges()
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            if ((abs(image[i][j] - image[i][j + 1]) >= 40) || (abs(image[i][j] - image[i + 1][j]) >= 40))
            {
                image[i][j] = 0;
            }
            else
            {
                image[i][j] = 255;
            }
        }
    }
}

void Shrink_Image()
{
    int temp1;
    if (temp1 == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i / 2][j / 2] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 2; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
    }
    if (temp1 == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i / 3][j / 3] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 3; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i = SIZE / 3; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
    }
    if (temp1 == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i / 4][j / 4] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 4; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
        for (int i = SIZE / 4; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = 255;
            }
        }
    }
}



void blur(){
unsigned char space[258][258];
long avg;
        for (int i = 0; i < SIZE; ++i){
            for (int j = 0; j < SIZE; ++j){
                    avg += image[i][j];
            }
        }

        avg /= SIZE*SIZE;

        for (int i = 0; i < 258; ++i){
            for (int j = 0; j < 258; ++j){
                space[i][j] = avg;

            }
        }
        for (int i = 1; i < 258; ++i){
            for (int j = 1; j < 258; ++j){

                space[i][j] = image[i-1][j-1];
            }
            }

        for (int i = 1; i < 258; ++i){
            for (int j = 1; j < 258; ++j){
            int kernel;
            kernel = space[i-1][j-1] + space[i-1][j] + space[i-1][j+1] + space[i][j-1] + space[i][j] + space[i][j+1] + space[i+1][j-1] + space[i+1][j] + space[i][j+1];
            kernel /= 9;
            space[i][j] = kernel;

            }
        }
        for (int i = 1; i < 258; ++i){
            for (int j = 1; j < 258; ++j){

                 image[i-1][j-1] = space[i][j];
            }
            }

}
