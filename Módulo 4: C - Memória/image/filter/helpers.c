#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float b, g, r, average;
    int i, j, avrgint;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            b = image[i][j].rgbtBlue;
            g = image[i][j].rgbtGreen;
            r = image[i][j].rgbtRed;
            average = (b + g + r) / 3;
            avrgint = round(average);
            image[i][j].rgbtBlue = avrgint;
            image[i][j].rgbtGreen = avrgint;
            image[i][j].rgbtRed = avrgint;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float b, g, r;
    int i, j, newb, newg, newr;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            b = image[i][j].rgbtBlue;
            g = image[i][j].rgbtGreen;
            r = image[i][j].rgbtRed;
            newr = round((.393 * r) + (.769 * g) + (.189 * b));
            newg = round((.349 * r) + (.686 * g) + (.168 * b));
            newb = round((.272 * r) + (.534 * g) + (.131 * b));
            if (newr > 255)
            {
                newr = 255;
            }
            if (newb > 255)
            {
                newb = 255;
            }
            if (newg > 255)
            {
                newg = 255;
            }
            image[i][j].rgbtBlue = newb;
            image[i][j].rgbtGreen = newg;
            image[i][j].rgbtRed = newr;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tempb, tempg, tempr;
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            tempb = image[i][j].rgbtBlue;
            tempg = image[i][j].rgbtGreen;
            tempr = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][width - (j + 1)].rgbtBlue = tempb;
            image[i][width - (j + 1)].rgbtGreen = tempg;
            image[i][width - (j + 1)].rgbtRed = tempr;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Make a copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    //blur!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red, blue, green;
            red = blue = green = 0;
            float blocks = 0;
            //Find neighbour values
            for (int x = - 1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int imagex = i + x;
                    int imagey = j + y;
                    //Check if is a valid neighbour
                    if (imagex < 0 || imagey < 0 || imagex > (height - 1) || imagey > (width - 1))
                    {
                        continue;
                    }
                    //Get neighbour value and add to color
                    red += image[imagex][imagey].rgbtRed;
                    blue += image[imagex][imagey].rgbtBlue;
                    green += image[imagex][imagey].rgbtGreen;
                    blocks ++;
                }
                //Divide color by number blocks (neighbour + 1)
                temp[i][j].rgbtRed = round(red / blocks);
                temp[i][j].rgbtBlue = round(blue / blocks);
                temp[i][j].rgbtGreen = round(green / blocks);
            }
        }
    }
    //Change original image into blur image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
