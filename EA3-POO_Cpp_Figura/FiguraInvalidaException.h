/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#ifndef FIGURAINVALIDAEXCEPTION_H_
#define FIGURAINVALIDAEXCEPTION_H_

#include <string>

using namespace std;

class FiguraInvalidaException
{
	private:
		string mensaje;

	public:
		FiguraInvalidaException(const string& mensaje);
		const string& what() throw();
};





#endif // FIGURAINVALIDAEXCEPTION_H_
