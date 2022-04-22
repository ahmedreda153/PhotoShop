// FCAI - Programming 1 - 2022 - Assignment 3
// Program Name: Photoshop
// Program Description: Apply filters on RGB (bmp) photos
// Last Modification Date: 04/4/2022
// First author - ID : Salma Mohammed Mahmoud / 20210161
// Second author - ID : Mohamed Ehab Tawfik / 20210331
// Third author - ID : Ahmed Reda Elsayed / 20210018
// Under The Supervision of: Dr. Mohamed El-Ramly

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char secondImage[SIZE][SIZE][RGB];

void displayMenu();
void loadImage();
void saveImage();
void blackWhite();
void invert();
void mergeImages();
void flipImage();
void darkenLighten();
void rotateImage();
void detectImageEdges();
void enlargeImage();
void shrinkImage();
void mirrorImage();
void shuffleImage();
void blur();

int main()
{
    char choice;
    loadImage();
    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "You're Now Using The Black and White Filter" << endl;
            blackWhite();
            break;

        case '2':
            cout << "You're Now Using The Invert Filter" << endl;
            invert();
            break;

        case '3':
            cout << "You're Now Using The Merge Filter" << endl;
            mergeImages();
            break;

        case '4':
            cout << "You're Now Using The Flip Filter" << endl;
            flipImage();
            break;

        case '5':
            cout << "You're Now Using The Darken and Lighten Filter" << endl;
            darkenLighten();
            break;

        case '6':
            cout << "You're Now Using The rotate Filter" << endl;
            rotateImage();
            break;

        case '7':
            cout << "You're Now Using The Detect Image Edges Filter" << endl;
            detectImageEdges();
            break;

        case '8':
            cout << "You're Now Using The Enlarge Filter" << endl;
            enlargeImage();
            break;

        case '9':
            cout << "You're Now Using The Shrink Filter" << endl;
            shrinkImage();
            break;

        case 'a':
            cout << "You're Now Using The Mirror Filter" << endl;
            mirrorImage();
            break;

        case 'b':
            cout << "You're Now Using The Shuffle Filter" << endl;
            shuffleImage();
            break;

        case 'c':
            cout << "You're Now Using The Blur Filter" << endl;
            blur();
            break;

        case 's':
            saveImage();
            cout << "photo saved" << endl;
            break;

        case 'l':
            cout << "u can load another image and apply filters on it after save the first" << endl;
            loadImage();
            break;

        case '0':
            cout << "Thanks For Using The App" << endl;
            return 0;
        }
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
    readRGBBMP(imageFileName, image);
}

void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter The Name You Want To Save The Image With: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

void displayMenu()
{
    cout << "\n1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-rotate Image\n7-Detect Image Edges\n8-Enlarge Image" << endl;
    cout << "9-Shrink Image\na-Miror 1/2 Image\nb-Shuffle Image\nc-Blur Image\ns-Save The Image to a File\nl-Load another image after save the first\n0-Exit" << endl;
    cout << "\nPlease select a filter to apply or 0 to exit the program: ";
}

void blackWhite()
{

    long avg = 0;
    int temp;
    int rgb;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                avg += image[i][j][k];
            }
        }
    }

    avg /= SIZE * SIZE * RGB;

    cout << "The Average is: " << avg << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                temp += image[i][j][k];
                rgb = k;
            }
            temp /= 3;
            if (temp >= avg)
            {
                image[i][j][rgb] = 255;
                image[i][j][rgb - 1] = 255;
                image[i][j][rgb - 2] = 255;
            }
            else
            {
                image[i][j][rgb] = 0;
                image[i][j][rgb - 1] = 0;
                image[i][j][rgb - 2] = 0;
            }
            temp = 0;
        }
    }
}

void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
}

void mergeImages()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                secondImage[i][j][k] = image[i][j][k];
            }
        }
    }
    cout << "Now Choose The Second Image: " << endl;
    loadImage();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = (secondImage[i][j][k] + image[i][j][k]) / 2;
            }
        }
    }
}

void flipImage()
{
    int choice;
    cout << "do yo want to flip the photo \n1.horizontal\n2.vertical\n";
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {

                    secondImage[i][255 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    secondImage[255 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {

                image[i][j][k] = secondImage[i][j][k];
            }
        }
    }
}

void darkenLighten()
{
    char character;
    cout << "choose (d) if u want to darken the image" << endl;
    cout << "choose (l) if u want to lighten the image" << endl;
    cout << "choose: ";
    cin >> character;
    if (character == 'd')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = image[i][j][k] / 2;
                }
            }
        }
    }
    else if (character == 'l')
    {
        int num = 0;
        int i, j;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if ((image[i][j][k] + (image[i][j][k] / 2)) > 255)
                    {
                        image[i][j][k] = 255;
                    }
                    else
                    {
                        image[i][j][k] = image[i][j][k] + (image[i][j][k] / 2);
                    }
                }
            }
        }
    }
    else
        cout << "ERROR INVALID CHOOSE";
}

void rotateImage()
{
    int angle;
    cout << "Please Choose the angle (90 - 180 - 270):  ";
    cin >> angle;

    if (angle == 270)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    secondImage[255 - j][i][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = secondImage[i][j][k];
                }
            }
        }
    }
    if (angle == 180)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    secondImage[255 - i][255 - j][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = secondImage[i][j][k];
                }
            }
        }
    }
    if (angle == 90)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    secondImage[255 - j][i][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = secondImage[i][j][k];
                }
            }
        }
    }
}

void detectImageEdges()
{
    unsigned char gsImage[SIZE][SIZE];
    int temp;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                temp += image[i][j][k];
            }
            temp /= 3;
            gsImage[i][j] = temp;
            temp = 0;
        }
    }

    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            if ((abs(gsImage[i][j] - gsImage[i][j + 1]) >= 40) || (abs(gsImage[i][j] - gsImage[i + 1][j]) >= 40))
            {
                gsImage[i][j] = 0;
            }
            else
            {
                gsImage[i][j] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (gsImage[i][j] == 0)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 0;
                }
            }
            else
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
    }
}

void enlargeImage()
{
    int quarter;
    cout << "1.first quarter\n2.second quarter\n3.third quarter\n4.fourth quarter\npls choose the quarter you want to enlarge: ";
    cin >> quarter;

    if (quarter == 1)
    {
        for (int i = 0; (i < SIZE / 2); i++)
        {
            for (int j = 0; j < (SIZE / 2); j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    int pixel = image[i][j][k];
                    secondImage[i + i][j + j][k] = pixel;
                    secondImage[i + i][j + j + 1][k] = pixel;
                    secondImage[i + i + 1][j + j][k] = pixel;
                    secondImage[i + i + 1][j + j + 1][k] = pixel;
                }
            }
        }
    }
    else if (quarter == 2)
    {
        for (int i = 0; i < (SIZE / 2); i++)
        {
            for (int j = 127; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    int pixel = image[i][j][k];
                    secondImage[i + i][j + j][k] = pixel;
                    secondImage[i + i][j + j + 1][k] = pixel;
                    secondImage[i + i + 1][j + j][k] = pixel;
                    secondImage[i + i + 1][j + j + 1][k] = pixel;
                }
            }
        }
    }
    else if (quarter == 3)
    {
        for (int i = 127; i < SIZE; i++)
        {
            for (int j = 0; j < (SIZE / 2); j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    int pixel = image[i][j][k];
                    secondImage[i * 2 - 127 * 2][j + j][k] = pixel;
                    secondImage[i * 2 - 127 * 2][j + j + 1][k] = pixel;
                    secondImage[i * 2 - 127 * 2 + 1][j + j][k] = pixel;
                    secondImage[i * 2 - 127 * 2 + 1][j + j + 1][k] = pixel;
                }
            }
        }
    }
    else if (quarter == 4)
    {
        for (int i = 127; i < SIZE; i++)
        {
            for (int j = 127; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    int pixel = image[i][j][k];
                    secondImage[i * 2 - 127 * 2][j * 2 - 127 * 2][k] = pixel;
                    secondImage[i * 2 - 127 * 2][j * 2 - 127 * 2 + 1][k] = pixel;
                    secondImage[i * 2 - 127 * 2 + 1][j * 2 - 127 * 2][k] = pixel;
                    secondImage[i * 2 - 127 * 2 + 1][j * 2 - 127 * 2 + 1][k] = pixel;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i][j][k] = secondImage[i][j][k];
            }
        }
    }
}

void shrinkImage()
{
    int dimension;
    cout << "1.shrink image to 1/2\n2.sheink image to 1/3\n3.shrink image to 1/4\n";
    cout << "please choose (1 - 2 - 3): ";
    cin >> dimension;

    if (dimension == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i / 2][j / 2][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 2; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
    }
    if (dimension == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i / 3][j / 3][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 3; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
        for (int i = SIZE / 3; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
    }
    if (dimension == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i / 4][j / 4][k] = image[i][j][k];
                }
            }
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = SIZE / 4; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
        for (int i = SIZE / 4; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][j][k] = 255;
                }
            }
        }
    }
}

void mirrorImage()
{
    int side;
    cout << "do you want to mirror the \n1.Right half\n2.Left half\n3.Upper half\n4.Lowe half" << endl;
    cin >> side;

    if (side == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        image[i][j][k] = image[i][255 - j][k];
                    }
                }
            }
        }
    }
    if (side == 2)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        image[i][255 - j][k] = image[i][j][k];
                    }
                }
            }
        }
    }
    if (side == 3)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        image[255 - j][i][k] = image[j][i][k];
                    }
                }
            }
        }
    }
    if (side == 4)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    if (j < 128)
                    {
                        image[j][i][k] = image[255 - j][i][k];
                    }
                }
            }
        }
    }
}

void shuffleImage()
{
    unsigned char firstQuarter[SIZE][SIZE][RGB];
    unsigned char secondQuarter[SIZE][SIZE][RGB];
    unsigned char thirdQuarter[SIZE][SIZE][RGB];
    unsigned char fourthQuarter[SIZE][SIZE][RGB];

    for (int i = 0; i < (SIZE / 2); i++)
    {
        for (int j = 0; j < (SIZE / 2); j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                firstQuarter[i][j][k] = image[i][j][k];              // temp to save first quarter in image
                secondQuarter[i][j][k] = image[i][j + 128][k];       // temp to save second quarter in image
                thirdQuarter[i][j][k] = image[i + 128][j][k];        // temp to save third quarter in image
                fourthQuarter[i][j][k] = image[i + 128][j + 128][k]; // temp to save fourth quarter in image
            }
        }
    }

    string quartersArrange;
    cout << "please enter the order to rearrange photo quarters: ";
    cin >> quartersArrange;
    int count = 1;
    while (count <= 4)
    {
        if (count == 1) // First Quarter
        {
            for (int i = 0; i < (SIZE / 2); i++)
            {
                for (int j = 0; j < (SIZE / 2); j++)
                {
                    for (int k = 0; k < RGB; k++)
                    {
                        if (quartersArrange[0] == '1')
                        {
                            image[i][j][k] = firstQuarter[i][j][k];
                        }
                        else if (quartersArrange[0] == '2')
                        {
                            image[i][j][k] = secondQuarter[i][j][k];
                        }
                        else if (quartersArrange[0] == '3')
                        {
                            image[i][j][k] = thirdQuarter[i][j][k];
                        }
                        else if (quartersArrange[0] == '4')
                        {
                            image[i][j][k] = fourthQuarter[i][j][k];
                        }
                    }
                }
            }
            count++;
        }
        else if (count == 2) // Second Quarter
        {
            for (int i = 0; i < (SIZE / 2); i++)
            {
                for (int j = 0; j < (SIZE / 2); j++)
                {
                    for (int k = 0; k < RGB; k++)
                    {
                        if (quartersArrange[1] == '1')
                        {
                            image[i][j + 128][k] = firstQuarter[i][j][k];
                        }
                        else if (quartersArrange[1] == '2')
                        {
                            image[i][j + 128][k] = secondQuarter[i][j][k];
                        }
                        else if (quartersArrange[1] == '3')
                        {
                            image[i][j + 128][k] = thirdQuarter[i][j][k];
                        }
                        else if (quartersArrange[1] == '4')
                        {
                            image[i][j + 128][k] = fourthQuarter[i][j][k];
                        }
                    }
                }
            }
            count++;
        }
        else if (count == 3) // Third Quarter
        {
            for (int i = 0; i < (SIZE / 2); i++)
            {
                for (int j = 0; j < (SIZE / 2); j++)
                {
                    for (int k = 0; k < RGB; k++)
                    {
                        if (quartersArrange[2] == '1')
                        {
                            image[i + 128][j][k] = firstQuarter[i][j][k];
                        }
                        else if (quartersArrange[2] == '2')
                        {
                            image[i + 128][j][k] = secondQuarter[i][j][k];
                        }
                        else if (quartersArrange[2] == '3')
                        {
                            image[i + 128][j][k] = thirdQuarter[i][j][k];
                        }
                        else if (quartersArrange[2] == '4')
                        {
                            image[i + 128][j][k] = fourthQuarter[i][j][k];
                        }
                    }
                }
            }
            count++;
        }
        else if (count == 4) // Fourth Quarter
        {
            for (int i = 0; i < (SIZE / 2); i++)
            {
                for (int j = 0; j < (SIZE / 2); j++)
                {
                    for (int k = 0; k < RGB; k++)
                    {
                        if (quartersArrange[3] == '1')
                        {
                            image[i + 128][j + 128][k] = firstQuarter[i][j][k];
                        }
                        else if (quartersArrange[3] == '2')
                        {
                            image[i + 128][j + 128][k] = secondQuarter[i][j][k];
                        }
                        else if (quartersArrange[3] == '3')
                        {
                            image[i + 128][j + 128][k] = thirdQuarter[i][j][k];
                        }
                        else if (quartersArrange[3] == '4')
                        {
                            image[i + 128][j + 128][k] = fourthQuarter[i][j][k];
                        }
                    }
                }
            }
            count++;
        }
    }
}

void blur()
{
    unsigned char space[SIZE + 2][SIZE + 2][RGB];

    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                space[i][j][k] = image[i - 1][j - 1][k];
            }
        }
    }
    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                int kernelR, kernelG, kernelB;
                if (k == 0)
                {
                    kernelR = space[i - 1][j - 1][k] + space[i - 1][j][k] + space[i - 1][j + 1][k] + space[i][j - 1][k] + space[i][j][k] + space[i][j + 1][k] + space[i + 1][j - 1][k] + space[i + 1][j][k] + space[i][j + 1][k];
                    kernelR /= 9;
                    space[i][j][k] = kernelR;
                }
                if (k == 1)
                {

                    kernelG = space[i - 1][j - 1][k] + space[i - 1][j][k] + space[i - 1][j + 1][k] + space[i][j - 1][k] + space[i][j][k] + space[i][j + 1][k] + space[i + 1][j - 1][k] + space[i + 1][j][k] + space[i][j + 1][k];
                    kernelG /= 9;
                    space[i][j][k] = kernelG;
                }
                if (k == 2)
                {

                    kernelB = space[i - 1][j - 1][k] + space[i - 1][j][k] + space[i - 1][j + 1][k] + space[i][j - 1][k] + space[i][j][k] + space[i][j + 1][k] + space[i + 1][j - 1][k] + space[i + 1][j][k] + space[i][j + 1][k];
                    kernelB /= 9;
                    space[i][j][k] = kernelB;
                }
            }
        }
    }
    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[i - 1][j - 1][k] = space[i][j][k];
            }
        }
    }
}