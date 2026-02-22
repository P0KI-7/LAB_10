#ifndef MyPipeline_hpp
#define MyPipeline_hpp


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
    //T run(T value) const;
    
    // Trace
    //std::vector<T> trace(T value const);

    // Out <<
//  operator<<

};
 

template<class T>
template<class F>
void MyPipeline<T>::addStep(const std::string& name, F func)
{
    if (name.empty()) {
        ;
    }
    steps.push_back({name, std::function<T(T)>(func)});
}

template<class T>
void MyPipeline<T>::removeStep(size_t index)
{
    if (index >= steps.size()) {
        ;
    }
    steps.erase(steps.begin() + index);
}



#endif // MyPipeline_hpp