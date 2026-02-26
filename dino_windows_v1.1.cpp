#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <random>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;
int in_hi_score(){
    ifstream inFile("example.txt");
    int hi_score;
    if (inFile >> hi_score) {
        inFile.close();
        return hi_score;
    } else {
        cout << "can't find HI score" << endl;
        return -1;
    }
}
void game(){
    bool dino_type=1;
    int tpye_1=0;
    int near_type=10;
    int x=0;
    vector<char> a;
    a.resize(48,' ');
    int hi_score = in_hi_score();
    int y=0;
    for(;;){
        if(x%100==0){
            y=3;
            cout<<"!!!!!!                              HI "<<hi_score<<' '<<x<<endl;
        }
        else if(y>0){
            cout<<"!!!!!!                              HI "<<hi_score<<' '<<x<<endl;
            y--;
        }
        else{
            cout<<"                                    HI "<<hi_score<<' '<<x<<endl;
        }
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
    if (x > hi_score) {
        ofstream outFile("example.txt");
        outFile << x << endl;
        outFile.close();
        cout << "NEW HI SCORE!!"<< endl;
    }
    else if(hi_score == -1){
        ofstream outfile("example.txt");
        outfile << x;
        outfile.close();
        cout << "Something went wrong!"<< endl;
    }
    else{
        cout << "HI SCORE: " << hi_score << endl;
    }
    cout<<"Version 1.1 for windows"<<endl;
    cout<<"by littlesnowman 26/2/2026"<<endl;
    system("timeout -1");
}
int main(){
    cout<<"welcome to the game,it's like chrome dino"<<endl;
    cout<<"   0  0  0"<<endl;
    cout<<" 000     0000  0000"<<endl;
    cout<<" 0 0  0  0  0  0  0"<<endl;
    cout<<" 000  0  0  0  0000"<<endl;
    cout<<"game will start"<<endl;
    system("timeout -1");
    system("cls");
    game();
    return 0; 
}