#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;
#define height 30
#define width 80
struct snack{
    int h;
    int w;
    int len = 2;
    char dir;
    vector<pair<int,int> >bodypostions;
};
int pos1 = 5,pos2 = 10;
bool isVaild(snack &obj){
    if(obj.h == pos1 && obj.w == pos2){
        //str += "q";
        //p = "";
        obj.len++;
        pos1 = rand()%height-1;
        pos2 = rand()%width-1;
    }



}
//string q = "qqq";
//string b = "f";
void Window(snack &obj){
     /// drawing the window

     //int k = 0;
     int u = 1;
     int lenn = 3;
     cout << "\t\tScore : " << obj.len - 1<<"\n\n\n";
     for(int i = 0; i< height; ++i){
        cout << "\t\t¶";
         if(isVaild(obj)){
         }
        for(int j = 0; j < width; ++j){

            if(i == obj.bodypostions[obj.bodypostions.size()-1].first && j == obj.bodypostions[obj.bodypostions.size()-1].second){
                cout << '*';

                continue;
            }
            if(i == pos1 && j == pos2){
                cout << '*';
                continue;

            }

            if(i == 0 || i == height-1){
                cout << '=';
            }else{
             bool body = false;
             for(int k = 0 ; k < obj.bodypostions.size(); ++k)
                {

                    if(obj.bodypostions[k].first == i && obj.bodypostions[k].second == j){
                        cout << '*';
                        body = true;
                        break;
                    }

                }
                if(!body){
                        cout << ' ';
                    }
            }



        }
        cout << "¶\n";
     }


}

void move_snack(char ch,snack &obj){
    //obj.bodypostions.push_back({obj.h,obj.w});
    switch(ch){
       case 'w':
            obj.h--;
            break;
       case 's':
            obj.h++;
            break;
       case 'd':
            obj.w++;
            break;
       case 'a':
            obj.w--;


    }
    obj.bodypostions.push_back({obj.h,obj.w});
    if(obj.bodypostions.size() > obj.len){
        obj.bodypostions.erase(obj.bodypostions.begin());
    }
}
bool GameOver(snack&obj){

return obj.h == height-1 || obj.w == width-1 || obj.h == -1 || obj.w == -1;
}
void prinGameOver(){
    for(int i = 0; i < 12; ++i){
        cout << endl;
        for(int j = 0; j < 12; ++j){
          cout << " ";
        }

    }

    cout << "Game Over!";


}

int main()
{
    snack obj;
    obj.h = 10;
    obj.w = 23;
    obj.bodypostions.push_back({10,23});
    //Window(obj);
    int flage = 1;
    while(!GameOver(obj)){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        Window(obj);
        //obj.w++;
        cout << kbhit() << endl;
        if(kbhit()){
            obj.dir = getch();
        }
        move_snack(obj.dir,obj);

    }
    system("cls");
    prinGameOver();
    return 0;
}
