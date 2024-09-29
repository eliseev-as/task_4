#include <iostream>
#include <thread>

std::mutex mtx;
int counter = 1;

bool is_even = counter % 2 == 0;
bool is_odd = counter % 2 != 0;

void print_numbers(const bool predicate) {
    while (counter <= 10) {
        mtx.lock();
        if (predicate) {
            std::cout << counter << std::endl;
            counter++;
        }
        mtx.unlock();
    }
}

int main() {
    std::thread t1(print_numbers, is_even);
    std::thread t2(print_numbers, is_odd);

    t1.join();
    t2.join();

    return 0;
}
