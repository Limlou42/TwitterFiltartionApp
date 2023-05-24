#include "TweetsClass.h"

void TweetsClass::FilterAndDisplayTweet(vector <string> bannedWords, vector <string> positiveWords, vector<string> negativeWords)
{
	CheckForBannedWords(bannedWords);
	CheckToneOfTweet(positiveWords, negativeWords);

	cout << MTweet << endl;
	cout << MFilteredTweet << endl;
	cout << endl;

	int bannedWordsAmount = MBannedWordInTweet.size();
	for (int word = 0; bannedWordsAmount > word; word++)
	{
		cout << "The Word " << MBannedWordInTweet[word] << " Appears: " << MBannedWordsAmountShown[word] << " Times" << endl;
	}

	cout << endl;
	cout << "the tone of the tweet was: " << MToneOfTweet << endl;
	cout << "*****************************************************************" << endl;
}

//function to check for banned words and filter them and also save how many times they appear//
void TweetsClass::CheckForBannedWords(vector <string> bannedWords)
{
	//first sets the filtered tweet to its original//
	MFilteredTweet = MTweet;
	//main for loop that runs through each banned word//
	for (int Word = 0; bannedWords.size() > Word; Word++)
	{
		//make tweet and banned word lower case so it can be properly checked//
		string LowerCaseTweet = MaKeStringLowerCase(MTweet);
		string bannedWord = MaKeStringLowerCase(bannedWords[Word]);
		//find the word in the string of it is there//
		int bannedWordIndex = LowerCaseTweet.find(bannedWord);
		int lengthOfBannedWord = bannedWord.length();
		//other values that are used later for times word appears//
		bool wordAppears = false;
		int TimesBannedAppers = 0;

		//i used a while loop here so that the if statement check keeps running till the end of the string//
		//meand its more accuater if words appears after the first check//
		while (bannedWordIndex != -1)
		{
			//the minus one is returned if the word cannot be found//
			if (bannedWordIndex != -1)
			{
				//for loop to change the banned word to have * in it. saves the first letter and the final one//
				for (int index = bannedWordIndex + 1; index < (bannedWordIndex + lengthOfBannedWord) - 1; index++)
				{
					MFilteredTweet[index] = '*';
				}
				wordAppears = true;
			}
			//keeps the program running to check for more of the same banned words//
			bannedWordIndex = LowerCaseTweet.find(bannedWord, bannedWordIndex + bannedWord.length());
			TimesBannedAppers++;
		}
		//if the word appears add it to each vector//
		if (wordAppears)
		{
			MBannedWordInTweet.push_back(bannedWord);
			MBannedWordsAmountShown.push_back(TimesBannedAppers);
		}
	}
}

//check each word in tweet against the positive and negative words//
void TweetsClass::CheckToneOfTweet(vector <string> positiveWords, vector <string> negativeWords)
{
	//make string lower for better checks//
	string lowerCaseTweet = MaKeStringLowerCase(MTweet);

	//for loop for positive words//
	for (int word = 0; positiveWords.size() > word; word++)
	{
		//try find the word in the tweet//
		int chosenWordIndex = lowerCaseTweet.find(positiveWords[word]);

		//keeps looking for words until it reaches the end of the string without finding the word//
		while (chosenWordIndex != -1)
		{
			//for each positive word add to the tone//
			MToneLevelOfTweet++;
			//after finding one word keep going from past that word index//
			chosenWordIndex = lowerCaseTweet.find(positiveWords[word], chosenWordIndex + 1);
		}
	}

	//for loop for negative words in the tweet//
	for (int word = 0; negativeWords.size() > word; word++)
	{
		//try find the word in the tweet//
		int chosenWordIndex = lowerCaseTweet.find(negativeWords[word]);

		//keeps looking for words until it reaches the end of the string without finding the word//
		while (chosenWordIndex != -1)
		{
			//for each negative word minus to the tone//
			MToneLevelOfTweet--;
			//after finding one word keep going from past that word index//
			chosenWordIndex = lowerCaseTweet.find(negativeWords[word], chosenWordIndex + 1);
		}
	}

	//if statement to check the tone number and make the string tone the correct value//
	if (MToneLevelOfTweet > 0)
	{
		MToneOfTweet = "Positive";
	}
	else if (MToneLevelOfTweet < 0)
	{
		MToneOfTweet = "Negative";
	}
	else 
	{
		MToneOfTweet = "Neutral";
	}
}

//makes any string passed through lower case//
string TweetsClass::MaKeStringLowerCase(string myString)
{
	//iterate though each character and use cstream to make each case lower//
	for (int character = 0; character < myString.length(); character++)
	{
		myString[character] = tolower(myString[character]);
	}
	//return the string//
	return myString;
}