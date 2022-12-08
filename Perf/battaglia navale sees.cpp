#include <iostream>
#include <ctime>
#include <stdlib.h>
#define N 10

using namespace std;

void generaCampo(int campo[][N],int terreno[][N]);
void visualizzaMat(int campo[][N]);
int battagliaNavale(int campo[][N],int terreno[][N]);

int main(){
	int mat1[N][N], mat2[N][N];
	int c;
	generaCampo(mat1,mat2);
	srand(time(NULL));
	c=battagliaNavale(mat1,mat2);
	cout<<"hai vinto con "<<c<<"tentativi\n";
}

void visualizzaMat(int campo[][N]){
	
	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
		cout<<campo[i][j]<<"\t";
	}
	cout<<endl;
	}
	
}
                 //campo è ciò che si vede, terreno è il corrispettivo con le navi
void generaCampo(int campo[][N],int terreno[][N]){
	
	for (int i = 0; i<N; i++){
		for(int j=0; j<N; j++){
			campo[i][j]=0;
		}
	}
	
	for (int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			terreno[i][j] = rand() %2;
		}
	}
}

int battagliaNavale(int campo[][N],int terreno[][N]){
	int x, y;
	int contaNavi=0;
	int tentativi;
	int naviPrese;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if (terreno[i][j]==1){
				contaNavi++;
			}
		}
	}
	do{
		
	    visualizzaMat(campo);
		do{
     	cout<<"inserisci la cordinata X"<<endl;
    	cin>>x;
        }while(x>N||x<0);
      
        do{
     	cout<<"inserisci la cordinata Y"<<endl;
	    cin>>y;
        }while(y>N||y<0);
        system("cls");
           if(terreno[y][x]==1){
           cout<<"hai preso una nave"<<endl;
           campo[y][x]=1;
           naviPrese++;
        }else{
   	      cout<<"non hai preso un cazzo (gg)\n";
   	     campo[y][x]=4;
        }   
         tentativi++;
         
         
	 }while(naviPrese!=contaNavi);
	 
	 return tentativi;
   }









