/**//* 39.166.716-RASGIDO,Ivan_Gonzalo-(04-1361) *//**/

#include "Figura.h"

FiguraInvalidaException::FiguraInvalidaException(const string& mensaje)
{
	this->mensaje = mensaje;
}

const string& FiguraInvalidaException::what()  throw()
{
	return mensaje;
}
