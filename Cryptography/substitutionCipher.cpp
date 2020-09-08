#include<bits/stdc++.h>
#include<locale>
using namespace std;

int key[26];
int dekey[26];
char maxi[26]={'z','x','q','j','k','v','b','p','y','g','f','w','m','u','c','l','d','r','h','s','n','i','o','a','t','e'};

char getValue(char c,vector< pair< char,char > > v)
{
	for(int i=0;i<26;i++)
	{
		char t = v[i].second;
		char ans = v[i].first;
		if(t == c)
		{
			return ans;
		}
	}
}
string cryptanalysis(string s)
{
	int freq[26];
	vector< pair< int,char > > v;
	vector< pair< char,char > > v1;
	memset(freq,0,sizeof(freq));
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		{
			freq[s[i]-'a']++;	
		}	
	}
	for(int i=0;i<26;i++)
	{
		char c = i+'a';
		v.push_back(make_pair(freq[i],c));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<26;i++)
	{
		char t = v[i].second;
		v1.push_back(make_pair(maxi[i],t));	
	}
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
			s[i] = getValue(s[i],v1);
	}
	return s;
}
void generateKey(){
	char vis[26];
	memset(vis,0,sizeof(vis));
	int i = 0;
	srand (time(NULL));
	while(i<26)
	{
		int r = rand()%26;
		if(vis[r]==0)
		{
			vis[r]=1;
			key[i] = r;
			dekey[r]=i;
			i++;
		}
	}
	return;
}
string encrypt(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		{
			s[i] =  key[s[i]-'a'] + 'a';
		}	
	}
	return s;
}

string decrypt(string s)
{
	for(int i=0;i<s.size();i++)
	{
		if(isalpha(s[i]))
		{
			s[i] = dekey[s[i]-'a']+'a';
		}
		
	}
	return s;
}
string lower(string s)
{
	locale loc;
	for(int i=0;i<s.size();i++)
	{
		s[i] = tolower(s[i],loc);
	}
	return s;
}
int main()
{
	int choice;
	string s;
	while(1)
	{
		cout<<"..........MENU........."<<endl;
		cout<<"1.Generate Key"<<endl;
		cout<<"2.Encrypt Message"<<endl;
		cout<<"3.Decrypt Message"<<endl;
		cout<<"4.CryptAnalysis"<<endl;
		cout<<"5.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: generateKey();
					cout<<"The Key Generated is : "<<endl;
					for(int i =0;i<26;i++)
					{
						char c = 'a'+i;
						cout<<c<<" ";
					}
					cout<<endl;
					for(int i =0;i<26;i++)
					{
						char c = 'a'+key[i];
						cout<<c<<" ";
					}
					cout<<endl;
				break;
			case 2: cout<<"Enter Your Message to be Encrypted :"<<endl;
					getline(cin,s);
					getline(cin,s);
					s = lower(s);
					s = encrypt(s);
					cout<<s<<endl;
				break;
			case 3:	cout<<"Enter Your Message to be Decrypted :"<<endl;
					getline(cin,s);
					getline(cin,s);
					s = lower(s);
					s = decrypt(s);
					cout<<s<<endl;
				break;
			case 4: s = cryptanalysis(s);
					cout<<s<<endl;
				break;
			case 5: return 0;
					
			default : cout<<"Invalid Input.Please try Again"<<endl;
				return 0;
		}
	}
	return 0;
}
