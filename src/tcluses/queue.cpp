#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Push elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Access front and back elements
    std::cout << "Front element: " << myQueue.front() << std::endl; // 10
    std::cout << "Back element: " << myQueue.back() << std::endl;   // 30

    // Pop elements
    myQueue.pop(); // Removes 10
    std::cout << "Front element after pop: " << myQueue.front() << std::endl; // 20

    // Check size and emptiness
    std::cout << "Queue size: " << myQueue.size() << std::endl; // 2
    std::cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << std::endl; // No

    return 0;
}