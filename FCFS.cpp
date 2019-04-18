//a randomly generated FCFS scheduler.
#include<iostream>
#include<ctime>
#define SIZE 100
using namespace std;

struct Process {
	int burst[SIZE];
	int arrival[SIZE];
	int wait[SIZE];
	int turnaround[SIZE];
};

int main() {
//Variable declaration.
	struct Process process;
	int avgwait = 0, avgturnaround = 0;
	process.wait[0] = 0;
	srand(time(NULL));

//Inputs a random process burst time into the array.
	for (int i = 0; i < SIZE; i++) {
		process.burst[i] = rand() % 21;
		if (process.burst[i] == 0) {
			process.burst[i] = rand() % 21;
		}
	}

//Inputs a random arrival time into the arrival array.
	for (int i = 0; i < SIZE; i++) {
		process.arrival[i] = rand() % 11;
	}

//Selection sort the arrival time.
	for (int i = 0; i < SIZE - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < SIZE; j++)
			if (process.arrival[j] < process.arrival[minIndex])
				minIndex = j;
		if (minIndex != i) {
			int tmp = process.arrival[i];
			process.arrival[i] = process.arrival[minIndex];
			process.arrival[minIndex] = tmp;
		}
	}

//Calculates the wait time.
	for (int i = 1; i < SIZE; i++) {
		process.wait[i] = 0;
		for (int j = 0; j < i; j++) {
			process.wait[i] += process.burst[j];
		}
	}
	cout << "Process:\tBurst Time:\tArrival Time:\tWaiting Time:\tTurnaround Time:";

//Calculates the turn-around time.
	for (int i = 0; i < SIZE; i++) {
		process.turnaround[i] = process.burst[i] + process.wait[i];
		//adding numerator together for avgwait and avgturnaround
		avgwait = avgwait + process.wait[i];
		avgturnaround = avgturnaround + process.turnaround[i];
		cout << "\nP[" << i + 1 << "]" << "\t\t" << process.burst[i] << "\t\t" << process.arrival[i] << "\t\t" << process.wait[i]
			<< "\t\t" << process.turnaround[i];
	}

//Calculates the average wait time and average turn-around time then outputs the data.
	avgwait = avgwait / SIZE;
	avgturnaround = avgturnaround / SIZE;
	cout << "\n\nAverage Waiting Time: " << avgwait;
	cout << "\nAverage Turnaround Time: " << avgturnaround << endl;
	//system("PAUSE");
	return 0;
}
