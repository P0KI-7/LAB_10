#ifndef MyPipeline_hpp
#define MyPipeline_hpp


#include <iostream>
#include <string>
#include <vector>
#include <functional>


 template <class T>
struct Step
{
    std::string name;
    std::function<T(T)> func;
};

template <class T>
class MyPipeline
{
    std::vector<Step<T>> steps;
public:
    // Basic methods
    MyPipeline() : steps() {};
    size_t size() const { return steps.size(); }
    bool empty() const { return steps.empty(); }
    void clear() { steps.clear(); }

    // Adding step
    template<class F>
    void addStep(const std::string& name, F func);

    // Remove step
    void removeStep(size_t index);
    
    // Run pipeline
    T run(T value) const;
    
    // Trace
    std::vector<T> trace(T value) const;

    // Out <<
    template<class U>
    friend std::ostream& operator<<(std::ostream& os, const MyPipeline<U>& p);
};
 

template<class T>
template<class F>
void MyPipeline<T>::addStep(const std::string& name, F func)
{
    if (name.empty()) {
        //;
    }
    steps.push_back({name, std::function<T(T)>(func)});
}

template<class T>
void MyPipeline<T>::removeStep(size_t index)
{
    if (index >= steps.size()) {
        //;
    }
    steps.erase(steps.begin() + index);
}

template<class T>
T MyPipeline<T>::run(T value) const
{
    for (auto &step : steps) {
        value = step.func(value);
    }
    return value;
}

template<class T>
std::vector<T> MyPipeline<T>::trace(T value) const
{
    std::vector<T> tr;
    T current = value;
    for (auto &step : steps) {
        current = step.func(value);
        tr.push_back(current);
    }
    return tr;
}

template<class U>
std::ostream& operator<<(std::ostream& os, const MyPipeline<U>& p)
{
    os << :"Pipekines step: " << p.steps.size() << std::endl;
    for (size_t i = 0; i < p.steps.size(); ++i) {
        os << i << ") " << p.steps[i].name << std::endl;
    }
    return os;
}

#endif // MyPipeline_hpp