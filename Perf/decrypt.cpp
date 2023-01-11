#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

int main(){
	std::string str;
	std::vector<int> chiavi;
	int temp=0;
	
	std::cout<<"Inserisci la stringa\n";
	std::getline(std::cin>>std::ws, str);
	char* charStr = new char[str.size()+1];
	std::copy(str.begin(), str.end(), charStr);
	char* v = new char[str.size()+1];
	char* ord = new char[str.size()+1];

	v[str.length()]='\0';
	charStr[str.length()]='\0';
	ord[str.length()]='\0';
	
	int* unic = new int[str.length()+1];
	
	for (int i = 0; i<str.length(); i++){
		unic[i]=0;
	}
	
	srand(str.length());
	for(int i = 0; i<str.length(); i++){
		while(unic[temp-1]!=0){
			
			temp = rand() %str.length()+1;
		}
		
		unic[temp-1]=1;
		chiavi.push_back(temp);
	}
	
	srand(str.length()+371);
	for (int i = 0; i<str.length(); i++){
		charStr[i] = charStr[i]-(rand() % 10+1);
		ord[i] = charStr[i];
		
	}
	
	for(int i = 0; i<str.length(); i++){
	
	temp = chiavi[i];
	
		v[temp-1] = ord[i];
		charStr[temp-1] = ord[i];
		charStr[i] = v[temp-1];
	
	}
		std::cout<<v<<"\n";
		
			 system("Pause");
}
