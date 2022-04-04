// FCAI - Programming 1 - 2022 - Assignment 3
// Program Name: Photoshop
// Program Description: Apply filters on gray scale (bmp) photos
// Last Modification Date: 04/4/2022
// First author - ID : Salma Mohamed Mahmoud / 20210161
// Second author - ID : Mohame Ehab Tawfik / 20210331
// Third author - ID : Ahmed Reda Elsayed / 20210018
// Under The Supervision of: Dr. Mohamed El-Ramly

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char secondImage[SIZE][SIZE];

void displayMenu();
void loadImage();
void saveImage();
void blackWhite();
void invert();
void mergeImages();
void flip(char choice);
void darkenLighten(char character);
void rotateImage(int angle);
void detectImageEdges();
void enlargeImage(int quarter);
void shrinkImage(int dimension);
void mirrorImage(int side);
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
            char flipChoice;
            cout << "You're Now Using The Flip Filter" << endl;
            cout << "Do you want to Flip (h)orizontally or (v)ertically ? ";
            cin >> flipChoice;
            flip(flipChoice);
            break;

        case '5':
            char character;
            cout << "You're Now Using The Darken and Lighten Filter" << endl;
            cout << "choose (d) if u want to darken the image" << endl;
            cout << "choose (l) if u want to lighten the image" << endl;
            cout << "choose: ";
            cin >> character;
            darkenLighten(character);
            break;

        case '6':
            int angle;
            cout << "You're Now Using The rotate Filter" << endl;
            cout << "Please Choose the angle (90 - 180 - 270):  ";
            cin >> angle;
            rotateImage(angle);
            break;

        case '7':
            cout << "You're Now Using The Detect Image Edges Filter" << endl;
            detectImageEdges();
            break;

        case '8':
            int quarter;
            cout << "You're Now Using The Enlarge Filter" << endl;
            cout << "1.first quarter\n2.second quarter\n3.third quarter\n4.fourth quarter\npls choose the quarter you want to enlarge: ";
            cin >> quarter;
            enlargeImage(quarter);
            break;

        case '9':
            int dimension;
            cout << "You're Now Using The Shrink Filter" << endl;
            cout << "please choose the dimension (1/2 - 1/3 - 1/4): ";
            cin >> dimension;
            shrinkImage(dimension);
            break;

        case 'a':
            int side;
            cout << "You're Now Using The Mirror Filter" << endl;
            cout << "do you want to mirror the \n1.Right half\n2.Left half\n3.Upper half\n4.Lowe half" << endl;
            cin >> side;
            mirrorImage(side);
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
    readGSBMP(imageFileName, image);
}

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
    cout << "\n1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-rotate Image\n7-Detect Image Edges\n8-Enlarge Image" << endl;
    cout << "9-Shrink Image\na-Miror 1/2 Image\nb-Shuffle Image\nc-Blur Image\ns-Save The Image to a File\nl-Load another image after save the first\n0-Exit" << endl;
    cout << "\nPlease select a filter to apply or 0 to exit the program: ";
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

                secondImage[255 - i][j] = image[i][j];
            }
        }
    }

    else if (choice == 'h')
    {

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                secondImage[i][255 - j] = image[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            image[i][j] = secondImage[i][j];
        }
    }
}

void darkenLighten(char character)
{
    if (character == 'd')
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                image[i][j] = image[i][j] / 2;
            }
        }
    }
    else if (character == 'l')
    {
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
}

void rotateImage(int angle)
{
    if (angle == 90)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                secondImage[j][255 - i] = image[i][j];
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

void detectImageEdges()
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

void enlargeImage(int quarter)
{
    if (quarter == 1)
    {
        for (int i = 0; (i < SIZE / 2); i++)
        {
            for (int j = 0; j < (SIZE / 2); j++)
            {
                int pixel = image[i][j];
                secondImage[i + i][j + j] = pixel;
                secondImage[i + i][j + j + 1] = pixel;
                secondImage[i + i + 1][j + j] = pixel;
                secondImage[i + i + 1][j + j + 1] = pixel;
            }
        }
    }
    else if (quarter == 2)
    {
        for (int i = 0; i < (SIZE / 2); i++)
        {
            for (int j = 127; j < SIZE; j++)
            {
                int pixel = image[i][j];
                secondImage[i + i][j + j] = pixel;
                secondImage[i + i][j + j + 1] = pixel;
                secondImage[i + i + 1][j + j] = pixel;
                secondImage[i + i + 1][j + j + 1] = pixel;
            }
        }
    }
    else if (quarter == 3)
    {
        for (int i = 127; i < SIZE; i++)
        {
            for (int j = 0; j < (SIZE / 2); j++)
            {
                int pixel = image[i][j];
                secondImage[i * 2 - 127 * 2][j + j] = pixel;
                secondImage[i * 2 - 127 * 2][j + j + 1] = pixel;
                secondImage[i * 2 - 127 * 2 + 1][j + j] = pixel;
                secondImage[i * 2 - 127 * 2 + 1][j + j + 1] = pixel;
            }
        }
    }
    else if (quarter == 4)
    {
        for (int i = 127; i < SIZE; i++)
        {
            for (int j = 127; j < SIZE; j++)
            {
                int pixel = image[i][j];
                secondImage[i * 2 - 127 * 2][j * 2 - 127 * 2] = pixel;
                secondImage[i * 2 - 127 * 2][j * 2 - 127 * 2 + 1] = pixel;
                secondImage[i * 2 - 127 * 2 + 1][j * 2 - 127 * 2] = pixel;
                secondImage[i * 2 - 127 * 2 + 1][j * 2 - 127 * 2 + 1] = pixel;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = secondImage[i][j];
        }
    }
}

void shrinkImage(int dimension)
{
    if (dimension == 1 / 2)
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
    if (dimension == 1 / 3)
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
    if (dimension == 1 / 4)
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

void mirrorImage(int side)
{
    if (side == 1)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (j < 128)
                {
                    image[i][j] = image[i][255 - j];
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
                if (j < 128)
                {
                    image[i][255 - j] = image[i][j];
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
                if (j < 128)
                {
                    image[255 - j][i] = image[j][i];
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
                if (j < 128)
                {
                    image[j][i] = image[255 - j][i];
                }
            }
        }
    }
}

void shuffleImage()
{
    unsigned char firstQuarter[SIZE][SIZE];
    unsigned char secondQuarter[SIZE][SIZE];
    unsigned char thirdQuarter[SIZE][SIZE];
    unsigned char fourthQuarter[SIZE][SIZE];

    for (int i = 0; i < (SIZE / 2); i++)
    {
        for (int j = 0; j < (SIZE / 2); j++)
        {
            firstQuarter[i][j] = image[i][j];              // temp to save first quarter in image
            secondQuarter[i][j] = image[i][j + 128];       // temp to save second quarter in image
            thirdQuarter[i][j] = image[i + 128][j];        // temp to save third quarter in image
            fourthQuarter[i][j] = image[i + 128][j + 128]; // temp to save fourth quarter in image
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
                    if (quartersArrange[0] == '1')
                    {
                        image[i][j] = firstQuarter[i][j];
                    }
                    else if (quartersArrange[0] == '2')
                    {
                        image[i][j] = secondQuarter[i][j];
                    }
                    else if (quartersArrange[0] == '3')
                    {
                        image[i][j] = thirdQuarter[i][j];
                    }
                    else if (quartersArrange[0] == '4')
                    {
                        image[i][j] = fourthQuarter[i][j];
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
                    if (quartersArrange[1] == '1')
                    {
                        image[i][j + 128] = firstQuarter[i][j];
                    }
                    else if (quartersArrange[1] == '2')
                    {
                        image[i][j + 128] = secondQuarter[i][j];
                    }
                    else if (quartersArrange[1] == '3')
                    {
                        image[i][j + 128] = thirdQuarter[i][j];
                    }
                    else if (quartersArrange[1] == '4')
                    {
                        image[i][j + 128] = fourthQuarter[i][j];
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
                    if (quartersArrange[2] == '1')
                    {
                        image[i + 128][j] = firstQuarter[i][j];
                    }
                    else if (quartersArrange[2] == '2')
                    {
                        image[i + 128][j] = secondQuarter[i][j];
                    }
                    else if (quartersArrange[2] == '3')
                    {
                        image[i + 128][j] = thirdQuarter[i][j];
                    }
                    else if (quartersArrange[2] == '4')
                    {
                        image[i + 128][j] = fourthQuarter[i][j];
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
                    if (quartersArrange[3] == '1')
                    {
                        image[i + 128][j + 128] = firstQuarter[i][j];
                    }
                    else if (quartersArrange[3] == '2')
                    {
                        image[i + 128][j + 128] = secondQuarter[i][j];
                    }
                    else if (quartersArrange[3] == '3')
                    {
                        image[i + 128][j + 128] = thirdQuarter[i][j];
                    }
                    else if (quartersArrange[3] == '4')
                    {
                        image[i + 128][j + 128] = fourthQuarter[i][j];
                    }
                }
            }
            count++;
        }
    }
}

void blur()
{
    unsigned char space[258][258];
    long avg;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            avg += image[i][j];
        }
    }

    avg /= SIZE * SIZE;

    for (int i = 0; i < 258; ++i)
    {
        for (int j = 0; j < 258; ++j)
        {
            space[i][j] = avg;
        }
    }
    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {

            space[i][j] = image[i - 1][j - 1];
        }
    }

    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {
            int kernel;
            kernel = space[i - 1][j - 1] + space[i - 1][j] + space[i - 1][j + 1] + space[i][j - 1] + space[i][j] + space[i][j + 1] + space[i + 1][j - 1] + space[i + 1][j] + space[i][j + 1];
            kernel /= 9;
            space[i][j] = kernel;
        }
    }
    for (int i = 1; i < 258; ++i)
    {
        for (int j = 1; j < 258; ++j)
        {

            image[i - 1][j - 1] = space[i][j];
        }
    }
}