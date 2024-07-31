#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

class SpinLock
{
private:
    std::atomic_flag lock_flag = ATOMIC_FLAG_INIT;

public:
    void lock()
    {
        int spin_count = 0;
        while (lock_flag.test_and_set(std::memory_order_acquire))
        {
            if (++spin_count >= 20)
            {
                std::this_thread::yield();
                spin_count = 0;
            }
        }
    }

    void unlock()
    {
        lock_flag.clear(std::memory_order_release);
    }
};

void multiplyByTwo(int &shared_var, SpinLock &spinlock)
{
    for (int i = 0; i < 10; ++i)
    {
        spinlock.lock();
        shared_var *= 2;
        std::cout << "Multiplied: " << shared_var << std::endl;
        spinlock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void divideByTwo(int &shared_var, SpinLock &spinlock)
{
    for (int i = 0; i < 10; ++i)
    {
        spinlock.lock();
        if (shared_var != 0)
        { // Check to avoid division by zero
            shared_var /= 2;
            std::cout << "Divided: " << shared_var << std::endl;
        }
        spinlock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    int shared_var = 4; // Start with a value that ensures safe division
    SpinLock spinlock;

    std::thread t1(multiplyByTwo, std::ref(shared_var), std::ref(spinlock));
    std::thread t2(divideByTwo, std::ref(shared_var), std::ref(spinlock));

    t1.join();
    t2.join();

    return 0;
}

