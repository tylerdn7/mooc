/**
 * fifteen.c
 *
 * Ahasanul Basher Hamza
 * 
 * ahasanulhamza133@gmail.com
 * 
 * hamza133
 * 
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    
    //initializing integer variable k with value d*d - 1
    
    int k = d*d-1;
    
    //iterating over rows
    
    for(int i = 0; i < d; i++)
    {
        
        // iterating over columns
        
        for(int j = 0;j < d;j++,k--)
        {
            //initializing board with the value of k
            
            board[i][j] = k;
            
            //if d is equal 4 then swapping the value of 2 with 1
            
            if(d == 4)
            {
                if(board[i][j] == 1)
                {
                    board[i][j-1] = 1;
                    board[i][j] = 2;
                }
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
    
    //iterating over rows
     
    for(int i = 0;i < d;i++)
    {
        // iterating over columns
        
        for(int j = 0;j < d;j++)
        {
            //if boards value is equal 0 then the program is changing its look with an underscore
            
            if(board[i][j] == 0)
            {
                printf(" _ |");
            }
            else
            {
                //else the other values are printing as they are
                
                printf("%2d |",board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    
    int k,l,x,y,zero = 0,temp;
    
    //iterating over rows

    for(int i = 0;i < d;i++)
    {
        // iterating over columns
        
        for(int j = 0;j < d;j++)
        {
            //if zero is equal to boards values
            
            if(zero == board[i][j])
            {
                
                //then assinging the place of zeroes values in k and l variable
                
                k = i;
                l = j;
            }
            
            //if tile is equal to boards values
            
            if(tile == board[i][j])
            {
                
                //then assinging the place of tiles values in x and y variable
                    
                x = i;
                y = j;
            }
        }
    }
    
    //checking if tile borders empty space, moves tile and returns true, else returns false.
    
    if(board[k][l-1] == board[x][y+1])
    {
        return false;
    }
    
    //implementing the same method for every possible tile moves
    
    else if(board[k][l+1] == board[x][y])
    {
        temp = board[x][y];
        board[x][y] = board[k][l];
        board[k][l] = temp;
        return true;
    }
    else if(board[k][l-1] == board[x][y])
    {
        temp = board[x][y];
        board[x][y] = board[k][l];
        board[k][l] = temp;
        return true;
    }
    else if(board[k-1][l] == board[x][y])
    {
        temp = board[x][y];
        board[x][y] = board[k][l];
        board[k][l] = temp;
        return true;
    }
    else if(board[k+1][l] == board[x][y])
    {
        temp = board[x][y];
        board[x][y] = board[k][l];
        board[k][l] = temp;
        return true;
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    
    //if d == 3 then for winning configuaration
    
    if(d == 3)
    {
        //check for the first row
        
        if((board[0][0] == 1) && (board[0][1] == 2) && (board[0][2] == 3))
        {
            //if the first rows all value matched then entering into the second rows conditions
            
            if((board[1][0] == 4) && (board[1][1] == 5) && (board[1][2] == 6))
            {
                //if the second rows all value matched then entering into the third rows conditions and checking the values 
                
                if((board[2][0] == 7) && (board[2][1] == 8) && (board[2][2] == 0)) 
                {
                    //if the third rows all value matched then returns true
                    
                    return true;
                }
            }
        }
    }
    
    //else if d == 4 then for winning configuaration
    
    else if(d == 4)
    {
        //check for the first row
        
        if((board[0][0] == 1) && (board[0][1] == 2) && (board[0][2] == 3) && (board[0][3] == 4))
        {
            //if the first rows all value matched then entering into the second rows conditions
            
            if((board[1][0] == 5) && (board[1][1] == 6) && (board[1][2] == 7) && (board[1][3] == 8))
            {
                //if the second rows all value matched then entering into the third rows conditions
                
                if((board[2][0] == 9) && (board[2][1] == 10) && (board[2][2] == 11) && (board[2][3] == 12)) 
                {
                    //if the third rows all value matched then entering into the fourth rows conditions and checking the values
                    
                    if((board[3][0] == 13) && (board[3][1] == 14) && (board[3][2] == 15) && (board[3][3] == 0))
                    {
                        //if the fourth rows all value matched then returns true
                        
                        return true;
                    }
                }
            }
        }
    }
    return false;
}