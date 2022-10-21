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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
    //Start edges Gx/y = rules, after that loop
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Creat a matrix to get values from neighbours
            int matrixi[3] = {i - 1, i, i + 1};
            int matrixj[3] = {j - 1, j, j + 1};
            //New colors
            int redx, greenx, bluex, redy, greeny, bluey;
            redx = greenx = bluex = redy = greeny = bluey = 0;
            //Look for neighbour
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int newrow = matrixi[x];
                    int newcolumn = matrixj[y];
                    RGBTRIPLE matrix = temp[newrow][newcolumn];
                    if (newrow < height && newrow >= 0 && newcolumn < width && newcolumn >= 0)
                    {
                    //Calculate Gx and Gy
                    redx += (matrix.rgbtRed * gx[x][y]);
                    greenx += (matrix.rgbtGreen * gx[x][y]);
                    bluex += (matrix.rgbtBlue * gx[x][y]);
                    redy += (matrix.rgbtRed * gy[x][y]);
                    greeny += (matrix.rgbtGreen * gy[x][y]);
                    bluey += (matrix.rgbtBlue * gy[x][y]);
                    }
                }
            }
            int red = round(sqrt((redx * redx) + (redy * redy)));
            int green = round(sqrt((greenx * greenx) + (greeny * greeny)));
            int blue = round(sqrt((bluex * bluex) + (bluey * bluey)));
            //Make sure no byte is above 255
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
        }
    }
    return;
}
