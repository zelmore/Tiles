/*
Tiles.cpp
Zachary Elmore
6/17/16
find out how many tiles are needed for a fooring project
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int INCHES_IN_A_FOOT = 12; //Constant for the inches in a foot
const int TILES_PER_BOX = 20; //Constant for the number of tiles per box

int numberOfTilesForRoom(int tileSize, int roomWFt, int roomWIn, int roomLFt, int roomLIn);
void displayResults(int tiles, int boxes, int extra);
int numberOfBoxes(int numTiles);

int main()
{
	int tileSize;
	int numRooms;
	int roomCounter;
	int roomWFt;//Room's width in feet
	int roomWIn;//Room's width in inches
	int roomLFt;//Room's length in feet
	int roomLIn; //Room's length in inches
	int boxes;
	int totalTileCounter = 0;
	double tilesForRoom;
	double extra;

	cout << "Enter size of the tiles in inches: ";//User enters the size of the tiles
	cin >> tileSize;
	while (tileSize <= 0)//Output if the user enters an invalid integer
	{
		cout << "ERROR! Enter a valid integer.";
		cin >> tileSize;
	}

	cout << "Enter number of rooms: ";//User enters the number of rooms
	cin >> numRooms;
	while (numRooms < 1)//Output if the user enters an invalid integer
	{
		cout << "ERROR! Enter a valid integer.";
		cin >> numRooms;
	}

	for (roomCounter = 0; roomCounter < numRooms; roomCounter++)//For-loop for rooms
	{
		cout << "Enter room width in feet: ";//User enters in how many feet are in the width
		cin >> roomWFt;
		while (roomWFt <= 0)//Output if the user enters an invalid integer
		{
			cout << "Error! Enter a valid number.";
			cin >> roomWFt;
		}

		cout << "Enter room width inches: ";//User enters in how many inches are in the width
		cin >> roomWIn;
		while (roomWIn < 0 || roomWIn > 11) //Output if the user enters an invalid integer
		{
			cout << "Error! Enter a valid number.";
			cin >> roomWIn;
		}

		cout << "Enter room length feet: ";//User enters in how many feet are in the length
		cin >> roomLFt;
		while (roomLFt <= 0)//Output if the user enters an invalid integer
		{
			cout << "Error! Enter a valid number.";
			cin >> roomLFt;
		}

		cout << "Enter room length inches: ";//User enters in how many inches are in the length
		cin >> roomLIn;
		while (roomLIn < 0 || roomLIn > 11)//Output if the user enters an invalid integer
		{
			cout << "Error! Enter a valid number.";
			cin >> roomLIn;
		}

		tilesForRoom = numberOfTilesForRoom(tileSize, roomWFt, roomWIn, roomLFt, roomLIn);/*Calls for the equation used to find the
																						  number of tiles needed for the project*/
		totalTileCounter += tilesForRoom;
		cout << "Room requires " << tilesForRoom << " tiles.\n\n";//Output for the number of tiles required
	}
	boxes = numberOfBoxes(totalTileCounter);//Calls for the number of boxes needed for the project
	extra = totalTileCounter - (boxes * TILES_PER_BOX);//Calls for the amount of extra tiles
	displayResults(totalTileCounter, boxes, extra);//Calls for the display of the results

	cin.ignore();
	cin.get();
	return 0;
}

int numberOfTilesForRoom(int tileSize, int roomWFt, int roomWIn, int roomLFt, int roomLIn)
{//equation for finding the number of tiles needed for the project
	float tiles = (((roomWFt * INCHES_IN_A_FOOT) + roomWIn) / float(tileSize)) * (((roomLFt * INCHES_IN_A_FOOT) + roomLIn)
		/ float(tileSize));
	return tiles;
}

int numberOfBoxes(int numTiles)// equation for finding the number of boxes needed
{
	int boxes;
	boxes = (float(numTiles) / TILES_PER_BOX);
	return boxes;
}

void displayResults(int tiles, int boxes, int extra)//Layout for the display of results
{
	cout << "Total tiles required is " << tiles << "." << endl;
	cout << "Number of boxes needed is " << boxes << "." << endl;
	cout << "There will be " << extra << " extra tiles.";
}