/*
 * File name: singletonDerivedNew.h
 * Created on: Jul 3, 2017
 */

#ifndef SINGLETONDERIVEDNEW_H_
#define SINGLETONDERIVEDNEW_H_

#include <thread>
#include <mutex>

template<typename T>
class singletonDerivedNew: public T {

public:
    virtual ~singletonDerivedNew() {
    }

    static singletonDerivedNew &getInstance() {
        if(nullptr == instance_){
            std::lock_guard<std::mutex> lk(mutex_);
            if(nullptr == instance_){
                instance_ = new singletonDerivedNew;
            }
        }
        return (*instance_);
    }

private:
    singletonDerivedNew() : T() {
    }

    singletonDerivedNew(const singletonDerivedNew &) = delete;
    singletonDerivedNew(singletonDerivedNew &&) = delete;

    singletonDerivedNew operator=(const singletonDerivedNew &) = delete;
    singletonDerivedNew operator=(singletonDerivedNew &&) = delete;

private:
    static singletonDerivedNew *instance_;
    static std::mutex mutex_;
};

template<typename K>
singletonDerivedNew<K>* singletonDerivedNew<K>::instance_ = nullptr;

template<typename T>
std::mutex singletonDerivedNew<T>::mutex_;


#endif /* SINGLETONDERIVEDNEW_H_ */
