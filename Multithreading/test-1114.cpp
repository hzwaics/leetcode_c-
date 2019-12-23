class Foo {
public:
    Foo() {
        smx.lock();
        tmx.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        smx.unlock();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        smx.lock();
        printSecond();
        tmx.unlock();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        tmx.lock();
        printThird();
    }

    private:
    mutex smx, tmx;
};

// mutex的复习