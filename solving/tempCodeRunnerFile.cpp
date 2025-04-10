 N;
    std::multiset<int> absHeap;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        if (x == 0) {
            std::cout << pop(absHeap) << "\n";
        } else {
            push(absHeap, x);
        }
    }