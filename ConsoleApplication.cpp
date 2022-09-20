#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

void multiplyAndAdd(int a, int b, int rep) {
	for (int i = 0; i < rep; i++) {
		int x = 5 * a + 2 * b;
	};
}

void multiplyAndAddABitMore(int a, int b, int rep) {
	for (int i = 0; i < rep; i++) {
		int x = 2 * a + 3 * b + 3 * a - b;
	};
}

void main(void) {
	int a = 321;
	int b = 123;

	int th = 1000;
	int mi = 1000000;
	int bi = 100000000;

	auto now = high_resolution_clock::now();
	auto zero = duration_cast<microseconds>(now - now);

	microseconds timer1_th = zero;
	microseconds timer1_mi = zero;
	microseconds timer1_bi = zero;

	microseconds timer2_th = zero;
	microseconds timer2_mi = zero;
	microseconds timer2_bi = zero;

	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAdd(a, b, th);
		auto stop = high_resolution_clock::now();
		timer1_th += duration_cast<microseconds>(stop - start);
	}

	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAdd(a, b, mi);
		auto stop = high_resolution_clock::now();
		timer1_mi += duration_cast<microseconds>(stop - start);
	}

	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAdd(a, b, bi);
		auto stop = high_resolution_clock::now();
		timer1_bi += duration_cast<microseconds>(stop - start);
	}


	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAddABitMore(a, b, th);
		auto stop = high_resolution_clock::now();
		timer2_th += duration_cast<microseconds>(stop - start);
	}

	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAddABitMore(a, b, mi);
		auto stop = high_resolution_clock::now();
		timer2_mi += duration_cast<microseconds>(stop - start);
	}

	for (int i = 0; i <= th; i++) {
		auto start = high_resolution_clock::now();
		multiplyAndAddABitMore(a, b, bi);
		auto stop = high_resolution_clock::now();
		timer2_bi += duration_cast<microseconds>(stop - start);
	}

	cout << "\nmultiplyAndAdd (x10^3) (us): " << timer1_th.count() / static_cast<double>(th) << endl;
	cout << "multiplyAndAdd (x10^6) (ms): " << timer1_mi.count() / static_cast<double>(mi) << endl;
	cout << "multiplyAndAdd (x10^9) (ms): " << timer1_bi.count() / static_cast<double>(mi) << endl;

	cout << "\nmultiplyAndAddABitMore (x10^3) (us): " << timer2_th.count() / static_cast<double>(th) << endl;
	cout << "multiplyAndAddABitMore (x10^6) (ms): " << timer2_mi.count() / static_cast<double>(mi) << endl;
	cout << "multiplyAndAddABitMore (x10^9) (ms): " << timer2_bi.count() / static_cast<double>(mi) << endl;
}