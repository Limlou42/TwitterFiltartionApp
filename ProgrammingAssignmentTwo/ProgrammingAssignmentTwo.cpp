#include "TweetsClass.h"
#include "TweetsUsingStruct.h"
#include "ConversionFunctions.h"
using namespace std;

//file name strings//
const string KPositiveWordsFileName = "positive", KNegativeWordsFileName = "negative";
const string KBannedWordsFileName = "banned";

int main()
{
    //banned, positive and negative words saved to a vector//
    vector <string> bannedWords, positiveWords, negativeWords;
    vector <words> wordsInTweet;
    FileToVectorConversion(bannedWords, KBannedWordsFileName);
    FileToVectorConversion(positiveWords, KPositiveWordsFileName);
    FileToVectorConversion(negativeWords, KNegativeWordsFileName);

    //all file tweets all saved to a vector with type of a class//
    vector <TweetsClass> file1Tweets, file2Tweets, file3Tweets, file4Tweets;
    vector <vector <TweetsClass>> tweetVectors = {file1Tweets, file2Tweets, file3Tweets, file4Tweets};
    vector <string> KTweetsFileNames = { "tweets1" , "Tweets2" , "Tweets3" , "Tweets4" };

    for (int vec = 0; vec < tweetVectors.size(); vec++)
    {
        GetTweetsFromFile(tweetVectors[vec], KTweetsFileNames[vec]);
    }    

    ReadEachTweetToStruct(KTweetsFileNames[0], wordsInTweet);
    ReadEachTweetToStruct(KTweetsFileNames[1], wordsInTweet);
    ReadEachTweetToStruct(KTweetsFileNames[2], wordsInTweet);
    ReadEachTweetToStruct(KTweetsFileNames[3], wordsInTweet);

}