#include "PlayList.h"
#include<iostream>
#include"Songs.h"
using namespace std;

//default constructor
PlayList::PlayList()
{
	sop = 2;
	song_index = 0;
	nos = 0;
	plLi_arr = new Songs[sop];
}

//destructor
PlayList::~PlayList()
{
	delete[] plLi_arr;
}
//function to add song in the playlist
void PlayList::AddSong(const Songs& s)
{
	Songs sng_null;
	int index = 0;
	while (!(*(plLi_arr + index) == sng_null) && (index < sop))
	{
		index++;
	}
	if (index == (sop - 1) || index > (sop - 1))
	{
		doublesize();
	}
	(*(plLi_arr + index)) = s;
	cout << "Song has been added to the playlist." << endl;
}
bool PlayList::DeleteSong(const Songs & s)
{
	Songs sng_null;
	int index = 0;
	while (index != sop)
	{
		if (*(plLi_arr + index) == s)
		{
			int nindx = index + 1;  //next index
			while (nindx <= (sop - 1))
			{
				if (!(*(plLi_arr + nindx) == sng_null))
				{
					*(plLi_arr + index) = *(plLi_arr + nindx);
					nindx++;
					index++;
					if (nindx == sop - 1)
					{
						*(plLi_arr + nindx) = sng_null;
						*(plLi_arr + (nindx - 1)) = sng_null;
						return true;
					}
				}
				else
				{
					*(plLi_arr + (nindx - 1)) = sng_null;
					if (index < (sop / 2))
					{
						halfsize();
					}
					return true;
				}
			}

		}
		else
		{
			if ((*(plLi_arr + index) == sng_null) && (index < (sop / 2)))
			{
				halfsize();
			}
		}
		index++;
	}
	return false;
}
//function to print all the songs
void PlayList::ShowAll() const
{
	for (int index = 0; index < sop; index++)
	{
		cout << *(plLi_arr + index) << endl;
	}
}
void PlayList::play(int num)
{
	Songs sng_null;
	song_index = 0;
	int c = 0;
	for (c; c != num; c++)
	{
		cout << *(plLi_arr + song_index) << endl;
		if (song_index == (sop - 1))
		{
			song_index = -1;
		}
		song_index++;
	}
}
//function to print playlist size ,total number of songs in the playlist and current song index
void PlayList::ShowStatus() const
{
	cout << "Size of playlist is " << sop << " , ";
	int count = 0;  //loop variable
	int nos1 = 0;      //variable for number of total songs in the playlist
	Songs sng_null;
	for (count; count < sop; count++)   //loop for finding total number of songs
	{
		if (!(*(plLi_arr + count) == sng_null))
		{
			nos1++;
		}
	}
	cout << "Number of songs in the Playlist " << nos1 << " , ";
	cout << "Currently at song number " << song_index << endl;
}
//function to double the size of the playlist and used in add function
void PlayList::doublesize()
{
	int nsop = sop * 2;
	Songs* nplLi_arr = new Songs[nsop];
	for (int index = 0; index < sop; index++)
	{
		*(nplLi_arr + index) = *(plLi_arr + index);
	}
	this->sop = nsop;
	plLi_arr = nplLi_arr;
}
//function to half the size of playlist 
void PlayList::halfsize()
{
	int nsop = sop / 2;
	Songs* nplLi_arr = new Songs[nsop];
	for (int index = 0; index < sop; index++)
	{
		*(nplLi_arr + index) = *(plLi_arr + index);
	}
	this->sop = nsop;
	plLi_arr = nplLi_arr;
}


//overloaded operator to add the song in the play list
PlayList operator+(PlayList & pl, Songs & s)
{
	pl.AddSong(s);
	return pl;
}

//overloaded operator to remove song from the playlist
PlayList operator-(PlayList & pl, Songs & s)
{
	pl.DeleteSong(s);
	return pl;
}

