#ifndef PLOT_H
#define PLOT_H
#include"booking.h"
#include<vector>

using namespace std;
enum class features {Power  ,Water,Riverside};
class Plot
{
public:
    Plot();
    Plot(int ID, double Size, double CostPerNight);
    Plot(int ID, double Size, double CostPerNight, const vector<features> &feature);
    bool bookingposssible(int from,int to,int visitors ,const vector<features>&wishes);
    bool bookingposssible(int from, int to, int visitors);
    void book(const Booking &b);
    int getID() const;
    double getSize() const;
    double getCostPerNight() const;
    vector<Booking> getBookings() const;


    vector<features> getFeature() const;

private:
    int ID;
    double Size;
    double CostPerNight;
    vector<Booking>bookings;
    vector<features> feature;

};

#endif // PLOT_H
