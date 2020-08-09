// WordLister
# include <bits/stdc++.h>
using namespace std;
# define ll long long

class WordLister
{
	public :
		WordLister() // constructor needs to be public
		{
			wordlist();
		}
	private :
		ll Count;
		string str;
		void wordlist()
		{
			freopen("LargeText.txt","r",stdin);
			freopen("CompleteWordlist.txt","w",stdout);
			Count=0;
			ll i,j;
			getline(cin,str); // single line input for space seperated string
			string temp="";
			for(i=0;i<str.size();i++)
			{
				if(str[i]>='A' && str[i]<='Z')//conert everything in lower case
					str[i]=str[i]+32;
				if(str[i]<'a'||str[i]>'z') // .,!,@, any other symbol will be replace by a ' '
					str[i]=' ';
			}// we will have large string of  lower case space seperated words.
			for(i=0;i<str.size();i++)
			{
				j=0;
				while(str[i+j]>='a' && str[i+j]<='z')
				{
					temp+=str[i+j];//we are storing the word here.
					j++;
				}
				if(temp!="")
				{
					cout<<temp<<endl; //write the word in the complete word list file
					Count++;
				}
				temp="";
				i+=j;
			}	
		//	cout<<"Total-"<<Count<<endl;
		}	
};

/*
						i,j
	N	A	B	H	_	D	H	A	R	A 	_
*/
