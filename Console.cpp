/////////////////////////////////////// Console (class) //////////////////////////////////////
// This class lets you implement your own intepreter. Arguments give with running program   //
// or command gives through std::in are saved in console object. Now, depending on state of //
// the object, you can execute your own code.                                               //
//////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Console
{
public:
	string command_;
	string argv_[10];	// assumption: no more than 10 arguments
	int argc_ = 2;

	void consConvMain(int margc, char* margv[])
	{
		for (int i = 1; i < margc; i++)
		{
			for (int a = 0; margv[i][a] != '\0'; a++)
				command_ += margv[i][a];

			if (i < margc - 1) command_ += ' ';
		}

		consArgcArgv();
	}
	void consArgcArgv()
	{
		consResetArgcArgv();
		argv_[0] = command_;

		for (int i = 0; i < command_.length(); i++)
		{
			if (argc_ == size(argv_)) break;
			if (command_[i] == ' ') argc_++;
			else argv_[argc_ - 1] += command_[i];
		}
	}
	void consResetArgcArgv()
	{
		for (int i = 0; i < size(argv_); i++)
			argv_[i] = "\0";

		argc_ = 2;
	}
	void consArgcArgvTest()
	{
		cout << dec << "argc_ = " << argc_ << "\n";
		for (int i = 0; i < argc_; i++)
			cout << "argv[" << i << "]_ = " << argv_[i] << "\n";
		cout << "\n";
		_getch();
	}
};

int main(int argc, char* argv[])
{
	Console hcons_;

	if (argc > 1) // Execute if program has been launched with any arguments
	{
		hcons_.consConvMain(argc, argv);
		hcons_.consArgcArgvTest(); // See what has been saved in object.

		argc = 0; // From now, always start loop from else.
	}
	else
	{
		while (getline(cin, hcons_.command_))
		{
			hcons_.consArgcArgv();
			hcons_.consArgcArgvTest(); // See what has been saved in object.
		}
	}

	return 0;
}
