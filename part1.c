#include <stdio.h>
void meno(int *cond);
void print_page(char gaem[8][8]);
void name_get(char name1[50], char name2[50]);
void print_name(char name1[50], char name2[50]);
void print_point(int *point_black, int *point_white, char name1[], char name2[]);
void black_run(char game[8][8], int *x_move, int *y_move);
void white_run(char game[8][8], int *x_move, int *y_move);
int can_black_run(char game[8][8], int *point_black, int *point_white);
int can_white_run(char game[8][8], int *point_black, int *point_white);
int get_time(int *time);
int cal_time(int *time);
void print_time(time_t time_black, time_t tiem_white, char name1[], char name2[]);
void piece_in_game(char game[8][8], int black_piece_in_game, int white_piece_in_game);
int is_move_valid(int x_move, int y_move, char game[8][8], int *point_black, int *point_white);
void find_neigbor(int x_move, int y_move, char game[8][8], int *point_black, int *point_white);
void change(char game[8][8], int x_move, int y_move, int x, int y, char another_char, int *point_black, int *point_white);

meno(ptr_condition);
int main()
{
    while (1)
    {
        char game[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', 'b', 'w', ' ', ' ', ' '},
                           {' ', ' ', ' ', 'w', 'b', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

        int condition;
        int black_piece_in_game = 2;
        int white_piece_in_game = 2;
        int *ptr_condition = &condition;
        int x_move, y_move;
        int point_black = 2, point_white = 2;
        char name1[50];
        char name2[50];
        int is_get_user_name = 0;
        if (condition == 11)
        {
            do
            {
                if (is_get_user_name == 0)
                {
                    name_get(name1, name2);
                    is_get_user_name++;
                }
                print_point(point_black, point_white, name1, name2);
                print_page(game);
                if (can_black_run(game, &point_black, &point_white) == 1)
                {
                    do
                    {
                        /*get move of black pice*/

                        black_run(game, &x_move, &y_move);
                        x_move--;
                        y_move--;
                        /*check wether the position of pice is empty*/
                        if (game[x_move][y_move] != ' ')
                        {
                            continue;
                        }
                        /*if it was position will be black*/
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'b';
                        }
                        /*check wether can srrunded white pices*/
                        if (is_move_valid(x_move, y_move, game, &point_black, &point_white) == 0)
                        {
                            game[x_move][y_move] = ' ';
                            continue;
                        }
                        /*if it can break */
                        else
                        {
                            break;
                        }
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'b';
                            break;
                        }
                    } while (1);
                }

                /*this func can find all neigbor and change white pice to black pice*/
                find_neigbor(x_move, y_move, game, &point_black, &point_white);
                piece_in_game(game, &black_piece_in_game, &white_piece_in_game);
                if (can_black_run(game, &point_black, &point_white) == 0 && can_white_run(game, &point_black, &point_white) == 0)
                {
                    if (black_piece_in_game > white_piece_in_game)
                    {
                        printf("The winner is :%s", name1);
                    }
                    else if (black_piece_in_game < white_piece_in_game)
                    {
                        printf("The winner is :%s", name2);
                    }
                    break;
                }
                print_point(&point_black, &point_white, name1, name2);
                print_page(game);

                if (can_white_run(game, &point_black, &point_white) == 1)
                {
                    do
                    {

                        white_run(game, &x_move, &y_move);
                        x_move--;
                        y_move--;
                        if (game[x_move][y_move] != ' ')
                        {
                            continue;
                        }
                        game[x_move][y_move] = 'w';

                        if (is_move_valid(x_move, y_move, game, &point_black, &point_white) == 0)
                        {
                            game[x_move][y_move] = ' ';
                            continue;
                        }
                        else
                        {
                            break;
                        }
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'w';
                            break;
                        }
                    } while (1);
                }
                find_neigbor(x_move, y_move, game, &point_black, &point_white);
                piece_in_game(game, &black_piece_in_game, &white_piece_in_game);
                if (can_black_run(game, &point_black, &point_white) == 0 && can_white_run(game, &point_black, &point_white) == 0)
                {
                    if (point_black > point_white)
                    {
                        printf("The winner is :%s", name1);
                    }
                    else if (point_black < point_white)
                    {
                        printf("The winner is :%s", name2);
                    }
                    break;
                }

                print_page(game);

            } while (1);
        }

        // time game:#####################################################################################################
        // time game:#####################################################################################################
        // time game:#####################################################################################################
        // time game:#####################################################################################################

        else if (condition == 12)
        {
            time_t time_game_black;
            time_t time_game_white;
            time_t time_game;
            time_t panish_time;
            time_t show_black_time;
            time_t show_white_time;
            time_t first_time = time(NULL);
            printf("Enter time of the game(sec):");
            get_time(&time_game);
            printf("Enter panish time(sec):");
            get_panish_time(&panish_time);
            print_page(game);
            time_game_black = time(NULL) + time_game;
            time_game_white = time(NULL) + time_game;
            time_t sum_black_time = 0;
            do
            {
                if (is_get_user_name == 0)
                {
                    name_get(name1, name2);
                    is_get_user_name++;
                }
                print_point(point_black, point_white, name1, name2);
                print_page(game);
                if (can_black_run(game, &point_black, &point_white) == 1)
                {
                    do
                    {
                        /*get move of black pice*/

                        black_run(game, &x_move, &y_move);
                        x_move--;
                        y_move--;
                        /*check wether the position of pice is empty*/
                        if (game[x_move][y_move] != ' ')
                        {
                            continue;
                        }
                        /*if it was position will be black*/
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'b';
                        }
                        /*check wether can srrunded white pices*/
                        if (is_move_valid(x_move, y_move, game, &point_black, &point_white) == 0)
                        {
                            game[x_move][y_move] = ' ';
                            continue;
                        }
                        /*if it can break */
                        else
                        {
                            break;
                        }
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'b';
                            break;
                        }
                    } while (1);
                }

                /*this func can find all neigbor and change white pice to black pice*/
                sum_black_time += time(NULL) - first_time;
                show_black_time = time_game_black - time(NULL);
                show_white_time = time_game_white - time(NULL) + sum_black_time;

                find_neigbor(x_move, y_move, game, &point_black, &point_white);
                piece_in_game(game, &black_piece_in_game, &white_piece_in_game);
                if (can_black_run(game, &point_black, &point_white) == 0 && can_white_run(game, &point_black, &point_white) == 0)
                {
                    if (black_piece_in_game > white_piece_in_game)
                    {
                        printf("The winner is :%s", name1);
                    }
                    else if (black_piece_in_game < white_piece_in_game)
                    {
                        printf("The winner is :%s", name2);
                    }
                    break;
                }
                print_time(show_black_time, show_white_time, name1, name2);
                print_point(&point_black, &point_white, name1, name2);
                print_page(game);

                if (can_white_run(game, &point_black, &point_white) == 1)
                {
                    do
                    {

                        white_run(game, &x_move, &y_move);
                        x_move--;
                        y_move--;
                        if (game[x_move][y_move] != ' ')
                        {
                            continue;
                        }
                        game[x_move][y_move] = 'w';

                        if (is_move_valid(x_move, y_move, game, &point_black, &point_white) == 0)
                        {
                            game[x_move][y_move] = ' ';
                            continue;
                        }
                        else
                        {
                            break;
                        }
                        if (game[x_move][y_move] == ' ')
                        {
                            game[x_move][y_move] = 'w';
                            break;
                        }
                    } while (1);
                }
                sum_black_time += time(NULL) - first_time;
                show_black_time = time_game_black - time(NULL);
                show_white_time = time_game_white - time(NULL) + sum_black_time;

                find_neigbor(x_move, y_move, game, &point_black, &point_white);
                piece_in_game(game, &black_piece_in_game, &white_piece_in_game);
                if (can_black_run(game, &point_black, &point_white) == 0 && can_white_run(game, &point_black, &point_white) == 0)
                {
                    if (point_black > point_white)
                    {
                        printf("The winner is :%s", name1);
                    }
                    else if (point_black < point_white)
                    {
                        printf("The winner is :%s", name2);
                    }
                    break;
                }
                print_time(show_black_time,show_white_time,name1,name2);
                print_point(&point_black,&point_white,name1,name2);
                print_page(game);

            } while (1);
        }
        else if (condition == 2)
        {
        }
        else if (condition == 3)
        {
            printf("exit");
        }
    }
}
void print_point(int *point_black, int *point_white, char name1[], char name2[])
{
    printf("%s ==============>>>>>>     %d", name1, *point_black);
    printf("%s ==============>>>>>>     %d", name2, *point_white);
}
void print_time(time_t time_black, time_t time_white, char name1[], char name2[])
{
    printf("%s has %d time.", name1, time_black);
    printf("%s has %d time.", name2, time_white);
}
void get_panish_time(int *panish_time)
{
    scanf("%d", panish_time);
}
void get_time(int *time)
{
    scanf("%d", time);
}
void piece_in_game(char game[8][8], int *black_piece_in_game, int *white_piece_in_game)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game[i][j] == 'b')
            {
                *black_piece_in_game++;
            }
            else if (game[i][j] == 'w')
            {
                *white_piece_in_game++;
            }
        }
    }
}
void print_page(char game[8][8])

{
    printf("    %d  %d  %d  %d  %d  %d  %d  %d\n", 1, 2, 3, 4, 5, 6, 7, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d :", i + 1);

        for (int j = 0; j < 8; j++)
        {

            printf("(%c)", game[i][j]);
            if (j == 7)
            {
                printf("\n");
            }
        }

        printf("\n");
    }
}
void print_name(char name1[50], char name2[50])
{
    printf(" player one is: %s\n", name1);
    printf(" player two is: %s\n", name2);
}
void print_point(int point_black, int point_white, char name1[], char name2[])
{
    printf("enter point of %s: %d\n", name1, point_black);
    printf("enter point of %s: %d\n", name2, point_white);
}

void change(char game[8][8], int x_move, int y_move, int x, int y, char another_char, int *point_black, int *point_white)
{
    // x is the position of finded piece
    // y is the posision of finded piece
    // y_move is the position of entered piece
    // x_move is the posision of enteres piece
    if (x == x_move)
    {
        if (y > y_move)
        {
            for (int i = y_move + 1; i < y; i++)
            {
                game[x_move][i] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
        else
        {
            for (int i = y + 1; i < y_move; i++)
            {
                game[x_move][i] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
    }
    if (y == y_move)
    {
        if (x > x_move)
        {
            for (int i = x_move + 1; i < x; i++)
            {
                game[i][y_move] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
        else
        {
            for (int i = x + 1; i < x_move; i++)
            {
                game[i][y_move] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
    }
    int i1 = x_move;
    int j1 = y_move;

    if (y != y_move && x != x_move)
    {

        if (x > x_move && y > y_move)
        {

            while (i1 != x)
            {
                i1++;
                j1++;
                game[i1][j1] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
        else if (x > x_move && y_move > y)
        {
            while (i1 != x)
            {
                i1++;
                j1--;
                game[i1][j1] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
        else if (x_move > x && y > y_move)
        {
            while (i1 != x)
            {
                i1--;
                j1++;
                game[i1][j1] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
        else if (x_move > x && y_move > y)
        {
            while (i1 != x)
            {
                i1--;
                j1--;
                game[i1][j1] = game[x_move][y_move];
                if (another_char == 'b')
                {
                    *point_white++;
                }
                else
                {
                    *point_black++;
                }
            }
        }
    }
}
void black_run(char game[8][8], int *x_move, int *y_move)
{
    printf("black turn :\n\n");
    printf("enter row of your move:");
    scanf("%d", x_move);
    printf("enter column of your move: ");
    scanf("%d", y_move);
}
void white_run(char game[8][8], int *x_move, int *y_move)

{
    printf("white turn :\n\n");
    printf("enter rwo of your move:");
    scanf("%d", x_move);
    printf("enter column of your move: ");
    scanf("%d", y_move);
}
void find_neigbor(int x_move, int y_move, char game[8][8], int *point_black, int *point_white)
{
    int achive_black = 0;
    int x = x_move;
    int y = y_move;
    int x_black_find = -1;
    int y_black_find = -1;
    int get_end = 0;
    char another_char;
    if (game[x_move][y_move] == 'b')
    {
        another_char = 'w';
    }
    else
    {
        another_char = 'b';
    }
    // find the black upper
    x--;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x--;
        }
        else
        {
            break;
        }
    }
    // find black down
    x = x_move;
    y = y_move;
    x++;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x++;
        }
        else
        {
            break;
        }
    }
    // find black right
    x = x_move;
    y = y_move;
    y++;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            y++;
        }
        else
        {
            break;
        }
    }
    // find black left
    x = x_move;
    y = y_move;
    y--;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            y--;
        }
        else
        {
            break;
        }
    }
    // find black up-right
    x = x_move;
    y = y_move;
    x--;
    y++;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x--;
            y++;
        }
        else
        {
            break;
        }
    }
    // find black up-left
    x = x_move;
    y = y_move;
    x--;
    y--;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x--;
            y--;
        }
        else
        {
            break;
        }
    }
    // find black down-right
    x = x_move;
    y = y_move;
    x++;
    y++;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x++;
            y++;
        }
        else
        {
            break;
        }
    }
    // find black down-left
    x = x_move;
    y = y_move;
    x++;
    y--;
    while (get_end == 0)
    {

        if (game[x][y] == game[x_move][y_move])
        {
            x_black_find = x;
            y_black_find = y;
            change(game, x_move, y_move, x_black_find, y_black_find, another_char, point_black, point_white);
            break;
        }
        else if (game[x][y] == another_char)
        {
            x++;
            y--;
        }
        else
        {
            break;
        }
    }
}
int can_black_run(char game[8][8], int *point_black, int *point_white)
{
    int counter_empty = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game[i][j] != ' ')
            {
                counter_empty++;
            }
        }
    }
    if (counter_empty == 64)
    {
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game[i][j] == ' ')
            {
                game[i][j] = 'b';
                if (is_move_valid(i, j, game, point_black, point_white) == 1)
                {
                    game[i][j] = ' ';
                    return 1;
                }
                else
                {
                    game[i][j] = ' ';
                }
            }
        }
    }
    return 0;
}
int can_white_run(char game[8][8], int *point_black, int *point_white)
{
    int counter_empty = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game[i][j] != ' ')
            {
                counter_empty++;
            }
        }
    }
    if (counter_empty == 64)
    {
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (game[i][j] == ' ')
            {
                game[i][j] = 'w';
                if (is_move_valid(i, j, game, point_black, point_white) == 1)
                {
                    game[i][j] = ' ';
                    return 1;
                }
                else
                {
                    game[i][j] = ' ';
                }
            }
        }
    }
    return 0;
}

void meno(int *cond)
{
    printf("chose type of game: \n\n");
    printf("(1) new game:\n");
    printf("(2) continue last game:\n");
    printf("(3) exit:\n");
    int condition;
    scanf("%d", &condition);
    int condition1;
    if (condition == 1)
    {
        printf("(1)normal game:\n");
        printf("(2)pro game game:\n");
        scanf("%d", &condition1);
        if (condition1 == 1)
        {
            *cond = 11;
        }
        else if (condition1 == 2)
        {
            *cond = 12;
        }
    }
    else if (condition == 2)
    {
        *cond = 2;
    }
    else if (condition == 3)
    {
        *cond = 3;
    }
}
void name_get(char name1[50], char name2[50])
{
    printf("enter name of user 1:");
    scanf("%s", name1);
    printf("enter name of user 2:");
    scanf("%s", name2);
}
int is_move_valid(int x_move, int y_move, char game[8][8], int *point_black, int *point_white)
{

    /* the x int and y int is define to (x,y) position of the achivement of the same pice*/
    int x = x_move;
    int y = y_move;

    int get_end = 0;
    /* the another char is define to detemine the rivel of the player
    for example 'w' is rivel of 'b'*/
    char another_char;
    /*one of the thinks that we have to check is if the pice not to be beside the enserted pice*/
    int is_neigbor_beside = 0;
    /* condition to fine another pice or rivel pice*/

    if (game[x_move][y_move] == 'b')
    {
        another_char = 'w';
    }
    else
    {
        another_char = 'b';
    }
    /*check same pice down*/

    // find the black upper
    x--;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {

        while (get_end == 0)
        {
            if (game[x][y] == another_char)
            {
                x--;
                is_neigbor_beside++;
            }
            /*this condition check if the neigbor of the pice is rivel checked the another pice in that way*/
            else if (game[x][y] == game[x_move][y_move])
            {

                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black down
    x = x_move;
    y = y_move;
    is_neigbor_beside = 0;
    x++;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                x++;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {

                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black right
    x = x_move;
    y = y_move;
    is_neigbor_beside = 0;
    y++;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                y++;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {

                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black left
    x = x_move;
    y = y_move;
    is_neigbor_beside = 0;
    y--;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {

                y--;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {

                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black up-right
    x = x_move;
    y = y_move;
    is_neigbor_beside = 0;
    x--;
    y++;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                x--;
                y++;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {

                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black up-left
    x = x_move;
    y = y_move;
    is_neigbor_beside = 0;
    x--;
    y--;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                x--;
                y--;
                is_neigbor_beside++;
            }

            else if (game[x][y] == game[x_move][y_move])
            {
                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black down-right
    x = x_move;
    y = y_move;
    x++;
    is_neigbor_beside = 0;
    y++;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                x++;
                y++;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    // find black down-left
    x = x_move;
    y = y_move;
    x++;
    is_neigbor_beside = 0;
    y--;
    if (game[x][y] != game[x_move][y_move] || game[x][y] != ' ')
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char)
            {
                x++;
                y--;
                is_neigbor_beside++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                if (is_neigbor_beside != 0)
                {
                    return 1;
                }
                is_neigbor_beside++;
            }
            else
            {
                break;
            }
        }
    }
    return 0;
}
