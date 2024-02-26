#include "booking.h"

Booking::Booking()
{

}

Booking::Booking(int from, int to, const std::vector<std::string> &name, double CostPerNight) : from(from),
    to(to),
    name(name),
    cost((to-from)*CostPerNight),
    payeed(false)
{}

int Booking::getFrom() const
{
    return from;
}

int Booking::getTo() const
{
    return to;
}

std::vector<std::string> Booking::getName() const
{
    return name;
}

void Booking::setPayeed()
{
    payeed = true;
}

bool Booking::getPayeed() const
{
    return payeed;
}

double Booking::getCost() const
{
    return cost;
}

