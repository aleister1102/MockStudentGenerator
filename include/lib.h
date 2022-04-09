#pragma once
// Common
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
// Unicode
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
// Regex/String
#include <string>
#include <sstream>
#include <regex>

using namespace std;

// Files path
#define STUDENTS "data/students.csv"
#define STUDENTS2 "data/students.txt"
#define FIRSTNAMES "data/firstNames.csv"
#define MIDDLENAMES "data/middleNames.txt"
#define LASTNAMES "data/lastNames.txt"
#define DOMAINS "data/domains.txt"
#define OPERATOR "data/operators.txt"
#define WARDS "data/wards.txt"
#define STREETS "data/streets.txt"

// Regex pattern
#define WORDS "(?! )[A-z ]+"
#define NUMBERS "[0-9]+"
#define ID "[0-9]{1,8}"
#define NAME " [A-z ]+"
#define GPA "[0-9]+\\.*[0-9]{0,2}(?=,)"
#define TEL "[0-9]{4}-[0-9]{3}-[0-9]{3}"
#define EMAIL "[a-z]+@[a-z]+\\.com"
#define DATE "[0-9]{2}/[0-9]{2}/[0-9]{4}"
#define HOUSE_NUMBER_STREET "(?:[0-9]+/*)+ [A-z ]+"
#define HOUSE_NUMBER "([0-9]+/*)+"
#define WARD "([A-z]+ *)+(?=Ward)"
#define DISTRICT "([A-z]+ *)+(?=District)"
#define CITY "([A-z]+ *)+(?=city)"