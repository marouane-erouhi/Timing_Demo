#include "Timing.h"
#include <vector>

int main() {
	//Timing* timing = new Timing(true);

	// test printf and cout
	{
		int num = 100;
		{
			Timing timing("prinf");
			for (int i = 0; i < num; i++) {
				printf("i:%d", i);
			}
			printf("\n");
		}
		{
			Timing timing("cout");
			for (int i = 0; i < num; i++) {
				std::cout << "i:" << i;
			}
			std::cout << std::endl;
		}
	}

	//int test_times[3];
	//int test_iterations = 100;

	//{
	//	Timing timing("Test 1 = pre allocated", test_times[0]);
	//	for (int i = 0; i < test_iterations; i++) {
	//		std::vector<int> list(100000);
	//		for (int i = 0; i < 100000; ++i) {
	//			//list.push_back(i);
	//			list[i] = i;
	//		}
	//	}
	//}
	//printf("time avg: %d\n", test_times[0] / test_iterations);

	//{
	//	Timing timing("Test 2 - push_back", test_times[1]);
	//	for (int i = 0; i < test_iterations; i++) {
	//		std::vector<int> list;
	//		for (int i = 0; i < 100000; ++i) {
	//			list.push_back(i);
	//		}
	//	}
	//}
	//printf("time avg: %d\n", test_times[1] / test_iterations);

	//{
	//	Timing timing("Test 3 - array", test_times[2]);
	//	for (int i = 0; i < test_iterations; i++) {
	//		int list[100000];
	//		for (int i = 0; i < 100000; ++i) {
	//			list[i] = i;
	//		}
	//	}
	//}
	//printf("time avg: %d\n", test_times[2] / test_iterations);


	//{
	//	const char* timerName = "Test 1";
	//	timing->StartTimer(timerName);
	//	std::vector<int> list(100000);
	//	for (int i = 0; i < 100000; ++i) {
	//		//list.push_back(i);
	//		list[i] = i;
	//	}
	//	timing->EndTimer(timerName);
	//}

	//{
	//	const char* timerName = "Test 2";
	//	timing->StartTimer(timerName);
	//	std::vector<int> list;
	//	for (int i = 0; i < 100000 * 100; ++i) {
	//		list.push_back(i);
	//	}
	//	timing->EndTimer(timerName);
	//}

	//timing->PrintFinalSummary();
	//delete timing;

}
