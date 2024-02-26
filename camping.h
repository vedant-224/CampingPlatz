#ifndef CAMPING_H
#define CAMPING_H
#include"plot.h"
#include<string>

class Camping
{
public:
    Camping();
    Camping(const string &name);
    void addplot();
    void addplot(Plot *plot);
    ~Camping();

    bool book(int id,const vector<string>&guests,int from,int to,const vector<features>&wishes);
    void display() const;
    void display(int from,int to);
    bool bookplot(const vector<string>&guests,int from,int to,const vector<features>&wishes);
private:
    string name;
    vector<Plot*>plots;
    static int newid;

};

#endif // CAMPING_H
