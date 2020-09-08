#include<bits/stdc++.h>
using namespace std;

string freq;

void init(){
    freq = "eariotnslcudpmhgbfywkvxzjq";
}
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
void bruteForceAttack(string str){
	cout<<"..........Brute Force Decryption Attack Begin...........\n";
	cout<<"..........Checking for each possible keys..........\n";
	cout<<"Key   |    possible plain text\n";
	for(int i=0;i<26;i++){
		cout<<i<<"  ";
		string text = decrypt(str,i);
		cout<<text<<endl;
	}
	cout<<endl<<endl;
}
string freqencyAttack(string str){
	cout<<"..........Frequency Analysis Attack Begin...........\n";
	cout<<"..........Checking for possible keys..........\n";
 	int freqC[26];
	vector< pair< int,char > > v;
	memset(freqC,0,sizeof(freqC));
	for(int i=0;i<str.size();i++){
		if(isalpha(str[i]))
		{
			freqC[str[i]-'a']++;	
		}	
	}
	for(int i=0;i<26;i++){
		char c = i+'a';
		v.push_back(make_pair(freqC[i],c));
	}
	sort(v.begin(),v.end(),comp());
//	for(int i=0;i<26;i++){
//		cout<<"char - "<<v[i].second<<" freq - "<<v[i].first<<endl;
//	}
	cout<<"Generating possible plain text : \n\n";
	for(int i=0;i<4;i++){
	//	cout<<"freq - "<<freq[i]<<endl;
	//	cout<<"vec - "<<v[0].second<<endl;
		int key = freq[i]-v[0].second;
		key = abs(key);
		string text = decrypt(str,key);
		cout<<"Key - "<<key<<" , "<<text<<endl<<endl;
	}
    return str;
}
int main(){
    string text;
    int key;
    init();
    cout<<"Enter cipher key (int) :";
    cin>>key;
    while(1){
        cout<<"...................Menu..................\n";
        cout<<"1.Encrypt the plain Text\n";
        cout<<"2.Decrypt the encrypted Text\n";
        cout<<"3.Brute force attack\n";
        cout<<"4.Frequency analysis attack\n";
        cout<<"5.Exit\n";
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
            case 3: cout<<"Enter the encrypted text\n";
                    getline(cin,text);
					getline(cin,text);
                    transform(text.begin(), text.end(), text.begin(), ::tolower);
                    bruteForceAttack(text);
                    break;
            case 4: cout<<"Enter the encrypted text\n";
                    getline(cin,text);
					getline(cin,text);
                    transform(text.begin(), text.end(), text.begin(), ::tolower);
                    freqencyAttack(text);
                    break;
            case 5: return 0;
                    break;
            default: cout<<"invalid input\n";return 0;
                    break;      
        }
    }
    return 0;
}
