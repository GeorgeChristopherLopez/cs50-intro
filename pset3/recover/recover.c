#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
         fprintf(stderr, "improper arguments\n");
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    int result = strncmp(argv[1],"card.raw", 99);

    if (result != 0)
        {
            fprintf(stderr, "wrong file name\n");
            fprintf(stderr, "Usage: ./recover card.raw\n");
            return 1;
        }

         // remember filenames
        char *infile = argv[1];

        //file name array is 8 "000.jpg"
        char filename[8]= {0};

        //jpeg counter
        int numJPG = 0;


         // open input file
        FILE *raw_file = fopen(infile, "r");
        if (raw_file == NULL)
        {
            fprintf(stderr, "Could not open %s.\n", infile);
            return 2;
        }

        FILE *out_file = NULL;

     // create byte buffer
     // typedef uint8_t BYTE;
     // BYTE buffer[512];
        unsigned char buffer[512] = {0};


        //Read from the file until end of card
        while (fread(buffer, sizeof(buffer), 1, raw_file) == 1)
        {

            //JPEG? JPG?
            if  (buffer[0] == 0xff &&
                 buffer[1] == 0xd8 &&
                 buffer[2] == 0xff &&
                (buffer[3] & 0xf0) == 0xe0)
            {

                // If the jpeg-sequence is found write into new jpeg
               if(out_file != NULL)
                {
                  fclose(out_file);

                }

                // generate the file name
                sprintf(filename,"%03d.jpg", numJPG);



                out_file = fopen(filename, "wb");

                 if(out_file == NULL)
                {
                    printf("could not open %s. \n", filename);
                    return 1;

                }

               //write out_file from buffer
                fwrite(&buffer, sizeof(buffer), 1, out_file);

                //Increment the jpeg counter number
                numJPG++;


            }

            else
            {
               if(out_file!=NULL)
                fwrite(buffer, sizeof(buffer), 1, out_file);

            }


        }

    if(out_file!=NULL)
      fclose(out_file);

    if(raw_file!=NULL)
      fclose(raw_file);

    return 0;
}
