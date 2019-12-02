#pragma once
// song.h

#ifndef SONGS_H
#define SONGS_H

#include <iostream>

using namespace std;

// Song is a simple class that stores a title and artist as strings
// it just provides i/o operators, == operator, constructors and Set function
class Songs
{
	// output the song in the format:
	// title, artist
	friend ostream& operator<<(ostream& os, const Songs& song);

	// input the song in the format:
	// title, artist
	friend istream& operator>>(istream& is, Songs& song);

	// compare two song objects for equality
	friend bool operator==(const Songs& lhs, const Songs& rhs);

public:
	// constructors
	Songs();
	Songs(const char* t, const char* a);

	// set the song
	void Set(const char* t, const char* a);

private:
	static const int MAX_CHARS = 64;

	char title[MAX_CHARS];
	char artist[MAX_CHARS];
};

#endif

