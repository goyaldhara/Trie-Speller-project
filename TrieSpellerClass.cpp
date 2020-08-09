// TrieSpellerClass
# include <bits/stdc++.h>
using namespace std;
# define ll long long

class TrieSpellerClass
{
	private :
		
		map <string,ll> map1;
		set <string> v;
		vector <string> words_suggested_for_given_word;
	
	struct trie
	{
		string  word_ending_here;
		struct trie * Next[26];
		trie()
		{
			word_ending_here="";
			ll k;
			for(k=0;k<26;k++)//edges in the trie
				Next[k]=NULL;
		}
	};
	void add(struct trie * node,string word,ll pos)	// 1--> current node , 2--> word currently in use, 3--> index in this word (0) // nabh
	{
		if(pos==word.size()) // end of word
			node->word_ending_here=word; // if the word is ending here, store it in the current node
		else
		{
			ll K=word[pos]-'a'; //a--0 , b--1,c--2 
			if(node->Next[K]==NULL) // n--a --> we will create a node for a 
				node->Next[K]=new trie(); // difference between new & malloc & calloc
			add(node->Next[K],word,pos+1); // recursively go into this node , pos+1
		}
	}// we represent the character by edge and the node by the word_ending_here
	
	bool find(struct trie * node,string word,ll pos)//sma
	{
		if(pos==word.size())//small,s
		{
			if(node->word_ending_here=="")//if some word is ending here, and it is not an empty string, just return 1, else returnn 0
				return 0;
			else
				return 1;
		}
		else
		{
			ll K=word[pos]-'a';//seprate the letter, if edge is not present return 0, if edge is present recursively dive deep
			if(node->Next[K]==NULL)
				return 0;
			return find(node->Next[K],word,pos+1);
		}
	}
	
	
	void suggesting_words(struct trie * node)//we are just traversing the subtree of the TRIE, for a given node
	{
		ll i,j;
		for(i=0;i<26;i++)
		{
			if(node->Next[i]!=NULL)
				suggesting_words(node->Next[i]);
		}
		if(node->word_ending_here!="")
			words_suggested_for_given_word.push_back(node->word_ending_here);
	}
	
	
	void suggestion(struct trie * node,string word,ll pos) //1. find words of greater length, 2. find words of lesser length, 3. mismatch words, 4. dive deep into recursion
	{
		if(pos==word.size())//words of greater length
			return suggesting_words(node);	
		ll K=word[pos]-'a';
		if(node->word_ending_here!="")//take all the words in way, words of lesser length, all the words in way
			words_suggested_for_given_word.push_back(node->word_ending_here);
		if(node->Next[K]==NULL)	//word mismatch ,smb
			return suggesting_words(node);//s, sm, small, small1	
		else if(node->Next[K]!=NULL)//move to next
			return suggestion(node->Next[K],word,pos+1);
	}
	
	public :
		
		TrieSpellerClass()
		{
			ll i,j;
			struct trie * root =new trie;
			ifstream in("CompleteWordlist.txt"); //entire wordlist is stored in the 'in' stream
				string word;
				while(in)
				{
			        in>>word;	//	cin>>word;
			        map1[word]++;	// word --> frequency match 
			        v.insert(word); // insert the word in the set v
			    }
			    in.close();
			
			for(set <string> ::iterator it=v.begin();it!=v.end();it++)	// using iterator we will access each of the word and add it in the trie
				add(root,*it,0LL);
			in.close(); // always close the stream
			
			cout<<"SYSTEM READY FOR SPELL CHECK:";
			cout<<endl<<endl;
			while(1)
			{
				cout<<"ENTER THE WORD:";
			
				string temp;
				cin>>temp;
				if(find(root,temp,0LL))// tries to find the word in TRIE, if it is present return 1, else return 0.
					cout<<"ENTERED WORD IS CORRECT:"<<temp<<endl;
				else
				{
					words_suggested_for_given_word.clear();
					suggestion(root,temp,0LL);
					string most_favourable_word="";
					ll freq=0;//will help us to find the word with max frequency
					for(i=0;i<words_suggested_for_given_word.size();i++)
					{
						cout<<words_suggested_for_given_word[i]<<",";
						if(freq<map1[words_suggested_for_given_word[i]])
						{
							freq=map1[words_suggested_for_given_word[i]];
							most_favourable_word=words_suggested_for_given_word[i];
						}
					}
					cout<<endl<<"SUGGESTION::"<<most_favourable_word<<endl;
				}
				cout<<"Enter EXIT to exit or anything else to continue:";
				string ch;
				cin>>ch;
				if(ch=="EXIT" or ch=="exit")
					break;
			}
		}
};
/*
nabh - 2
nab	- 1
na - 1
n-1
nb - 1

n--> n
nb --> n, na, nab, naq,	nabh
naq --> n,na,nab,nabh
*/
