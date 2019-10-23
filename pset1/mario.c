#include <cs50.h>
#include <stdio.h>

// INSTRUCTIONS: TYPE ./mario  THEN hit enter key to start


int main(void)
{
 
   int height = get_int("Height: ");
    if (height > 8 || height < 1 )
    {  
        main();
    } else {
        int dots = height - 1;
        int blocks = height - height +1;
     
         
            for (int row = 0; row < height; row++) 
                {
                    for (int col = 0; col < dots; col++) 
                 {
                    printf(" ");
                 }      
                        
                   for (int col = 0; col < blocks; col++) 
                {
                     printf("#");
                }
                    dots--;
                    blocks++;
                    printf("\n");
                }
            
    }
}   


