#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;
int empty_row, empty_column;
int board[5][5];

void board_size();
void shuffle_number();
void play_puzzle_game();
void print_board();

int main()
{
    printf("Enter size of board (Minimum: 2 And Maximum: 5): ");
    scanf("%d", &size);

    if(size < 2 || size > 5)
    {
        printf("Invalid board size. Please enter a value between 2 and 5.\n");
        return 1;
    }

    board_size();
    shuffle_number();

    printf("Welcome to the Sliding Puzzle Game!\n");
    printf("Instructions:\n");
    printf("Use ('w', 'a', 's', 'd') or ('W', 'A', 'S', 'D') to move the empty tile 'UP' , 'LEFT' , 'DOWN' , or 'RIGHT' respectively.\n");
    printf("Try to reorder the numbers from 1 to %d.\n\n", size * size - 1);

    play_puzzle_game();

    return 0;
}

void board_size()
{
    int num = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == size - 1 && j == size - 1)
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = num++;
            }
        }
    }
    empty_row = size - 1;
    empty_column = size - 1;
}

void shuffle_number()
{
    srand(time(NULL));

    for(int i = 0; i < size * size * 10; i++)
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
            if(empty_row < size - 1)
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
            if(empty_column < size - 1)
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
            printf("\nEnter your move (w/a/s/d) or (W/A/S/D) to move the empty tile, q to quit): ");
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

            if(row_change + empty_row >= 0 && row_change + empty_row < size && column_change + empty_column >= 0 && column_change + empty_column < size)
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
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
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
            printf("\nEnter your move ((w/a/s/d) or (W/A/S/D) to move the empty tile, q to quit): ");
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

            if(row_change + empty_row >= 0 && row_change + empty_row < size && column_change + empty_column >= 0 && column_change + empty_column < size)
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

    for(int i = 0; i < size; i++)
    {
        printf("---+");
    }
    printf("\n");

    for(int i = 0; i < size; i++)
    {
        printf("|");

        for(int j = 0; j < size; j++)
        {
            if(board[i][j] == 0)
            {
                printf(" * ");
            }
            else
            {
                printf(" %d ", board[i][j]);
            }

            printf("|");

        }

        printf("\n+");

        for(int j = 0; j < size; j++)
        {
            printf("---+");
        }
        printf("\n");
    }
}
