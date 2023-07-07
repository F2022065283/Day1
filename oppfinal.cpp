#include <iostream>
#include <string>
using namespace std;
class TravelPackage
{
public:
    virtual ~TravelPackage() {}
    virtual string getDetails() const = 0;
    virtual double calculateTotalCost() const = 0;
};
class Package : public TravelPackage
{
private:
    string id;
    string name;
    string tripType;
    string destination;
    int duration;
    double price;
    string description;

public:
    Package(const string &id, const string &name, const string &tripType,
            const string &destination, int duration, double price, const string &description)
        : id(id), name(name), tripType(tripType), destination(destination),
          duration(duration), price(price), description(description) {}

    // Getter and setter methods
    string getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    string getTripType() const
    {
        return tripType;
    }
    string getDestination() const
    {
        return destination;
    }
    int getDuration() const
    {
        return duration;
    }
    double getPrice() const
    {
        return price;
    }
    string getDescription() const
    {
        return description;
    }

    string getDetails() const
    {
        return "ID: " + id + "\nName: " + name + "\nType: " + tripType + "\nDestination: " + destination + "\nDuration: " + to_string(duration) + " days\nPrice: $" + to_string(price) + "\nDescription: " + description;
    }

    double calculateTotalCost() const
    {
        return price;
    }

    // Operator overloading
    friend istream &operator>>(istream &is, Package &package)
    {
        cout << "Enter package ID: ";
        is >> package.id;
        cout << "Enter package name: ";
        is >> package.name;
        cout << "Enter trip type: ";
        is >> package.tripType;
        cout << "Enter destination: ";
        is >> package.destination;
        cout << "Enter duration (in days): ";
        is >> package.duration;
        cout << "Enter price: ";
        is >> package.price;
        cout << "Enter description: ";
        is >> package.description;

        return is;
    }

    friend ostream &operator<<(ostream &os, const Package &package)
    {
        os << "ID: " << package.id << "\nName: " << package.name << "\nType: " << package.tripType
           << "\nDestination: " << package.destination << "\nDuration: " << package.duration
           << " days\nPrice: $" << package.price << "\nDescription: " << package.description;

        return os;
    }

    bool operator==(const Package &other) const
    {
        return price == other.price;
    }

    bool operator>=(const Package &other) const
    {
        return price >= other.price;
    }
};

class Booking
{
private:
    string customerName;
    string contactInfo;
    string bookingDate;
    bool paymentStatus;
    const TravelPackage *package;

public:
    Booking(const string &customerName, const string &contactInfo,
            const string &bookingDate, bool paymentStatus, const TravelPackage *package)
        : customerName(customerName), contactInfo(contactInfo), bookingDate(bookingDate),
          paymentStatus(paymentStatus), package(package) {}

    // Getter and setter methods
    string getCustomerName() const { return customerName; }
    string getContactInfo() const { return contactInfo; }
    string getBookingDate() const { return bookingDate; }
    bool getPaymentStatus() const { return paymentStatus; }
    const TravelPackage *getPackage() const { return package; }

    void setPaymentStatus(bool status) { paymentStatus = status; }
};

class Customer
{
private:
    string id;
    string name;
    string contactInfo;
    Booking *bookings[100];
    int numBookings;

public:
    Customer(const string &id, const string &name, const string &contactInfo)
        : id(id), name(name), contactInfo(contactInfo), numBookings(0) {}

    // Getter and setter methods
    string getId() const { return id; }
    string getName() const { return name; }
    string getContactInfo() const { return contactInfo; }

    void addBooking(Booking *booking)
    {
        bookings[numBookings++] = booking;
    }

    void displayBookings() const
    {
        cout << "Booking history for customer " << name << ":\n";
        for (int i = 0; i < numBookings; i++)
        {
            cout << "Booking " << i + 1 << ":\n";
            cout << "Package details:\n"
                 << bookings[i]->getPackage()->getDetails() << "\n";
            cout << "Customer name: " << bookings[i]->getCustomerName() << "\n";
            cout << "Contact info: " << bookings[i]->getContactInfo() << "\n";
            cout << "Booking date: " << bookings[i]->getBookingDate() << "\n";
            cout << "Payment status: " << (bookings[i]->getPaymentStatus() ? "Paid" : "Not Paid") << "\n";
            cout << "==============================\n";
        }
    }
};

int main()
{
    // Package(const string &id, const string &name, const string &tripType,
    // const string &destination, int duration, double price, const string &description)


    string id="P123",name,triptype,desc="Enjoy a week in the City of Love.",dest;
    int duration=4;
    double price;

    bool jack =false;
    cout<<"---------Main menu ----------\n";
    cout<<"Enter Pakage Name\n";
    fflush(stdin);
    getline(cin,name);
    do
    {
            cout<<"Enter Trip Type (holiday packages / business trips / adventure trips)\n";
    fflush(stdin);
    getline(cin,triptype);
    if(triptype != "holiday packages" && triptype != "business trips " && triptype != "adventure trips")
    {
        cout<<"Invalid chooise\n";
        jack=true;
    }
    }
    while(jack!=true);
    if(triptype=="holiday packages")
    {
        price=20000;
    }
    else if(triptype=="business trips")
    {
        price=50000;
    }
    else
        price=60000;
    cout<<"Enter Destination\n";
    fflush(stdin);
    getline(cin,dest);


    Package package1(id, name, triptype, dest, duration, price, desc);


    Booking booking1("Ali Hamza", "Alihamza@gmail.com", "2023-07-01", false, &package1);
    
    Customer customer("C001", "Ali Adnan", "Aliadnan@gmail.com");
    customer.addBooking(&booking1);

    customer.displayBookings();

    return 0;
}
