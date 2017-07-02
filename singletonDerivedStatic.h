/*
 * File name: singletonDerivedStatic.h
 * Created on: Jul 3, 2017
 */

#ifndef SINGLETONDERIVEDSTATIC_H_
#define SINGLETONDERIVEDSTATIC_H_

template<typename T>
class singletonDerivedStatic: public T {

public:
    virtual ~singletonDerivedStatic() {
    }

    static singletonDerivedStatic &getInstance() {
        static singletonDerivedStatic instance;
        return instance;
    }

private:
    singletonDerivedStatic() : T() {
    }

    singletonDerivedStatic(const singletonDerivedStatic &) = delete;
    singletonDerivedStatic(singletonDerivedStatic &&) = delete;

    singletonDerivedStatic operator=(const singletonDerivedStatic &) = delete;
    singletonDerivedStatic operator=(singletonDerivedStatic &&) = delete;
};

#endif /* SINGLETONDERIVEDSTATIC_H_ */
