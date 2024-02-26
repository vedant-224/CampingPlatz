#ifndef BOOKING_H
#define BOOKING_H
#include <vector>


class Booking
{
public:
    Booking();
    Booking(int from, int to, const std::vector<std::string> &name, double CostPerNight);



    int getFrom() const;
    int getTo() const;

    std::vector<std::string> getName() const;

    void setPayeed();

    bool getPayeed() const;

    double getCost() const;

private:
    int from;
    int to;
    std::vector<std::string> name;
    double cost;
    bool payeed;






};

#endif // BOOKING_H
