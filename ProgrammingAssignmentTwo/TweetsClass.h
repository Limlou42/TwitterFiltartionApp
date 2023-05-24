#pragma once
#include <string>
#include <vector>
using namespace std;

//my tweets class to save the tweet and any other infrmation i need in one blueprint//
class TweetsClass
{
public:
	string MTweet;                         //entire unchanged string of tweet
	string MFilteredTweet;                 //tweet after changes are made
	vector <string> MBannedWordInTweet;    //string vector showing each banned word shown
	vector <int> MBannedWordsAmountShown;  //links to last vector and shows how many times each banned word was shwon
	int MToneLevelOfTweet = 0;             //int value that determines tone of the tweet
	string MToneOfTweet;                   //string value that shows tone of tweet bades off last value

	//functions to alter original tweet or work out values//
	void FilterAndDisplayTweet(vector <string> bannedWords, vector <string> positiveWords, vector<string> negativeWords);
	void CheckForBannedWords(vector <string> bannedWords);
	void CheckToneOfTweet(vector <string> positiveWords, vector <string> negativeWords);
	string MaKeStringLowerCase(string tweet);

};

