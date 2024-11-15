#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<math.h>
using namespace std;
#define ROWS 100
#define COLS 100
#define CDIM 10
#define RDIM 10
#define PI 3.1476
#define CAPACITY 1000
void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT |
        ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState ==

            FROM_LEFT_1ST_BUTTON_PRESSED)

        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void color(int textColor, int backgroundColor = 0) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD color = (backgroundColor << 4) | (textColor & 0x0F);
    SetConsoleTextAttribute(hConsole, color);
}
void linefunction(int p1x, int p1y, int p2x, int p2y, char sym = -37) {


    for (float alpha = 0; alpha <= 1; alpha = alpha + 0.01) {

        int row_index = p1y * alpha + p2y * (1 - alpha);
        int col_index = p1x * alpha + p2x * (1 - alpha);
        gotoRowCol(row_index, col_index);
        cout << sym;

    }


}
void print_circle(int cr, int cc, int R, char sym = -37, int i = 1) {
    color(i);
    for (float theta = 0; theta <= 360; theta = theta + 1) {

        int x = ceil(R * cos(theta * PI / 180) + cc),
            y = ceil(R * sin(theta * PI / 180) + cr);
        gotoRowCol(y-1, x-1);
        cout << sym;

    }
}
void dice_box(char sym = -37) {
    
    int sr = 50;
    int sc = 105;
    for (int i = 0; i < RDIM; i++) {
        for (int j = 0 ; j < CDIM; j++) {

            gotoRowCol(i + sr, j + sc);
            if(i==0 or i==RDIM-1 or j==0 or j==CDIM-1)
            cout << sym;
        }

    }
}
void box(int sr,int sc) {
    char sym = -37;

    for (int r = 0; r < RDIM; r++) {
        for (int c = 0; c < CDIM; c++) {
           


            


            gotoRowCol(r + sr, c + sc);
            if (r==0  or r == RDIM - 1 or c == 0 or c == CDIM - 1)
                cout << sym;

        }
    }
               

}
void grid_maker() {

    for (int r = 0; r < RDIM; r++) {

        for (int c = 0; c < CDIM; c++) {
            
            int sr = r * RDIM;
            int sc = c * CDIM;
            box(sr,sc);
        }
    }

}
void drawVerticalSnake(int startY, int endY, int amplitude, double frequency, int xOffset, char sym = -37) {
    color(18);
    for (int y = startY; y < endY; y++) {
        int x = int((amplitude * sin(frequency * y) + xOffset));
        gotoRowCol(y, x);
        cout << sym;
    }
}


void printing_numbers() {
    
    int temp = 100;
    gotoRowCol(0, 0);
    for (int i = 0; i < RDIM; i++) {
        for (int j = 0; j < CDIM; j++) {

            if (i % 2 == 0) {
                
                if (temp % 2 == 0)
                    color(4);
                else
                    color(15);
                gotoRowCol(RDIM / 2 + RDIM * i, CDIM / 2 + CDIM * j - 1);
                cout << temp--;
                
            }
            else {
                if (temp % 2 == 0)
                    color(4);
                else
                    color(15);
                gotoRowCol(RDIM / 2 + RDIM * i, COLS - CDIM * j - 6);
                cout << temp--;
            }

        }
    }

}
void moving_goti(int n,int color) {

    int start_row = (n - 1) / 10;
    int start_column = (n - 1) % 10;
    int r = (9 - start_row) * RDIM;
    int c = 0;

    if (start_row % 2 == 0)
        c = start_column * CDIM;
    else
        c = (9 - start_column) * CDIM;

    print_circle(r + 5, c + 5, 3,-37,color+1);
    
}
void remove_goti(int n) {
    int start_row = (n - 1) / 10;
    int start_column = (n - 1) % 10;
    int r = (9 - start_row) * RDIM;
    int c = 0;

    if (start_row % 2 == 0)
        c = start_column * CDIM;
    else
        c = (9 - start_column) * CDIM;

    print_circle(r + 5, c + 5, 3,' ');
}
void spinning_animation_of_dice() {
    int i = 0;
    while (i <= 5) {
        Sleep(10);
        dice_box();
        Sleep(10);

        dice_box(' ');

        linefunction(110, 50, 105, 55);
        linefunction(105, 55, 110, 60);
        linefunction(110, 60, 115, 55);
        linefunction(115, 55, 110, 50);
        Sleep(10);

        linefunction(110, 50, 105, 55, ' ');
        linefunction(105, 55, 110, 60, ' ');
        linefunction(110, 60, 115, 55, ' ');
        linefunction(115, 55, 110, 50, ' ');
        i++;
    }

    dice_box();
}
int printing_dots_and_giving_a_random_number(char sym = -37) {
    int sum = 0;
    int number;
    char ch;




    number = rand() % 6 + 1;
    sum += number;
    if (number == 6) {
        gotoRowCol(52, 107);
        cout << sym;
        gotoRowCol(57, 107);
        cout << sym;
        gotoRowCol(52, 112);
        cout << sym;
        gotoRowCol(57, 112);
        cout << sym;

        gotoRowCol(55, 108);
        cout << sym;
        gotoRowCol(55, 112);
        cout << sym;


    }
    else  if (number == 5) {
        gotoRowCol(55, 109);
        cout << sym;
        gotoRowCol(52, 107);
        cout << sym;
        gotoRowCol(57, 107);
        cout << sym;
        gotoRowCol(52, 112);
        cout << sym;
        gotoRowCol(57, 112);
        cout << sym;

    }
    else  if (number == 4) {
        gotoRowCol(52, 107);
        cout << sym;
        gotoRowCol(57, 107);
        cout << sym;
        gotoRowCol(52, 112);
        cout << sym;
        gotoRowCol(57, 112);
        cout << sym;

    }
    else   if (number == 3) {
        gotoRowCol(52, 107);
        cout << sym;
        gotoRowCol(55, 109);
        cout << sym;
        gotoRowCol(57, 112);
        cout << sym;

    }
    else   if (number == 2) {
        gotoRowCol(55, 108);
        cout << sym;
        gotoRowCol(55, 112);
        cout << sym;

    }
    else  if (number == 1) {
        gotoRowCol(55, 109);
        cout << sym;

    }
    if (sum == 18) {
        return 0;
    }
    return sum;

}
void removing_dice_numbers() {
    char sym = ' ';
    gotoRowCol(52, 107);
    cout << sym;
    gotoRowCol(57, 107);
    cout << sym;
    gotoRowCol(52, 112);
    cout << sym;
    gotoRowCol(57, 112);
    cout << sym;

    gotoRowCol(55, 108);
    cout << sym;
    gotoRowCol(55, 112);
    cout << sym;
    gotoRowCol(55, 109);
    cout << sym;

}
int Animation_of_dice() {
    color(15);
    int result = 0;
    int sum = 0;
    do {
        if (true) {
            if (result == 6)
                _getch();
            removing_dice_numbers();
            spinning_animation_of_dice();
            result = printing_dots_and_giving_a_random_number();
            sum += result;
            Sleep(1000);
            Sleep(100);

        }
        if (sum == 18) {
            gotoRowCol(70, 110);
            cout << "SAR GAYA!";
            return 0;
        }
    } while (result == 6);
    return sum;
}

void ladderfunction(int p1x, int p1y, int p2x, int p2y, char sym = -37) {
    color(94);
    int i = 0;
    int fix = 5;
    for (float alpha = 0; alpha <= 1; alpha = alpha + 0.01) {

        int row_index = int(p1y * alpha + p2y * (1 - alpha));
        int col_index = int(p1x * alpha + p2x * (1 - alpha));


        gotoRowCol(row_index, col_index);
        cout << sym;
        gotoRowCol(row_index + fix, col_index + fix);
        cout << sym;

        if (row_index % 7 == 0 || col_index % 11 == 0) {
            linefunction(col_index, row_index, col_index + 3, row_index + 3);
        }
    }


}
void all_ladders() {

    ladderfunction(12, 6, 2, 24);
    ladderfunction(72, 96, 92, 76);
    ladderfunction(2, 96, 22, 65);
    ladderfunction(52, 75, 72, 15);
    ladderfunction(21, 47, 32, 25);

}
void all_snakes() {
    drawVerticalSnake(5,25,4,0.4,35);
    drawVerticalSnake(65,95,3,0.4,85);
    drawVerticalSnake(55,85,2,0.4,25);
}


void printStartButton() {

  
   
    cout << "--------------------------------------" << endl;
    cout << "                                                  |                                    |" << endl;
    cout << "                                                  |  *****  *****  *****  *****  ***** |" << endl;
    cout << "                                                  |  *        *    *   *  *   *    *   |" << endl;
    cout << "                                                  |  *****    *    *****  *****    *   |" << endl;
    cout << "                                                  |      *    *    *   *  *   *    *   |" << endl;
    cout << "                                                  |  *****    *    *   *  *   *    *   |" << endl;
    cout << "                                                  |                                    |" << endl;
    cout << "                                                  -------------------------------------" << endl;
    
}
void start_menu() {

    gotoRowCol(50, 50);
    cout << "NEW GAME" << endl;
    gotoRowCol(60, 50);
    cout << "SAVE GAME" << endl;
}

int ladder_moving_goti(int n) {

    if (n == 1)
        return 37;
    else if (n == 8)
        return 22;
    else if (n == 26)
        return 62;
    else if (n == 58)
        return 19;
    else if (n == 80)
        return 19;
        return 0;
}
int snake_moving_goti(int n) {

    if (n == 97)
        return -20;
    else if (n == 32)
        return -23;
    else if (n == 43)
        return -25;
  
    return 0;
}
void init_players(string P[], int p) {
    string pn;
    for (int i = 0; i < p; i++) {
        gotoRowCol(55+5*i, 50);
        cin >> pn;
        P[i] = pn;
    }
    Sleep(1000);
    system("cls");
}

void print_goti(int P[], int n) {

    for (int i = 0; i <n; i++)
        moving_goti(P[i],i);

}

void print_player_names(string P[], int p,int turn) {
    int temp = 13;
    for (int i = 0; i < p; i++) {
        if (i+1 == turn)
            color(15, turn);
        else
            color(15);
        gotoRowCol(temp, 103);
        cout << P[i];
        temp += 3;
    }
}

int main() {
    srand(time(0));
    string Player_names[CAPACITY] = {};
    int PP[CAPACITY] = {  };
    int Prev_PP[CAPACITY] = {};
    int WIN[CAPACITY] = {};
    int no_of_players=0;
    int dice_numbers;
    int r;
    int c;

    gotoRowCol(ROWS/2, COLS/2);
    printStartButton();
    do {
        getRowColbyLeftClick(r, c);
    } while ( !(r >= 50 and r <= 58 and c >= 50 and c <= 87));
    system("cls");

    start_menu();
  
    do {
        getRowColbyLeftClick(r, c);
    } while (!(r >= 50 and r<=60 and c >= 50 and c <= 60));

    if (r == 60 and c >= 50 and c <= 60) {
        ifstream rdr("haha.txt");
        rdr >> no_of_players;
        for (int i = 0; i < no_of_players; i++)
            rdr >> PP[i];

        for (int i = 0; i < no_of_players; i++)
            rdr >> Player_names[i];


    }
    system("cls");
    int win_count = 0;
    int turn = 0;
    int l = 0;
    int s = 0;
    int ws = 0;
    print_goti(PP, no_of_players);
  
    color(15);
    if (r == 50 and c >= 50 and c <= 60) {

    gotoRowCol(ROWS / 2, COLS / 2);
    cout << "ENTER NUMBER OF PLAYERS:";
    cin >> no_of_players;
    init_players(Player_names, no_of_players);

    }
    grid_maker();
    printing_numbers();
    all_ladders();
    all_snakes();
   
    int hehe = 0;
        while (win_count < no_of_players - 1) {
            color(15);
                for (int i = 0; i < no_of_players; i++)
                {
                        if (PP[i] == 100) {
                            win_count++;
                            WIN[ws++] = i;
                            continue;
                        }
                        print_player_names(Player_names, no_of_players, i + 1);
                        int ch = _getch();
                        if (ch == 32) {

                            if (PP[i] != 0)
                                Prev_PP[i] = PP[i];


                            PP[i] += Animation_of_dice();
                            l = ladder_moving_goti(PP[i]);
                            s = snake_moving_goti(PP[i]);
                            PP[i] += l + s;


                            if (PP[i] > 100)
                                PP[i] = Prev_PP[i];

                            if (Prev_PP[i] != 0)
                                remove_goti(Prev_PP[i]);
                            printing_numbers();
                            moving_goti(PP[i], i);

                            if (hehe >= 1)
                                print_goti(PP, no_of_players);
                        }
                        else if (ch == 's' or ch== 'S') {
                            system("cls");
                            gotoRowCol(50, 50);
                            cout << "GAME SAVED!" << endl;
                            ofstream wtr("haha.txt");
                            wtr << no_of_players << " ";
                            for (int i = 0; i < no_of_players; i++)
                                wtr << PP[i] << " ";
                            

                            for (int i = 0; i < no_of_players; i++)
                                wtr << Player_names[i] << " ";

                            return 0;
                        }
                }
             hehe++;
        }
   





  
        

        //LEADERBOARD
        system("cls");
        color(15);
        int temp = 1;
         for (int i = 0; i < no_of_players; i++) {
            int result = WIN[i];
            gotoRowCol(50 + i * 3, 50);
            cout << Player_names[i] << " " << temp++ << "s" << endl;
        }


        _getch();
        return 0;
}