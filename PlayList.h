#pragma once
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include"Songs.h"
#include<iostream>
using namespace std;

class PlayList
{
private:
	Songs* plLi_arr;//songs array
	int sop;//size of playlist
	int nos;//number of songs
	int song_index;  //current song index
public:
	PlayList();
	~PlayList();
	void AddSong(const Songs& s);   //function to add song to the playlist
	bool DeleteSong(const Songs& s);    //function to delete song from the play list
	void ShowAll() const;      //function to print all the songs in the playlist
	void play(int num = 1);   //function to play the songs in the playlist
	void ShowStatus()const;   //function to show the status information of playlist
	void doublesize();        //function used in add function
	void halfsize();       //function used in delete function
	friend PlayList operator+(PlayList& pl, Songs& s);  //overloaded operator for increment
	friend PlayList operator-(PlayList& pl, Songs& s);  //overloaded operator for decrement
};
#endif

