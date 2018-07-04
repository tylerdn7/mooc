/**
 * caesar.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * caesar.c is a program that encrypts
 * messages using Caesar’s cipher
 * 
 * 
 **/
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>
 
 int main(int argc, string argv[])
 {
     //error checking
     
     if(argc != 2)
     {
         printf("You've not inputted the correct input yet\n");
         return 1;
     }
     
     //by using atoi() function this program is converting string into integer
     
     int k = atoi(argv[1]);
     
     //using GetString() to take string input from the user
     
     string s = GetString();
     
     //with for loop this program is iterating over every character in the string
     
     for(int i = 0, n = strlen(s); i < n; i++)
     {
         
         //checking whether it is an alphabetic character or not
         
         if(isalpha(s[i]))
         {
             
             //using ASCII math and adding the user inputted key the program is enciphering the plain text
             
             if(islower(s[i]))
             {
                 printf("%c",(((s[i] - 'a') + k) % 26) + 'a');
             }
             else if(isupper(s[i]))
             {
                 printf("%c",(((s[i] - 'A') + k) % 26) + 'A');
             }
         }
         else
         {
             //if it is not an alphabetic character then printing it as it was
             
             printf("%c",s[i]);
         }
     }
     
     printf("\n");
     
     return 0;
 }