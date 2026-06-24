#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

char point[9] = {49, 50, 51, 52, 53, 54, 55, 56, 57};
bool already[10];
int a[3][3];
class TicTacToe
{
private:
    string get_data;

public:
    void set_get_data(string);
    friend class editing;
    friend class play;
};

class display : public TicTacToe
{
public:
    void board();
    void startup();
    void note();
    void startGame();
    int edit_manu();
    void exit_func();
};

class Player
{
    string name[100];
    string first_player;
    string second_player;
    char player;

public:
    char player_2 = player;
    void set_first_player(string);
    void set_second_player(string);
    void set_player_will_play(char);
    string get_first_player();
    string get_second_player();
};

class AI
{
    int a[3][3], t, y, game = 1;
    char name[30];

public:
    AI();
    void print();
    int check();
    void pin();
    int attack();
    int defend(int, int, int);
    void ai(int);
};

class editing : public Player
{
    string player_edit;
    int input;
    int edit;

public:
    void edit_data(char &player, bool &win);
};

class checkwin
{
    string get_data;

public:
    bool check_win(char player);
};

class play : public TicTacToe
{
    string name_1st, name_2nd, num;
    char player_choice;

public:
    // ing player;

    play();
};

int main()
{
    int mode;
there:
    cout << "which mode you want to play? " << endl;
    cout << "1. Player vs AI " << endl;
    cout << "2. Player vs Player " << endl;
    cin >> mode;

    if (mode == 1)
    {
        AI ai;
    }
    else if (mode == 2)
    {
        play play_;
    }
    else
    {
        cout << "invlaid input try again...";
        goto there;
    }
}

void display ::note()
{
    cout << "$$$$$         $$                    $$       " << endl;
    cout << "$$  $$        $$                    $$        " << endl;
    cout << "$$   $$       $$                    $$        " << endl;
    cout << "$$    $$      $$                    $$        " << endl;
    cout << "$$     $$     $$     $$$$$$     $$$$$$$$$$$   $$$$$$$   " << endl;
    cout << "$$      $$    $$  $$$      $$$      $$       $$$   $$$      " << endl;
    cout << "$$       $$   $$  $$$      $$$      $$       $$$$$$$$         " << endl;
    cout << "$$        $$  $$  $$$      $$$      $$       $$$         " << endl;
    cout << "$$         $$$$$     $$$$$$         $$        $$$$$$$$       " << endl;

    cout << endl
         << endl
         << "\t\t\t\tWhen game starts you can exit the game or edit the game " << endl;
    cout << "\t\t\t\t\t     For exit just write (Exit)" << endl;
    cout << "\t\t\t\t\t     For edit just write (Edit)" << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " \t\t\t\t\t Press Enter to Proceed " << endl;
    system("pause");
    system("cls");
}

void display ::startGame()
{
    cout << "$$$$$$$$$$$$$$$                      $$$$$$$$$$$$$$$                              $$$$$$$$$$$$$$$        " << endl;
    cout << "      $$       *                           $$                                           $$              " << endl;
    cout << "      $$      * *                          $$                                           $$              " << endl;
    cout << "      $$       *                           $$                                           $$              " << endl;
    cout << "      $$      $$      $$$$$$               $$       $$$$$$            $$$$$$            $$        $$$$$$        $$$$$$$   " << endl;
    cout << "      $$      $$    $$$                    $$    $$$      $$$       $$$                 $$     $$$      $$$    $$$   $$$      " << endl;
    cout << "      $$      $$    $$$                    $$    $$$      $$$       $$$                 $$     $$$      $$$    $$$$$$$$         " << endl;
    cout << "      $$      $$    $$$                    $$    $$$      $$$$      $$$                 $$     $$$      $$$    $$$         " << endl;
    cout << "      $$      $$      $$$$$$               $$       $$$$$$$  $$$$     $$$$$$            $$        $$$$$$        $$$$$$$$       " << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " \t\t\t\t\t Developed by: Yasir Naeem (425)" << endl;
    cout << " \t\t\t\t\t Press Enter to Proceed " << endl;
    system("pause");

    system("cls");
}

void display ::board()
{
    cout << "\n";
    cout << "\t\t\t\t\t" << point[0] << " | " << point[1] << " | " << point[2] << "\n";
    cout << "\t\t\t\t\t"
         << "---------\n";
    cout << "\t\t\t\t\t" << point[3] << " | " << point[4] << " | " << point[5] << "\n";
    cout << "\t\t\t\t\t"
         << "---------\n";
    cout << "\t\t\t\t\t" << point[6] << " | " << point[7] << " | " << point[8] << "\n";
    cout << "\n";
}

void display ::startup()
{
    cout << "\t\t\t-----------------------------------------------------------------------" << endl;

    cout << "\t\t\t\t\t"
         << "        Welcome to Tic-Tac-Toe! " << endl;
    cout << "\t\t\t-----------------------------------------------------------------------" << endl;
}

bool checkwin ::check_win(char player)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (point[i] == player && point[i + 1] == player && point[i + 2] == player)
        {
            return true;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (point[i] == player && point[i + 3] == player && point[i + 6] == player)
        {
            return true;
        }
    }
    // Check diagonals
    if (point[0] == player && point[4] == player && point[8] == player)
    {
        return true;
    }
    if (point[2] == player && point[4] == player && point[6] == player)
    {
        return true;
    }
    // No win condition
    return false;
}

void Player::set_second_player(string name1)
{
    first_player = name1;
}

void Player::set_first_player(string name2)
{
    second_player = name2;
}

void Player ::set_player_will_play(char choice)
{
    player = choice;
}

void TicTacToe ::set_get_data(string data)
{
    get_data = data;
}

void editing ::edit_data(char &player, bool &win)
{
    display d2;
    checkwin c2;
here_2:
    edit = d2.edit_manu();
    string player_name;

    switch (edit)
    {
    case 1:
        cout << "Which player you want to change name? ";
        cout << "1st Player? \n2nd Player?";
        cin >> player_edit;
        if (player_edit == "1st" || player_edit == "1")
        {
            cout << "Enter 1st Player Name again ";
            cin >> player_name;
            set_first_player(player_name);
        }
        else if (player_edit == "2nd" || player_edit == "2")
        {
            cout << "Enter 2nd Player Name again ";
            cin >> player_name;
            set_second_player(player_name);
        }
        break;

    case 2:
        point[input - 1] = input + 48;
        already[input] = true;
        d2.board();
        win = c2.check_win(player);
        player = (player == 'X') ? 'O' : 'X';
        break;

    case 3:
        cout << "Nothing is changed" << endl;
        break;

    default:
        cout << "inavlid input ";
        goto here_2;
    }
}

int display ::edit_manu()
{
    int option;
    cout << "What u want to edit?" << endl;
    cout << "1. Player Name " << endl;
    cout << "2. last move " << endl;
    cout << "3. you don't want to change " << endl;
    cin >> option;

    return option;
}

void display ::exit_func()
{
    exit(0);
}

string Player ::get_first_player()
{
    return first_player;
}

string Player ::get_second_player()
{
    return second_player;
}

play ::play()
{

    Player p;
    editing e;
    display d;
    checkwin c;

    d.startGame();
    d.note();

    do
    {
        d.startup();
        d.board();

        bool win;

        for (int i = 0; i < 10; ++i)
            already[i] = true;

        cout << "Enter 1st Player Name  ";
        cin >> name_1st;
        p.set_first_player(name_1st);

        cout << "Enter 2nd Player Name  ";
        cin >> name_2nd;
        p.set_second_player(name_2nd);

    here_3:
        cout << "Which Player 1st Enter you (X , O) ?";
        cin >> player_choice;

        if (player_choice != 'X' && player_choice != 'O')
        {
            cout << " invalid input. Enter Again  " << endl;
            goto here_3;
        }
        else
        {
            p.set_player_will_play(player_choice);
        }

        char player_choice_2 = player_choice;
        string player_name_change = name_1st;

        while (true)
        {
        here:
            cout << "Player " << player_name_change << " ( " << player_choice << " ) turn. Enter a number from 1 to 9: ";
            cin >> num;
            if (num == "exit" || num == "Exit")
            {
                d.exit_func();
            }
            else if (num == "edit" || num == "Edit")
            {
                e.edit_data(player_choice, win);
                goto here;
            }

            int input = stoi(num);

            if (input > 0 && input <= 9)
            {
                if (!already[input])
                {
                    cout << "That cell is already occupied. Please try again. " << endl;
                    goto here;
                }

                else
                {
                    for (int i = 1; i <= 9; i++)
                    {

                        if (input == i && already[input])
                        {
                            system("cls");
                            point[input - 1] = player_choice;
                            already[input] = false;
                            d.board();
                            win = c.check_win(player_choice);
                        }
                    }
                }

                if (win)
                {
                    if (player_choice == 'X' && player_choice_2 == 'X')
                    {
                        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
                        cout << "\t\t\t\t\t\t\t" << p.get_first_player() << " is win " << endl;
                        cout
                            << "\t\t\t-----------------------------------------------------------------------" << endl;
                    }
                    else
                    {
                        cout << "\t\t\t-----------------------------------------------------------------------" << endl;
                        cout << "\t\t\t\t\t\t\t" << p.get_second_player() << " is win " << endl;
                        cout
                            << "\t\t\t-----------------------------------------------------------------------" << endl;
                    }

                    break;
                }

                player_choice = (player_choice == 'X') ? 'O' : 'X';
                player_name_change = (player_name_change == name_1st) ? name_2nd : name_1st;
            }
            else
            {
                cout << "Invalid number. Try again." << endl;
            }
        }
    } while (true);
}

void AI ::print()
{
    int i, j;
    cout << "\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
                cout << ".\t";
            else if (a[i][j] == 1)
                cout << "X\t";
            else
                cout << "O\t";
        }
        cout << endl;
    }
}

int AI ::check()
{
    for (int i = 0; i < 3; i++)
        if ((a[i][0] != 0 && a[i][0] == a[i][1] && a[i][1] == a[i][2]) || (a[0][i] != 0 && a[0][i] == a[1][i] && a[1][i] == a[2][i]))
            return 1;

    if (a[0][0] != 0 && a[0][0] == a[1][1] && a[1][1] == a[2][2])
        return 1;
    else if (a[0][2] != 0 && a[0][2] == a[1][1] && a[1][1] == a[2][0])
        return 1;
    else
        return 0;
}

void AI ::pin()
{
    int r = 0, c = 0;
    cout << "Enter row: ";
    cin >> r;
    cout << "Enter column: ";
    cin >> c;
    r--;
    c--;
    if (r > 2 || c > 2 || r < 0 || c < 0)
    {
        cout << "Enter correct value ";
        cout << name;
        cout << ".\n";
        pin();
    }
    else if (a[r][c] != 0)
    {
        cout << "It is already filled.\n";
        pin();
    }
    else
        a[r][c] = t;
}

int AI ::defend(int c, int p, int b)
{
    if (b < 3)
        return 0;
    else if (a[0][0] + a[1][1] + a[2][2] == 2 * c && a[0][0] != p && a[1][1] != p && a[2][2] != p)
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i][i] == 0)
            {
                a[i][i] = y;
                cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                return 1;
            }
        }
    }
    else if (a[0][2] + a[1][1] + a[2][0] == 2 * c && a[0][2] != p && a[1][1] != p && a[2][0] != p)
    {
        for (int i = 0; i < 3; i++)
        {
            if (a[i][2 - i] == 0)
            {
                a[i][2 - i] = y;
                cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                return 1;
            }
        }
    }
    else
    {
        int i, j;
        for (i = 0; i < 3; i++)
        {
            if (a[i][0] + a[i][1] + a[i][2] == 2 * c && a[i][0] != p && a[i][1] != p && a[i][2] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (a[i][j] == 0)
                    {
                        a[i][j] = y;
                        cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                        return 1;
                    }
                }
            }
            else if (a[0][i] + a[1][i] + a[2][i] == 2 * c && a[0][i] != p && a[1][i] != p && a[2][i] != p)
            {
                for (j = 0; j < 3; j++)
                {
                    if (a[j][i] == 0)
                    {
                        a[j][i] = y;
                        cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int AI ::attack()
{
    int i, j;
    if (a[0][0] + a[0][2] + a[2][0] + a[2][2] == t || a[0][0] + a[0][2] + a[2][0] + a[2][2] == 2 * t)
    {
        for (i = 0; i < 3; i++)
        {
            if (a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            return 1;
                        }
                    }
                }
            }
            if (a[0][i] + a[1][i] + a[2][i] == y && (a[0][i] == y || a[1][i] == y || a[2][i] == y))
            {
                if (i == 1)
                {
                    for (j = 0; j < 3; j++)
                    {
                        if (a[j][i] == 0)
                        {
                            a[j][i] = y;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                }
                else
                {
                    for (j = 2; j >= 0; j--)
                    {
                        if (a[j][i] == 0)
                        {
                            a[j][i] = y;
                            cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                            return 1;
                        }
                    }
                }
            }
        }

        if (a[0][0] + a[1][1] + a[2][2] == y && (a[0][0] == y || a[1][1] == y || a[2][2] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if ((a[i][i] == 0) && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][i] + a[1][i] + a[2][i] == y) && (a[0][i] == y || a[1][i] == y || a[2][i] == y))))
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][i] + a[1][i] + a[2][i] == t && (a[0][i] == t || a[1][i] == t || a[2][i] == t)))
                    {
                        a[i][i] = y;
                        cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        }
        else if (a[0][2] + a[1][1] + a[2][0] == y && (a[0][2] == y || a[1][1] == y || a[2][0] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0 && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == y) && (a[0][2 - i] == y || a[1][2 - i] == y || a[2][2 - i] == y))))
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == t && (a[0][2 - i] == t || a[1][2 - i] == t || a[2][2 - i] == t)))
                    {
                        a[i][2 - i] = y;
                        cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
        }
    }
    else
    {
        if (a[0][0] + a[1][1] + a[2][2] == y && (a[0][0] == y || a[1][1] == y || a[2][2] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if ((a[i][i] == 0) && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][i] + a[1][i] + a[2][i] == y) && (a[0][i] == y || a[1][i] == y || a[2][i] == y))))
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][i] + a[1][i] + a[2][i] == t && (a[0][i] == t || a[1][i] == t || a[2][i] == t)))
                    {
                        a[i][i] = y;
                        cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                        return 1;
                    }
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][i] == 0)
                {
                    a[i][i] = y;
                    cout << "Computer turn: " << i + 1 << " " << i + 1 << endl;
                    return 1;
                }
            }
        }

        else if (a[0][2] + a[1][1] + a[2][0] == y && (a[0][2] == y || a[1][1] == y || a[2][0] == y))
        {
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0 && ((a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y)) || ((a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == y) && (a[0][2 - i] == y || a[1][2 - i] == y || a[2][2 - i] == y))))
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    if ((a[i][0] + a[i][1] + a[i][2] == t && (a[i][0] == t || a[i][1] == t || a[i][2] == t)) && (a[0][2 - i] + a[1][2 - i] + a[2][2 - i] == t && (a[0][2 - i] == t || a[1][2 - i] == t || a[2][2 - i] == t)))
                    {
                        a[i][2 - i] = y;
                        cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                        return 1;
                    }
                }
            }

            for (i = 2; i >= 0; i--)
            {
                if (a[i][2 - i] == 0)
                {
                    a[i][2 - i] = y;
                    cout << "Computer turn: " << i + 1 << " " << 3 - i << endl;
                    return 1;
                }
            }
        }

        else
        {
            for (i = 0; i < 3; i++)
            {
                if (a[i][0] + a[i][1] + a[i][2] == y && (a[i][0] == y || a[i][1] == y || a[i][2] == y))
                {
                    if (i == 1)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for (j = 2; j >= 0; j--)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                return 1;
                            }
                        }
                    }
                }
                else if (a[0][i] + a[1][i] + a[2][i] == y && (a[0][i] == y || a[1][i] == y || a[2][i] == y))
                {
                    if (i == 1)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (a[j][i] == 0)
                            {
                                a[j][i] = y;
                                cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                                return 1;
                            }
                        }
                    }
                    else
                    {
                        for (j = 2; j >= 0; j--)
                        {
                            if (a[j][i] == 0)
                            {
                                a[j][i] = y;
                                cout << "Computer turn: " << j + 1 << " " << i + 1 << endl;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void AI ::ai(int b)
{
    if (!defend(y, t, b))
    {
        if (!defend(t, y, b))
        {
            if ((a[0][0] + a[0][2] + a[2][0] + a[2][2] == t + y || a[0][0] + a[0][2] + a[2][0] + a[2][2] == t + 2 * y) && a[1][1] == 0)
            {
                for (int i = 0; i < 3; i += 2)
                {
                    for (int j = 0; j < 3; j += 2)
                        if (a[i][j] == 0)
                        {
                            a[i][j] = y;
                            cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                            goto end;
                        }
                }
            }
            else if (b == 2 && a[1][1] == 0)
            {
                a[1][1] = y;
                cout << "Computer turn: 2 2\n";
                goto end;
            }
            if (!attack())
            {
                if (b == 0)
                {
                    time_t seconds;
                    time(&seconds);
                    srand((unsigned int)seconds);
                    int i, j;
                    a[(rand() % 2) * 2][(rand() % 2) * 2] = y;
                    for (i = 0; i < 3; i += 2)
                    {
                        for (j = 0; j < 3; j += 2)
                            if (a[i][j] == y)
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                    }
                }
                else if (a[1][1] == 0)
                {
                    a[1][1] = y;
                    cout << "Computer turn: 2 2\n";
                }
                else
                {
                    int i, j;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (a[i][j] == 0)
                            {
                                a[i][j] = y;
                                cout << "Computer turn: " << i + 1 << " " << j + 1 << endl;
                                goto end;
                            }
                        }
                    }
                }
            }
        }
    }
end:
    cout << endl;
}

AI ::AI()
{
    Player p2;
    display d2;

    d2.startGame();

    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            a[i][j] = 0;
    if (game == 1)
    {
        string name;
        cout << "What is your good name? ";
        cin >> name;
        p2.set_first_player(name);
        cout << "\nHi " << p2.get_first_player();
        cout << ", so you wanna challenge me in Tic Tac Toe, right?\nLet's see who wins.";

        cout << "\nChoice is your's " << p2.get_first_player();
        cout << ", wanna go 1st or 2nd?";
    }
    else
    {
        cout << "\nOkay so you think you can beat me this time " << p2.get_first_player();
        cout << ".\nLet's see again if you can.";

        cout << "\nThis time you wanna go 1st or 2nd, " << p2.get_first_player() << " ? ";
    }

input:
    cin >> t;
    switch (t)
    {
    case 1:
        y = 2;
        cout << "\nSo your symbol is X.\nAnd mine is O.\n\nLet's start the game.";
        print();
        for (i = 0; i < 9;)
        {
            pin();
            print();
            i++;
            if (i > 4)
                if (check())
                {
                    cout << "\nOh, you won " << p2.get_first_player();
                    cout << " .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.";

                    exit(0);
                    break;
                }
            if (i >= 8)
                break;
            ai(i);
            print();
            i++;
            if (i > 5)
                if (check())
                {
                    cout << "\nIt is impossible to beat me ";
                    cout << p2.get_first_player();
                    if (game > 1)
                        cout << ", you couldn't beat me this time too, I won.";
                    else
                        cout << ", I won, you loose.";

                    break;
                }
        }
        break;

    case 2:
        y = 1;
        cout << "\nSo your symbol is O.\nAnd mine is X.\n\nLet's start the game.";
        print();
        for (i = 0; i < 9;)
        {
            ai(i);
            print();
            i++;
            if (i > 4)
                if (check())
                {
                    cout << "It is impossible to beat me ";
                    cout << p2.get_first_player();
                    if (game > 1)
                        cout << ", you couldn't beat me this time too, I won.";
                    else
                        cout << ", I won, you loose.";

                    break;
                }
            if (i >= 8)
                break;
            pin();
            print();
            i++;
            if (i > 5)
                if (check())
                {
                    cout << "\nOh, you won ";
                    cout << p2.get_first_player();
                    cout << " .\nCongratulations\nGreat work!\n\nMy algorithm needs to be improved.\nBie.";
                    exit(0);
                    break;
                }
        }
        break;
    default:
        cout << "Hey, ";
        cout << p2.get_first_player();
        cout << " you need to enter either 1 or 2.";
        cout << "\nEnter again: ";
        goto input;
        break;
    }
    if (!check())
    {
        if (game > 1)
            cout << "Well Played!\nBut you couldn't beat me this time too\n";
        else
            cout << "Well Played!\nIt is a tie.\n";
    }
    char c;
    cout << "Wanna play again ";
    cout << p2.get_first_player();
    cout << " y/n?";
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        game++;
        main();
    }
    else
        exit(0);
}