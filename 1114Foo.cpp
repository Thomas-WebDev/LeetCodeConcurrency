class 1114Foo {
pthread_mutex_t firstpTMLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t secondpTMLock = PTHREAD_MUTEX_INITIALIZER;
public:
    Foo() {
        pthread_mutex_lock(&firstpTMLock);
        pthread_mutex_lock(&secondpTMLock);
    }

    void first(function<void()> printFirst) {                
        printFirst(); // printFirst() outputs "first". Do not change or remove this line.
        pthread_mutex_unlock(&firstpTMLock);
    }
    void second(function<void()> printSecond) {
        pthread_mutex_lock(&firstpTMLock);        
        printSecond(); // printSecond() outputs "second". Do not change or remove this line.
        pthread_mutex_unlock(&secondpTMLock);
    }
    void third(function<void()> printThird) {
        pthread_mutex_lock(&secondpTMLock);
        printThird(); // printThird() outputs "third". Do not change or remove this line.
    }
};
