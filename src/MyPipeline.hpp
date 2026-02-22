#ifndef MyPipeline_hpp
#define MyPipeline_hpp


#include <string>
#include <vector>
#include <functional>


 template <class T>
class MyPipeline
{
    std::vector<Step> steps;
public:
    // Basic methods
    MyPipeline() : steps() {};
    size_t size() const { return steps.size() };
    bool empty() const { return steps.empty() };
    void clear() { steps.clear() };

    // Adding step
    //template<class F>
    //void addStep(const std::string& name, F func);
    // Remove step
    //void removeStep(size_t index);
    // Run pipeline
    //T run(T value) const;
    // Trace
    //std::vector<T> trace(T value const);

    // Out <<
//  operator<<

};
 
 template <class T>
struct Step
{
    std::string name;
    std::function<T(T)> func;
};

#endif // MyPipeline_hpp