#include <iostream>
#include <thread>
#include <chrono>

void task() {
    std::cout << "Thread is running\n";
}

int main() {
    std::thread myThread(task); // Thread is in the "new" state
    // ...

    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
}