#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int>::iterator it;
void initialise(string key){
	for(int i=0;i<key.size();i++){
		mp[key[i]] = i;
	}
}
string encrypt(string str,string key){
	int row,col;
	col = key.size();
	row = str.size()/col;
	if(str.size()%col){
		row++;
	}
	char arr[row][col];
	for(int i=0,k=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(str[k]=='\0'){
				arr[i][j] = '_' ;
			}
			else{
				arr[i][j]=str[k];
				k++;
			}
		}
	}
	for(int i=0;i<key.size();i++){
		cout<<key[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int j;
	string cipher="";
	for(it=mp.begin();it!=mp.end();it++){
		j=it->second;
		for (int i=0; i<row; i++) 
		{ 
				cipher += arr[i][j]; 
		} 
	}	
	return cipher;
}

string decrypt(string str,string key){
	int row,col;
	col = key.size();
	row = str.size()/col;
	char arr[row][col],deCipher[row][col];
	int k=0;
	for(int j=0;j<col;j++){
		for(int i=0;i<row;i++){
			arr[i][j] = str[k++];
		}
	}
	int index=0;
	for(it=mp.begin();it!=mp.end();it++){
		it->second = index++;
	}
	k = 0; 
    for (int l=0,j; key[l]!='\0'; k++) 
    { 
        j = mp[key[l++]]; 
        for (int i=0; i<row; i++) 
        { 
            deCipher[i][k]=arr[i][j]; 
        } 
    } 
   for(int i=0;i<key.size();i++){
		cout<<key[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cout<<deCipher[i][j]<<" ";
		}
		cout<<endl;
	}
    string msg = ""; 
    for (int i=0; i<row; i++) 
    { 
        for(int j=0; j<col; j++) 
        { 
            if(deCipher[i][j] != '_') 
                msg += deCipher[i][j]; 
        } 
    } 
    return msg; 
}

int main(){
	string str,key;
	cout<<"Enter key"<<endl;
	cin>>key;	
	initialise(key);
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
