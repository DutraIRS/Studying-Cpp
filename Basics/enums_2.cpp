#include <iostream>

using std::cout;
using std::endl;

int main()
{
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, HBO, Netflix};

    Streaming streamingSubscription = DisneyPlus;

    switch(streamingSubscription)
    {
        case AppleTV:
            cout << "It's all so strange... {" << streamingSubscription << "}" << endl;
            break;

        case DisneyPlus:
            cout << "It's all so bad... {" << streamingSubscription << "}" << endl;
            break;

        default:
            cout << "I'd rather read a book... {" << streamingSubscription << "}" << endl;
    }

    enum Months {Jan = 1, Feb, Mar, Apr, May};
    Months monthOne = May;
    cout << monthOne << endl;

    enum Weekdays {Mon = 10, Tue, Wed = 3, Thu = -3, Fri};
    Weekdays dayOne = Fri;
    cout << dayOne << endl;

    return 0;
}