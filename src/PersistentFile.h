/*
	PersistentFile.h

	By Jim Davies
	Jacobus Systems, Brighton & Hove, UK
	http://www.jacobus.co.uk

	Provided under the MIT license: https://github.com/jacobussystems/ArdJack/blob/master/LICENSE
	Copyright (c) 2019 James Davies, Jacobus Systems, Brighton & Hove, UK

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
	documentation files (the "Software"), to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions
	of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
	THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

#pragma once

#include "Globals.h"

#ifdef ARDUINO
	#include <arduino.h>
	#include "DetectBoard.h"

	#ifdef ARDJACK_FLASH_AVAILABLE
		#include <FlashStorage.h>
	#endif
#else
	//#include "WProgram.h"
#endif


#ifdef ARDJACK_INCLUDE_PERSISTENCE

class PersistentFileManager;

// The struct that is persisted (multiple times) by the 'PersistentFile' class.
typedef struct
{
	char Line[ARDJACK_PERSISTED_LINE_LENGTH];
} PersistentFileLine;



class PersistentFile
{
protected:
	int _LineIndex;																// read line index (0-based)
	bool _WriteMode;

#ifdef ARDUINO
#else
	FILE* _File;
#endif

public:
	int LineCount;																// no.of lines read, or written so far
	PersistentFileManager* Manager;
	char Name[ARDJACK_MAX_NAME_LENGTH];

#ifdef ARDUINO
	int StartLineInFlash;
#else
	char Filename[MAX_PATH];
#endif

	PersistentFile();

	virtual bool Close();
	virtual bool Eof();
	virtual bool Gets(char* line, int size);
	virtual bool IsOpen();
	virtual bool Open(const char* mode);
	virtual bool PutNameValuePair(const char* name, const char* value);
	virtual bool Puts(const char* line);
};

#endif
