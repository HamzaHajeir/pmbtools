/*
 MIT License

Copyright (c) 2019 Phil Bowles <H48266@gmail.com>
   github     https://github.com/philbowles/H4
   blog       https://8266iot.blogspot.com
   groups     https://www.facebook.com/groups/esp8266questions/
              https://www.facebook.com/H4-Esp8266-Firmware-Support-2338535503093896/


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include"pmb_config.h"

#include<Arduino.h>

#include<string>
#include<vector>
#include<map>

using namespace std;

void            _HAL_feedWatchdog();
uint32_t        _HAL_freeHeap();
uint32_t        _HAL_maxHeapBlock();
size_t          _HAL_maxPayloadSize();
#ifdef ARDUINO_ARCH_ESP32
string          _HAL_uniqueName(const string& prefix="ESP32");
#else
string          _HAL_uniqueName(const string& prefix="ESP8266");
#endif

#if PMB_DEBUG
void            dumpvs(const vector<string>& vs);
void            dumpnvp(const std::map<string,string>& ms);
#endif

void            dumphex(const uint8_t* mem, size_t len);
string          encodeUTF8(const string &);
string          flattenMap(const std::map<string,string>& m,const string& fs,const string& rs,function<string(const string&)> f=[](const string& s){ return s; });
uint32_t        hex2uint(const uint8_t* str);
string 		    join(const vector<string>& vs,const char* delim="\n");
std::map<string,string> json2nvp(const string& s);
string          lowercase(string);
string          ltrim(const string& s, const char d=' ');
string          nvp2json(const std::map<string,string>& nvp);
string          replaceAll(const string& s,const string& f,const string& r);
string          rtrim(const string& s, const char d=' ');
vector<string>  split(const string& s, const char* delimiter="\n");
string		    stringFromInt(int i,const char* fmt="%d");
bool		    stringIsAlpha(const string& s);
bool		    stringIsNumeric(const string& s);
string          trim(const string& s, const char d=' ');
string          uppercase(string);
string          urlencode(const string &s);