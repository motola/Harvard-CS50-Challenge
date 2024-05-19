#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            int avgValue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float) 3);
            image[i][j].rgbtRed = avgValue;
            image[i][j].rgbtGreen = avgValue;
            image[i][j].rgbtBlue = avgValue;

         }
      }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed, sepiaGreen, sepiaBlue;

      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {
            sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen ) + (0.189 * image[i][j].rgbtBlue));
            sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen ) + (0.168 * image[i][j].rgbtBlue));
            sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen ) + (0.131 * image[i][j].rgbtBlue));

           if (sepiaRed > 255) {
                sepiaRed = 255;
           }

            if (sepiaGreen > 255) {
                sepiaGreen = 255;
           }

             if (sepiaBlue > 255) {
                sepiaBlue= 255;
           }



            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

         }
      }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
      RGBTRIPLE imageReflect;

      for (int i = 0; i < height; i++) {
         for (int j = 0; j < width / 2; j++) {

          imageReflect = image[i][j];
          image[i][j] = image[i][width - j - 1];
          image[i][width - j - 1] =  imageReflect;
         }
      }



    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE image_copy[height][width];

       for (int i = 0; i < height; i++) {
         for (int j = 0; j < width; j++) {

          float red = 0, green = 0, blue = 0, calc_pixel = 0;

          for (int new_height = i - 1; new_height < i + 2;  new_height++) {
            for (int new_width = j - 1; new_width < j + 2; new_width++) {

               if (new_height >= 0 && new_width >= 0 && new_height < height && new_height < width) {

                   red += image[new_height][new_width].rgbtRed;
                   green += image[new_height][new_width].rgbtGreen;
                   blue += image[new_height][new_width].rgbtBlue;
                   calc_pixel++;
               }


         }
         }

            image_copy[i][j].rgbtRed = round (red / calc_pixel);
            image_copy[i][j].rgbtGreen = round (green / calc_pixel);
            image_copy[i][j].rgbtBlue = round (blue / calc_pixel);
         }
       }

            for (int  i = 0; i < height; i++) {
               for (int j = 0; j < width; j++) {
                     image[i][j] = image_copy[i][j];
               }

         }

    return;
}
