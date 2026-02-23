#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <random>
#include <conio.h>
using namespace std;
void game(){
    bool dino_type=1;
    int tpye_1=0;
    int near_type=10;
    int x=0;
    vector<char> a;
    a.resize(48,' ');
    for(;;){
        cout<<"                                           "<<x<<endl;
        x++;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 9);
        int random_number = dis(gen);
        if(tpye_1==0){
            dino_type=0;
        }
        else{
            dino_type=1;
            tpye_1--;
        }
        
        if (_kbhit()) {
            char key = _getch();
            if (key == ' ') {
                dino_type=1;
                tpye_1=4;
            }
        }
        cout<<"-----------------------------------------------"<<near_type<<endl;
        a.erase(a.begin());
        a.push_back(' ');
        if(dino_type==0){
            a[0]='0';
            cout<<endl;
        }
        else{
            cout<<'0'<<endl;
        }
        if(random_number==5){
            if(x>=5){
                a[47]='x';
            }
        }
        for(int i=0;i<(int)a.size();i++){
            cout<<a[i];
        }
        for(int i=0;i<(int)a.size();i++){
            if(a[i]=='x'){
                near_type=i-1;
                break;
            }
        }
        if(near_type==0 and dino_type==0){
            break;
        }
        cout<<endl;
        cout<<"-----------------------------------------------"<<endl;            
        system("cls");
        Sleep(1);
    }
    system("cls");
    cout<<"gameover!!!"<<endl;
    cout<<"Score:"<<x<<endl;
    cout<<"Version 1.0 for windows"<<endl;
    cout<<"by littlesnowman 14/2/2026"<<endl;
    system("timeout -1");
}
int main(){
    cout<<"welcome to the game,it's like chrome dino"<<endl;
    cout<<"game will start"<<endl;
    system("timeout -1");
    system("cls");
    game();
    return 0; 
}