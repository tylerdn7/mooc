/**
 * initials.c
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * initials.c is a program that prompts a user for their name
 * (using GetString to obtain their name as a string)
 * and then outputs their initials in uppercase 
 * with no spaces or periods, followed 
 * by a newline (\n) and nothing more
 * 
 * 
 **/
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>
 
 int main(void)
 {
     
     //taking input by using GetString();
     
     string s = GetString();
     
     //error checking
     
     if(s == NULL)
     {
         printf("Invalid input\n");
         return 1;
     }
     
     //if the first letter is lower than converting it into an uppercase letter
     
     if(islower(s[0]))
     {
         printf("%c",toupper(s[0]));
     }
     else
     {
          printf("%c",s[0]);
     }
     
     //iterating over every character in the string
     
     for(int i = 0, n = strlen(s); i < n; i++)
     {
         
         //if in the string is space is found
         
         if(s[i] == ' ')
         {
             /*and after the space the letter is small then the program is converting that into
             an uppercase letter else it is being printed as it is*/
             
             if(islower(s[i+1]))
             {
                 printf("%c",toupper(s[i+1]));
             }
             else
             {
                 printf("%c",toupper(s[i+1]));
             }
         }
     }
     printf("\n");
 }