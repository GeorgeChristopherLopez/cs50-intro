#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>




int main(int argc, string argv[])
{
// check that the user use 1 command line arg
  
  if (argc!=2)
      {
      //if not prompt for "key"
        printf("Usage: ./caesar key\n");
    
      } else {//if yes
              //iterate over char of argv[1] aka the key to check if they are digits   
                
                 string s = argv[1];
                 int l = strlen(argv[1]);
                  
 
                  for(int i = 0; i < l; i++)
                  {
                      if(!isdigit(s[i]))
                      {
                         printf("Usage: ./caesar key\n");
                         return(1);
                      }  
                        
    
                   }
                  
                          // convert string to interger
                        int k = atoi(argv[1]);
                        // remainder of 26
                   
                          
                        //promt user for plaintext

                     
                       string plaintext = get_string("plaintext: ");
                      
                  
                        //iterate over each char of the plaintext
                         int plaintextLength = strlen(plaintext);
                      for(int j = 0; j < plaintextLength; j++)
                      {
                        plaintext[j] = plaintext[j] + k;
                       }
                        printf("ciphertext: %s\n", plaintext);
                      
      
      
      
      
      
      
      
      
                    

                        //if uppercase rotate preserving case

                        //if lowercase rotate preserving case

                        //if neither print char as is

                        //print \n
                     
                     
                  }
  
}
