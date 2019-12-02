#include "Songs.h"



// Songs.cpp

#include <iostream>
#include "Songs.h"
#include <cstring>
using namespace std;

// ignore any newlines in input
void IgnoreNewLines()
{
	while (cin.peek() == '\n')
		cin.ignore();
}

// default constructor
Songs::Songs()
{
	strcpy_s(title, "");
	strcpy_s(artist, "");
}

Songs::Songs(const char* t, const char* a)
{
	Set(t, a);
}

void Songs::Set(const char* t, const char* a)
{
	if (strlen(t) < MAX_CHARS)
		strcpy_s(title, t);

	if (strlen(a) < MAX_CHARS)
		strcpy_s(artist, a);
}

// output operator
ostream& operator<<(ostream & os, const Songs & song)
{
	os << song.title << ", " << song.artist;

	return os;
}

// input operator
istream& operator>>(istream & is, Songs& song)
{
	// ignore any newlines
	IgnoreNewLines();

	// read until the comma
	cin.getline(song.title, Songs::MAX_CHARS, ',');

	// ignore the space in between
	if (cin.peek() == ' ')
		cin.ignore();

	// ignore any newlines
	IgnoreNewLines();

	// read until new line
	cin.getline(song.artist, Songs::MAX_CHARS);

	return is;
}

// equality test operator
bool operator==(const Songs & lhs, const Songs & rhs)
{
	if (strcmp(lhs.title, rhs.title))
		return false;

	if (strcmp(lhs.artist, rhs.artist))
		return false;

	return true;
}

