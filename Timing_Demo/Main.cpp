#include "Timing.h"
#include <vector>

int main() {
	Timing* timing = new Timing(true);

	{
		const char* timerName = "Test 1";
		timing->StartTimer(timerName);
		std::vector<int> list;
		for (int i = 0; i < 100000; ++i) {
			list.push_back(i);
		}
		timing->EndTimer(timerName);
	}

	{
		const char* timerName = "Test 2";
		timing->StartTimer(timerName);
		std::vector<int> list;
		for (int i = 0; i < 100000 * 100; ++i) {
			list.push_back(i);
		}
		timing->EndTimer(timerName);
	}

	timing->PrintSummary();
	delete timing;

}
