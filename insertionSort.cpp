#include <iostream>
#include <cstdlib>
#include <fstream>
#include<time.h>
using namespace std;

class insertionSort{
public:
    int *arr;
    int comparison = 0;
    int length;
    insertionSort()
    {
        length = 30 + rand() % (1000 - 30 + 1);
        arr = new int[length];
    }
    void populate()
    {
            for(int j=0;j<length;j++)
            {
                arr[j] = rand()%100;
            }
        }


    int sort(){
        int key;
        int i;
        for(int j=1;j<length;j++)
        {   key = arr[j];
            i = j-1;
            while(i>=0 && arr[i]>key)
            {   comparison++;
                arr[i+1] = arr[i];
                i--;
            }
            
			
			arr[i+1] = key;

        }
        return comparison;
    }

    };
    int main(){
        srand(time(0));
        ofstream myFile;
        ofstream myFile1;
        myFile.open("compare.csv");
        myFile1.open("length.csv");
     for(int i=0;i<100;i++){
        insertionSort obj;
        obj.populate();
        myFile1<<obj.length;
        myFile1<<endl;
        myFile<<obj.sort();
        myFile<<endl;}
    }
