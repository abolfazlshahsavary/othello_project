#include <stdio.h>
#include <time.h>
void meno(int *cond);
void print_page(char gaem[8][8]);
void name_get(char name1[50], char name2[50]);
void print_name(char name1[50], char name2[50]);
void print_point(int *point_black, int *point_white, char name1[], char name2[]);
void black_run(char game[8][8], int *x_move, int *y_move);
void white_run(char game[8][8], int *x_move, int *y_move);
int can_black_run(char game[8][8], int *point_black, int *point_white);
int can_white_run(char game[8][8], int *point_black, int *point_white);
void piece_in_game(char game[8][8], int *black_piece_in_game, int *white_piece_in_game);
int is_move_valid(int x_move, int y_move, char game[8][8], int *point_black, int *point_white);
void find_neigbor(int x_move, int y_move, char game[8][8], int *point_black, int *point_white);
void change(char game[8][8], int x_move, int y_move, int x, int y, char another_char, int *point_black, int *point_white);
void print_time(time_t time_black, time_t tiem_white, char name1[], char name2[]);
void get_time(long long int *time);
void get_panish_point(int *panish_point);
void equle_matrix(char a[8][8], char b[8][8]);

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
        meno(ptr_condition);
        if (condition == 11)
        {
            do
            {
                if (is_get_user_name == 0)
                {
                    name_get(name1, name2);
                    is_get_user_name++;
                    print_point(&point_black, &point_white, name1, name2);
                    print_page(game);
                }

                if (can_black_run(game, &point_black, &point_white) == 1)
                {
                    do
                    {
                        /*get move of black pice*/

                        black_run(game, &x_move, &y_move);
                        x_move--;
                        y_move--;
                        /*check wether the position of pice is not empty*/
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
                print_point(&point_black, &point_white, name1, name2);
                print_page(game);

            } while (1);
        }

        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################
        // time game:############################################################################################################

        else if (condition == 12)
        {
            // gmae board to come back
            char game_board_black_back[8][8];
            char game_board_white_back[8][8];
            // these int is decler to defind the times witch player have come back
            int is_go_back_black = 0;
            int is_go_back_white = 0;
            // char to know if player have wana back
            char wana_back;
            // last time witch black and white was have
            time_t time_befor_black;
            time_t time_befor_white;
            // couning the roud of play
            int round_game = 0;
            // player can't come back for the first time this int is prohibit this action
            int is_ask_to_back_black = 0;
            int is_ask_to_back_white = 0;
            // the game board for black and white is equlse to real game board at the first time
            equle_matrix(game_board_black_back, game);
            equle_matrix(game_board_white_back, game);
            // declere teh point of players
            point_black = 2;
            point_white = 2;
            // counting the number of black and white piece in game
            black_piece_in_game = 2;
            white_piece_in_game = 2;
            // the time for black and white
            time_t time_game_black;
            time_t time_game_white;
            // time of the game
            time_t time_game;
            // point to panish
            int panish_point;
            int one_ask_black = 0;
            int one_ask_white = 0;
            // we need to be update at time to calculate the
            time_t first_time;
            int counter_time_null=0;
            printf("Enter time of the game(sec):\n");
            do
            {
                printf("The time of the game can't be more than 1000 seconds:\n");
                get_time(&time_game);
            } while (time_game > 1000);
            time_game_black = time_game;
            time_game_white = time_game;
            printf("Enter panish point(sec):\n");
            get_panish_point(&panish_point);

            name_get(name1, name2);
            time_t time_befor;
            time_t time_after;

            do
            {
                if (is_get_user_name == 0)
                {

                    is_get_user_name++;
                    print_point(&point_black, &point_white, name1, name2);
                    print_page(game);
                }
                if (one_ask_black == 0)
                {

                    if (can_black_run(game, &point_black, &point_white) == 1 && time_game_black > 0)
                    {
                        // comeback for black
                        if (is_ask_to_back_black != 0)
                        {
                            printf("do you want to back(y)for Yes and any key for No:\n");
                            scanf(" %c", &wana_back);
                            if (wana_back == 'y' && is_go_back_black != 2)
                            {

                                // changing the board game
                                equle_matrix(game, game_board_black_back);
                                // print the page to move again

                                is_go_back_black++;
                                // decreas the time of black
                                time_game_white += (time_befor_black + time_befor_white);
                                // increas the time of white
                                point_black = point_black - (panish_point * is_go_back_black);
                                printf("%d", panish_point);
                                printf("%d", is_ask_to_back_black);
                                print_page(game);
                                // counting the number of comback

                                print_point(&point_black, &point_white, name1, name2);
                                print_time(time_game_black, time_game_white, name1, name2);
                            }
                        }
                    }
                    if (counter_time_null == 0)
                    {

                        equle_matrix(game_board_black_back, game);
                        first_time = time(NULL);
                        counter_time_null++;
                    }

                    do
                    {
                        one_ask_black++;
                        is_ask_to_back_black++;
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
                counter_time_null = 0;
                one_ask_black = 0;
                // time witch is spended to run is equlse to time null after -time null befor run
                time_after = time(NULL) - first_time;
                // to going back we need to have all the past time of the run
                time_befor_black = (time_after);
                time_game_black -= (time_after);
                if (time_game_black < 0)
                {
                    point_black = 0;
                    printf("%s is winner.", name2);
                    break;
                }
                if (time_game_white < 0)
                {
                    point_white = 0;
                    printf("%s is winner", name1);
                    break;
                }

                print_time(time_game_black, time_game_white, name1, name2);

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

                if (can_white_run(game, &point_black, &point_white) == 1 && time_game_white > 0)
                {
                    do
                    {
                        if (one_ask_white == 0)
                        {
                            if (is_ask_to_back_white != 0)
                            {
                                // not allow black to come back after it

                                printf("do you want to back(y)for Yes and any key for No:");
                                scanf(" %c", &wana_back);
                                if (wana_back == 'y' && is_go_back_white != 2)
                                {

                                    equle_matrix(game, game_board_white_back);
                                    is_go_back_white++;
                                    time_game_black += (time_befor_black + time_befor_white);
                                    point_white -= (is_go_back_black * panish_point);
                                    print_page(game);
                                    // counting the number of comback

                                    print_point(&point_black, &point_white, name1, name2);
                                    print_time(time_game_black, time_game_white, name1, name2);
                                }
                            }
                        }
                        if (counter_time_null == 0)
                        {

                            equle_matrix(game_board_white_back, game);
                            counter_time_null++;
                            first_time = time(NULL);
                        }
                        one_ask_white++;
                        is_ask_to_back_white++;
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
                one_ask_white=0;
                time_after = time(NULL) - first_time;
                counter_time_null = 0;
                time_befor_white = time_after;

                time_game_white -= (time_after);
                print_time(time_game_black, time_game_white, name1, name2);
                if (time_game_black < 0)
                {
                    point_black = 0;
                    printf("%s is winner.", name2);
                }
                if (time_game_white < 0)
                {
                    point_white = 0;
                    printf("%s is winner", name1);
                }

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

            } while (1);
        }
        else if (condition == 2)
        {
            printf("continue the nucomplete games:");
        }
        else if (condition == 3)
        {
            printf("exit");
            break;
        }
    }
}

void print_point(int *point_black, int *point_white, char name1[], char name2[])
{
    printf("%s ==============>>>>>>     %d\n\n", name1, *point_black);
    printf("%s ==============>>>>>>     %d\n\n", name2, *point_white);
}
void get_panish_point(int *panish_point)
{
    scanf("%d", panish_point);
}
void print_time(time_t time_black, time_t time_white, char name1[], char name2[])
{
    printf("%s has %d time.\n\n", name1, time_black);
    printf("%s has %d time.\n\n", name2, time_white);
}

void get_time(long long int *time)
{
    scanf("%lld", time);
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
void equle_matrix(char a[8][8], char b[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
void print_page(char game[8][8])

{
    printf("     %d    %d    %d    %d    %d    %d    %d    %d \n", 1, 2, 3, 4, 5, 6, 7, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d :", i + 1);

        for (int j = 0; j < 8; j++)
        {

            printf("[(%c)]", game[i][j]);
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
    printf(" player one is:(black) %s\n\n", name1);
    printf(" player two is:(white) %s\n\n", name2);
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
                }
            }
        }
    }
    // this is two position to be able to move and change
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
                }
            }
            if (another_char == 'b')
            {
                (*point_white)--;
            }
            else
            {
                (*point_black)--;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
                }
            }
            if (another_char == 'b')
            {
                (*point_white)--;
            }
            else
            {
                (*point_black)--;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
                }
            }
            if (another_char == 'b')
            {
                (*point_white)--;
            }
            else
            {
                (*point_black)--;
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
                    (*point_white)++;
                }
                else
                {
                    (*point_black)++;
                }
            }
            if (another_char == 'b')
            {
                (*point_white)--;
            }
            else
            {
                (*point_black)--;
            }
        }
    }
}
void black_run(char game[8][8], int *x_move, int *y_move)
{
    printf("black turn :\n\n");
    printf("enter row of your move:\n");
    scanf("%d", x_move);
    printf("enter column of your move:\n");
    scanf("%d", y_move);
}
void white_run(char game[8][8], int *x_move, int *y_move)

{
    printf("white turn :\n\n");
    printf("enter rwo of your move:\n");
    scanf("%d", x_move);
    printf("enter column of your move:\n");
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
    printf("OTHELLO OTHELLO OTHELLO\n\n");
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
    int counter_another_between = 0;
    /*check same pice down*/

    // find the black upper
    x--;
    if (game[x][y] == another_char && x_move != 0)
    {

        while (get_end == 0)
        {
            if (game[x][y] == another_char && x > 0)
            {
                counter_another_between++;
                x--;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black down
    x = x_move;
    y = y_move;
    x++;
    if (game[x][y] == another_char && x_move != 7)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && x < 7)
            {
                x++;
                counter_another_between++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
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
    if (game[x][y] == another_char && y_move != 7)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && y < 7)
            {
                counter_another_between++;
                y++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black left
    x = x_move;
    y = y_move;

    y--;
    if (game[x][y] == another_char && y_move != 0)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && y > 0)
            {
                counter_another_between++;
                y--;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black up-right
    x = x_move;
    y = y_move;

    x--;
    y++;
    if (game[x][y] == another_char && x_move != 0 && y_move != 7)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && x > 0 && y < 7)
            {
                counter_another_between++;
                x--;
                y++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black up-left
    x = x_move;
    y = y_move;

    x--;
    y--;
    if (game[x][y] == another_char && x_move != 0 && y_move != 0)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && x < 0 && y < 0)
            {
                counter_another_between++;
                x--;
                y--;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black down-right
    x = x_move;
    y = y_move;
    x++;

    y++;
    if (game[x][y] == another_char && y_move != 7 && x_move != 7)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && x < 7 && y < 7)
            {
                counter_another_between++;
                x++;
                y++;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    // find black down-left
    x = x_move;
    y = y_move;
    x++;

    y--;
    if (game[x][y] == another_char && x_move != 7 && y_move != 0)
    {
        while (get_end == 0)
        {

            if (game[x][y] == another_char && x < 7 && y > 0)
            {
                counter_another_between++;
                x++;
                y--;
            }
            else if (game[x][y] == game[x_move][y_move])
            {
                return 1;
            }
            else
            {
                break;
            }
            if (counter_another_between >= 5)
            {
                break;
            }
        }
    }
    return 0;
}
