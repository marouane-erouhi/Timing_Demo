#ifndef TIMING_H
#define TIMING_H
#include <iostream>  
#include <chrono>

class Timing {
private:
	const char* blockName; /// Give the timing block a name
	//int& output;
	std::chrono::time_point<std::chrono::steady_clock> startTime;
	std::chrono::time_point<std::chrono::steady_clock> endTime;

public:
	/// Grab the current time upon construction of Timer
	//Timing(const char* name, int& output_):blockName(name), output(output_){
	//	startTime = std::chrono::high_resolution_clock().now();
	//}
	Timing(const char* name) :blockName(name){
		startTime = std::chrono::high_resolution_clock().now();
	}

	~Timing() {
		/// When the timer goes out of scope, grab the time - subtract from startTime = deltaTime
		endTime =  std::chrono::high_resolution_clock().now();
		/// time_since_epoch started at Thu Jan 1 00:00:00 1970
		int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
		int64_t end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();
		auto diff = end - start;
		//output = diff;
		std::cout << blockName << ": " << diff << " microseconds\n";	
	}
};
#endif
