#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Feedback
{
private:
    string feedback;
    int rating;

public:
    string getFeed()
    {
        return feedback;
    }
    int getRating()
    {
        return rating;
    }

    void setRating(int r)
    {
        rating = r;
    }
    void setFeed(string fb)
    {
        feedback = fb;
    }
    void writeFeedback(string did, string pid)
    {
        ofstream feedbackFile;
        feedbackFile.open("feedbacks.txt", ios::app);
        feedbackFile << did << " " << pid << " " << feedback << " " << rating << endl;
        feedbackFile.close();
    }
};
#endif