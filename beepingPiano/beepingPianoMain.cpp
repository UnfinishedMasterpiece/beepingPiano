/*
	File Name: beepingPianoMain.cpp
	Written By: Sergio Flor
	3/12/2018
	
	**NOTE: THIS PROGRAM USES THE LEGACY BEEP FUNCTION. UNFORTUNATELY IT WILL NO LONGER WORK ON MODERN SYSTEMS.
	But if you have an older system with a timing chip for the PC Speaker, Have at it!
	
	I started this as just me playing around on the computer labs in college.
	
	They ran Windows 10 but they were older systems and were still able to route the sound through the default audio device.
	
	It's a fun little program but I see no point in developing it further due to the fact I can't actually tell if it works on my laptop...
	and I'm not in range of a PC that could play it.
*/

#include <iostream> //allows for input/output
#include <iomanip> //output formatting in this case
#include <windows.h> //beep and sleep commands

using namespace std; //so I don't have to call the standard namespace everytime I do some I/O

void bpmToWholeNote(); //converts the Beats per Minute (BPM) into milliseconds for use with the beep command
void determineNoteLength(double whole); //uses the millisecond conversion as a whole note base for half note, Quarter, etc. only accounts for a 4/4 time signature as of right now. Outputs result in miliseconds.
void playSong(double whole, double half, double quarter, double eighth, double sixteenth); //several arrays for notes and currently plays one song, "Merrilly We Roll Along".

void main() {
	system("color 4b"); //This changes the background to a reddish orange and the text to a complimenting teal, remove this line if you're not into it, I don't mind.
	bpmToWholeNote(); //starts the program. I set this up as a procedural program where each function is a step in the process. Step 1.
	system("pause"); //Waits for user response to terminate program.
}

void bpmToWholeNote() { //Step 1

	int bpm; //BPM entered by user.
	double whole; //Whole note in milliseconds, it's a double for program fluidity because some results have decimals. They will, however get truncated when entered into the beep function.

	cout << setfill('-'); //I wanted a heading that looked cool.
	cout << setw(40) << "Welcome to the Beeping Piano!" << setw(12) << "\n"; //This was oringinally going to be a PC speaker piano in C++ completely with event listeners for keys being pressed, octave switching, etc. I just kept the name.
	cout << setw(37) << "Written by: Sergio Flor" << setw(15) << "\n"; //C'est moi!
	cout << "\nEnter the Beats per Minute (BPM).\n"; //prompts user for input
	cin >> bpm; //user input

	if (bpm <= 140) {
		whole = (60000 / bpm);
		determineNoteLength(whole); //Step 2
	}									//BPM to Millisecond conversion. Tosses whole as a parameter for the next step.
	else if (bpm > 140) {
		(bpm / 2);
		whole = (60000 / bpm);
		whole = (whole / 2);
		determineNoteLength(whole); //Step 2
	}
}

void determineNoteLength(double whole) { //Step 2

	double half, quarter, eighth, sixteenth; //stores other notes

	half = (whole / 2);
	quarter = (half / 2); //populates the values of the other notes
	eighth = (quarter / 2);
	sixteenth = (eighth / 2);

	cout << fixed << setprecision(0) << endl;
	cout << setfill('-');
	cout << setw(41) << "All notes are in miliseconds(ms)" << setw(11) << "\n";
	cout << setfill(' ') << endl;
	cout << setw(20) << "Whole note" << setw(20) << whole << endl;
	cout << setw(19) << "Half note" << setw(20) << half << endl;
	cout << setw(22) << "Quarter note" << setw(17) << quarter << endl; //Prints out notes and their values
	cout << setw(21) << "Eighth note" << setw(18) << eighth << endl;
	cout << setw(24) << "Sixteenth note" << setw(14) << sixteenth << endl;
	cout << "\n";

	playSong(whole, half, quarter, eighth, sixteenth); //Step 3
}

void playSong(double whole, double half, double quarter, double eighth, double sixteenth) { //Step 3 with notes as parameters

	int a[8]{ 27, 55, 110, 220, 440, 880, 1760, 3520 };
	int aSharp[8]{ 29, 58, 116, 233, 466, 932, 1865, 3729 };
	int b[8]{ 31, 62, 123, 245, 494, 988, 1975, 3951 };
	int c[8]{ 16, 33, 65, 131, 262, 523, 1046, 2093 };
	int cSharp[8]{ 17, 35, 69, 139, 277, 554, 1109, 2217 };
	int d[8]{ 18, 37, 73, 147, 294, 587, 1175, 2349 };			//I got these values online. All in hertz.
	int dSharp[8]{ 19, 39, 78, 155, 311, 622, 1244, 2489 };
	int e[8]{ 21, 41, 82, 165, 330, 659, 1328, 2637 };
	int f[8]{ 22, 44, 87, 175, 349, 698, 1397, 2794 };
	int fSharp[8]{ 23, 46, 92, 185, 370, 740, 1480, 2960 };
	int g[8]{ 24, 49, 98, 196, 392, 784, 1568, 3136 };
	int gSharp[8]{ 26, 52, 104, 208, 415, 831, 1661, 3322 };

	Beep(b[4], quarter);
	Beep(a[4], quarter);
	Beep(g[4], quarter);
	Beep(a[4], quarter);

	Beep(b[4], quarter);
	Beep(b[4], quarter);
	Beep(b[4], half);

	Beep(a[4], quarter);
	Beep(a[4], quarter);
	Beep(a[4], half);
									//Plays the only song hard coded in this program, "Merrily We Roll Along"
	Beep(b[4], quarter);
	Beep(b[4], quarter);
	Beep(b[4], half);

	Beep(b[4], quarter);
	Beep(a[4], quarter);
	Beep(g[4], quarter);
	Beep(a[4], quarter);

	Beep(b[4], quarter);
	Beep(b[4], quarter);
	Beep(b[4], half);

	Beep(a[4], quarter);
	Beep(a[4], quarter);
	Beep(b[4], quarter);
	Beep(a[4], quarter);

	Beep(g[4], half);
	Sleep(half); //acts as a "rest"
}