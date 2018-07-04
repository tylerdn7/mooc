/**
 * vigenere.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * vigenere.c is a program that encrypts
 * messages using Vigenère’s cipher
 * 
 * 
 **/
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include <cs50.h>
 
 int main(int argc, string argv[])
 {
     //error checking
     
     if(argc != 2)
     {
         printf("You haven't inputted the corect input yet\n");
         return 1;
     }
     
     //error checking
     
     if(argv[1] == NULL)
     {
         printf("Wrong input\n");
         return 1;
     }
     
     //error checking
     
     for(int i = 0; i < strlen(argv[1]); i++)
     {
         if(!isalpha(argv[1][i]))
         {
             printf("Invalid input\n");
             return 1;
         }
     }
     
     //taking input from the user using GetString()
     
     string s = GetString();
     
     //iterating over the strings and keywords every character by using for loop
     
     for(int i = 0, j = 0, n = strlen(s); i < n; i++)
     {
      
      //key for encrypting the plain text
      
         int k = argv[1][j % strlen(argv[1])] - 97;
      
         //checking whether it is alphabetical character or not
         
         if(isalpha(s[i]))
         {
             /*here every condition is checking whether it is met its condition or not
             if the condition is met the program is encrypting the plain text using
             ASCII math*/
             
             if(islower(s[i]) && islower(argv[1][j % strlen(argv[1])]))
             {
                 printf("%c",(((s[i] - 'a') + k) % 26) + 'a');
                 j++;
             }
             else if(islower(s[i]) && isupper(argv[1][j % strlen(argv[1])]))
             {
                 printf("%c",(((s[i] - 'A') + k) % 26) + 'a');
                 j++;
             }
             else if(isupper(s[i]) && islower(argv[1][j % strlen(argv[1])]))
             {
                 printf("%c",(((s[i] - 'a') + k) % 26) + 'a');
                 j++;
             }
             else if(isupper(s[i]) && isupper(argv[1][j % strlen(argv[1])]))
             {
                 printf("%c",(((s[i] - (' ' + 1)) + k) % 26) + 'A');
                 j++;
             }
         }
         else
         {
             /*if it is not an alphabetical character then 
             its not enciphered and printed as it is*/
             
             printf("%c",s[i]);
         }
     }
     
     printf("\n");
     
     return 0;
 }