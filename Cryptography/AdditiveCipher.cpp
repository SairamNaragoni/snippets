#include<bits/stdc++.h>
using namespace std;

string encrypt(string str,int key){
    for(int i=0;i<str.length();i++){
    	if(isalpha(str[i])){
    		str[i] = 'a'+(str[i]-'a'+key)%26;
		}
    }
    return str;
}
string decrypt(string str,int key){
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i])){
    		str[i] = 'a'+(str[i]-'a'-key+26)%26;
		}	
    }
    return str;
}
struct comp
{
    bool operator()(pair<int,char> &a, pair<int,char> &b) const {
	if(a.first == b.first){
    	return a.second<b.second;
	}
	else{
	return a.first > b.first; 
	}
	}
};

int main(){
    string text;
    int key;
    cout<<"Enter cipher key (int) : ";
    cin>>key;
    while(1){
        cout<<"...................Menu..................\n";
        cout<<"1.Encrypt the plain Text\n";
        cout<<"2.Decrypt the encrypted Text\n";
        cout<<"3.Exit\n";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter the plain text\n";
					getline(cin,text);
					getline(cin,text);
                    transform(text.begin(), text.end(), text.begin(), ::tolower); 
                    cout<<"Encrypted text is : \n"<<encrypt(text,key)<<endl;
                    break;
            case 2: cout<<"Enter the encrypted text\n";
                    getline(cin,text);
					getline(cin,text);
                    transform(text.begin(), text.end(), text.begin(), ::tolower);
                    cout<<"plain text is : \n"<<decrypt(text,key)<<endl;
                    break;
            case 3: return 0;
                    break;
            default: cout<<"invalid input\n";return 0;
                    break;      
        }
    }
    return 0;
}
