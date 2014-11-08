#include <iostream>

#include <boost/shared_ptr.hpp>

#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>

#include "Calculator.h"

using namespace std;

using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;

using namespace foo::bar::baz;

using boost::shared_ptr;

int main(int argc, char** argv)
{
    shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    socket->open();
    shared_ptr<TBinaryProtocol> protocol(new TBinaryProtocol(socket));
    CalculatorClient client(protocol);

    cout << client.add(1, 1) << endl;
    cout << client.sub(2, 3) << endl ;
    cout << client.mul(5, 8) << endl;
    try {
        cout << client.div(13, 21) << endl;
        cout << client.div(34, 0) << endl;
    } catch (ArithmeticException& e) {
        cerr << e.message << endl;
    } catch (...) {
        cerr << "Unknown exception!" << endl;
    }

    return 0;
}
