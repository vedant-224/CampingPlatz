#include "camping.h"
#include<iostream>
Camping::Camping()
{

}
int Camping::newid=0;
Camping::Camping(const string &name) : name(name)
{}

void Camping::addplot()
{
    int ID;
    double Size;
    double CostPerNight;
    cin>>ID>>Size>>CostPerNight;
    addplot(new Plot{newid++,Size,CostPerNight});
  //  Plot* newplot = new Plot(oldid++, size, costPerNight);
}

void Camping::addplot(Plot *plot)
{
    for(const auto&p1:plots)
    {
        if(plot->getID()==p1->getID())
        {
            cout<<"id already exist";
            return ;
        }


    }
    plots.push_back(plot);

}

Camping::~Camping()
{
    for(auto p:plots)
    {
        delete p;
    }
}

bool Camping::book(int id,const vector<string>& guests, int from, int to,const vector<features>&wishes)
{
    for(const auto &p1:plots)
    {
        if(p1->getID()==id)
        {
            if(p1->bookingposssible(from,to,guests.size(),wishes))
            {
                p1->book({from,to,guests,p1->getCostPerNight()});
                return true;
            }
        }


    }
    return false;
}

void Camping::display() const
{
    for(const auto&p1:plots)

    {

        cout<<p1->getID();
        cout<<p1->getSize();
        cout<<p1->getBookings().size();

}

}

void Camping::display(int from, int to)
{

for(const auto&p1:plots)

{
        if(p1->bookingposssible(from,to,0))
        {
        cout<<p1->getID();
        cout<<p1->getSize();
        cout<<p1->getBookings().size();
        }
}



}

bool Camping::bookplot(const vector<string> &guests, int from, int to,const vector<features>&wishes)
{



for(const auto& p1:plots)
{
        if(p1->bookingposssible(from,to,guests.size(),wishes))
        {
            p1->book({from,to,guests,p1->getCostPerNight()});
            cout<<"buchung erfolgreich";
            cout<<p1->getID();
           return true;

        }
}
return false;
}

void Camping::createReminder(int today)
{

for(const auto&p1:plots)
{
        for(const auto&b1:p1->getBookings())
        {
           if(b1.getPayeed()==false)
           {
                if(b1.getTo()<today)
                {
                    cout<<p1->getID();
                    cout<<b1.getCost();
                    cout<<b1.getName().at(0);

                }

           }

        }

}


}





















