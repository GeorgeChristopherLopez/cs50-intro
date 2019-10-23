#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) {
    
    float dollars;
    do{   
    //get amount in dollars
    dollars = get_float("Change owed: ");
    
    }
    while (dollars < 0);
    
    int cents = round (dollars *100);
    int amount = cents;
    int count = cents;

    do{
      printf("%i Quarter(s)\n", amount/25);
      count = amount/25;
      amount = amount%25;  

    }
    while (amount > 25);
    
    
    do{
         printf("%i Dime(s)\n", amount/10);
      count = count + amount/10;
      amount = amount%10;  
        
    }
    while (amount > 10);
    
     do{
          printf("%i Nickel(s)\n", amount/5);
      count = count + amount/5;
      amount = amount%5;  
    }
    while (amount > 5);
   
     do{
          printf("%i Penny(s)\n", amount/1);
      count = count + amount/1;
      amount = amount%1;  
     
    }
    while (amount > 1);
    
    
     printf("Total Coins Used is %i\n", count);
    
   
}
        
    //Convert users input from float  to int (dollars and cents)
   
    
    
