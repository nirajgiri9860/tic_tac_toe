#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void menu(void);
void rules(void);
void game(void);
void display(void);
char check(void);
int replay(void);
void reset(void);
inline void thank(void){
    cout << "\tThank you for using our software." << endl;
}
inline void error(void){
    cout << "\tError: Invalid Selection" << endl;
}

char val[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char ox, xo, tem, choice;
int num, player1=0, player2=0;

int main()
{
    menu();
    return 0;
}

void menu(void){
    char choiceMenu;
    int flagMenu=0;
g1:
    system("cls");
    if(flagMenu!=0){
        error();
        flagMenu--;
    }
    cout << endl << "\t\tTic Tac Toe\n\n";
    cout << "\t1. Play\n\t2. Rules\n\t3. Exit\n\n\tMake your selection: ";
    cin >> choiceMenu;
    if(choiceMenu=='1'){
        system("cls");
        game();
    }
    else if(choiceMenu=='2'){
        system("cls");
        rules();
    }
    else if(choiceMenu=='3'){
        thank();
        exit(0);
    }
    else{
        flagMenu++;
        goto g1;
    }
}

void game(void){
    int flag=0, temNum;
    string name1, name2;
    char choiceGame, winFlag;
g1:
    cout << "Enter name(Player 1): ";
    cin >> name1;
    cout << "Enter name(Player 2): ";
    cin >> name2;
    system("cls");
    cout << "\t---------------------------------------" << endl;
    cout << "\t\tWelcome " << name1 << " and " << name2 << endl ;
    cout << "\t---------------------------------------" << endl << endl << endl;
    cout << name1 << ", choose avatar (X/O): ";
    cin >> ox;
    if(!(ox=='X' || ox=='x' || ox=='O' || ox=='o')){
        system("cls");
        error();
        goto g1;
    }
    if(ox=='X' || ox=='x'){
        ox = 'X';
        xo = 'O';
    }else{
        ox = 'O';
        xo = 'X';
    }
    for(int k=0; k<9; k++){
        system("cls");
        if(flag!=0){
            cout << "\tNote:\t" << num << " is invalid" << endl;
            flag--;
        }
        cout << "\n\t" << name1 << ": (" << ox << ")\t" << name2 << ": (" << xo << ")" << endl;
        display();
        if(k>4){
            winFlag = check();
            if(winFlag==ox){
                cout << "\n\n\tCongratulations: " << name1 << " won the match" << endl;
                if(replay()==1){
                    fflush(stdin);
                    reset();
                    goto g1;
                }else{
                    thank();
                    exit(0);
                }
            }
            else if(winFlag==xo){
                cout << "\n\n\tCongratulations: " << name2 << " won the match" << endl;
                if(replay()==1){
                    fflush(stdin);
                    reset();
                    goto g1;
                }else{
                    thank();
                    exit(0);
                }
            }
        }
        if(flag!=0){
            if(tem==ox){
                cout << endl << endl << "Enter number (" << name1 << "): ";
            }else{
                cout << endl << endl << "Enter number (" << name2 << "): ";
            }
            flag--;
        }else if(player1<=player2){
            tem = ox;
            player1++;
            cout << endl << endl << "Enter number (" << name1 << "): ";
        }else if(player2<player1){
            tem = xo;
            player2++;
            cout << endl << endl << "Enter number (" << name2 << "): ";
        }
        cin >> num;
        switch(num)
        {
        case 1:
            if(val[0][0]<58){
                val[0][0] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 2:
            if(val[0][1]<58){
                val[0][1] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 3:
            if(val[0][2]<58){
                val[0][2] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 4:
            if(val[1][0]<58){
                val[1][0] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 5:
            if(val[1][1]<58){
                val[1][1] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 6:
            if(val[1][2]<58){
                val[1][2] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 7:
            if(val[2][0]<58){
                val[2][0] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 8:
            if(val[2][1]<58){
                val[2][1] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        case 9:
            if(val[2][2]<58){
                val[2][2] = tem;
            }else{
                flag+=2;
                k--;
            }
            break;
        default:
            flag+=2;
            k--;
        }
    }
    system("cls");
    cout << "\n\t" << name1 <<": (" << ox << ")\t" << name2 << ": (" << xo << ")" << endl;
    display();
    cout << "\n\n\tNote: Out of moves." << endl;
    choiceGame = replay();
    if(replay()){
        goto g1;
    }else{
        thank();
        exit(0);
    }
}

void display(void){
    cout << endl << endl;
    for(int i=0; i<5; i++){
        cout << "\t\t";
        if((i%2)==0){
            for(int j=0; j<5; j++){
                if((j%2)==0){
                    cout << " " << val[i/2][j/2] << " ";
                }else{
                    cout << " | ";
                }
            }
        }else{
            for(int j=0; j<5; j++){
                if((j%2)==0){
                    cout << "---";
                }else{
                    cout << "   ";
                }
            }
        }
        cout << endl;
    }
}

void rules(void){
    system("cls");
    cout << endl << "\t#  Rules:\n\n";
    cout << "\t1. Choose your avatar (X/O)\n\t2. Enter number(1-9) to fill empty box with your avatar (X/O)\n";
    cout << "\t3. The one who gets three avatar in a sequence either diagonally, horizontally or vertically wins" << endl << endl;
    cout << "\tReturn to Menu(Y/N): ";
    cin >> choice;
    if(choice=='Y' || choice=='y'){
        system("cls");
        menu();
    }else{
        thank();
        exit(0);
    }
}

char check(void){
    int checkVal;
    if(val[0][0]==val[0][1] && val[0][0]==val[0][2]){
        return val[0][0];
    }
    else if(val[0][0]==val[1][0] && val[0][0]==val[2][0]){
        return val[0][0];
    }
    else if(val[0][0]==val[1][1] && val[0][0]==val[2][2]){
        return val[0][0];
    }

    else if(val[2][2]==val[2][1] && val[2][2]==val[2][0]){
        return val[2][2];
    }
    else if(val[2][2]==val[1][2] && val[2][2]==val[0][2]){
        return val[2][2];
    }

    else if(val[2][0]==val[1][1] && val[2][0]==val[0][2]){
        return val[2][0];
    }

    else if(val[1][0]==val[1][1] && val[1][0]==val[1][2]){
        return val[1][0];
    }
    else if(val[0][1]==val[1][1] && val[0][1]==val[2][1]){
        return val[0][1];
    }
    else{
        return '\0';
    }
}

int replay(void){
    char yes;
    cout << "\tDo you want to play again(Y/N): ";
    cin >> yes;
     if(yes=='Y' || yes=='y'){
        fflush(stdin);
        return 1;
     }else{
         return 0;
     }
}

void reset(void){
    int temNum;
    system("cls");
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            temNum = (x*3)+y+1;
            val[x][y] = '0' + (char)temNum;
        }
    }
    player1 = 0;
    player2 = 0;
}
