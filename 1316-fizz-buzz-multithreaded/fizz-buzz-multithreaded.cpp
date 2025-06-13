class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;

public:
    FizzBuzz(int n) {
        this->n = n;
        turn = 1;
    }

    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            if (turn > n) break;
            while (turn <= n && !(turn % 3 == 0 && turn % 5 != 0)) {
                cv.wait(lock);
                if (turn > n) return;
            }
            if (turn > n) break;
            printFizz();
            ++turn;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            if (turn > n) break;
            while (turn <= n && !(turn % 5 == 0 && turn % 3 != 0)) {
                cv.wait(lock);
                if (turn > n) return;
            }
            if (turn > n) break;
            printBuzz();
            ++turn;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            if (turn > n) break;
            while (turn <= n && !(turn % 3 == 0 && turn % 5 == 0)) {
                cv.wait(lock);
                if (turn > n) return;
            }
            if (turn > n) break;
            printFizzBuzz();
            ++turn;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            if (turn > n) break;
            while (turn <= n && !(turn % 3 != 0 && turn % 5 != 0)) {
                cv.wait(lock);
                if (turn > n) return;
            }
            if (turn > n) break;
            printNumber(turn);
            ++turn;
            cv.notify_all();
        }
    }
};
