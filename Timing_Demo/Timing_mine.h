#pragma once
#include <iostream>  
#include <chrono>
#include <unordered_map>

struct TimerInfo {
	std::chrono::time_point<std::chrono::steady_clock> startTime;
	std::chrono::time_point<std::chrono::steady_clock> endTime;
};

class Timing {
private:
	std::unordered_map<const char*, TimerInfo*> timers;
	bool printOnEnd = false;
	bool detroyTimerOnEnd = true;

public:
	Timing(bool printOnEnd_ = false, bool detroyTimerOnEnd_ = true) 
		: printOnEnd(printOnEnd_), detroyTimerOnEnd(detroyTimerOnEnd_) {
		
	}
	~Timing() {
		for (auto val : timers) {
			delete val.second;
		}
	}

	void StartTimer(const char* timerName) {
		if (timers.count(timerName) == 0) {
			// create timer
			TimerInfo* timer = new TimerInfo();
			timer->startTime = std::chrono::high_resolution_clock().now();
			timers.insert({ timerName, timer });
		} else {
			printf("Timing:: Timer '%s' already exists, use a diffrent name.\n", timerName);
		}
	}

	int64_t EndTimer(const char* timerName) {
		auto timerMap = timers.find(timerName);
		TimerInfo* timer = timerMap->second;
		
		if (timer) {
			timer->endTime = std::chrono::high_resolution_clock().now();
			int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>(timer->startTime).time_since_epoch().count();
			int64_t end = std::chrono::time_point_cast<std::chrono::microseconds>(timer->endTime).time_since_epoch().count();
			int64_t diff = end - start;

			if (printOnEnd) {
				std::cout << "Timming::" << timerName << ": " << diff << " microseconds\n";
			}

			// destroy timer
			if (detroyTimerOnEnd) {
				delete timer;
				timers.erase(timerMap);
			}
			// return diffrence
			return diff;
		}
		// no such timer exists
		printf("Timing::No such timer called: '%s'\n", timerName);
		return 0;
	}

	void PrintFinalSummary() {
		printf("Timers created through out execution:----------------------\n");
		for (auto timer : timers) {
			std::cout << timer.first << ": " << timer.second->endTime.time_since_epoch().count() - timer.second->startTime.time_since_epoch().count() << " miliseconds.\n";
		}
		printf("End timing summary ----------------------------------------\n");
	}
};