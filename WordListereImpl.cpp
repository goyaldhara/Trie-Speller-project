// Implementation
# include <bits/stdc++.h>
# include "WordLister.cpp"
# include "TrieSpellerImpl.cpp"
using namespace std;
# define ll long long

//int main()
//{
//	WordLister wl;// wordlister's constructor call
//	return 0;
//}

/*
Implementation - 2 parts 
1. We will be reading the large text and seperating each of the words and mapping each word with its frequency : will be done in WordList.cpp
2. For a given word -  : will be done in TrieSpellerCLass.cpp
	a. apply prefix search on it.
	b. check if the word is right or wrong
	c. if right, just tell its right.
	d. if wrong: find most suitable right word from the recommendation shown by the trie prefix search
	e. most suitable word will be selected on the basis of the frequecy of the word in the "Large Text" read and implemented

anq ;---> ant, and, ans : ans --> most repeated, frequency, proablility: Baye's Algo
1.
	a. we will convert everything to lower case.
	b. seperate out each word
	c. write the words in a file
*/
