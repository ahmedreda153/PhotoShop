#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char secondImage[SIZE][SIZE][RGB];

void Menu();
void loudImage();
void saveImage();
void invert();
void enlargeImage();
void mirrorImage();
void shrinkImage();
void shuffleImage();

int main()
{
    char choice;
    loudImage();
    while (true)
    {
        Menu();
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "You're Now Using The Black and White Filter" << endl;
            break;

        case '2':
            cout << "You're Now Using The Invert Filter" << endl;
            invert();
            break;

        case '3':
            cout << "You're Now Using The Merge Filter" << endl;

            break;

        case '4':
            cout << "You're Now Using The Flip Filter" << endl;

            break;

        case '5':
            cout << "You're Now Using The Darken and Lighten Filter" << endl;

            break;

        case '6':
            cout << "You're Now Using The rotate Filter" << endl;

            break;

        case '7':
            cout << "You're Now Using The Detect Image Edges Filter" << endl;

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
            break;

        case 's':
            saveImage();
            cout << "photo saved" << endl;
            break;

        case 'l':
            cout << "u can load another image and apply filters on it after save the first" << endl;

            break;

        case '0':
            cout << "Thanks For Using The App" << endl;
            return 0;
        }
    }
}

void Menu()
{
    cout << "\n1-Black & White Filter\n2-Invert Filter\n3-Merge Filter\n4-Flip Image\n5-Darken and Lighten Image\n6-rotate Image\n7-Detect Image Edges\n8-Enlarge Image" << endl;
    cout << "9-Shrink Image\na-Mirror 1/2 Image\nb-Shuffle Image\nc-Blur Image\ns-Save The Image to a File\nl-Load another image after save the first\n0-Exit" << endl;
    cout << "\nPlease select a filter to apply or 0 to exit the program: ";
}

void loudImage()
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
