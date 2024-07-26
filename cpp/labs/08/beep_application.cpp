#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

void beepThread(atomic<bool>& running, int delay) {
    while (running.load()) {
        cout << '\a' << flush;  // Beep
        this_thread::sleep_for(chrono::seconds(delay));  // Wait for the specified delay
    }
}

int main() {
    atomic<bool> running(true);  // Atomic flag to control the thread
    int delay = 3;  // Delay in seconds

    // Start the beep thread
    thread t(beepThread, ref(running), delay);

    // Wait for the user to press Enter
    cin.get();

    // Stop the beep thread
    running.store(false);
    t.join();

    return 0;
}
