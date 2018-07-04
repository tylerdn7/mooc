/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 * 
 * Ahasanul Basher Hamza
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#define SIZE 45
#define HASH_SIZE 9999
#include "dictionary.h"

// word counter variable

int word_counter = 0;

// creating a node

typedef struct node
{
    char s[SIZE];
    struct node *next;
}
node;

// creating an array of nodes

node *hashtable[HASH_SIZE];

// creating a hash function

int hash_function(const char* s)
{
    // in key variable storing the first character's ascii value and returning it
    
    int key = toupper(s[0]) - 'A';
    return key;
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // in hash variable storing the ascii value after hashing the word string with hash_function
    
    int hash = hash_function(word);
    
    // creating a head pointer which is pointing hashtable[hash] (the first value of the linked list)
    
    node *head = hashtable[hash];
    
    // creating another pointer which points to head pointer
    
    node *checker = head;
    
    // a loop will check whether the string is inside the dictionary or not until the chekcer pointer points to NULL
    
    while(checker != NULL)
    {
        // strcasecmp is checking the given string.if it matches with the dictionary string then returning true
        
        if(strcasecmp(checker->s,word) == 0)
        {
            return true;
        }
        
        // else pointing to the next node
        
        checker = checker->next;
    }
    
    // if not matched then returning false
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Initializing the hash table with NULL pointer
    
    for(int i = 0;i < HASH_SIZE;i++)
    {
        hashtable[i] = NULL;
    }
    
    
    // creating an array for the text file words
    
    char words[SIZE];
    
    // opening a file in read mode
    
    FILE *in = fopen(dictionary,"r");
    
    // fscanning every words until it reaches EOF
    
    while(fscanf(in,"%s",words) != EOF)
    {
        // hashing the string words and storing it in hash variable
        
        int hash = hash_function(words);
        
        // if hashtable[hash] = NULL
        
        if(hashtable[hash] == NULL)
        {
            // mallocking a node pointer ptr
            
            node *ptr = malloc(sizeof(node));
            
            // copying the words value in ptr->s
            
            strcpy(ptr->s,words);
            
            // pointing ptr->next node to NULL
            
            ptr->next = NULL;
            
            // hashtable[hash] pointing to ptr 
            
            hashtable[hash] = ptr;
        
            // incrementing word counter
            
            word_counter++;
        }
        else
        {
            // mallocking a node pointer crawler  
            
            node *crawler = malloc(sizeof(node));
            strcpy(crawler->s,words);
            
            // copying the value of words in crawler->s
            crawler->next = hashtable[hash];
            
            // crawler->next pointing to hashtable[hash] 
            
            hashtable[hash] = crawler;
            
            // and hashtable[hash] pointing to crawler
            
            // incrementing word counter
            
            word_counter++;
        }
        
    }
    fclose(in);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // returing the number of loaded words
    
    return word_counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // iterating over the array of linked list
    
    for(int i = 0;i < HASH_SIZE;i++)
    {
        // creating node ptr which points to hashtable[index of i]
        
        node *head = hashtable[i];
        
        // creating another loop cursor which points to head pointer
        
        node *cursor = head;
        
        // while cursor is not equals NULL
        
        while(cursor != NULL)
        {
            // creating a temporary pointer which has value of cursor
            
            node *temp = cursor;
            
            // cursor is now pointing to the next node
            
            cursor = cursor->next;
            
            // freeing the temporary pointer
            
            free(temp);
        }
        
        // if unload complete returning true
        
        return true;
    }
    
    return false;
}
