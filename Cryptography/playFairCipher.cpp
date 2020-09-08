#include<bits/stdc++.h>
using namespace std;

char key[5][5];
string removeDuplicates(string str){
	int hash[25];
	memset(hash, 0, sizeof(hash)); 
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='j')
			str[i]='i';
		hash[str[i]-'a']++;
		if(hash[str[i]-'a']>1){
			str.erase(str.begin()+i);
			i--;
		}
	}
	return str;
}
void keyGen(string str){
	string abc = "abcdefghijklmnopqrstuvwxyz";
	str = str+abc;
	str = removeDuplicates(str);
	int k=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			key[i][j]=str[k];
			k++; 
		}
	}
	return ;
}
int* findIJ(char c){
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++){
			if(key[i][j]==c){
				int* arr = new int[2];
				arr[0]=i;
				arr[1]=j;
				return arr;
			}
		}
	}		
}
string preprocess(string str){
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	for(int i=0;i<str.length();i++){
		if(str[i]=='j')
			str[i]='i';
	}
	if(str.size()%2!=0){
		str = str+'x';
	}
	return str;
}
string encrypt(string str){
	for(int i=0;i<str.size();i+=2){
		char c1 = str[i];
		char c2 = str[i+1];
		int* ij = findIJ(c1);
		int* ijp = findIJ(c2);
		if(ij[0]==ijp[0]){
			str[i]=key[ij[0]][(ij[1]+1)%5];
			str[i+1]=key[ijp[0]][(ijp[1]+1)%5];
		}
		else if(ij[1]==ijp[1]){
			str[i]=key[(ij[0]+1)%5][ij[1]];
			str[i+1]=key[(ijp[0]+1)%5][ijp[1]];
		}
		else{
			str[i] = key[ij[0]][ijp[1]];
			str[i+1] = key[ijp[0]][ij[1]];
		}
	}
	return str;
}
string decrypt(string str){
	for(int i=0;i<str.size();i+=2){
		char c1 = str[i];
		char c2 = str[i+1];
		int* ij = findIJ(c1);
		int* ijp = findIJ(c2);
		if(ij[0]==ijp[0]){
			str[i]=key[ij[0]][(ij[1]-1+5)%5];
			str[i+1]=key[ijp[0]][(ijp[1]-1+5)%5];
		}
		else if(ij[1]==ijp[1]){
			str[i]=key[(ij[0]-1+5)%5][ij[1]];
			str[i+1]=key[(ijp[0]-1+5)%5][ijp[1]];
		}
		else{
			str[i] = key[ij[0]][ijp[1]];
			str[i+1] = key[ijp[0]][ij[1]];
		}
	}
	return str;
}
int main(){	
	string keyStr;
	cout<<"Enter The Key\n";
	cin>>keyStr;
	transform(keyStr.begin(), keyStr.end(), keyStr.begin(), ::tolower);
	keyGen(keyStr);
	cout<<"..........Generated Key.........\n";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++){
			cout<<key[i][j]<<" ";
		}
		cout<<endl;
	}	
	while(1){
		cout<<"........MENU.........."<<endl;
		cout<<"1.Encryption"<<endl;
		cout<<"2.Decryption"<<endl;
		cout<<"3.Exit"<<endl;
		int choice;
		cin>>choice;
		string str;
		switch(choice){
			case 1 : cout<<"Enter the string to be encrypted\n";
					getline(cin,str);
					getline(cin,str);
					str = encrypt(preprocess(str));
					cout<<"The encrypted string is : "<<str<<endl; 
				break;
			case 2 : cout<<"Enter the string to be decrypted\n";
					getline(cin,str);
					getline(cin,str);
					str = decrypt(preprocess(str));
					cout<<"The decrypted string is : "<<str<<endl;
				break;
			case 3 : return 0;
			default : cout<<"Invalid choice.\nTry again\n";
		}
	}
	return 0;
}
