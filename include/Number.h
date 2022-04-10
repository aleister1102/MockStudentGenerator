#pragma once
#include "lib.h"

class ReturnFlags
{
private:
	bool _successful = true;
	int _errorCode = 0;
	string _message = "";

public:
	bool Successful(){return _successful;}
	int ErrorCode(){return _errorCode;}
	string Message(){return _message;}
	void setSuccessful(bool value){_successful=value;}
	void setErrorCode(int value){_errorCode=value;}
	void setMessage(string message){_message=message;}
};

class Number
{
public:
	static tuple<ReturnFlags, int> parseInt(string);
	static tuple<ReturnFlags, float> parseFloat(string);
	static int tryParseInt(string);
	static float tryParseFloat(string);
};
