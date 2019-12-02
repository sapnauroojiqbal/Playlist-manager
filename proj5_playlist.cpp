// proj5_playlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstring>
#include"PlayList.h"
#include"Songs.h"
using namespace std;

bool Menu(PlayList& play_list)
{
	char title[64], artist[64];
	Songs s;
	bool good;

	do
	{
		good = true;

		cout << "\n\nPlayList Program!\n"
			<< "\tA - Add a song\n"
			<< "\tD - Delete a song\n"
			<< "\tI - Increment a song in the playlist\n"
			<< "\tR - Removing a song from the playlist\n"
			<< "\tP - Play number of song\n"
			<< "\tS - Show all songs\n"
			<< "\tT - Show playlist status\n"
			<< "\tQ - Quit\n: ";

		char choice;
		cin >> choice;

		switch (toupper(choice))
		{
		case 'A':
		{cout << "Input the song in the format (Song, Artist name), to add in the list " << endl;
		cin.getline(title, 64);
		cin.getline(artist, 64);
		s.Set(title, artist);
		play_list.AddSong(s);
		break;
		}

		case 'D':
		{ cout << "Input the song in the format (Song, Artist name), to delete from the list" << endl;
		cin.getline(title, 64);
		cin.getline(artist, 64);
		s.Set(title, artist);
		if (play_list.DeleteSong(s) == true)
		{
			cout << "Song successfully deleted\n";
		}
		else
		{
			cout << "No such song exists\n";
		}
		break;
		}

		case 'P':
		{int n;
		cout << "Input the number of songs you want to play" << endl;
		cin >> n;
		play_list.play(n);
		break;
		}
		case 'I':
		{
			cout << "Input the song in the format (Song, Artist name), to add in the list " << endl;
			cin.getline(title, 64);
			cin.getline(artist, 64);
			s.Set(title, artist);

			PlayList p1 = play_list + s;
			break;

		}
		case 'R':
		{
			cout << "Input the song in the format (Song, Artist name), to add in the list " << endl;
			cin.getline(title, 64);
			cin.getline(artist, 64);
			s.Set(title, artist);

			PlayList p1 = play_list - s;
			break;
		}
		case 'S':
		{
			play_list.ShowAll();
			break;
		}
		case 'T':
		{
			play_list.ShowStatus();
			break;
		}
		case 'Q':
		{
			return false;
		}
		default:
			good = false;
		}
	} while (!good);

	return true;
}

int main()
{
	PlayList play_list;

	while (Menu(play_list));

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
