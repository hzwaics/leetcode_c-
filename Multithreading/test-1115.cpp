class FooBar {
private:
    int n;
    mutex smx, tmx;

public:
    FooBar(int n) {
        this->n = n;
        smx.lock();
        tmx.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            tmx.unlock();
        	printFoo();
            smx.lock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            tmx.lock();
        	printBar();
            smx.unlock();
        }
    }
};