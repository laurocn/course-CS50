#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    //Check if user correctly fill command and image
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //Open file for reading
    FILE *input_file = fopen(argv[1], "r");

    //Check if is valid
    if (input_file == NULL)
    {
        printf("Could not open the file");
        return 2;
    }

    //Store blocks of 512 bytes in array
    unsigned char buffer[512];
    int count_image = 0;
    FILE *output_file = NULL;
    //Define file name
    char *filename = malloc(8 * sizeof(char));

    // Check if it is a JPEG in the block
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        if (buffer[0] == 0xff && buffer [1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Print filename, %03 = 3 digits, i = integer, "count_image" define the integer
            sprintf(filename, "%03i.jpg", count_image);
            //Open file to be write ("w") in it
            output_file = fopen(filename, "w");
            //Count +
            count_image++;
        }
        //if the file is not NULL
        if (output_file != NULL)
        {
            //write inside the image found in the prior step. Here, it is considered that the jpegs are saved in sequence, hence there is no need to "end" before reaching the designeted 512 bytes
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);
    return 0;
}
