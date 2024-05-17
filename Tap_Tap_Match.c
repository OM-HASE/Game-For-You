#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board_in[10][10];
char board_fin[10][10];
int score;

void start_taptap();
int checker(int size);
void shuffle(char *array, int n);
void boardsize(int size);
void display_game(int size);
void play_taptap(int size, int start);

int main()
{
    start_taptap();
    return 0;
}

void start_taptap()
{
    int size;
    int call;
    int start = 0;
    char input;

    do
    {
        printf("Enter the size of board (Minimum: 2 & Maximum: 10) and (Even Number Between 2-10): ");
        scanf("%d", &size);
    }while(size < 2 || size > 10);

    call = checker(size);

    boardsize(call);
    score = 0;

    printf("Press 's' or 'S' to start the game and Press 'q' or 'Q' to quit at any time.\n");
    scanf(" %c", &input);

    if(input == 's' || input == 'S')
    {
        start = 1;
    }
    else if(input == 'q' || input == 'S')
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
        start_taptap();
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

    srand(time(NULL)); //random number generator

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
    int all_cards_shown = 0;

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
            printf("Congratulations! You have matched all the pairs in %d attempts.\n", number_attempt);
            display_game(size);
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
