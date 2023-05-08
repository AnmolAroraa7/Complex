#include <iostream>
#include <cstdlib>
#include <fstream>
#include<time.h>
using namespace std;

class mergeSort{
public:
    int *A;
    int c = 0;
    int length;
    mergeSort()
    {
        length = 30 + rand() % (1000 - 30 + 1);
        A = new int[length];
    }
    void populate()
    {
            for(int j=0;j<length;j++)
            {
                A[j] = rand()%100;
            }
        }

	void merge(int l, int m,int n){
		int r[1000];
		int i,j,k;
		i=l;
		j=m+1;
		k=l;
	
		while(i<=m && j<=n){
			if(A[i]<=A[j]){
				r[k]=A[i];
				k++;
				i++;
			}
			else{
				r[k]=A[j];
				k++;
				j++;
			}
			c++;
		}
		while(i>m && j<=n){
			r[k]=A[j];
			j++;
			k++;
		}
		while(j>n && i<=m){
			r[k]=A[i];
			i++;
			k++;
		}
		for(i=l;i<=n;i++){
			A[i]=r[i];
		}
	}
    int sort(int left,int right){
        int mid;
        if (left<right){
        	mid=(left+right)/2;
        	sort(left,mid);
        	sort(mid+1,right);
        	merge(left,mid,right);
        	
		}
        
        return c;
    }

    };
    int main(){
        srand(time(0));
        ofstream myFile;
        ofstream myFile1;
        myFile.open("compare1.csv");
        myFile1.open("length1.csv");
     for(int i=0;i<100;i++){
        mergeSort obj;
        obj.populate();
        myFile1<<obj.length;
        myFile1<<endl;
        int l=obj.length;
        myFile<<obj.sort(0,l-1);
        myFile<<endl;}
    }
