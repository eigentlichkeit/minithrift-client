# calculator.thrift

namespace cpp foo.bar.baz

enum OperationType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
}

struct Operation {
    1:OperationType type,
    2:double op1,
    3:double op2
}

exception ArithmeticException {
    1:string message
}

exception IllegalArgumentException {
    1:string message
}

service Calculator {
    double perform(1:Operation o) throws (1:ArithmeticException ae,
                                          2:IllegalArgumentException iae)
}

