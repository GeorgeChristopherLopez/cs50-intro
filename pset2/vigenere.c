#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

string shift(char* c, string p);

int main(int argc, string argv[])
{
// check that the user use 1 command line arg
  
  if (argc!=2)
      {
      //if not prompt for "keyword"
        printf("Usage: ./vigenere keyword\n");
    
      } else {//if yes
              //iterate over char of argv[1] aka the key to check if they are digits   
                
                 string s = argv[1];
                 int l = strlen(argv[1]);
                  
 
                  for(int i = 0; i < l; i++)
                  {
                      if(!isalpha(s[i]))
                      {
                         printf("Usage: ./vigenere keyword\n");
                         return(1);
                      }                      
                   }                     
                                            
                       //promt user for plaintext
                       string plaintext = get_string("plaintext: ");
                       // cipher plaintext according to key
                       string cipherText = shift(argv[1], plaintext);             
                        // print ciphered text
                       printf("ciphertext: %s\n", cipherText);
  
                  }
  
}

string shift(char* c, string p)
{  
    char cipherText;
    int cipherValue;
    int pLength = strlen(p);
    int keyLength = strlen(c);
    
    for(int i = 0; i< pLength; i++){
        
        if(islower(p[i])){
            p[i] = ((int)p[i]-97 + (int)tolower(c[i%keyLength])-97) %26 + 97;
            
        }
        else if (isupper(p[i])){
            p[i] = ((int)p[i]-65 + (int)toupper(c[i % keyLength])-65) %26 + 65;
            
        }
        

    }
return p;  
 }
