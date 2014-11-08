# calculator.thrift

namespace cpp foo.bar.baz

exception ArithmeticException {
	1:string message
}

service Calculator {
	double add(1:double a, 2:double b)
	double sub(1:double a, 2:double b)
	double mul(1:double a, 2:double b)
	double div(1:double a, 2:double b) throws (1:ArithmeticException e)
}

