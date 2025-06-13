class Foo {
private:
   binary_semaphore secondSem{0};
   binary_semaphore thirdSem{0};
public:
    Foo() {}

    // second() should be executed after first() and third() 

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        secondSem.release();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        secondSem.acquire();
        printSecond();
        thirdSem.release();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        thirdSem.acquire();
        printThird();
    }
};