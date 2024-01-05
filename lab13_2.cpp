#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[N][M]){
    for(int i = 0; i < M + 2; i++) cout << "-";
    cout << "\n";
    for(int i = 0; i < N; i++){
        cout << "|";
        for(int j = 0; j < M; j++){
            if(image[i][j]) cout << "*";
            else cout << " ";
        }
        cout << "|\n";
    }
     for(int i = 0; i < M + 2; i++) cout << "-";
     cout << "\n";
}

void updateImage(bool image[N][M], int s, int x, int y){

   for(int i = x - s; i <= x + s and i < N; i++){
   if (i < 0) continue;
       for(int j = y - s; j <= y + s and j < M; j++){
           if (j < 0) continue;
           if(sqrt(pow(i - x, 2) + pow(j - y, 2)) <= (s-1))
               image[i][j] = 1; 
    }
  }
}