#include "plot.h"

Plot::Plot()
{

}

Plot::Plot(int ID, double Size, double CostPerNight) : ID(ID),
    Size(Size),
    CostPerNight(CostPerNight)
{}

bool Plot::bookingposssible(int from, int to, int visitors,const vector<features>&wishes)
{
    if(Size<4*visitors)
    {
        return false;
    }
    for(const auto&b1:bookings)
    {

        if(b1.getFrom()<from&&b1.getTo()>to)
        {
            return false;
        }
        if(b1.getFrom()>from&&b1.getFrom()<to)
        {
            return false;
        }
        if(b1.getTo()>from&&b1.getTo()<to)
        {
            return false;
        }
        if(b1.getFrom()>from&&b1.getTo()<to)
        {
            return false;
        }


    }

   int  count=0;
    for(const auto &f1:getFeature())
    {
        for(const auto &f2:wishes)
        {
            if(f1==f2)
            {
                count++;
            }
        }
    }

    if(count!=wishes.size())
    {
        return false;
    }
    return true;
}



bool Plot::bookingposssible(int from, int to, int visitors)
{
    if(Size<4*visitors)
    {
        return false;
    }
    for(const auto&b1:bookings)
    {

        if(b1.getFrom()<from&&b1.getTo()>to)
        {
            return false;
        }
        if(b1.getFrom()>from&&b1.getFrom()<to)
        {
            return false;
        }
        if(b1.getTo()>from&&b1.getTo()<to)
        {
            return false;
        }
        if(b1.getFrom()>from&&b1.getTo()<to)
        {
            return false;
        }


    }

    return true;
}
void Plot::book(const Booking &b)
{
    if(bookingposssible(b.getFrom(),b.getTo(),(b.getName().size())))
    {
        bookings.push_back(b);
    }
}

int Plot::getID() const
{
    return ID;
}

double Plot::getSize() const
{
    return Size;
}

double Plot::getCostPerNight() const
{
    return CostPerNight;
}

vector<Booking> Plot::getBookings() const
{
    return bookings;
}

vector<features> Plot::getFeature() const
{

    return feature;
}

Plot::Plot(int ID, double Size, double CostPerNights, const vector<features> &feature) :
    ID(ID),
    Size(Size),
    CostPerNight(CostPerNights),
    feature(feature)
{}
