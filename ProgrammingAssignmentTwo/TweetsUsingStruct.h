#pragma once
const string KFileTypeTXT = ".txt";

struct words
{
    string word;
    int timesAppeared = 0;
};

void ReadEachTweetToStruct(string fileName, vector<words> &structWords)
{
    ifstream file;
    string wordFromTweet;
    file.open(fileName + KFileTypeTXT);

    while (file.is_open())
    {
        bool wordAlreadyInStruct = false;

        file >> wordFromTweet;
        for (int tweetWord = 0; tweetWord < structWords.size(); tweetWord++)
        {
            if (structWords[tweetWord].word == wordFromTweet)
            {
                wordAlreadyInStruct = true;
                structWords[tweetWord].timesAppeared++;
            }
        }

        if (!wordAlreadyInStruct)
        {
            words temp = { wordFromTweet, 1 };
            structWords.push_back(temp);
        }

        if (file.eof())
        {
            file.close();
        }

    }
}

void DisplayAllWords(vector<words> structWords)
{
	for(int index = 0; index < structWords.size(); index++)
	{
        cout << structWords[index].word << "  " << structWords[index].timesAppeared << endl;
        if(index % 5 == 0)
        {
            system("pause");
        }
	}
}

bool CheckIfInVector(vector<words> structWords, string word)
{
    bool inStruct = false;
	for(int index = 0; index < structWords.size(); index++)
	{
		if(structWords[index].word == word)
		{
            inStruct = true;
		}
	}
    return inStruct;
}






//
//void DisplayTopTenWords()
//{
//
//
//
//}

