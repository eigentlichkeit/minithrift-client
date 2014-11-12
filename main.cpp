#include <iostream>

#include <boost/shared_ptr.hpp>

#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/protocol/TJSONProtocol.h>

#include "calculator_types.h"
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
    shared_ptr<TBinaryProtocol> inputProtocol(new TBinaryProtocol(socket));
    shared_ptr<TJSONProtocol> outputProtocol(new TJSONProtocol(socket));
    CalculatorClient client(inputProtocol, outputProtocol);
    Operation o;

    o.type = OperationType::ADD;
    o.op1 = 1;
    o.op2 = 1;
    cout << client.perform(o) << endl;
    o.type = OperationType::SUBTRACT;
    o.op1 = 2;
    o.op2 = 3;
    cout << client.perform(o) << endl;
    o.type = OperationType::MULTIPLY;
    o.op1 = 5;
    o.op2 = 8;
    cout << client.perform(o) << endl;
    try {
        o.type = OperationType::DIVIDE;
        o.op1 = 13;
        o.op2 = 21;
        cout << client.perform(o) << endl;
        o.op1 = 34;
        o.op2 = 0;
        cout << client.perform(o) << endl;
    } catch (ArithmeticException& e) {
        cerr << e.message << endl;
    } catch (...) {
        cerr << "Unknown exception!" << endl;
    }

    return 0;
}
