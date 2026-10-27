#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Notification {
protected:
    string recipientName;
public:
    Notification(string name) { recipientName = name; }
    virtual void send() const {
        cout << "Sending generic notification to " << recipientName << endl;
    }
    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
private:
    string emailAddress;
public:
    EmailNotification(string name, string email) : Notification(name) { emailAddress = email; }
    void send() const override {
        cout << "Sending Email to " << recipientName << " at address " << emailAddress << "..." << endl;
    }
};

class SMSNotification : public Notification {
private:
    string phoneNumber;
public:
    SMSNotification(string name, string phone) : Notification(name) { phoneNumber = phone; }
    void send() const override {
        cout << "Sending SMS to " << recipientName << " at number " << phoneNumber << "..." << endl;
    }
};

int main() {
    cout << "--- Polymorphism Demo ---" << endl;
    EmailNotification emailObj("Alice", "alice@example.com");
    SMSNotification smsObj("Bob", "+256-777-123456");

    vector<Notification*> notifications;
    notifications.push_back(&emailObj);
    notifications.push_back(&smsObj);

    for (Notification* notif : notifications) {
        notif->send(); 
    }
    return 0;
}