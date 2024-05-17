#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void loopthegame();

char board_in[10][10];
char board_fin[10][10];
int score;

void start_taptap();
void modified();
int checker(int size);
void shuffle(char *array, int n);
void boardsize(int size);
void display_game(int size);
void play_taptap(int size, int start);

int size_pz;
int empty_row, empty_column;
int board[5][5];

void start_pzg();
void board_size();
void shuffle_number();
void play_puzzle_game();
void print_board();

int main()
{
    int gameplay;
    printf("Welcome To Game For You\n\n");
    printf("Enter number to play game(Choice 1:- TAP TAP MATCH GAME) or (Choice 2:- SLIDING PUZZLE GAME): ");
    scanf("%d", &gameplay);

    if(gameplay == 1)
    {
        start_taptap();
        loopthegame();
    }

    else if(gameplay == 2)
    {
        start_pzg();
        loopthegame();
    }

    else
    {
        printf("Unrecognized game selection: %d\n", gameplay);
        loopthegame();
    }
    return 0;
}

void loopthegame()
{
    char call;
    printf("Press 'R' or 'r' to repeat the game or Press 'E' or 'e' to exit the game: ");
    scanf(" %c", &call);

    int gameplay;
    if(call == 'R' || call == 'r')
    {
        printf("Enter number to play game(Choice 1:- TAP TAP MATCH GAME) or (Choice 2:- SLIDING PUZZLE GAME): ");
        scanf("%d", &gameplay);

        if(gameplay == 1)
        {
            start_taptap();
            loopthegame();
        }

        else if(gameplay == 2)
        {
            start_pzg();
            loopthegame();
        }

        else
        {
            printf("Unrecognized game selection: %s\n", gameplay);
            loopthegame();
        }
    }
    else if (call == 'E' || call == 'e')
    {
        printf("Exiting...\n");
    }
    else
    {
        printf("Unrecognized Input.");
        loopthegame();
    }
}

void start_taptap()
{
         printf("Selected game is TAP TAP MATCH GAME\n\n");
         printf("Welcome to the TAP TAP MATCH Game!\n");

        modified();

         
}

void modified()
{
    int size;
         int call;
         int start = 0;
         char input;

         do
         {
             printf("Enter the size of board (Minimum: 2 & Maximum: 10) or (Even Number Between 2 -10): ");
             scanf("%d", &size);
         }while(size < 2 || size > 10);

         call = checker(size);

         boardsize(call);
         score = 0;

         printf("Press 's' or 'S' to start the game and Press 'q' or 'Q' to quit at any time.\n");
         scanf(" %c", &input);

         if(input == 'S' || input == 's')
         {
             start = 1;
         }
         else if(input == 'Q' || input == 'q')
         {
             printf("Exiting...\n");
         }

        play_taptap(size, start);
}

int checker(int size)
{
    if(size % 2 == 0)
    {
        return size;
    }

    else
    {
        printf("Invalid Input\n");
        modified();
    }
}

void shuffle(char *array, int n)
{
    if(n > 1)
    {
        for(int i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void boardsize(int size)
{
    int i, j;
    char symbols [10 * 10];
    char symbol = 'A';
    int pair_placed = 0;
    int symbol_random[10][10] = {0};

    srand(time(NULL));

    for(i = 0; i < size * size; i++)
     {
         symbols[i] = symbol;
         pair_placed++;
         if (pair_placed % 2 == 0)
         {
             symbol++;
         }
     }

    shuffle(symbols, size * size);

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            board_in[i][j] = symbols[i * size + j];
            board_fin[i][j] = 0;
        }
    }
}

void display_game(int size)
{
    int i, j;

    printf("\n");
    printf(" ");
    for(j = 0; j < size; j++)
    {
        printf("  %d ", j);
    }
    printf("\n");

    for(i = 0; i < size; i++)
    {
        printf("-----");
    }
    printf("\n");

    for(i = 0; i < size; i++)
    {
        printf("%d", i);
        printf("|");
        for(j = 0; j < size; j++)
        {
            if(board_fin[i][j])
            {
                printf("  %c ", board_in[i][j]);
            }
            else
            {
                printf("  * ");
            }
        }
        printf("\n");
    }
    for(i = 0; i < size; i++)
    {
        printf("-----");
    }
    printf("\n");
    printf("Score: %d\n", score);
}

void play_taptap(int size, int start)
{
    int first_row, first_column, second_row, second_column;
    char input;
    int number_attempt = 0;
    int all_cards_shown = 1;

    while(start)
    {
        display_game(size);

        printf("\nEnter the row and column of the first card: ");
        scanf("%d %d", &first_row, &first_column);

        if(first_row < 0 || first_row >= size || first_column < 0 || first_column >= size)
        {
            printf("Invalid input. Please enter valid row and column numbers.\n");
            continue;
        }

        printf("\nEnter the row and column of the Second card: ");
        scanf("%d %d", &second_row, &second_column);

        if(first_row == second_row && first_column == second_column)
        {
            printf("Invalid input. Please enter valid row and column numbers.\n");
            continue;
        }

        if(second_column < 0 || second_column >= size || second_row < 0 || second_row >= size)
        {
            printf("Invalid input. Please enter valid row and column numbers.\n");
            continue;
        }

        if(board_fin[first_row][first_column] || board_fin[second_row][second_column])
        {
            printf("You have already revealed those cards. Please try again.\n");
            continue;
        }

        if(board_in[first_row][first_column] == board_in[second_row][second_column])
        {
            printf("Match Found!\n");
            board_fin[first_row][first_column] = 1;
            board_fin[second_row][second_column] = 1;
            score += 10;
        }
        else
        {
            printf("No match. The symbols in those positions were: %c and %c\n", board_in[first_row][first_column], board_in[second_row][second_column]);
        }

        number_attempt++;
        all_cards_shown = 1;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(!board_fin[i][j])
                {
                    all_cards_shown = 0;
                    break;
                }
            }
            if(!all_cards_shown)
            {
                break;
            }
        }

        if(all_cards_shown)
        {
            display_game(size);
            printf("Congratulations! You have matched all the pairs in %d attempts.\n", number_attempt);
            break;
        }

        printf("Press 'q' or 'Q' to quit at any time or any other key to continue.\n");
        scanf(" %c", &input);
        if(input == 'q' || input == 'Q')
        {
            printf("Exiting...\n");
            break;
        }
    }
}

// pzg

void start_pzg()
{
        printf("Selected game is SLIDING PUZZLE GAME\n\n");

        printf("Welcome to the Sliding Puzzle Game!\n");
        printf("Instructions:\n");
        printf("Use ('w'-'W':- Top) ('a'-'A':- Left) ('s'-'S':- Down) ('d'-'D':- Right) to move the empty tile.\n");

        printf("Enter size of board (Minimum: 2 And Maximum: 5): ");
        scanf("%d", &size_pz);

        if(size_pz < 2 || size_pz > 5)
        {
            printf("Invalid board size. Please enter a value between 2 and 5.\n");
        }

        printf("Try to reorder the numbers from 1 to %d.\n\n", size_pz * size_pz - 1);

        board_size();
        shuffle_number();
        play_puzzle_game();
}

void board_size()
{
    int num = 1;
    for(int i = 0; i < size_pz; i++)
    {
        for(int j = 0; j < size_pz; j++)
        {
            if(i == size_pz - 1 && j == size_pz - 1)
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = num++;
            }
        }
    }
    empty_row = size_pz - 1;
    empty_column = size_pz - 1;
}

void shuffle_number()
{
    srand(time(NULL));

    for(int i = 0; i < size_pz * size_pz * 10; i++)
    {
        int direction = rand() % 4;

        switch(direction)
        {
        case 0:
            if(empty_row > 0)
            {
                board[empty_row][empty_column] = board[empty_row - 1][empty_column];
                board[--empty_row][empty_column] = 0;
            }
            break;

        case 1:
            if(empty_row < size_pz - 1)
            {
                board[empty_row][empty_column] = board[empty_row + 1][empty_column];
                board[++empty_row][empty_column] = 0;
            }
            break;

        case 2:
            if(empty_column > 0)
            {
                 board[empty_row][empty_column] = board[empty_row][empty_column - 1];
                 board[empty_row][--empty_column] = 0;
            }
            break;

        case 3:
            if(empty_column < size_pz - 1)
            {
                board[empty_row][empty_column] = board[empty_row][empty_column + 1];
                board[empty_row][++empty_column] = 0;
            }
            break;
        }
    }
}

void play_puzzle_game()
{
    char move;
    int solve = 0;

    while(1)
    {

        if(!solve)
        {
            print_board();
            printf("\nEnter your move ('w'-'W':- Top) ('a'-'A':- Left) ('s'-'S':- Down) ('d'-'D':- Right): ");
            scanf(" %c", &move);

            if(move == 'q' || move == 'Q')
            {
                printf("Quitting...\n");
                break;
            }

            int row_change = 0, column_change = 0;

            switch(move)
            {
                case 'w' : row_change = -1; break;
                case 'W' : row_change = -1; break;
                case 's' : row_change = 1; break;
                case 'S' : row_change = 1; break;
                case 'a' : column_change = -1; break;
                case 'A' : column_change = -1; break;
                case 'd' : column_change = 1; break;
                case 'D' : column_change = 1; break;
                default: printf("Invalid move. Please use 'w', 'a', 's', 'd', or 'q'.\n"); continue;
            }

            if(row_change + empty_row >= 0 && row_change + empty_row < size_pz && column_change + empty_column >= 0 && column_change + empty_column < size_pz)
            {
                board[empty_row][empty_column] = board[empty_row + row_change][empty_column + column_change];
                board[empty_row + row_change][empty_column + column_change] = 0;
                empty_row += row_change;
                empty_column += column_change;
            }
            else
            {
                printf("Invalid move. Please try again.\n");
                continue;
            }

            int num = 1;
            solve = 1;
            for(int i = 0; i < size_pz; i++)
            {
                for(int j = 0; j < size_pz; j++)
                {
                    if(board[i][j] != 0 && board[i][j] != num++)
                    {
                        solve = 0;
                        break;
                    }
                }
            }
        }

        if(solve)
        {
            printf("\nCongratulations! You solved the puzzle!\n");
            print_board();
            break;
        }
        else
        {
            print_board();
            printf("\nEnter ('w'-'W':- Top) ('a'-'A':- Left) ('s'-'S':- Down) ('d'-'D':- Right) to move the empty tile, q to quit): ");
            scanf(" %c", &move);

            if(move == 'q' || move == 'Q')
            {
                printf("Quitting...\n");
                break;
            }

            int row_change = 0, column_change = 0;

            switch(move)
            {
                case 'w' : row_change = -1; break;
                case 'W' : row_change = -1; break;
                case 's' : row_change = 1; break;
                case 'S' : row_change = 1; break;
                case 'a' : column_change = -1; break;
                case 'A' : column_change = -1; break;
                case 'd' : column_change = 1; break;
                case 'D' : column_change = 1; break;
                default: printf("Invalid move. Please use 'w', 'a', 's', 'd', or 'q'.\n"); continue;
            }

            if(row_change + empty_row >= 0 && row_change + empty_row < size_pz && column_change + empty_column >= 0 && column_change + empty_column < size_pz)
            {
                board[empty_row][empty_column] = board[empty_row + row_change][empty_column + column_change];
                board[empty_row + row_change][empty_column + column_change] = 0;
                empty_row += row_change;
                empty_column += column_change;
            }
            else
            {
                printf("Invalid move. Please try again.\n");
                continue;
            }
        }
    }
}

void print_board()
{
    printf("+");

    for(int i = 0; i < size_pz; i++)
    {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < size_pz; i++)
    {
        printf("|");

        for(int j = 0; j < size_pz; j++)
        {
            if(board[i][j] == 0)
            {
                printf(" # ");
            }
            else
            {
                printf(" %d ", board[i][j]);
            }

            printf("|");

        }

        printf("\n+");

        for(int j = 0; j < size_pz; j++)
        {
            printf("---+");
        }
        printf("\n");
    }
}