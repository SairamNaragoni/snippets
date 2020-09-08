#include<bits/stdc++.h>
using namespace std;

string encrypt(string str,int key){
	string result="";
	int row=key,col=str.size();
	char arr[row][col] ;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j] = '\n';
		}
	}
	bool dir_down = false;
	row=col=0;
	for(int i=0;i<str.size();i++){		
		if(row==0||row==(key-1)){
			dir_down = !dir_down;
		}
		arr[row][col++] = str[i]; 
		dir_down?row++ : row--; 
	}
	for (int i=0; i < key; i++) 
		for (int j=0; j < str.size(); j++) 
			if (arr[i][j]!='\n') 
				result+=(arr[i][j]); 
	return result;	
}

string decrypt(string str,int key){
	char arr[key][str.size()]; 
	int row=key,col=str.size();
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			arr[i][j] = '\n';
		}
	}	
	bool dir_down=false; 
	row = 0, col = 0; 
	for (int i=0; i < str.size(); i++) 
	{ 
		if(row==0||row==(key-1)){
			dir_down = !dir_down;
		} 
		arr[row][col++] = '*'; 	
		dir_down?row++ : row--; 
	} 
	int index = 0; 
	for (int i=0; i<key; i++) 
		for (int j=0; j<str.size(); j++) 
			if (arr[i][j] == '*' && index<str.size()) 
				arr[i][j] = str[index++]; 
	string result=""; 
	dir_down = false;
	row = 0, col = 0; 
	for (int i=0; i< str.size(); i++) 
	{ 
		if(row==0||row==(key-1)){
			dir_down = !dir_down;
		} 
		if (arr[row][col] != '*') 
			result+=(arr[row][col++]); 
		dir_down?row++: row--; 
	} 
	return result; 
}

int main(){
	string str;
	int key;
	cout<<"Enter the Key (int) \n";
	cin>>key;
	while(1){
		cout<<"......MENU.........."<<endl;
		cout<<"1.Encryption"<<endl;
		cout<<"2.Decryption"<<endl;
		cout<<"3.Exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice){
			case 1 : cout<<"Enter the string to be encrypted\n";
					getline(cin,str);
					getline(cin,str);
					str = encrypt(str,key);
					cout<<"The encrypted string is : "<<str<<endl; 
				break;
			case 2 : cout<<"Enter the string to be decrypted\n";
					getline(cin,str);
					getline(cin,str);
					str = decrypt(str,key);
					cout<<"The decrypted string is : "<<str<<endl;
				break;
			case 3 : return 0;
			default : cout<<"Invalid choice.\nTry again\n";
		}
	}
	return 0;
}
