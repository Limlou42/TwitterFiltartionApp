#pragma once

//turns each file containing check words into a vector to be used anywhere in program//
void FileToVectorConversion(vector <string>& vectorToFill, string fileName)
{
    ifstream file;
    string word = "";
    //open the file contaning the words using passed in variables//
    file.open(fileName + KFileTypeTXT);

    if (file.is_open())
    {
        //gets eachg line of file and adds it to the vector passed in//
        while (getline(file, word))
        {
            vectorToFill.push_back(word);
        }
    }
    file.close();
}

//function to get the tweets from the file and put them into a class//
void GetTweetsFromFile(vector <TweetsClass>& fileTweets, string filename)
{
    //variables for the file and string for each line//
    string tweet;
    ifstream file;
    //open file and make file name using variables//
    file.open(filename + KFileTypeTXT);

    //check if file is open//
    if (file.is_open())
    {
        //get each line from file and turn into a string//
        while (getline(file, tweet))
        {
            //make a class for each line and add to original class//
            TweetsClass temp;
            temp.MTweet = tweet;
            fileTweets.push_back(temp);
        }
    }
    //if file fails to open or isn't found give an error//
    else
    {
        cout << "ERROR OPENING FILE" << endl;
    }
    file.close();
}